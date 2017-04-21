#!/bin/bash

for stream in 0 # 0 1 2 3 4 5
do
  for xs in 9999 # 1 10    101 1001 110 1010    201 1101 210 1110    301 1201 310 1210    401 1301 410 1310
  do
    ./run_XSLL_gMC.sh s mixed   $stream $xs
    ./run_XSLL_gMC.sh s charged $stream $xs
    ./run_XSLL_gMC.sh s uds     $stream $xs
    ./run_XSLL_gMC.sh s charm   $stream $xs
  done
done
