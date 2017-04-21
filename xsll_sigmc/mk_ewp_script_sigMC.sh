#! /bin/tcsh -f

set DIR    = $1
set MDL    = `echo $2 | cut -d "/" -f 1`
set LEVEL  = `echo $2 | cut -d "/" -f 2`
set TAG    = `echo $2 | cut -d "/" -f 3`
set FILE   = $3
set FLAG   = $4
set MODE   = $5
set RUN    = $6
      
#set OUT = 'script/'$FLAG'_'$FILE'_m'$MODE'm_'$LEVEL$TAG'.sh'      
set OUT = 'script_c10flip/'$FLAG'_'$FILE'_m'$MODE'm_'$LEVEL$TAG'.sh'      
set LOG =    'log/'$FLAG'_'$FILE'_m'$MODE'm_'$LEVEL$TAG'.log'
set HBK =    'hbk/'$FLAG'_'$FILE'_m'$MODE'm_'$LEVEL$TAG'.hbk'
      
#****************************************
      
echo '#! /bin/tcsh -f\n' > $OUT

echo 'setenv MY_TOP_DIR $HOME/ewp/modules/xsll_sigmc' >> $OUT
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


set CNT = 0
foreach f ($DIR"evtgen_exp"*"_"$FILE"_"*.mdst)
set NAME_NAME  = `basename $f .mdst | cut -d "_" -f 1-5`
set NAME_MODE  = `basename $f .mdst | cut -d "_" -f 5`
set NUMBER = `grep $NAME_NAME ~/script/scale_sigmc_no.txt | cut -d "|" -f 3`
set FACTOR = `grep $NAME_MODE ~/script/scale_sigmc_factor.txt | cut -f 2`
set ANSWER = `echo "$NUMBER * $FACTOR" | bc`
echo 'process_event '$f $ANSWER>> $OUT
@ CNT++
end

echo '\nterminate' >> $OUT
echo 'EOF\n' >> $OUT

echo 'h2root '$HBK '&& rm ' $HBK >> $OUT 

echo $CNT $OUT

chmod 755 $OUT

echo 'bsub -q s '$OUT >> $RUN
