#! /bin/tcsh -f

setenv MY_TOP_DIR $HOME/ewp/modules/skim_xsll
setenv BELLE_MESSAGE_LEVEL INFO
setenv USE_GRAND_REPROCESS_DATA 1
source /belle/local/etc/cshrc_general

echo    $LD_LIBRARY_PATH
echo    $BASF_MODULE_DIR
echo    $PANTHER_TABLE_DIR

basf << EOF >  test.log

nprocess set 0

path create main
path add_module main fix_mdst XSLL

module put_parameter XSLL flag_mode\9999
module put_parameter XSLL SkimFileName\test.index

initialize
histogram define test.hbk

process_url http://bweb3/montecarlo.php?ex=17&rs=794&re=800&ty=evtgen-uds&dt=on_resonance&bl=caseB&dv=zfserve&st=10
#process_url http://bweb3/montecarlo.php?ex=17&rs=807&re=864&ty=evtgen-uds&dt=on_resonance&bl=caseB&dv=zfserve&st=10

terminate
EOF

h2root test.hbk && rm  test.hbk
