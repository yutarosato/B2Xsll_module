#! /bin/tcsh -f
if( $#argv != 4 )then
    echo " Usage : $0 [que-type] [fl_mode_xs] [setname] [lambdaone]"
    exit 1
endif

bsub -q $1 script_lambdaone${4}_c10flip/sigMC_07_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_09_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_11_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_13_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_15_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_17_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_19a_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_19b_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_21_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_23_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_25_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_27_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_31_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_33_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_35_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_37a_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_37b_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_39_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_41a_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_41b_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_43_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_45a_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_45b_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_47_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_49_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_51_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_55_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_61_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_63_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
bsub -q $1 script_lambdaone${4}_c10flip/sigMC_65_m$2m_caseB_c10flip_lambdaone${4}_set$3.sh
