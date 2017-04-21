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

#process_event /home/belle/syutaro/ewp/mcprod_xsspin/evtgen/mdst/mdst7/evtgen_exp_07__bpxs1mm__A_-0.mdst
#process_event /home/belle/syutaro/ewp/mcprod_xsspin/evtgen/mdst/mdst7/evtgen_exp_07__b0xs1mm__A_-0.mdst

#process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/evtgen_dev/norm/mdst_setA/nine100_ten100/evtgen_exp_31__b0kee_norm_100_100__A_-0.mdst 234.00
#process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/evtgen_dev/norm/mdst_setA/nine100_ten100/evtgen_exp_31__b0kmm_norm_100_100__A_-0.mdst 234.00
#process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/evtgen_dev/norm/mdst_setA/nine100_ten100/evtgen_exp_31__b0kstee_norm_100_100__A_-0.mdst 742.00
#process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/evtgen_dev/norm/mdst_setA/nine100_ten100/evtgen_exp_31__b0kstmm_norm_100_100__A_-0.mdst 559.00
#process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/evtgen_dev/norm/mdst_setA/nine100_ten100/evtgen_exp_31__b0xsee_norm_100_100__A_-0.mdst 1590.615
#process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/evtgen_dev/norm/mdst_setA/nine100_ten100/evtgen_exp_31__b0xsmm_norm_100_100__A_-0.mdst 1063.440
#process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/evtgen_dev/norm/mdst_setA/nine100_ten100/evtgen_exp_31__bpkee_norm_100_100__A_-0.mdst 234.00
#process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/evtgen_dev/norm/mdst_setA/nine100_ten100/evtgen_exp_31__bpkmm_norm_100_100__A_-0.mdst 234.00
#process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/evtgen_dev/norm/mdst_setA/nine100_ten100/evtgen_exp_31__bpkstee_norm_100_100__A_-0.mdst 742.00
#process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/evtgen_dev/norm/mdst_setA/nine100_ten100/evtgen_exp_31__bpkstmm_norm_100_100__A_-0.mdst 559.00
#process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/evtgen_dev/norm/mdst_setA/nine100_ten100/evtgen_exp_31__bpxsee_norm_100_100__A_-0.mdst 1590.030
#process_event /home/belle/syutaro/Store/ewp/sigmc_xsll/evtgen_dev/norm/mdst_setA/nine100_ten100/evtgen_exp_31__bpxsmm_norm_100_100__A_-0.mdst 1061.200

#process_event /home/belle/katoe/work/sigmc/evtgen/mdst/set_trainingA/evtgen_exp_07_b0kee-0.mdst
#process_event /home/belle/katoe/work/sigmc/evtgen/mdst/set_trainingA/evtgen_exp_07_b0kstee-0.mdst
#process_event /home/belle/katoe/work/sigmc/evtgen/mdst/set_trainingA/evtgen_exp_07_b0xsee-0.mdst
#process_event /home/belle/katoe/work/sigmc/evtgen/mdst/set_trainingA/evtgen_exp_07_bpkee-0.mdst

process_event /home/belle/syutaro/ewp/mcprod/evtgen/test.mdst

terminate
EOF

h2root test.hbk && rm test.hbk
