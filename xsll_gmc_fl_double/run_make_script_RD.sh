#!/bin/bash

for exp in 13 15 17 21 31 35 39 51 65
do
  for xs in 9999 #1 10    101 1001 110 1010    201 1101 210 1110    301 1201 310 1210    401 1301 410 1310
  do
    ./make_ewp_script_gMC_fl_RD.sh $exp $xs
  done
done
