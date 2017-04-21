d#! /bin/tcsh -f

set DIR    = $1
set MDL    = `echo $2 | cut -d "/" -f 1`
set LEVEL  = `echo $2 | cut -d "/" -f 2`
set TAG    = `echo $2 | cut -d "/" -f 3`
set FILE   = $3
set FLAG   = $4
set MODE   = $5
set RUN    = $6
set NAME   = `basename $FILE .index | cut -d "_" -f2-3`
set TYPE   = `echo $NAME | cut -d "_" -f 1` 

set OUT = 'script/'$TYPE'/'$MODE'/'$FLAG'_'$NAME'_m'$MODE'm_'$LEVEL$TAG'.sh'
set LOG =    'log/'$TYPE'/'$MODE'/'$FLAG'_'$NAME'_m'$MODE'm_'$LEVEL$TAG'.log'
set HBK =    'hbk/'$TYPE'/'$MODE'/'$FLAG'_'$NAME'_m'$MODE'm_'$LEVEL$TAG'.hbk'

mkdir -p 'script/'$TYPE'/'$MODE      
#****************************************
      
echo '#! /bin/tcsh -f\n' > $OUT

echo 'setenv MY_TOP_DIR $HOME/ewp/modules/xsll_gmc' >> $OUT
echo 'setenv BELLE_MESSAGE_LEVEL INFO' >> $OUT
if($LEVEL == 'caseA') echo 'unsetenv USE_GRAND_REPROCESS_DATA' >> $OUT
if($LEVEL == 'caseB') echo 'setenv USE_GRAND_REPROCESS_DATA 1' >> $OUT

echo 'source /sw/belle/local/etc/cshrc_general\n' >> $OUT # KEKCC

echo 'echo    $LD_LIBRARY_PATH'     >> $OUT
echo 'echo    $BASF_MODULE_DIR'     >> $OUT
echo 'echo    $PANTHER_TABLE_DIR\n' >> $OUT

echo "mkdir -p    log/"$TYPE"/"$MODE >> $OUT
echo "mkdir -p    hbk/"$TYPE"/"$MODE >> $OUT
  
echo 'basf << EOF > ' $LOG'\n' >> $OUT

echo 'nprocess set 0\n' >> $OUT
  
echo 'path create main'     >> $OUT
echo 'path create analysis\n' >> $OUT

echo 'path add_module main fix_mdst'         >> $OUT
echo 'path add_condition main >:0:analysis'  >> $OUT
echo 'path add_condition main <=:0:KILL'     >> $OUT
echo 'path add_module analysis XSLL'         >> $OUT
echo 'path add_condition analysis >:0:EXIT'  >> $OUT
echo 'path add_condition analysis <=:0:KILL\n' >> $OUT

echo 'module put_parameter '$MDL' flag_mode\\'$MODE >> $OUT
echo '' >> $OUT

echo 'initialize' >> $OUT
echo 'histogram define '$HBK'\n' >> $OUT

echo 'process_event '$FILE >> $OUT

echo '\nterminate' >> $OUT
echo 'EOF\n' >> $OUT

echo 'h2root '$HBK '&& rm ' $HBK >> $OUT 

echo $OUT

chmod 755 $OUT

echo 'bsub -q b_a '$OUT >> $RUN
