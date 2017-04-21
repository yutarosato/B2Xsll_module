#!/bin/bash

for A7  in norm flip
do
for A9  in `seq -200 20 200`
do
for A10 in `seq -200 20 200`
do
    ./run_XSLL_Gen.sh  s $A7 $A9 $A10 A
done
done
done
