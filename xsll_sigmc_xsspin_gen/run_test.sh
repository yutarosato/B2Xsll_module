#! /bin/tcsh -f

setenv MY_TOP_DIR $HOME/ewp/modules/xsll_gen
setenv BELLE_MESSAGE_LEVEL INFO
setenv USE_GRAND_REPROCESS_DATA 1
source /sw/belle/local/etc/cshrc_general

echo    $LD_LIBRARY_PATH
echo    $BASF_MODULE_DIR
echo    $PANTHER_TABLE_DIR

basf << EOF >  test.log

nprocess set 0

path create main
path create analysis

path add_module main XSLL
module put_parameter XSLL flag_mode\9999

initialize
histogram define test.hbk


process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/evtgen_dev_xsspin/norm/mdst_setA/nine100_ten100/evtgen_exp_31__b0xs0ee_norm_100_100__A_-0.mdst 1000

terminate
EOF

h2root test.hbk && rm test.hbk
