#!/bin/bash

for stream in 0
do
  for type in uds charm mixed charged
  do
    for exp in 31 # 13 15 17 21 31 35 39 51 65
    do
      ./run_XSLL_gMC_e0${exp}.sh s $type $stream 9999
    done
  done
done
