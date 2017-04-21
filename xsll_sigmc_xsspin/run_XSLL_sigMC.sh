#! /bin/tcsh -f
if( $#argv != 3 )then
    echo " Usage : $0 [que-type] [fl_mode_xs] [setname]"
    exit 1
endif

bsub -q $1 script/sigMC_07_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_09_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_11_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_13_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_15_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_17_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_19a_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_19b_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_21_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_23_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_25_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_27_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_31_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_33_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_35_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_37a_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_37b_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_39_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_41a_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_41b_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_43_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_45a_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_45b_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_47_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_49_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_51_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_55_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_61_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_63_m$2m_caseB_set$3.sh
bsub -q $1 script/sigMC_65_m$2m_caseB_set$3.sh

