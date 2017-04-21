#!/bin/bash

#for A7  in norm #flip
#do
#for A9  in `seq -200 20 200`
#do
#for A10 in `seq -200 20 200`
#do
    #./run_XSLL_Gen.sh  s $A7 $A9 $A10 A
#done
#done
#done




#for A7  in norm flip
#do
#for A9  in `seq -200 20 200`
#do
#for A10 in `seq -200 20 200`
#do
# for FM in 200 410 480
#do
#  ./run_XSLL_Gen_fm.sh  s  $A7 $A9 $A10 A $FM
#done
#done
#done
#done


#for A7  in norm flip
#do
#for A9  in `seq -200 20 200`
#do
#for A10 in `seq -200 20 200`
#do
# for MB in 465 495
#do
#  ./run_XSLL_Gen_mb.sh  s  $A7 $A9 $A10 A $MB
#done
#done
#done
#done


for A7  in norm
do
for A9  in `seq -200 20 200`
do
for A10 in `seq -200 20 200`
do
 for LAMBDA in 362
do
  ./run_XSLL_Gen_lambdaone.sh  s  $A7 $A9 $A10 A $LAMBDA
done
done
done
done
