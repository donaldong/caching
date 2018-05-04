load_data <- function(csv) {
    dat <- read.csv(csv)
    dat$hit_ratio <- dat$hit / (dat$hit + dat$miss)
    dat$cache_ratio <- dat$cache_size / dat$data_size
    return(dat)
}

plot.hit_ratio.cache_ratio <- function(csv) {
    dat <- load_data(csv)
    plot(hit_ratio ~ cache_ratio, dat, pch=19, cex=0.5, 
        col=rgb(red = 0, green = 0, blue = 0, alpha = 0.2), main=csv)
}
