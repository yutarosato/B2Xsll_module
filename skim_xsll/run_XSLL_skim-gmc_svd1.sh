#! /bin/tcsh -f
if( $#argv != 3 )then
    echo " Usage : $0 [que-type] [EVENT] [STREAM]"
    echo '[que ]   = {s l}'
    echo '[EVENT ] = {uds, charm, mixed, charged}'
    echo '[STREAM] = {0-5} for qq, {0-9} for bb'
    exit 1
endif

bsub -q $1 script_svd1/skim-gmc_$2_e007c001s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e007c002s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e007c003s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e007c004s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e007c005s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e007c006s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e009c001s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e009c002s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e009c003s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e009c004s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e011c001s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e011c002s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e011c003s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e011c004s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e011c005s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e011c006s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e011c007s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e011c008s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e013c001s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e013c002s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e013c003s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e013c004s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e013c005s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e013c006s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e013c007s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e013c008s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e013c009s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e013c010s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e013c011s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e013c012s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e015c001s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e015c002s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e015c003s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e015c004s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e015c005s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e015c006s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e015c007s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e015c008s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e015c009s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e015c010s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e015c011s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e015c012s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e015c013s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e017c001s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e017c002s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e017c003s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e017c004s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e017c005s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e017c006s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e017c007s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e017c008s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e017c009s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e017c010s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e017c011s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c001s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c002s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c003s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c004s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c005s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c006s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c007s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c008s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c009s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c010s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c011s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c012s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c013s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c014s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c015s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c016s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c017s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c018s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c019s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c020s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c021s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c022s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c023s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c024s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e019c025s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e021c001s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e021c002s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e021c003s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e021c004s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e023c001s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e023c002s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e023c003s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e023c004s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e023c005s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e023c006s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c001s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c002s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c003s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c004s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c005s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c006s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c007s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c008s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c009s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c010s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c011s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c012s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c013s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c014s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c015s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c016s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c017s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c018s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c019s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c020s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c021s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c022s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c023s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c024s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c025s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e025c026s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c001s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c002s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c003s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c004s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c005s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c006s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c007s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c008s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c009s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c010s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c011s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c012s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c013s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c014s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c015s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c016s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c017s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c018s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c019s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c020s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c021s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c022s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c023s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c024s0$3_caseB.sh
bsub -q $1 script_svd1/skim-gmc_$2_e027c025s0$3_caseB.sh
