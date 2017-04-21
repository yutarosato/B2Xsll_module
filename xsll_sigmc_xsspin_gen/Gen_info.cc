#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  int XSLL::Gen_info( std::map<int,int>& child_id_map, std::multiset<int>& n_particle_set,
		       const int fl_message )
  {
    //std::cout << "Gen start!" << std::endl;
    if( mc !=1 ){
      std::cout << "Data is Real Data. Gen Function skip. "
		<< std::endl;
      return 0;
    }
    
    Gen_hepevt_Manager& genMgr = Gen_hepevt_Manager::get_manager();
    if( fl_message==2 ) genMgr.dump();
    
    Gen_hepevt& Upsilon4S( genMgr( Panther_ID(1) ) );

    // which B is signal ?
    Gen_hepevt& B1( genMgr( Panther_ID(2) ) );
    Gen_hepevt& B2( genMgr( Panther_ID(3) ) );

    int ll1 = genMgr( Panther_ID( B1.daFirst() + 1 ) ).idhep() * genMgr( Panther_ID( B1.daFirst() + 2 ) ).idhep();
    int ll2 = genMgr( Panther_ID( B2.daFirst() + 1 ) ).idhep() * genMgr( Panther_ID( B2.daFirst() + 2 ) ).idhep();
    int k1  = genMgr( Panther_ID( B1.daFirst() ) ).idhep();
    int k2  = genMgr( Panther_ID( B2.daFirst() ) ).idhep();

    sigb_id=0;
    if( ll1 == -121 || ll1 == -169 ) sigb_id += 2;
    if( ll2 == -121 || ll2 == -169 ) sigb_id += 3;
    if( !(sigb_id == 2 || sigb_id == 3) ) std::cout << "Error in the selction of B_sig" << std::endl, abort();
    
    Gen_hepevt& B ( genMgr(Panther_ID(sigb_id      )) );
    Gen_hepevt& lp( genMgr(Panther_ID(B.daFirst()+1)) );
    Gen_hepevt& lm( genMgr(Panther_ID(B.daFirst()+2)) );
    Gen_hepevt& Xs( genMgr(Panther_ID(B.daFirst()  )) );
    if( B.idhep() == B0_LUND || B.idhep() == Bplus_LUND ) genbfl = -1;
    else if( B.idhep() == antiB0_LUND || B.idhep() == Bminus_LUND ) genbfl = 1;
    
    if( child_id_map.count(lp.get_ID()) != 0) std::cout << "error ????? duplication(l+)" << std::endl;
    if( child_id_map.count(lm.get_ID()) != 0) std::cout << "error ????? duplication(l-)" << std::endl;
    child_id_map.insert( std::pair<int, int> (lp.get_ID(),lp.idhep()) );
    child_id_map.insert( std::pair<int, int> (lm.get_ID(),lm.idhep()) );

    if( Xs_set.count( Xs.idhep() ) ){
      find_fin_child( Xs, child_id_map, n_particle_set, fl_message );
    }else{
      std::cout << "other strange particle ??????????????????????" << std::endl;
      abort();
    }

    if( abs(Xs.idhep())==Xsd_LUND  || abs(Xs.idhep())==Xsu_LUND  ||
	abs(Xs.idhep())==Xsd1_LUND || abs(Xs.idhep())==Xsu1_LUND    ) gen_fl_xs = 1;
    else gen_fl_xs = -1;


    if( fl_message ){
      std::cout << "------------------------------------------------------------------------------"
		<< std::endl;
      std::cout << " # of Xsll rec-child : " << child_id_map.size() << " [ ";
      for (std::map<int, int>::iterator i = child_id_map.begin(); i != child_id_map.end(); i++){
	std::cout << i->second << "(" << i->first << ") ";
      }
      std::cout << " ] " << std::endl;
      std::cout << " # of Xs all-child : " <<  n_particle_set.size() << " [ ";
      int count=0;
      for (std::multiset<int>::iterator i = n_particle_set.begin(); i != n_particle_set.end(); i++){
	std::cout << *i << " ";
      }
      std::cout << " ]" << std::endl;
    }


    // Judgement of gen_mode
    int n_total      = n_particle_set.size();
    int n_charged_pi = n_particle_set.count( PIplus_LUND   );
    int n_neutral_pi = n_particle_set.count( PI0_LUND      );
    int n_charged_k  = n_particle_set.count( Kplus_LUND    );
    int n_ks         = n_particle_set.count( Ks_LUND       );   
   
    int n_kl         = n_particle_set.count( Kl_LUND       );
    int n_gamma      = n_particle_set.count( Gamma_LUND    );
    int n_proton     = n_particle_set.count( Proton_LUND   );
    int n_neutron    = n_particle_set.count( Neutron_LUND  );
    int n_electron   = n_particle_set.count( Electron_LUND );
    int n_muon       = n_particle_set.count( MUminus_LUND  );
    
    int n_rest       = n_total - (n_charged_pi + n_neutral_pi )
      - ( n_charged_k + n_ks ) - ( n_kl + n_gamma + n_proton + n_neutron + n_electron + n_muon );

    if( n_charged_pi > 9 ) n_charged_pi = 9;
    if( n_neutral_pi > 9 ) n_neutral_pi = 9;
    if( n_charged_k  > 9 ) n_charged_k  = 9;
    if( n_ks         > 9 ) n_ks         = 9;
    if( n_kl         > 9 ) n_kl         = 9;
    if( n_gamma      > 9 ) n_gamma      = 9;
    if( n_proton     > 9 ) n_proton     = 9;
    if( n_neutron    > 9 ) n_neutron    = 9;
    if( n_electron   > 9 ) n_electron   = 9;
    if( n_muon       > 9 ) n_muon       = 9;
    if( n_rest       > 9 ) n_rest       = 9;
    
    gen_mode_bg     = 1000000*n_rest + 100000*n_electron + 10000*n_muon + 1000*n_kl + 100*n_proton + 10*n_neutron + n_gamma;
    gen_mode_xs     = 1000*n_neutral_pi + 100*n_charged_pi + 10*n_ks + n_charged_k;
    gen_mode_lepton = lm.idhep() == Electron_LUND ? 1 : 0;
    if( fl_message ){
      std::cout << "gen_mode_bg     = " << gen_mode_bg     << std::endl
		<< "gen_mode_xs     = " << gen_mode_xs     << std::endl
		<< "gen_mode_lepton = " << gen_mode_lepton << std::endl
		<< "------------------------------------------------------------------------------"
		<< std::endl;
    }

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    int nchild_b  = B.daLast() ==0 ? 0 : B.daLast()  - B.daFirst()  + 1; // the number of B children ( Xs l l + gamma )
    int nchild_xs = Xs.daLast()==0 ? 0 : Xs.daLast() - Xs.daFirst() + 1; // the number of children directly produced from Xs
    /*
      for(int i=0; i<nchild_xs; i++){
      int id = genMgr( Panther_ID( Xs.daFirst() + i ) ).idhep();
      tmp_set.insert(id);      // RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
      tmp_multiset.insert(id); // RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
      }
    */
    
    // [ EVENT ]
    double exprunNo = expNo*10000+runNo;
    Gen_dist->column( "exprun",    exprunNo );
    Gen_dist->column( "event",     evtNo    );

    Gen_dist->column( "gm_xs",      gen_mode_xs     );
    Gen_dist->column( "gm_l",       gen_mode_lepton );
    Gen_dist->column( "gm_bg",      gen_mode_bg     );
    Gen_dist->column( "gm_fl_xs",   gen_fl_xs       );

    Gen_dist->column( "bnchild",    nchild_b  ); // the number of B : Xs l l (+ gamma)

    HepLorentzVector lp_4V = HepLorentzVector( lp.PX(),lp.PY(), lp.PZ(), lp.E() );
    HepLorentzVector lm_4V = HepLorentzVector( lm.PX(),lm.PY(), lm.PZ(), lm.E() );
    gen_m_llg = (lp_4V + lm_4V).m();
    gen_m_ll  = gen_m_llg;
    Gen_dist->column( "ll_m",  gen_m_llg ); // invariant mass of di-lepton
    if( nchild_b == 4 ){
      Gen_hepevt& brem1( genMgr(Panther_ID(B.daFirst()+3)) );
      HepLorentzVector brem1_4V = HepLorentzVector( brem1.PX(),brem1.PY(), brem1.PZ(), brem1.E() );
      gen_m_llg = (lp_4V + lm_4V + brem1_4V).m();
      Gen_dist->column( "llg_m",  gen_m_llg    ); // invariant mass of di-lepton including bremsstrahlung gamma
      Gen_dist->column( "BremE",  brem1_4V.e() ); // bremsstrahlung gamma energy
    }else if( nchild_b > 4 ){
      Gen_hepevt& brem1( genMgr(Panther_ID(B.daFirst()+3)) );
      Gen_hepevt& brem2( genMgr(Panther_ID(B.daFirst()+3)) );
      HepLorentzVector brem1_4V = HepLorentzVector( brem1.PX(),brem1.PY(), brem1.PZ(), brem1.E() );
      HepLorentzVector brem2_4V = HepLorentzVector( brem2.PX(),brem2.PY(), brem2.PZ(), brem2.E() );
      gen_m_llg = ( lp_4V + lm_4V + brem1_4V + brem2_4V ).m();
      Gen_dist->column( "llg_m",  gen_m_llg    ); // invariant mass of di-lepton including bremsstrahlung gamma
      Gen_dist->column( "BremE",  brem1_4V.e() ); // bremsstrahlung gamma energy
    }else{
      Gen_dist->column( "llg_m",  gen_m_llg ); // invariant mass of di-lepton including bremsstrahlung gamma
      Gen_dist->column( "BremE",  -10       ); // bremsstrahlung gamma energy
    }


    //////////////////////////////////////////////////////////////////////////
    HepLorentzVector B_4V  = HepLorentzVector(  B.PX(),         B.PY(),          B.PZ(),          B.E()        );
    HepLorentzVector CC_4V = HepLorentzVector( lp.PX()+lm.PX(),lp.PY()+lm.PY(), lp.PZ()+lm.PZ(), lp.E()+lm.E() );
    Hep3Vector dilep_boost = -CC_4V.boostVector();
    lp_4V.boost( dilep_boost ); //   l+  momentum at dilepton-rest-frame
    B_4V.boost ( dilep_boost ); // rec-B momentum at dilepton-rest-frame
    gen_coslp = cos( lp_4V.vect().angle(B_4V.vect()) );
    if(      genbfl ==  1 ) ;
    else if( genbfl == -1 ) gen_coslp *= -1.0;
    Gen_dist->column( "coslp", gen_coslp );
    //////////////////////////////////////////////////////////////////////////    
    // B added at 20120726
    B_4V  = HepLorentzVector(  B.PX(),         B.PY(),          B.PZ(),          B.E()        );
    Gen_dist->column( "bp",        B_4V.vect().mag()         );
    Gen_dist->column( "bpt",       B_4V.perp()               );
    Gen_dist->column( "bc",        B_4V.cosTheta()           );
    B_4V.boost( cmboost );
    Gen_dist->column( "bpcm",      B_4V.vect().mag()         );
    Gen_dist->column( "bptcm",     B_4V.perp()               );
    Gen_dist->column( "bccm",      B_4V.cosTheta()           );
    // Xs added at 20120726
    HepLorentzVector Xs_4V = HepLorentzVector( Xs.PX(),Xs.PY(), Xs.PZ(), Xs.E() );
    Gen_dist->column( "xsp",       Xs_4V.vect().mag()        );
    Gen_dist->column( "xspt",      Xs_4V.perp()              );
    Gen_dist->column( "xsc",       Xs_4V.cosTheta()          );
    Xs_4V.boost( cmboost );
    Gen_dist->column( "xspcm",     Xs_4V.vect().mag()        );
    Gen_dist->column( "xsptcm",    Xs_4V.perp()              );
    Gen_dist->column( "xsccm",     Xs_4V.cosTheta()          );
    if( abs(Xs.idhep())==Kstr0_LUND || abs(Xs.idhep())==Kstrp_LUND ){
      Gen_hepevt& K( genMgr(Panther_ID(Xs.daFirst()  )) );
      HepLorentzVector K_4V = HepLorentzVector( K.PX(),K.PY(), K.PZ(), K.E() );
      Gen_dist->column( "kp",       K_4V.vect().mag()        );
      Gen_dist->column( "kpt",      K_4V.perp()              );
      Gen_dist->column( "kc",       K_4V.cosTheta()          );
      K_4V.boost( cmboost );
      Gen_dist->column( "kpcm",     K_4V.vect().mag()        );
      Gen_dist->column( "kptcm",    K_4V.perp()              );
      Gen_dist->column( "kccm",     K_4V.cosTheta()          );
    }
    // CC added at 20120726
    CC_4V = HepLorentzVector( lp.PX()+lm.PX(),lp.PY()+lm.PY(), lp.PZ()+lm.PZ(), lp.E()+lm.E() );
    Gen_dist->column( "ccp",       CC_4V.vect().mag()        );
    Gen_dist->column( "ccpt",      CC_4V.perp()              );
    Gen_dist->column( "ccc",       CC_4V.cosTheta()          );
    CC_4V.boost( cmboost );
    Gen_dist->column( "ccpcm",     CC_4V.vect().mag()        );
    Gen_dist->column( "ccptcm",    CC_4V.perp()              );
    Gen_dist->column( "ccccm",     CC_4V.cosTheta()          );
    // l+ added at 20120726
    lp_4V = HepLorentzVector( lp.PX(),lp.PY(), lp.PZ(), lp.E() );
    Gen_dist->column( "lpp",       lp_4V.vect().mag()        );
    Gen_dist->column( "lppt",      lp_4V.perp()              );
    Gen_dist->column( "lpc",       lp_4V.cosTheta()          );
    lp_4V.boost( cmboost );
    Gen_dist->column( "lppcm",     lp_4V.vect().mag()        );
    Gen_dist->column( "lpptcm",    lp_4V.perp()              );
    Gen_dist->column( "lpccm",     lp_4V.cosTheta()          );
    // l- added at 20120726
    lm_4V = HepLorentzVector( lm.PX(),lm.PY(), lm.PZ(), lm.E() );
    Gen_dist->column( "lmp",       lm_4V.vect().mag()        );
    Gen_dist->column( "lmpt",      lm_4V.perp()              );
    Gen_dist->column( "lmc",       lm_4V.cosTheta()          );
    lm_4V.boost( cmboost );
    Gen_dist->column( "lmpcm",     lm_4V.vect().mag()        );
    Gen_dist->column( "lmptcm",    lm_4V.perp()              );
    Gen_dist->column( "lmccm",     lm_4V.cosTheta()          );
    //////////////////////////////////////////////////////////////////////////    

    gen_xs_id = Xs.idhep();
    gen_m_xs  = Xs.M();


    double rnd = (double)rand()/RAND_MAX;
    
    // The pseudo-Xsspin MC samples are weighted to match the non-resonatnt Xs samples. @ 20130412
    ///*
    if( abs(gen_xs_id)==Xsd_LUND || abs(gen_xs_id)==Xsu_LUND ){ // xs-spin0
      if     ( gen_mode_lepton==1 && rnd > 0.723652*exp(-0.460508*gen_m_xs*gen_m_xs*gen_m_xs*gen_m_xs+2.94643*gen_m_xs*gen_m_xs*gen_m_xs-6.70178*gen_m_xs*gen_m_xs+5.44897*gen_m_xs-0.820457) ) return 1; // ee
      else if( gen_mode_lepton==0 && rnd > 0.45192*exp(-0.490437*gen_m_xs*gen_m_xs*gen_m_xs*gen_m_xs+3.17073*gen_m_xs*gen_m_xs*gen_m_xs-7.35618*gen_m_xs*gen_m_xs+6.21637*gen_m_xs-0.624332) ) return 1; // mm
    }else if( abs(gen_xs_id)==Xsd1_LUND || abs(gen_xs_id)==Xsu1_LUND ){ // xs-spin1
      if     ( gen_mode_lepton==1 && rnd > 1.24675*exp(-0.133397*gen_m_xs*gen_m_xs*gen_m_xs*gen_m_xs+0.319661*gen_m_xs*gen_m_xs*gen_m_xs+0.986125*gen_m_xs*gen_m_xs-4.19608*gen_m_xs+3.03569) ) return 1; // ee
      else if( gen_mode_lepton==0 && rnd > 1.31829*exp(-0.132990*gen_m_xs*gen_m_xs*gen_m_xs*gen_m_xs+0.300994*gen_m_xs*gen_m_xs*gen_m_xs+1.00374*gen_m_xs*gen_m_xs-4.24379*gen_m_xs+3.04577  ) ) return 1; // mm
    }
    //*/
   
    Gen_dist->column( "Xs_id",      gen_xs_id    );
    Gen_dist->column( "Xs_m",       gen_m_xs     );
    Gen_dist->column( "Xsndc",      nchild_xs    ); // the numbeor of children directly produced from Xs
    
    Gen_dist->column( "n_total",    n_total      );
    Gen_dist->column( "n_pi",       n_charged_pi );
    Gen_dist->column( "n_pi0",      n_neutral_pi );
    Gen_dist->column( "n_k",        n_charged_k  );
    Gen_dist->column( "n_ks",       n_ks         );
    Gen_dist->column( "n_kl",       n_kl         );
    Gen_dist->column( "n_gamma",    n_gamma      );
    Gen_dist->column( "n_proton",   n_proton     );
    Gen_dist->column( "n_neutron",  n_neutron    );
    Gen_dist->column( "n_electron", n_electron   );
    Gen_dist->column( "n_muon",     n_muon       );
    Gen_dist->column( "n_rest",     n_rest       );
    
    if( flag_mode == 1 || flag_mode == 9999 ) Gen_dist->dumpData();

    return 0;
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
