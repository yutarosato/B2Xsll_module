#! /bin/tcsh -f
if( $#argv != 5 )then
    echo " Usage : $0 [que-type] [A7] [A9] [A10] [setname]"
    exit 1
endif

bsub -q ${1} script_${2}/Gen_07_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_09_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_11_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_13_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_15_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_17_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_19a_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_19b_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_21_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_23_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_25_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_27_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_31_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_33_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_35_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_37a_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_37b_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_39_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_41a_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_41b_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_43_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_45a_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_45b_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_47_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_49_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_51_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_55_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_61_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_63_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
bsub -q ${1} script_${2}/Gen_65_m9999m_caseB_${2}_${3}_${4}_set${5}.sh
