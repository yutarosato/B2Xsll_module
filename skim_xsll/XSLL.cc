#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  //my analysis code
  // Constructor
  XSLL::XSLL() :
    mc(true),
    expNo(0),
    runNo(0),
    evtNo(0),
    numberOfEvent(0),
    numberOfSkim(0),
    gen_mode_xs    (0),
    gen_xs_id      (0),
    gen_mode_lepton(0),
    gen_mode_bg    (0),
    gen_fl_llg     (-1),
    gen_m_llg      (-10),
    genbfl         (0),
    electron_P_cut ( 0.400 ), // for stream [6-9]
    muon_P_cut     ( 0.800 ), // for stream [6-9]
    //electron_P_cut ( 0.245 ),
    //muon_P_cut     ( 0.590 ),
    min_e_dilep_cut( 1.8 ),
    Dr_cut         ( 2.0  ), // cm // [1.0]
    Dz_cut         ( 6.0 ), // [5.0]
    //eidprob_cut    ( 0.05 ), 
    //muLH_cut       ( 0.80 ),
    eidprob_cut    ( 0.80 ), // for stream [6-9]
    muLH_cut       ( 0.97 ), // for stream [6-9]
    masscut_pi0_L  ( -0.025 ),
    masscut_pi0_H  (  0.025 ),
    dE_cut         ( 0.21 ), 
    Mbc_cut_L      ( 5.20 ),
    Mbc_cut_H      ( 5.40 ),
    Rad_angle_cut  ( 0.05 )
  {
    std::cout << " +++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
    std::cout << "[ XSLL's constructor ]" << std::endl;
    strcpy( SkimFileName, "Skim_XSLL_test.index" );
    
    std::cout << "          Dr_cut = " << Dr_cut           << std::endl
	      << "          Dz_cut = " << Dz_cut           << std::endl
	      << "  electron_P_cut = " << electron_P_cut   << std::endl
	      << "      muon_P_cut = " << muon_P_cut       << std::endl
      	      << " min_e_dilep_cut = " << min_e_dilep_cut  << std::endl
	      << "     eidprob_cut = " << eidprob_cut      << std::endl
	      << "        muLH_cut = " << muLH_cut         << std::endl
	      << "   masscut_pi0_L = " << masscut_pi0_L    << std::endl
	      << "   masscut_pi0_H = " << masscut_pi0_H    << std::endl
	      << "          dE_cut = " << dE_cut           << std::endl
	      << "       Mbc_cut_L = " << Mbc_cut_L        << std::endl
      	      << "       Mbc_cut_H = " << Mbc_cut_H        << std::endl
      ;

    recon_set.insert( Ks_LUND      );
    recon_set.insert( Kplus_LUND   );
    recon_set.insert( Kminus_LUND  );
    recon_set.insert( PI0_LUND     );
    recon_set.insert( PIplus_LUND  );
    recon_set.insert( PIminus_LUND );

    std::cout << "   recon_set : ";
    std::set<int>::iterator it_recon = recon_set.begin();
    while( it_recon != recon_set.end() ){
      std::cout << *it_recon << ", ";
      ++it_recon;
    }
    std::cout << std::endl;

    nonrecon_set.insert( Kl_LUND          );
    nonrecon_set.insert( Gamma_LUND       );
    nonrecon_set.insert( Proton_LUND      );
    nonrecon_set.insert( antiProton_LUND  );
    nonrecon_set.insert( Neutron_LUND     );
    nonrecon_set.insert( antiNeutron_LUND );
    nonrecon_set.insert( Electron_LUND    );
    nonrecon_set.insert( Positron_LUND    );
    nonrecon_set.insert( MUplus_LUND      );
    nonrecon_set.insert( MUminus_LUND     );

    std::cout << "   nonrecon_set : ";
    std::set<int>::iterator it_nonrecon = nonrecon_set.begin();
    while( it_nonrecon != nonrecon_set.end() ){
      std::cout << *it_nonrecon << ", ";
      ++it_nonrecon;
    }
    std::cout << std::endl;
    
    Xs_set.insert( Xsd_LUND       );
    Xs_set.insert( antiXsd_LUND   );
    Xs_set.insert( Xsu_LUND       );
    Xs_set.insert( antiXsu_LUND   );
    Xs_set.insert( K0_LUND        );
    Xs_set.insert( antiK0_LUND    );
    Xs_set.insert( Kplus_LUND     );
    Xs_set.insert( Kminus_LUND    );
    Xs_set.insert( Kstr0_LUND     );
    Xs_set.insert( antiKstr0_LUND );
    Xs_set.insert( Kstrp_LUND     );
    Xs_set.insert( Kstrm_LUND     );
    
    std::cout << "   Xs_set : ";
    std::set<int>::iterator it_Xs = Xs_set.begin();
    while( it_Xs != Xs_set.end() ){
      std::cout << *it_Xs << ", ";
      ++it_Xs;
    }
    std::cout << std::endl;

    std::cout << " +++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
    
    return;
  }

  extern "C" Module_descr *mdcl_XSLL()
  {
    XSLL* module = new XSLL;
    Module_descr* dscr = new Module_descr( "XSLL", module );
    dscr->define_param("flag_mode", "flag_mode", &module->flag_mode );
    dscr->define_param( "SkimFileName", "SkimFileName", 256, module->SkimFileName );

    IpProfile::define_global( dscr ); // for IP tube constraint
    return dscr;
  }
  
  // Destructor
  XSLL::~XSLL( void )
  {
    return;
  }

  // initilization
  void XSLL::init( int *status )
  {
    std::cout << "[ XSLL's initilization ]" << std::endl;
    extern BasfOutputManager* BASF_Output;
    SkimFile = BASF_Output->open( SkimFileName );
    return;
  }

  // begin_run function
  void XSLL::begin_run( BelleEvent* evptr, int* status )
  {
    std::cout << " +++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
    std::cout << "[ XSLL's begin_run function ]" << std::endl;

    // IP information
    IpProfile::begin_run();
    m_IP     = IpProfile::position();
    m_IP_err = IpProfile::position_err();
    std::cout << "    IpProfile::position() = " << m_IP
	      << " +- " << m_IP_err
	      << std::endl;

    // Beam Energy information
    BeamEnergy::begin_run();    
    E_HER = BeamEnergy::E_HER();
    E_LER = BeamEnergy::E_LER();
    std::cout << "    BeamEnergy::E_HER()   = " << E_HER << std::endl
	      << "    BeamEnergy::E_LER()   = " << E_LER << std::endl;
    X_ANGLE = 0.022; // rad
    lab = HepLorentzVector( E_HER * sin(X_ANGLE), 0.0,
			   E_HER * cos(X_ANGLE) - E_LER, E_HER + E_LER );
    cmboost = -lab.boostVector();
    HepLorentzVector cm = lab;

    cm.boost(cmboost);
    eb = cm.e()/2.0;

    std::cout << "       4-momentum(lab)    = " << lab     << std::endl
	      << "       cmboost vector     = " << cmboost << std::endl
	      << "    half of CM energy(eb) = " << eb      << std::endl
	      << BeamEnergy::CMBoost() << std::endl;

    // for eid
    eid::init_data();

    // for Ptype
    Ptype dummy( "VPHO" );

    SkimFile->write();
    
    std::cout << " +++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
    return;
  }
  
  // hist_def function
  void XSLL::hist_def()
  {
    std::cout << "[ XSLL's hist_def function ]" << std::endl;
    extern BelleTupleManager* BASF_Histogram;
    BelleTupleManager* tm = BASF_Histogram;
    Skim_dist = tm->ntuple( "Skim_XSLL", "exp run evt skim event", 1 );
    //t1_dist = tm->ntuple( "e",  "id p ", 11 );
    //t2_dist = tm->ntuple( "mu", "id p ", 13 );

    return;
  }
  
  // event function
  void XSLL::event( BelleEvent* evptr, int* status )
  {
    //std::cout << "[ XSLL's event function ]" << std::endl;
    *status = 0;
    numberOfEvent++;
    
    // Belle event info
    expNo = 0;
    runNo = 0;
    evtNo = 0;
    
    getEventInfo(expNo, runNo, evtNo, mc);

    int expmc = ((belle_event*)BsGetEnt(BELLE_EVENT,1,BBS_No_Index))->m_ExpMC; // for IP tube constraint
    if( expmc!=2 ){
      if( !IpProfile::usable() ) return;
      if( !IpProfile::b_life_smeared_usable() ) return;
    }
    *status = event_start();
    return;
  }
  
  // end_run function
  void XSLL::end_run( BelleEvent* evtptr, int* status )
  {
    std::cout << "[ XSLL's end_run function ]" << std::endl;
    return;
  }

  // term function
  void XSLL::term()
  {
    std::cout << "[ XSLL's term function ]" << std::endl;
    delete SkimFile;
    //display_list( tmp_set, tmp_multiset ); // RRRRRRRRRRRRRRRRRRRRRRRRRR
    return;
  }
      
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
