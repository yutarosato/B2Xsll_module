#! /bin/tcsh -f
if( $#argv != 3 )then
    echo " Usage : $0 [que-type] [fl_mode_xs] [setname]"
    exit 1
endif

bsub -q $1 script_xsjpsi/sigMC_07_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_09_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_11_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_13_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_15_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_17_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_19a_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_19b_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_21_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_23_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_25_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_27_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_31_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_33_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_35_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_37a_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_37b_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_39_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_41a_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_41b_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_43_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_45a_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_45b_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_47_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_49_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_51_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_55_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_61_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_63_m$2m_caseB_xsjpsi_set$3.sh
bsub -q $1 script_xsjpsi/sigMC_65_m$2m_caseB_xsjpsi_set$3.sh
