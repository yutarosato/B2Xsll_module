#! /bin/tcsh -f
if( $#argv != 4 )then
    echo " Usage : $0 [que-type] [fl_mode_xs] [setname] [mb]"
    exit 1
endif

bsub -q $1 script_mb${4}/sigMC_07_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_09_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_11_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_13_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_15_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_17_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_19a_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_19b_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_21_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_23_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_25_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_27_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_31_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_33_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_35_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_37a_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_37b_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_39_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_41a_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_41b_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_43_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_45a_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_45b_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_47_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_49_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_51_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_55_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_61_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_63_m$2m_caseB_mb${4}_set$3.sh
bsub -q $1 script_mb${4}/sigMC_65_m$2m_caseB_mb${4}_set$3.sh
