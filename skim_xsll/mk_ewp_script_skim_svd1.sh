#! /bin/tcsh -f

set MDL    = `echo $1 | cut -d "/" -f 1`
set LEVEL  = `echo $1 | cut -d "/" -f 2`
set EVENT  = `echo $1 | cut -d "/" -f 3`
set STREAM = `echo $1 | cut -d "/" -f 4`
set TAG    = `echo $1 | cut -d "/" -f 5`

set expNo  = `echo $2 | cut -d "/" -f 1`
set runNoi = `echo $2 | cut -d "/" -f 2`
set runNof = `echo $2 | cut -d "/" -f 3`
      
set FLAG = $3
set RUN  = $4
set CNT  = $5

if( $expNo < 10 && $CNT < 10 ) then
  set NAME = "e00"$expNo"c00"$CNT"s0"$STREAM
 else if( $expNo >= 10 && $CNT < 10 ) then
  set NAME = "e0"$expNo"c00"$CNT"s0"$STREAM   
 else if( $expNo < 10 && $CNT >= 10 ) then
  set NAME = "e00"$expNo"c0"$CNT"s0"$STREAM
 else if( $expNo >= 10 && $CNT >= 10 ) then
  set NAME = "e0"$expNo"c0"$CNT"s0"$STREAM
endif

set OUT   = 'script_svd1/'$FLAG'_'$EVENT'_'$NAME'_'$LEVEL$TAG'.sh'
#set OUT   = 'script_svd1_other/'$FLAG'_'$EVENT'_'$NAME'_'$LEVEL$TAG'.sh'
set LOG   =         'log/'$FLAG'_'$EVENT'_'$NAME'_'$LEVEL$TAG'.log'
set HBK   =         'hbk/'$FLAG'_'$EVENT'_'$NAME'_'$LEVEL$TAG'.hbk'
set INDEX =       'index/'$FLAG'_'$EVENT'_'$NAME'_'$LEVEL$TAG'.index'
#****************************************
      
echo '#! /bin/tcsh -f\n' > $OUT

echo 'setenv MY_TOP_DIR $HOME/ewp/modules/skim_xsll' >> $OUT
#echo 'setenv MY_TOP_DIR $HOME/ys/modules/skim_xsll' >> $OUT
echo 'setenv BELLE_MESSAGE_LEVEL INFO' >> $OUT
if($LEVEL == 'caseA') echo 'unsetenv USE_GRAND_REPROCESS_DATA' >> $OUT
if($LEVEL == 'caseB') echo 'setenv USE_GRAND_REPROCESS_DATA 1' >> $OUT
#echo 'source /belle/local/etc/cshrc_general\n' >> $OUT # B-computer
echo 'source /sw/belle/local/etc/cshrc_general\n' >> $OUT # KEKCC

echo 'echo    $LD_LIBRARY_PATH'     >> $OUT
echo 'echo    $BASF_MODULE_DIR'     >> $OUT
echo 'echo    $PANTHER_TABLE_DIR\n' >> $OUT

echo 'basf << EOF > ' $LOG'\n' >> $OUT

echo 'nprocess set 0\n' >> $OUT

echo 'path create main'     >> $OUT
echo 'path add_module main fix_mdst '$MDL'\n'  >> $OUT

echo 'module put_parameter '$MDL' flag_mode\\9999'      >> $OUT
echo 'module put_parameter '$MDL' SkimFileName\\'$INDEX >> $OUT
echo '' >> $OUT

echo 'initialize' >> $OUT
echo 'histogram define '$HBK'\n' >> $OUT

@ STREAM += 10
~syutaro/script/mk_data_list_gmc.sh $expNo $runNoi $runNof $EVENT $STREAM >> $OUT

echo '\nterminate' >> $OUT
echo 'EOF\n' >> $OUT

echo 'h2root '$HBK '&& rm ' $HBK >> $OUT

echo $expNo $runNoi $runNof $CNT

chmod 755 $OUT

echo 'bsub -q l '$OUT >> $RUN

