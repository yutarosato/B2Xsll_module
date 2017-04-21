#!/bin/bash

#for A7  in norm flip # norm flip
#do
#for A9  in `seq -200 20 200`
#do
#for A10 in `seq -200 20 200`
#do
#bsub -q s  ./make_ewp_script_sigMC.sh $A7 $A9 $A10 A
#done
#done
#done


#for A7  in norm flip # norm flip
#do
#for A9  in `seq -800 400 800`
#do
#for A10 in `seq -800 400 800`
#do
#bsub -q s  ./make_ewp_script_sigMC.sh $A7 $A9 $A10 A
#done
#done
#done

###################
##  systematics  ##
###################
for A7  in flip # norm flip
do
for A9  in `seq -200 20 200`
do
for A10 in `seq -200 20 200`
do
#bsub -q e  ./make_ewp_script_sigMC_fm200.sh $A7 $A9 $A10 A
#bsub -q e  ./make_ewp_script_sigMC_fm410.sh $A7 $A9 $A10 A
#bsub -q e  ./make_ewp_script_sigMC_fm480.sh $A7 $A9 $A10 A
#bsub -q e  ./make_ewp_script_sigMC_mb465.sh $A7 $A9 $A10 A
#bsub -q e  ./make_ewp_script_sigMC_mb495.sh $A7 $A9 $A10 A
#bsub -q e  ./make_ewp_script_sigMC_lambdaone429.sh $A7 $A9 $A10 A
#bsub -q e  ./make_ewp_script_sigMC_lambdaone362.sh $A7 $A9 $A10 A
bsub -q e  ./make_ewp_script_sigMC_ff6.sh $A7 $A9 $A10 A
done
done
done
