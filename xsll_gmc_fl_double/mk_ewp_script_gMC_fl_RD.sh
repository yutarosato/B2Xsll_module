#! /bin/tcsh -f

set CNT    = $1
set MDL    = `echo $2 | cut -d "/" -f 1`
set LEVEL  = `echo $2 | cut -d "/" -f 2`
set EXP    = `echo $2 | cut -d "/" -f 3`
set TAG    = `echo $2 | cut -d "/" -f 4`

set FILE   = $3
set FLAG   = $4
set MODE   = $5
set RUN    = $6

if( $EXP < 10 && $CNT < 10 ) then
  set NAME = "e00"$EXP"c00"$CNT
 else if( $EXP >= 10 && $CNT < 10 ) then
  set NAME = "e0"$EXP"c00"$CNT
 else if( $EXP < 10 && $CNT < 100 ) then
  set NAME = "e00"$EXP"c0"$CNT
 else if( $EXP >= 10 && $CNT < 100 ) then
  set NAME = "e0"$EXP"c0"$CNT
 else if( $EXP < 10 ) then
  set NAME = "e00"$EXP"c"$CNT
 else if( $EXP >= 10 ) then
  set NAME = "e0"$EXP"c"$CNT
endif

set OUT   = 'script/rd/'$MODE'/'$FLAG'_'$NAME'_m'$MODE'm_'$LEVEL$TAG'.sh'
set LOG   =    'log/rd/'$MODE'/'$FLAG'_'$NAME'_m'$MODE'm_'$LEVEL$TAG'.log'
set HBK   =    'hbk/rd/'$MODE'/'$FLAG'_'$NAME'_m'$MODE'm_'$LEVEL$TAG'.hbk'
set INDEX =  'index/rd/'$MODE'/'$FLAG'_'$NAME'_m'$MODE'm_'$LEVEL$TAG'.index'

mkdir -p 'script/rd/'$MODE
#****************************************
      
echo '#! /bin/tcsh -f\n' > $OUT

echo 'setenv MY_TOP_DIR $HOME/ewp/modules/xsll_gmc_fl_double' >> $OUT
echo 'setenv BELLE_MESSAGE_LEVEL INFO' >> $OUT
if($LEVEL == 'caseA') echo 'unsetenv USE_GRAND_REPROCESS_DATA' >> $OUT
if($LEVEL == 'caseB') echo 'setenv USE_GRAND_REPROCESS_DATA 1' >> $OUT
echo 'source /sw/belle/local/etc/cshrc_general\n' >> $OUT

echo 'echo    $LD_LIBRARY_PATH'     >> $OUT
echo 'echo    $BASF_MODULE_DIR'     >> $OUT
echo 'echo    $PANTHER_TABLE_DIR\n' >> $OUT

echo "mkdir -p    log/rd/"$MODE >> $OUT
echo "mkdir -p    hbk/rd/"$MODE >> $OUT

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
  
echo 'module put_parameter '$MDL' flag_mode\\9999'      >> $OUT
echo '' >> $OUT

echo 'initialize' >> $OUT
echo 'histogram define '$HBK'\n' >> $OUT


@ LINEi = $CNT * 3
@ LINEi -= 2
@ LINEf = $CNT * 3
sed -n "$LINEi,$LINEf"p $FILE | awk '{print $1" "$2" "0}' >> $OUT

echo '\nterminate' >> $OUT
echo 'EOF\n' >> $OUT

echo 'h2root '$HBK '&& rm ' $HBK >> $OUT

echo $EXP $CNT

chmod 755 $OUT

echo 'bsub -q l '$OUT >> $RUN
