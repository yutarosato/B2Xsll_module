#! /bin/tcsh -f
if( $#argv != 2 )then
    echo " Usage : $0 [que-type] [fl_mode_xs]"
    exit 1
endif

bsub -q $1 script/rd/$2/RD_e007c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e007c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e007c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e007c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e007c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e007c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e009c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e009c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e009c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e009c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e011c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e011c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e011c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e011c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e011c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e011c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e011c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e011c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e013c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e013c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e013c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e013c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e013c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e013c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e013c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e013c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e013c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e013c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e013c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e013c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e015c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e015c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e015c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e015c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e015c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e015c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e015c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e015c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e015c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e015c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e015c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e015c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e015c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e017c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e017c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e017c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e017c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e017c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e017c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e017c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e017c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e017c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e017c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e017c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c014_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c015_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c016_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c017_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c018_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c019_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c020_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c021_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c022_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c023_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c024_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e019c025_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e021c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e021c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e021c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e021c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e023c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e023c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e023c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e023c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e023c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e023c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c014_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c015_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c016_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c017_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c018_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c019_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c020_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c021_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c022_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c023_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c024_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c025_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e025c026_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c014_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c015_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c016_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c017_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c018_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c019_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c020_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c021_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c022_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c023_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c024_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e027c025_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e031c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e031c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e031c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e031c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e031c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e031c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e031c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e031c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e031c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e031c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e031c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e031c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e031c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e031c014_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e031c015_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e031c016_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e031c017_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e033c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e033c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e033c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e033c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e033c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e033c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e033c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e033c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e033c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e033c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e033c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e033c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e033c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e033c014_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e033c015_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e033c016_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e033c017_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e035c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e035c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e035c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e035c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e035c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e035c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e035c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e035c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e035c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e035c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e035c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e035c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e035c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e035c014_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e035c015_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e035c016_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c014_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c015_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c016_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c017_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c018_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c019_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c020_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c021_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c022_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c023_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c024_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c025_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c026_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c027_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c028_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c029_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c030_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c031_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c032_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c033_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c034_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c035_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c036_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c037_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c038_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c039_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c040_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c041_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c042_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c043_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c044_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c045_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c046_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c047_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c048_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c049_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c050_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c051_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c052_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c053_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c054_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c055_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c056_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c057_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c058_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e037c059_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c014_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c015_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c016_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c017_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c018_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c019_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c020_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c021_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c022_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c023_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c024_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c025_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c026_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c027_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c028_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c029_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c030_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c031_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c032_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c033_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c034_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c035_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c036_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c037_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c038_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e039c039_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c014_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c015_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c016_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c017_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c018_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c019_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c020_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c021_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c022_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c023_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c024_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c025_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c026_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c027_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c028_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c029_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c030_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c031_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c032_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c033_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c034_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c035_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c036_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c037_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c038_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c039_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c040_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c041_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c042_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c043_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c044_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c045_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c046_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c047_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c048_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c049_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c050_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c051_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c052_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c053_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c054_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e041c055_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c014_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c015_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c016_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c017_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c018_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c019_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c020_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c021_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c022_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c023_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c024_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c025_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c026_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c027_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c028_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c029_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c030_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c031_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c032_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c033_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c034_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c035_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c036_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c037_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c038_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c039_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c040_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c041_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c042_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c043_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c044_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c045_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c046_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c047_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c048_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c049_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c050_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c051_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e043c052_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e045c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e045c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e045c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e045c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e045c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e045c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e045c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e045c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e045c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e045c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e045c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e045c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c014_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c015_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c016_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c017_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c018_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c019_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c020_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c021_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c022_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c023_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c024_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c025_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c026_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c027_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c028_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c029_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c030_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c031_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c032_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c033_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e047c034_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c014_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c015_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c016_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c017_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c018_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c019_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c020_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c021_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c022_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c023_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c024_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e049c025_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c014_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c015_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c016_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c017_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c018_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c019_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c020_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c021_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c022_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c023_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c024_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c025_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c026_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c027_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c028_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c029_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c030_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c031_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c032_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c033_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c034_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c035_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c036_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e051c037_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c014_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c015_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c016_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c017_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c018_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c019_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c020_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c021_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c022_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c023_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c024_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c025_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c026_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c027_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c028_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c029_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c030_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c031_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c032_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c033_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c034_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c035_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c036_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c037_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c038_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c039_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c040_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c041_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c042_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c043_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c044_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c045_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c046_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c047_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c048_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c049_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c050_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c051_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c052_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c053_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c054_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c055_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c056_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c057_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c058_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c059_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c060_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c061_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c062_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c063_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c064_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c065_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c066_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e055c067_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c014_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c015_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c016_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c017_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c018_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c019_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c020_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c021_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c022_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c023_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c024_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c025_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c026_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c027_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c028_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c029_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c030_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c031_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c032_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e061c033_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c014_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c015_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c016_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c017_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c018_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c019_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c020_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c021_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c022_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c023_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c024_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c025_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c026_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c027_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c028_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c029_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c030_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e063c031_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c001_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c002_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c003_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c004_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c005_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c006_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c007_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c008_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c009_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c010_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c011_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c012_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c013_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c014_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c015_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c016_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c017_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c018_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c019_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c020_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c021_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c022_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c023_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c024_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c025_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c026_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c027_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c028_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c029_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c030_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c031_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c032_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c033_m$2m_caseB_emu.sh
bsub -q $1 script/rd/$2/RD_e065c034_m$2m_caseB_emu.sh
