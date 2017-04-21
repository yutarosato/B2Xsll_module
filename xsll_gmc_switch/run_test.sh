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

process_event /home/belle/syutaro/ewp/modules/xsll_gmc/skim-gmc_mixed_e031c001s00_caseB.mdst 50

#process_event /home/belle/syutaro/ewp/sigmc_xsll/gsim/mdst_setA/evtgen_exp_31__b0kstee__A_-0.mdst 742.00

#process_event /home/belle/syutaro/ewp/skim/rd/right/index/skim-rd_e007c001_caseB.index 100
#process_event /home/belle/syutaro/ewp/skim/gmc/right/index/uds/s01/skim-gmc_uds_e007c001s00_caseB.index
#process_event /home/belle/syutaro/ewp/skim/gmc/right/index/charm/s01/skim-gmc_charm_e007c001s00_caseB.index
#process_event /home/belle/syutaro/ewp/skim/gmc/right/index/mixed/s01/skim-gmc_mixed_e007c001s00_caseB.index
#process_event /home/belle/syutaro/ewp/skim/gmc/right/index/charged/s01/skim-gmc_charged_e007c001s00_caseB.index

#process_url http://bweb3/mdst.php?ex=7&rs=6&re=872&skm=HadronB&dt=on_resonance&bl=caseB&dv=zfserv
#process_url http://bweb3/montecarlo.php?ex=7&rs=6&re=872&ty=evtgen-uds&dt=on_resonance&bl=caseB&st=10
#process_url http://bweb3/montecarlo.php?ex=7&rs=6&re=872&ty=evtgen-charm&dt=on_resonance&bl=caseB&st=10
#process_url http://bweb3/montecarlo.php?ex=7&rs=6&re=872&ty=evtgen-mixed&dt=on_resonance&bl=caseB&st=10
#process_url http://bweb3/montecarlo.php?ex=7&rs=6&re=872&ty=evtgen-charged&dt=on_resonance&bl=caseB&st=10

#process_url http://bweb3/mdst.php?ex=31&rs=231&re=232&skm=HadronBorJ&dt=on_resonance&bl=caseB&dv=zfserv
#process_url http://bweb3/mdst.php?ex=31&rs=880&re=881&skm=HadronBorJ&dt=on_resonance&bl=caseB&dv=zfserv
#process_url http://bweb3/mdst.php?ex=31&rs=1536&re=1537&skm=HadronBorJ&dt=on_resonance&bl=caseB&dv=zfserv
#process_url http://bweb3/mdst.php?ex=31&rs=231&re=232&ty=evtgen-uds&dt=on_resonance&bl=caseB&st=0
#process_url http://bweb3/montecarlo.php?ex=31&rs=880&re=881&ty=evtgen-uds&dt=on_resonance&bl=caseB&st=0
#process_url http://bweb3/montecarlo.php?ex=31&rs=1536&re=1537&ty=evtgen-uds&dt=on_resonance&bl=caseB&st=0

terminate
EOF

h2root test.hbk && rm test.hbk

