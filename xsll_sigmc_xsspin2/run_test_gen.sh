#! /bin/tcsh -f

setenv MY_TOP_DIR $HOME/ewp/modules/xsll_sigmc
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

#process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/gsim_xsspin/mdst_setA/evtgen_exp_31__b0xs0ee__A_-0.mdst 5
#process_event /home/belle/syutaro/ewp/mcprod_xsspin2/gsim/mdst/evtgen_exp_43__b0xs0mm__A_-0.mdst 0
#process_event /home/belle/syutaro/ewp/mcprod_xsspin2/gsim/mdst/evtgen_exp_43__b0xs1mm__A_-0.mdst 0
#process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/gsim_xsspin2/mdst_setA/evtgen_exp_31__b0xs0ee__A_-0.mdst 100

process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/evtgen_xsspin2/mdst_setA_kstr1430/evtgen_exp_55__b0kstr1430ee__A_-0.mdst
#process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/evtgen_xsspin2/mdst_setA_kstr1430/evtgen_exp_55__b0kstr1430mm__A_-0.mdst
#process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/evtgen_xsspin2/mdst_setA_kstr1430/evtgen_exp_55__bpkstr1430ee__A_-0.mdst
#process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/evtgen_xsspin2/mdst_setA_kstr1430/evtgen_exp_55__bpkstr1430mm__A_-0.mdst

terminate
EOF

h2root test.hbk && rm  test.hbk


