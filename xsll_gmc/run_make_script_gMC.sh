#!/bin/bash

for stream in 6 7 8 9 # 0 1 2 3 4 5
do
  for xs in 9999 #1 10    101 1001 110 1010    201 1101 210 1110    301 1201 310 1210    401 1301 410 1310
  do
    #bsub -q e ./make_ewp_script_gMC.sh uds     $stream $xs
    #bsub -q e ./make_ewp_script_gMC.sh charm   $stream $xs
    bsub -q e ./make_ewp_script_gMC.sh mixed   $stream $xs
    bsub -q e ./make_ewp_script_gMC.sh charged $stream $xs
  done
done

