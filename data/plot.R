source('utils.R')

png('519.lbm_r.lru.png', width=600, height=600)
plot.hit_ratio.cache_ratio('519.lbm_r.lru.csv')
dev.off()
