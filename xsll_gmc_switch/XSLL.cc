#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  //my analysis code
  // Constructor
  XSLL::XSLL() :
    mc(true),
    bb(-1),
    expNo(0),
    runNo(0),
    evtNo(0),
    gen_mode_B1     (0),
    gen_mode_B2     (0),
    gen_mode_bg1    (0),
    gen_mode_bg2    (0),
    gen_mode_lepton1(0),
    gen_mode_lepton2(0),
    sigb_id         (0),
    electron_P_cut  ( 0.245 ),
    muon_P_cut      ( 0.590 ),
    gam_E_cut       ( 0.04  ),
    pi0_E_cut       ( 0.30  ),
    selKPI          ( atc_pid(3, 1, 5, 3, 2) ),
    Dr_cut          (  1.0  ), // cm
    Dz_cut          (  5.0  ),
    eidprob_cut     (  0.05 ), 
    muLH_cut        (  0.80 ),
    masscut_pi0_L   ( -0.020 ),
    masscut_pi0_H   (  0.020 ),
    selKPI_cut      (  0.20  ),
    pseudo_cc_M_cut ( -0.20  ),
    dE_cut          (  0.21  ), 
    Mbc_cut_L       (  5.20  ),
    Mbc_cut_H       (  5.40  ),
    Rad_angle_cut   (  0.05  ),
    //masscut_Xs      (  2.00  )
    masscut_Xs      (  100.00  )
  {
    std::cout << " +++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
    std::cout << "[ XSLL's constructor ]" << std::endl;
    
    std::cout << "          Dr_cut = " << Dr_cut           << std::endl
	      << "          Dz_cut = " << Dz_cut           << std::endl
      	      << "  electron_P_cut = " << electron_P_cut   << std::endl
	      << "      muon_P_cut = " << muon_P_cut       << std::endl
      	      << "       gam_E_cut = " << gam_E_cut        << std::endl
	      << "       pi0_E_cut = " << pi0_E_cut        << std::endl
	      << "     eidprob_cut = " << eidprob_cut      << std::endl
	      << "        muLH_cut = " << muLH_cut         << std::endl
      	      << "   masscut_pi0_L = " << masscut_pi0_L    << std::endl
	      << "   masscut_pi0_H = " << masscut_pi0_H    << std::endl
	      << "      selKPI_cut = " << selKPI_cut       << std::endl
	      << " pseudo_cc_M_cut = " << pseudo_cc_M_cut  << std::endl
	      << "          dE_cut = " << dE_cut           << std::endl
	      << "       Mbc_cut_L = " << Mbc_cut_L        << std::endl
      	      << "       Mbc_cut_H = " << Mbc_cut_H        << std::endl
      ;

    recon_set.insert( Ks_LUND       );
    recon_set.insert( Kplus_LUND    );
    recon_set.insert( Kminus_LUND   );
    recon_set.insert( PI0_LUND      );
    recon_set.insert( PIplus_LUND   );
    recon_set.insert( PIminus_LUND  );
    recon_set.insert( Electron_LUND );
    recon_set.insert( Positron_LUND );
    recon_set.insert( MUplus_LUND   );
    recon_set.insert( MUminus_LUND  );

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
    //nonrecon_set.insert( Electron_LUND    ); // -> move to recon particle
    //nonrecon_set.insert( Positron_LUND    ); // -> move to recon particle
    //nonrecon_set.insert( MUplus_LUND      ); // -> move to recon particle
    //nonrecon_set.insert( MUminus_LUND     ); // -> move to recon particle
    nonrecon_set.insert(     Nu_E_LUND    ); // -> neutrinos are added
    nonrecon_set.insert( antiNu_E_LUND    );
    nonrecon_set.insert(     Nu_MU_LUND   );
    nonrecon_set.insert( antiNu_MU_LUND   );
    nonrecon_set.insert(     Nu_TAU_LUND  );
    nonrecon_set.insert( antiNu_TAU_LUND  );

    std::cout << "   nonrecon_set : ";
    std::set<int>::iterator it_nonrecon = nonrecon_set.begin();
    while( it_nonrecon != nonrecon_set.end() ){
      std::cout << *it_nonrecon << ", ";
      ++it_nonrecon;
    }
    std::cout << std::endl;
    /*
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
    */
    std::cout << " +++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
    
    return;
  }

  extern "C" Module_descr *mdcl_XSLL()
  {
    XSLL* module = new XSLL;
    Module_descr* dscr = new Module_descr( "XSLL", module );
    dscr->define_param("flag_mode", "flag_mode", &module->flag_mode );

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

    //std::cout << "    IpProfile::position() = " << m_IP
    //<< " +- " << m_IP_err
    //<< std::endl;

    // Beam Energy information
    BeamEnergy::begin_run();    
    E_HER = BeamEnergy::E_HER();
    E_LER = BeamEnergy::E_LER();

    //std::cout << "    BeamEnergy::E_HER()   = " << E_HER << std::endl
    //<< "    BeamEnergy::E_LER()   = " << E_LER << std::endl;
    
    X_ANGLE = 0.022; // rad
    lab = HepLorentzVector( E_HER * sin(X_ANGLE), 0.0,
			   E_HER * cos(X_ANGLE) - E_LER, E_HER + E_LER );
    cmboost = -lab.boostVector();
    HepLorentzVector cm = lab;

    cm.boost(cmboost);
    eb = cm.e()/2.0;

    //std::cout << "       4-momentum(lab)    = " << lab     << std::endl
    //<< "       cmboost vector     = " << cmboost << std::endl
    //<< "    half of CM energy(eb) = " << eb      << std::endl
    //<< BeamEnergy::CMBoost() << std::endl;

    // for eid
    eid::init_data();

    // for Ptype
    Ptype dummy( "VPHO" );
    std::cout << " +++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
    return;
  }
  
  // hist_def function
  void XSLL::hist_def()
  {
    std::cout << "[ XSLL's hist_def function ]" << std::endl;
    extern BelleTupleManager* BASF_Histogram;
    BelleTupleManager* tm = BASF_Histogram;


    std::stringstream sTmp_Gen;
    sTmp_Gen << " exprun event bb " // [ EVENT ]
	     << " gm_B1 gm_l1 gm_bg1 " // [ MODE ]
	     << " gm_B2 gm_l2 gm_bg2 "
	     << " n1_total n1_pi n1_pi0 n1_k n1_ks n1_kl n1_gamma n1_proton n1_electron n1_muon n1_nu_e n1_nu_mu n1_nu_tau n1_rest "
	     << " n2_total n2_pi n2_pi0 n2_k n2_ks n2_kl n2_gamma n2_proton n2_electron n2_muon n2_nu_e n2_nu_mu n2_nu_tau n2_rest "
      ;

    std::stringstream sTmp_B;
    sTmp_B << " exprun event " // [ EVENT ]
	   << " gm_bg1 gm_bg2 gm_B1 gm_B2 gm_nu1 gm_nu2 gm_l1 gm_l2 gm_m_xs gm_fl_xs " // [ MODE ]
      	   << " rm_xs rm_l "
	   << " Mbc dE " // [ B ]
	   << " b_m blund "
	   << " bp bpt bc bpcm bptcm bccm "
      	   << " xs_m " // [ Xs ]
	   << " cc_m cc_morg coslp " // [ Pseudo CC ]
      	   << " ccp ccpt ccc ccpcm ccptcm ccccm " //
	   << " lpi1_m lpi2_m lpi3_m lpi4_m xs1_m xs2_m xs3_m xs4_m " // [ switch mass ] // added at 20120828
	   << " dzll dzll3d dr_lp dr_lm dz_lp dz_lm drmax dzmax " // [ IP ]
	   << " dzll3d1 dzll3d2 dzll3d3 dzll3d4 " // [switch IP] // added at 20120828
	   << " epp mpp lppt lpc lppcm lpptcm lpccm " // [ Lepton ]
      	   << " emp mmp lmpt lmc lmpcm lmptcm lmccm "
	   << " lpph lpphcm lmph lmphcm " // added at 20120823
	   << " lp_eid lm_eid lp_muid lm_muid lp_kid lm_kid "
      //<< " lpgt lporg lpself lpselfID lpmoID " // remove at RD
      //<< " lmgt lmorg lmself lmselfID lmmoID " // remove at RD
	   << " kchg k_kid k_eid k_muid k_ep k_mp " // [ charged K ]
      //<< " korg kselfID kmoID " // remove at RD
	   << " ks_m kspi1id kspi2id " // [ Ks ]
	   << " kp kpt kc kpcm kptcm kccm "
	   << " kph kphcm " // added at 20120823
	   << " pi1_kid   pi2_kid   pi3_kid   pi4_kid " // [ charged pi ]
	   << " pi1_eid   pi2_eid   pi3_eid   pi4_eid "
	   << " pi1_muid  pi2_muid  pi3_muid  pi4_muid "
	   << " pi1_ep    pi2_ep    pi3_ep    pi4_ep "
      	   << " pi1_mp    pi2_mp    pi3_mp    pi4_mp "
	   << " pi1p      pi2p      pi3p      pi4p "
	   << " pi1pt     pi2pt     pi3pt     pi4pt "
	   << " pi1c      pi2c      pi3c      pi4c "  //
	   << " pi1ph     pi2ph     pi3ph     pi4ph " // added at 20120823
	   << " pi1pcm    pi2pcm    pi3pcm    pi4pcm "
	   << " pi1ptcm   pi2ptcm   pi3ptcm   pi4ptcm "
	   << " pi1phcm   pi2phcm   pi3phcm   pi4phcm " // added at 20120823
	   << " pi1ccm    pi2ccm    pi3ccm    pi4ccm " //
      //<< " pi1org    pi2org    pi3org    pi4org  " // remove at RD
      //<< " pi1self   pi2self   pi3self   pi4self " // remove at RD
      //<< " pi1selfID pi2selfID pi3selfID pi4selfID " // remove at RD
      //<< " pi1moID   pi2moID   pi3moID   pi4moID " // remove at RD
	   << " pi1trk    pi2trk    pi3trk    pi4trk "
	   << " pi1chg    pi2chg    pi3chg    pi4chg "
	   << " pi1svdr   pi2svdr   pi3svdr   pi4svdr "
	   << " pi1svdz   pi2svdz   pi3svdz   pi4svdz "
	   << " pi0_m pi0e pi0org " // [ neutral pi ]
	   << " pi0gam1E pi0gam2E "
	   << " thrust R2 " // [ QQ ]
	   << " k0mm2 k0et k0hso00 k0hso01 k0hso02 k0hso03 k0hso04 k0hso10 k0hso12 k0hso14 k0hso20 k0hso22 k0hso24 k0hoo0 k0hoo1 k0hoo2 k0hoo3 k0hoo4 " // [ RooKSFW ]
	   << " evis1 mmiss1 deroe1 " // [ Combinatorial ]
	   << " kflcl kflchi kfldgf kfbcl kfbchi kfbdgf " // [ Vertex ]
      //<< " kself pi0self rest rest2 rest_sw rest2_sw dntrk ntrk " // [ SELF ] // remove at RD
	   << " genbfl recbfl " // [ B flavor ]
      //<< " gb1_semi gb2_semi gb1nd gb2nd gb1d1_semi gb1d2_semi gb2d1_semi gb2d2_semi gb1_cc gb2_cc " // [Event Info] // remove at RD
      ;
    Gen_dist = tm->ntuple( "Gen", sTmp_Gen.str().c_str(),  12 );
    B_dist   = tm->ntuple( "B",   sTmp_B.str().c_str(),   511 );

    return;
  }
  
  // event function
  void XSLL::event( BelleEvent* evptr, int* status )
  {
    //std::cout << "[ XSLL's event function ]" << std::endl;
    *status = 0;
    
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
    event_start();
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
    return;
  }
      
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
