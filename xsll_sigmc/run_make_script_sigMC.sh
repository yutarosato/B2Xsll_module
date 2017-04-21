#!/bin/bash

for set in A B C D E F G H I J K L M N # O P Q R S T U

do
  for xs in 9999 # 1 10    101 1001 110 1010    201 1101 210 1110    301 1201 310 1210    401 1301 410 1310
  do

    #./make_ewp_script_sigMC.sh $set                             $xs # 1
    #./make_ewp_script_sigMC.sh $set$set                         $xs # 2
    #./make_ewp_script_sigMC.sh $set$set$set                     $xs # 3
    #./make_ewp_script_sigMC.sh $set$set$set$set                 $xs # 4
    #./make_ewp_script_sigMC.sh $set$set$set$set$set             $xs # 5
    #./make_ewp_script_sigMC.sh $set$set$set$set$set$set         $xs # 6
    #./make_ewp_script_sigMC.sh $set$set$set$set$set$set$set     $xs # 7
    #./make_ewp_script_sigMC.sh $set$set$set$set$set$set$set$set $xs # 8

    #bsub -q e ./make_ewp_script_sigMC_fm200.sh       $set                  $xs
    #bsub -q e ./make_ewp_script_sigMC_fm480.sh       $set                  $xs
    #bsub -q e ./make_ewp_script_sigMC_mb465.sh       $set                  $xs
    #bsub -q e ./make_ewp_script_sigMC_mb495.sh       $set                  $xs
    #bsub -q e ./make_ewp_script_sigMC_lambdaone429.sh $set                  $xs
    #bsub -q e ./make_ewp_script_sigMC_lambdaone362.sh $set                  $xs
    bsub -q e ./make_ewp_script_sigMC_ff6.sh       $set                  $xs

  done
done
