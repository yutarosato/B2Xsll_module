#! /bin/tcsh -f

setenv MY_TOP_DIR $HOME/ewp/modules/xsll_gmc
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

path add_module main fix_mdst
path add_condition main >:0:analysis
path add_condition main <=:0:KILL
path add_module analysis XSLL
path add_condition analysis >:0:EXIT
path add_condition analysis <=:0:KILL

module put_parameter XSLL flag_mode\9999
initialize
histogram define test.hbk

#process_event /group/belle/bdata_b/mcprod/specialmc2010/chargedjpsi/s0/e07/chargedjpsi.e7.s0.f1.n50000.mdst 100
process_event /group/belle/bdata_b/mcprod/specialmc2010/chargedpsi2s/s1/e31/chargedpsi2s.e31.s1.f1.n50000.mdst 1000


terminate
EOF

h2root test.hbk && rm test.hbk
