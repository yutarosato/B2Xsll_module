#! /bin/tcsh -f
set expNo  = $1
set runNoi = $2
set runNof = $3
set FLAG   = $4
set LEVEL  = $5
set TYPE   = $6
set event  = $7
set stream = $8
set skim   = 'HadronBJ'
set device = 'zfserve'
  

if( $FLAG == 'RD' ) then
  echo 'process_url http://bweb3/mdst.php?ex='$expNo'&rs='$runNoi'&re='$runNof'&skm='$skim'&dt='$TYPE'&bl='$LEVEL'&dv='$device
else if( $FLAG == 'gMC' ) then
   echo 'process_url http://bweb3/montecarlo.php?ex='$expNo'&rs='$runNoi'&re='$runNof'&ty='$EVENT'&dt='$TYPE'&bl='$LEVEL'&dv='$device'&st='$STREAM
endif
