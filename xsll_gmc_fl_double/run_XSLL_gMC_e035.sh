#! /bin/tcsh -f
if( $#argv != 4 )then
    echo " Usage : $0 [que-type] [EVENT] [STREAM] [fl_mode_xs]"
    echo '[EVENT ] = {$2, charm, mixed, charged}'
    echo '[STREAM] = {0}'
    exit 1
endif


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
bsub -q $1 script/$2/$4/gMC_$2_e035c017s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c018s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c019s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c020s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c021s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c022s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c023s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c024s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c025s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c026s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c027s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c028s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c029s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c030s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c031s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c032s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c033s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c034s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c035s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c036s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c037s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c038s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c039s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c040s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c041s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c042s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c043s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c044s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c045s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c046s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c047s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c048s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c049s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c050s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c051s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c052s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c053s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c054s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c055s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c056s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c057s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c058s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c059s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c060s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c061s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c062s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c063s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c064s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c065s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c066s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c067s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c068s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c069s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c070s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c071s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c072s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c073s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c074s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c075s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c076s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c077s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c078s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c079s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c080s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c081s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c082s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c083s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c084s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c085s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c086s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c087s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c088s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c089s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c090s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c091s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c092s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c093s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c094s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c095s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c096s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c097s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c098s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c099s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c100s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c101s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c102s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c103s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c104s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c105s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c106s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c107s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c108s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c109s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c110s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c111s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c112s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c113s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c114s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c115s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c116s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c117s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c118s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c119s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c120s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c121s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c122s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c123s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c124s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c125s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c126s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c127s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c128s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c129s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c130s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c131s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c132s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c133s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c134s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c135s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c136s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c137s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c138s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c139s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c140s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c141s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c142s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c143s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c144s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c145s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c146s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c147s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c148s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c149s0$3_m$4m_caseB.sh
bsub -q $1 script/$2/$4/gMC_$2_e035c150s0$3_m$4m_caseB.sh
