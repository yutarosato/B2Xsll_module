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
    gen_mode_xs    (0),
    gen_xs_id      (0),
    gen_mode_lepton(0),
    gen_mode_bg    (0),
    gen_fl_xs     (-1),
    gen_m_llg      (-10),
    gen_m_ll       (-10),
    gen_m_xs       (-10),
    gen_coslp      (-10),
    genbfl         (0),
    sigb_id        (0),
    //electron_P_cut (  0.245 ),
    electron_P_cut  ( 0.400 ),
    //muon_P_cut     (  0.590 ),
    muon_P_cut      ( 0.800 ),
    //gam_E_cut      (  0.04  ),
    gam_E_cut       ( 0.05  ),
    //pi0_E_cut      (  0.30  ),
    pi0_E_cut       ( 0.40  ),
    selKPI         ( atc_pid(3, 1, 5, 3, 2) ),
    Dr_cut         (  2.0   ), // cm
    Dz_cut         (  6.0   ),
    //eidprob_cut    (  0.05  ), 
    eidprob_cut    (  0.80  ), 
    //muLH_cut       (  0.80  ),
    muLH_cut       (  0.97  ),
    masscut_pi0_L  ( -0.025 ),
    masscut_pi0_H  (  0.025 ),
    //selKPI_cut     (  0.20  ),
    selKPI_cut     (  0.60  ),
    pseudo_cc_M_cut( -0.20  ),
    dE_cut         (  0.21  ), 
    Mbc_cut_L      (  5.20  ),
    Mbc_cut_H      (  5.40  ),
    Rad_angle_cut  (  0.05  )
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
    Xs_set.insert( Xsd1_LUND      ); // added for xs-spin1 @20130408
    Xs_set.insert( antiXsd1_LUND  ); // added for xs-spin1 @20130408
    Xs_set.insert( Xsu1_LUND      ); // added for xs-spin1 @20130408
    Xs_set.insert( antiXsu1_LUND  ); // added for xs-spin1 @20130408
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


    srand(0); // seed is fixed.
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
    sTmp_Gen << " exprun event " // [ EVENT ]
	     << " gm_xs gm_l gm_bg gm_fl_xs " // [ MODE ]
	     << " bnchild " // [ B ]
	     << " ll_m llg_m BremE coslp " // [ Pseudo CC ]
	     << " Xs_id Xs_m Xsndc " // [ Xs ]
	     << "  bp  bpt  bc  bpcm  bptcm  bccm " // [Momentum] added at 20120726
	     << " xsp xspt xsc xspcm xsptcm xsccm "
	     << "  kp  kpt  kc  kpcm  kptcm  kccm "
	     << " ccp ccpt ccc ccpcm ccptcm ccccm "
	     << " lpp lppt lpc lppcm lpptcm lpccm "
	     << " lmp lmpt lmc lmpcm lmptcm lmccm "
	     << " n_total n_pi n_pi0 n_k n_ks " // [ Xs children ]
	     << " n_kl n_gamma n_proton n_electron n_muon n_rest "
      ;
    
    std::stringstream sTmp_B;
    sTmp_B << " exprun event " // [ EVENT ]
	   << " gm_xs gm_xsid gm_l gm_bg gm_m_ll gm_m_llg gm_m_xs gm_fl_xs gm_coslp " // [ MODE ]
      	   << " rm_xs rm_l "
	   << " Mbc dE " // [ B ]
	   << " b_m blund "
	   << " bp bpt bc bpcm bptcm bccm "
      	   << " xs_m xsp xspt xsc xspcm xsptcm xsccm " // [ Xs ]
	   << " cc_m cc_morg coslp " // [ Pseudo CC ]
      	   << " ccp ccpt ccc ccpcm ccptcm ccccm " //
	   << " dzll dzll3d dr_lp dr_lm dz_lp dz_lm drmax dzmax " // [ IP ]
	   << " epp mpp lppt lpc lppcm lpptcm lpccm " // [ Lepton ]
      	   << " emp mmp lmpt lmc lmpcm lmptcm lmccm "
	   << " lp_eid lm_eid lp_muid lm_muid lp_kid lm_kid "
      	   << " lpgt lporg lpself lpselfID lpmoID "
	   << " lmgt lmorg lmself lmselfID lmmoID "
	   << " kchg k_kid k_eid k_muid k_ep k_mp " // [ charged K ]
	   << " korg kselfID kmoID "
	   << " ks_m kspi1id kspi2id " // [ Ks ]
	   << " kp kpt kc kpcm kptcm kccm " // 
	   << " pi1_kid   pi2_kid   pi3_kid   pi4_kid " // [ charged pi ]
	   << " pi1_eid   pi2_eid   pi3_eid   pi4_eid "
	   << " pi1_muid  pi2_muid  pi3_muid  pi4_muid "
	   << " pi1_ep    pi2_ep    pi3_ep    pi4_ep "
      	   << " pi1_mp    pi2_mp    pi3_mp    pi4_mp "
	   << " pi1p      pi2p      pi3p      pi4p "
	   << " pi1pt     pi2pt     pi3pt     pi4pt "
	   << " pi1c      pi2c      pi3c      pi4c " //
	   << " pi1pcm    pi2pcm    pi3pcm    pi4pcm "
	   << " pi1ptcm   pi2ptcm   pi3ptcm   pi4ptcm "
	   << " pi1ccm    pi2ccm    pi3ccm    pi4ccm " //
	   << " pi1org    pi2org    pi3org    pi4org  "
	   << " pi1self   pi2self   pi3self   pi4self "
      	   << " pi1selfID pi2selfID pi3selfID pi4selfID "
	   << " pi1moID   pi2moID   pi3moID   pi4moID "
	   << " pi1trk    pi2trk    pi3trk    pi4trk "
	   << " pi1chg    pi2chg    pi3chg    pi4chg "
      //<< " pi1cdcr   pi2cdcr   pi3cdcr   pi4cdcr "
      //<< " pi1cdcz   pi2cdcz   pi3cdcz   pi4cdcz "
	   << " pi1svdr   pi2svdr   pi3svdr   pi4svdr "
	   << " pi1svdz   pi2svdz   pi3svdz   pi4svdz "
	   << " pi0_m pi0e pi0org " // [ neutral pi ]
	   << " pi0gam1E pi0gam2E "
	   << " thrust R2 " // [ QQ ]
	   << " k0mm2 k0et k0hso00 k0hso01 k0hso02 k0hso03 k0hso04 k0hso10 k0hso12 k0hso14 k0hso20 k0hso22 k0hso24 k0hoo0 k0hoo1 k0hoo2 k0hoo3 k0hoo4 " // [ RooKSFW ]
      //<< " k1mm2 k1et k1hso00 k1hso01 k1hso02 k1hso03 k1hso04 k1hso10 k1hso12 k1hso14 k1hso20 k1hso22 k1hso24 k1hoo0 k1hoo1 k1hoo2 k1hoo3 k1hoo4 "
      //<< " evis1 evis2 evis3 evis1ks evis2ks evis3ks mmiss1 mmiss2 mmiss3 mmiss1ks mmiss2ks mmiss3ks deroe1 deroe2 deroe3 deroe1ks deroe2ks deroe3ks " // [ Combinatorial ]
	   << " evis1 mmiss1 deroe1 " // [ Combinatorial ]
	   << " kflcl kflchi kfldgf kfbcl kfbchi kfbdgf kfbcl2 kfbchi2 kfbdgf2 kfbclorg kfbchiorg kfbdgforg " // [ Vertex ]
	   << " self q2self kself pi0self rest rest_sw " // [ SELF ]
	   << " genbfl recbfl " // [ B flavor ]
	   << " gm_ccng gm_ccge cc_ng cc_g1e cc_g2e cc_g1_self cc_g2_self " // charmonium study @ added 20121030
	   << " heg_self leg_self heg_moid leg_moid cc_mheg cc_mleg cc_morgheg cc_morgleg " 
      ;
    Gen_dist = tm->ntuple( "Gen", sTmp_Gen.str().c_str(),  12 );
    B_dist   = tm->ntuple( "B",   sTmp_B.str().c_str(),   511 );
    //t1_dist  = tm->ntuple( "t1",  " r z conv cnt ", 14 );
    //t2_dist  = tm->ntuple( "t2",  " Egam Egamcm self had ", 16 );

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
    
    //getEventInfo(expNo, runNo, evtNo, mc);

    //int expmc = ((belle_event*)BsGetEnt(BELLE_EVENT,1,BBS_No_Index))->m_ExpMC; // for IP tube constraint
    //if( expmc!=2 ){
    //if( !IpProfile::usable() ) return;
    //if( !IpProfile::b_life_smeared_usable() ) return;
    //}

    Gen_beam_Manager &gen_beam_mgr = Gen_beam_Manager::get_manager();
    std::vector<Gen_beam>::const_iterator gen_beam = gen_beam_mgr.begin();
    expNo = gen_beam->ExpNo();
    runNo = gen_beam->RunNo();

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
    //display_list( tmp_set, tmp_multiset ); // RRRRRRRRRRRRRRRRRRRRRRRRRR
    return;
  }
      
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
