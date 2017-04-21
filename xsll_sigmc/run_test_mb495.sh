#! /bin/tcsh -f

setenv MY_TOP_DIR $HOME/ewp/modules/xsll_sigmc
setenv BELLE_MESSAGE_LEVEL INFO
setenv USE_GRAND_REPROCESS_DATA 1
source /sw/belle/local/etc/cshrc_general

echo    $LD_LIBRARY_PATH
echo    $BASF_MODULE_DIR
echo    $PANTHER_TABLE_DIR

basf << EOF >  test_mb495.log

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
histogram define test_mb495.hbk

process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/gsim_mb/mdst_mb495_setB/evtgen_exp_55__b0xsee_mb495__B_-0.mdst
process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/gsim_mb/mdst_mb495_setB/evtgen_exp_55__bpxsee_mb495__B_-0.mdst
process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/gsim_mb/mdst_mb495_setB/evtgen_exp_55__b0xsmm_mb495__B_-0.mdst
process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/gsim_mb/mdst_mb495_setB/evtgen_exp_55__bpxsmm_mb495__B_-0.mdst

#process_event /home/belle/syutaro/ewp/sigmc_xsll/gsim/mdst_setA/evtgen_exp_31__b0kee__A_-0.mdst 234.00
#process_event /home/belle/syutaro/ewp/sigmc_xsll/gsim/mdst_setA/evtgen_exp_31__b0kmm__A_-0.mdst 234.00
#process_event /home/belle/syutaro/ewp/sigmc_xsll/gsim/mdst_setA/evtgen_exp_31__b0kstee__A_-0.mdst 742.00
#process_event /home/belle/syutaro/ewp/sigmc_xsll/gsim/mdst_setA/evtgen_exp_31__b0kstmm__A_-0.mdst 559.00
#process_event /home/belle/syutaro/ewp/sigmc_xsll/gsim/mdst_setA/evtgen_exp_31__b0xsee__A_-0.mdst 2338.34
#process_event /home/belle/syutaro/ewp/sigmc_xsll/gsim/mdst_setA/evtgen_exp_31__b0xsmm__A_-0.mdst 1652.13
#process_event /home/belle/syutaro/ewp/sigmc_xsll/gsim/mdst_setA/evtgen_exp_31__bpkee__A_-0.mdst 234.00
#process_event /home/belle/syutaro/ewp/sigmc_xsll/gsim/mdst_setA/evtgen_exp_31__bpkmm__A_-0.mdst 234.00
#process_event /home/belle/syutaro/ewp/sigmc_xsll/gsim/mdst_setA/evtgen_exp_31__bpkstee__A_-0.mdst 742.00
#process_event /home/belle/syutaro/ewp/sigmc_xsll/gsim/mdst_setA/evtgen_exp_31__bpkstmm__A_-0.mdst 559.00
#process_event /home/belle/syutaro/ewp/sigmc_xsll/gsim/mdst_setA/evtgen_exp_31__bpxsee__A_-0.mdst 2337.48
#process_event /home/belle/syutaro/ewp/sigmc_xsll/gsim/mdst_setA/evtgen_exp_31__bpxsmm__A_-0.mdst 1648.65

terminate
EOF

h2root test_mb495.hbk && rm  test_mb495.hbk
