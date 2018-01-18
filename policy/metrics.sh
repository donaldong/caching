#!/bin/bash
function strip {
  echo $1 | sed -e "s/.*\///" -e "s/\.o.*//" -e "s/\.workload.*//"
}

for workload in ../workload/*.workload
do
  for algo in *.o
  do
    a=$(strip "$workload")
    b=$(strip "$algo")
    printf "$a $b "
    ./$algo $1 < $workload
  done
done
