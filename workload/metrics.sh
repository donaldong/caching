#!/bin/bash
for workload in *.workload
do
  printf "$workload "
  metrics/metrics.o < $workload
done
