exec_lru <- function(cache_size, data_size) {
    workload <- '519.lbm_r.raw.workload'
    cmd <- paste(c('./lru.o', cache_size, workload, data_size), collapse=' ')
    res <- system(cmd, intern=TRUE)
    return(as.numeric(strsplit(res, split=' ')[[1]]))
}

main <- function(r) {
    max_size <- 1e6
    data_sizes <- c()
    cache_sizes <- c()
    hit <- c()
    miss <- c()
    for (i in 1:r) {
        data_size <- runif(1) * max_size
        cache_size <- runif(1) * data_size
        data_size <- as.integer(data_size)
        cache_size <- as.integer(cache_size)
        res <- exec_lru(cache_size, data_size)
        data_sizes <- c(data_sizes, data_size)
        cache_sizes <- c(cache_sizes, cache_size)
        hit <- c(hit, res[1])
        miss <- c(miss, res[2])
    }
    return(data.frame(
        data_size=data_sizes,
        cache_size=cache_sizes,
        hit=hit,
        miss=miss
    ))
}
