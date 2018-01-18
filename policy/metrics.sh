#!/bin/bash
function strip {
  echo $1 | sed -e "s/.*\///" -e "s/\..*//"
}

for algo in *.o
do
  for workload in ../workload/*.workload
  do
    a=$(strip "$algo")
    b=$(strip "$workload")
    printf "$a $b "
    ./$algo $1 < $workload
  done
done
