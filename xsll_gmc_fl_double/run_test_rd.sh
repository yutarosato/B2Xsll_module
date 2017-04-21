#! /bin/tcsh -f

setenv MY_TOP_DIR $HOME/ewp/modules/xsll_gmc_fl_double
setenv BELLE_MESSAGE_LEVEL INFO
setenv USE_GRAND_REPROCESS_DATA 1
source /sw/belle/local/etc/cshrc_general

echo    $LD_LIBRARY_PATH
echo    $BASF_MODULE_DIR
echo    $PANTHER_TABLE_DIR

mkdir -p    log/rd/9999
mkdir -p    hbk/rd/9999
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

process_event /group/belle/bdata_b/dstprod/dat/e000013/HadronB/0416/on_resonance/00/e000013r000004-b20020416_1604.mdst 100
#process_event /group/belle/bdata_b/dstprod/dat/e000013/HadronB/0416/on_resonance/00/e000013r000005-b20020416_1604.mdst 0
#process_event /group/belle/bdata_b/dstprod/dat/e000013/HadronB/0416/on_resonance/00/e000013r000006-b20020416_1604.mdst 0

terminate
EOF

h2root test.hbk && rm  test.hbk
