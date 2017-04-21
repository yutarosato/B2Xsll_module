#!/bin/bash

for set in A # B C D E F G H I J K L M N O P Q R S T U
do
    bsub -q e ./make_ewp_script_sigMC.sh $set 9999
done
