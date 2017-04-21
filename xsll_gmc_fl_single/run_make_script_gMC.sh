#!/bin/bash

for type in uds charm mixed charged
do
  for stream in 0 # 1 2 3 4 5
  do
    ./make_ewp_script_gMC_fl.sh  $type $stream
  done
done
