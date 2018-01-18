#!/bin/bash
function strip {
  echo $1 | sed -e "s/.*\///" -e "s/\.o.*//" -e "s/\.workload.*//"
}

for workload in *.workload
do
  a=$(strip "$workload")
  printf "$a "
  metrics/metrics.o < $workload
done
