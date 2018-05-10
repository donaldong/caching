exec_sample <- function(data_size, workload) {
    workload <- paste0(workload, '.raw.workload')
    cmd <- paste(c('./sample.o', workload, data_size), collapse=' ')
    res <- system(cmd, intern=TRUE)
    return(as.numeric(strsplit(res, split=' ')[[1]]))
}

exec_policy <- function(policy, cache_size, workload) {
    workload <- paste0(workload, '.raw.comb.workload')
    cmd <- paste(c(policy, cache_size, workload), collapse=' ')
    res <- system(cmd, intern=TRUE)
    return(as.numeric(strsplit(res, split=' ')[[1]]))
}

gen <- function(r, workload, max_size, policies, all=FALSE) {
    df <- data.frame(data_size=integer(), cache_size=integer(),
        unique_size=integer(), reads=integer(), writes=integer(), data=integer(), ins=integer(), 
        avg_step=double(), avg_reuse_dist=double(),
        sum_sqrt_count=double(), sum_count=integer(), lis=integer(), lds=integer())
    for (policy in policies) {
        df[,policy] <- integer()
    }
    for (i in 1:r) {
        print(i)
        if (!all) {
            data_size <- runif(1, min=0.01) * max_size
            data_size <- max(as.integer(data_size), 1)
        } else {
            data_size <- max_size
        }
        metrics <- exec_sample(data_size, workload) 
        cache_size <- runif(1, min=0.01) * metrics[1]
        cache_size <- max(as.integer(cache_size), 1)
        hit <- c()
        for (j in 1:length(policies)) {
            name <- paste0(c('../policy/', policies[j], '.o'), collapse='')
            res <- exec_policy(name, cache_size, workload)
            hit <- c(hit, res[1])
        }
        df[i,] <- c(data_size, cache_size, metrics, hit)
    }
    return(df)
}

policies <- c('belady', 'lru', 'pivot', 'ld', 'mru')
