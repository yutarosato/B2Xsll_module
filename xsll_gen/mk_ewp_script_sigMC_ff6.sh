#! /bin/tcsh -f

set DIR    = $1
set MDL    = `echo $2 | cut -d "/" -f 1`
set LEVEL  = `echo $2 | cut -d "/" -f 2`
set TAG    = `echo $2 | cut -d "/" -f 3`
set FILE   = $3
set FLAG   = $4
set MODE   = $5
set RUN    = $6
      
set OUT = "script_ff6/${FLAG}_${FILE}_m${MODE}m_${LEVEL}${TAG}.sh"      
set LOG =    "log/log${TAG}/${FLAG}_${FILE}_m${MODE}m_${LEVEL}${TAG}.log"
set HBK =    "hbk/hbk${TAG}/${FLAG}_${FILE}_m${MODE}m_${LEVEL}${TAG}.hbk"

mkdir -p 'script_ff6'

#****************************************
      
echo '#! /bin/tcsh -f\n' > $OUT

echo 'setenv MY_TOP_DIR $HOME/ewp/modules/xsll_gen' >> $OUT
echo 'setenv BELLE_MESSAGE_LEVEL INFO' >> $OUT
echo 'setenv USE_GRAND_REPROCESS_DATA 1' >> $OUT
echo 'source /sw/belle/local/etc/cshrc_general\n' >> $OUT # KEKCC

echo 'echo    $LD_LIBRARY_PATH'     >> $OUT
echo 'echo    $BASF_MODULE_DIR'     >> $OUT
echo 'echo    $PANTHER_TABLE_DIR\n' >> $OUT

echo "mkdir -p log/log${TAG}"   >> $OUT
echo "mkdir -p hbk/hbk${TAG}\n" >> $OUT

echo 'basf << EOF > ' $LOG'\n' >> $OUT

echo 'nprocess set 0\n' >> $OUT
  
echo 'path create main'     >> $OUT
echo 'path create analysis\n' >> $OUT

echo 'path add_module main XSLL' >> $OUT

echo 'module put_parameter '$MDL' flag_mode\\'$MODE >> $OUT
echo '' >> $OUT

echo 'initialize' >> $OUT
echo 'histogram define '$HBK'\n' >> $OUT


set CNT = 0
foreach f ($DIR"evtgen_exp"*"_"$FILE"_"*.mdst)
set NAME_NAME  = `basename $f .mdst | cut -d "_" -f 1-5`
set NAME_MODE  = `basename $f .mdst | cut -d "_" -f 5`
set NUMBER = `grep $NAME_NAME ~/script/scale_sigmc_no.txt | cut -d "|" -f 3`
set FACTOR = `grep $NAME_MODE ~/script/scale_sigmc_factor_for_correction_function_ff6.txt | cut -f 2`
set ANSWER = `echo "$NUMBER * $FACTOR" | bc`
echo 'process_event '$f $ANSWER>> $OUT
@ CNT++
end

echo '\nterminate' >> $OUT
echo 'EOF\n' >> $OUT

echo 'h2root '$HBK '&& rm ' $HBK >> $OUT 

echo $CNT $OUT

chmod 755 $OUT

#echo 'bsub -q s '$OUT >> $RUN
