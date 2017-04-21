#! /bin/tcsh -f
if( $#argv != 4 )then
    echo " Usage : $0 [que-type] [EVENT] [STREAM] [fl_mode_xs]"
    echo '[EVENT ] = {uds, charm, mixed, charged}'
    echo '[STREAM] = {0}'
    exit 1
endif

bsub -q $1 script/$2/$4/gMC_$2_e007c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e007c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e007c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e007c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e007c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e007c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e009c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e009c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e009c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e009c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e011c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e011c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e011c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e011c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e011c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e011c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e011c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e011c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e013c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e013c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e013c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e013c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e013c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e013c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e013c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e013c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e013c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e013c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e013c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e013c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e015c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e015c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e015c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e015c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e015c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e015c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e015c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e015c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e015c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e015c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e015c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e015c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e015c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e017c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e017c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e017c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e017c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e017c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e017c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e017c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e017c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e017c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e017c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e017c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c014s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c015s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c016s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c017s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c018s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c019s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c020s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c021s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c022s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c023s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c024s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e019c025s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e021c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e021c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e021c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e021c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e023c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e023c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e023c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e023c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e023c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e023c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c014s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c015s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c016s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c017s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c018s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c019s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c020s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c021s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c022s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c023s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c024s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c025s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e025c026s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c014s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c015s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c016s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c017s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c018s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c019s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c020s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c021s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c022s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c023s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c024s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e027c025s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e031c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e031c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e031c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e031c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e031c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e031c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e031c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e031c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e031c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e031c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e031c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e031c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e031c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e031c014s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e031c015s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e031c016s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e031c017s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e033c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e033c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e033c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e033c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e033c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e033c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e033c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e033c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e033c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e033c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e033c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e033c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e033c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e033c014s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e033c015s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e033c016s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e033c017s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c014s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c015s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c016s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c014s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c015s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c016s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c017s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c018s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c019s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c020s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c021s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c022s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c023s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c024s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c025s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c026s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c027s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c028s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c029s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c030s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c031s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c032s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c033s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c034s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c035s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c036s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c037s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c038s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c039s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c040s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c041s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c042s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c043s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c044s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c045s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c046s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c047s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c048s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c049s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c050s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c051s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c052s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c053s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c054s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c055s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c056s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c057s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c058s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e037c059s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c014s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c015s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c016s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c017s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c018s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c019s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c020s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c021s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c022s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c023s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c024s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c025s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c026s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c027s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c028s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c029s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c030s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c031s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c032s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c033s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c034s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c035s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c036s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c037s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c038s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e039c039s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c014s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c015s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c016s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c017s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c018s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c019s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c020s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c021s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c022s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c023s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c024s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c025s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c026s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c027s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c028s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c029s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c030s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c031s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c032s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c033s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c034s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c035s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c036s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c037s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c038s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c039s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c040s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c041s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c042s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c043s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c044s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c045s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c046s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c047s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c048s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c049s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c050s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c051s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c052s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c053s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c054s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e041c055s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c014s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c015s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c016s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c017s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c018s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c019s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c020s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c021s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c022s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c023s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c024s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c025s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c026s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c027s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c028s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c029s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c030s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c031s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c032s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c033s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c034s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c035s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c036s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c037s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c038s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c039s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c040s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c041s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c042s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c043s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c044s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c045s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c046s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c047s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c048s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c049s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c050s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c051s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e043c052s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e045c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e045c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e045c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e045c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e045c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e045c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e045c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e045c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e045c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e045c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e045c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e045c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c014s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c015s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c016s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c017s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c018s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c019s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c020s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c021s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c022s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c023s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c024s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c025s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c026s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c027s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c028s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c029s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c030s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c031s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c032s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c033s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e047c034s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c014s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c015s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c016s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c017s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c018s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c019s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c020s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c021s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c022s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c023s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c024s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e049c025s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c014s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c015s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c016s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c017s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c018s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c019s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c020s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c021s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c022s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c023s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c024s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c025s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c026s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c027s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c028s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c029s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c030s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c031s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c032s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c033s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c034s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c035s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c036s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e051c037s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c014s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c015s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c016s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c017s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c018s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c019s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c020s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c021s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c022s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c023s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c024s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c025s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c026s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c027s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c028s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c029s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c030s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c031s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c032s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c033s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c034s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c035s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c036s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c037s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c038s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c039s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c040s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c041s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c042s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c043s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c044s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c045s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c046s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c047s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c048s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c049s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c050s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c051s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c052s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c053s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c054s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c055s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c056s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c057s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c058s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c059s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c060s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c061s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c062s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c063s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c064s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c065s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c066s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e055c067s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c014s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c015s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c016s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c017s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c018s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c019s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c020s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c021s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c022s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c023s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c024s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c025s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c026s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c027s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c028s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c029s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c030s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c031s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c032s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e061c033s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c014s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c015s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c016s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c017s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c018s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c019s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c020s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c021s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c022s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c023s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c024s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c025s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c026s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c027s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c028s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c029s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c030s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e063c031s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c001s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c002s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c003s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c004s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c005s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c006s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c007s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c008s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c009s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c010s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c011s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c012s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c013s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c014s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c015s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c016s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c017s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c018s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c019s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c020s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c021s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c022s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c023s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c024s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c025s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c026s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c027s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c028s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c029s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c030s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c031s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c032s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c033s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e065c034s0$3_m$4m_caseB.sh