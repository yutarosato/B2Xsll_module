#! /bin/tcsh -f

setenv MY_TOP_DIR $HOME/ewp/modules/xsll_gmc_fl_double
setenv BELLE_MESSAGE_LEVEL INFO
setenv USE_GRAND_REPROCESS_DATA 1
source /sw/belle/local/etc/cshrc_general

echo    $LD_LIBRARY_PATH
echo    $BASF_MODULE_DIR
echo    $PANTHER_TABLE_DIR

mkdir -p    log/uds/9999
mkdir -p    hbk/uds/9999
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

#process_event /group/belle/bdata_b/mcprod/dat/e000021/evtgen/uds/10/all/0807/on_resonance/00/evtgen-uds-10-all-e000021r000002-b20030807_1600.mdst 0
#process_event /group/belle/bdata_b/mcprod/dat/e000021/evtgen/uds/10/all/0807/on_resonance/00/evtgen-uds-10-all-e000021r000003-b20030807_1600.mdst 0
#process_event /group/belle/bdata_b/mcprod/dat/e000021/evtgen/uds/10/all/0807/on_resonance/00/evtgen-uds-10-all-e000021r000004-b20030807_1600.mdst 0
#process_url http://bweb3/montecarlo.php?ex=13&rs=4&re=5&ty=evtgen-uds&dt=on_resonance&bl=caseB&dv=zfserv&st=10
#process_event /home/belle/syutaro/ewp/modules/xsll_gmc/skim-gmc_mixed_e031c001s00_caseB.mdst 10
process_event /home/belle/syutaro/ewp/modules/xsll_gmc/skim-gmc_charm_e031c001s00_caseB.mdst 1000

terminate
EOF

h2root test.hbk && rm test.hbk
