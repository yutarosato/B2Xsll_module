#!/bin/bash

for set in  A B C D E F G # H I J K L M N O P Q R S T U
do
for xs in 9999 # 1 10    101 1001 110 1010    201 1101 210 1110    301 1201 310 1210    401 1301 410 1310
  do

    #./run_XSLL_sigMC_lambdaone.sh          s $xs $set 429
    #./run_XSLL_sigMC_lambdaone_c10flip.sh  s $xs $set 429

    ./run_XSLL_sigMC_lambdaone.sh          s $xs $set 362
    ./run_XSLL_sigMC_lambdaone_c10flip.sh  s $xs $set 362

    #./run_XSLL_sigMC_fm.sh          s $xs $set 200
    #./run_XSLL_sigMC_fm_c10flip.sh  s $xs $set 200
    #./run_XSLL_sigMC_fm.sh          s $xs $set 480
    #./run_XSLL_sigMC_fm_c10flip.sh  s $xs $set 480

    #./run_XSLL_sigMC_mb.sh          s $xs $set 465
    #./run_XSLL_sigMC_mb_c10flip.sh  s $xs $set 465
    #./run_XSLL_sigMC_mb.sh          s $xs $set 495
    #./run_XSLL_sigMC_mb_c10flip.sh  s $xs $set 495

    #./run_XSLL_sigMC.sh         s $xs $set
    #./run_XSLL_sigMC_c10flip.sh s $xs $set
    #./run_XSLL_sigMC.sh         s $xs $set$set
    #./run_XSLL_sigMC_c10flip.sh s $xs $set$set
    #./run_XSLL_sigMC.sh         s $xs $set$set$set
    #./run_XSLL_sigMC_c10flip.sh s $xs $set$set$set
    #./run_XSLL_sigMC.sh         s $xs $set$set$set$set
    #./run_XSLL_sigMC_c10flip.sh s $xs $set$set$set$set
    #./run_XSLL_sigMC.sh         s $xs $set$set$set$set$set
    #./run_XSLL_sigMC_c10flip.sh s $xs $set$set$set$set$set


    #./run_XSLL_sigMC.sh         s $xs $set$set$set$set$set$set
    #./run_XSLL_sigMC_c10flip.sh s $xs $set$set$set$set$set$set
    #./run_XSLL_sigMC.sh         s $xs $set$set$set$set$set$set$set
    #./run_XSLL_sigMC_c10flip.sh s $xs $set$set$set$set$set$set$set
    #./run_XSLL_sigMC.sh         s $xs $set$set$set$set$set$set$set$set
    #./run_XSLL_sigMC_c10flip.sh s $xs $set$set$set$set$set$set$set$set
  done
done
