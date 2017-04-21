#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif
  
  void XSLL::Rec_B_ana(std::vector<Particle> b_list,
		       std::map<int, int>& child_id_map1, std::map<int, int>& child_id_map2,
		       std::vector<Particle>& trk_list, std::vector<Particle>& gamma_list,
		       std::vector<Particle>& ks_list,
		       BelleTuple* hist, int gen_b_decay_info[][30], const bool fl_message )
  {
    if( fl_message ) std::cout << "ANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANA" << std::endl;
    Gen_hepevt_Manager& genMgr = Gen_hepevt_Manager::get_manager();
    
    for(std::vector<Particle>::iterator b = b_list.begin();
	b != b_list.end();
	b++)
      {
	Particle& B  = *b;
	Particle& CC = B.child(0);
	Particle& Xs = B.child(1);
	
	UserInfo& info_B  = dynamic_cast<UserInfo&>( B.userInfo()  );
	UserInfo& info_CC = dynamic_cast<UserInfo&>( CC.userInfo() );
	UserInfo& info_Xs = dynamic_cast<UserInfo&>( Xs.userInfo() );
	
	int n_recon1    = child_id_map1.size();
	int n_recon1_sw = child_id_map1.size(); // including "switch"
	int n_recon2    = child_id_map2.size();
	int n_recon2_sw = child_id_map2.size(); // including "switch"
	
	if( fl_message ) std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl
				   << " # of gen_children(n_recon1) = " << n_recon1
				   << " # of gen_children(n_recon2) = " << n_recon2
				   << ", # of recB_children = "         << CC.nChildren() + Xs.nChildren()
				   << std::endl;
	
	// [ EVENT ]
	double exprunNo = expNo*10000+runNo;
	hist->column( "exprun",    exprunNo );
	hist->column( "event",     evtNo    );
	// [ MODE ]
	int rec_mode_xs     = info_Xs.rec_mode();
	int rec_mode_lepton = info_CC.rec_mode();
	int n_neutral_pi    = int( rec_mode_xs/1000 );
	int n_charged_pi    = int( (rec_mode_xs-1000*n_neutral_pi)/100 );
	int n_Ks            = int( (rec_mode_xs-1000*n_neutral_pi-100*n_charged_pi)/10 );
	int n_charged_k     =       rec_mode_xs-1000*n_neutral_pi-100*n_charged_pi-10*n_Ks;
	
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// which B is fake-B
	int ntrk_B1=0;
	int ntrk_B2=0;
	int ntrk_lep=0;
	int ntrk_K=0;
	int ntrk_exceptpi0=0;
	if( bb == 1 ){
	  // leptons
	  if( which_B(CC.child(0).genHepevt(), gen_b_decay_info[0][0]) == 1 ) ntrk_B1++;
	  else ntrk_B2++;
	  
	  if( which_B(CC.child(1).genHepevt(), gen_b_decay_info[0][0]) == 1 ) ntrk_B1++;
	  else ntrk_B2++;
	  if( ntrk_B1 > ntrk_B2 ) ntrk_lep = 1;
	  else if( ntrk_B1 < ntrk_B2 ) ntrk_lep = 2;
	  
	  // K
	  if( Xs.child(0).genHepevt() ){
	    if( which_B(Xs.child(0).genHepevt(), gen_b_decay_info[0][0]) == 1 ) ntrk_B1++, ntrk_K=1;
	    else ntrk_B2++, ntrk_K=2;
	  }
	  
	  // charged pi
	  if( n_charged_pi > 0 ){
	    if( which_B(Xs.child(1).genHepevt(), gen_b_decay_info[0][0]) == 1 ) ntrk_B1++;
	    else ntrk_B2++;
	  }
	  if( n_charged_pi > 1 ){
	    if( which_B(Xs.child(2).genHepevt(), gen_b_decay_info[0][0]) == 1 ) ntrk_B1++;
	    else ntrk_B2++;
	  }
	  if( n_charged_pi > 2 ){
	    if( which_B(Xs.child(3).genHepevt(), gen_b_decay_info[0][0]) == 1 ) ntrk_B1++;
	    else ntrk_B2++;
	  }
	  if( n_charged_pi > 3 ){
	    if( which_B(Xs.child(4).genHepevt(), gen_b_decay_info[0][0]) == 1 ) ntrk_B1++;
	    else ntrk_B2++;
	  }
	  if( ntrk_B1 > ntrk_B2 ) ntrk_exceptpi0 = 1;
	  else if( ntrk_B1 < ntrk_B2 ) ntrk_exceptpi0 = 2;
	  
	  // neutral pi
	  if( n_neutral_pi > 0 && Xs.child(Xs.nChildren()-1).genHepevt() ){
	    if( which_B(Xs.child(Xs.nChildren()-1).genHepevt(), gen_b_decay_info[0][0]) == 1 ) ntrk_B1++;
	    else ntrk_B2++;
	  }
	  
	  if( fl_message ) std::cout << " ====================================================================" << std::endl
				     << "# of used tracks are " << ntrk_B1  << " (B1) and  " << ntrk_B2 << " (B2)" << std::endl
				     << "lep : "          << ntrk_lep
				     << ", K : "          << ntrk_K
				     << ", except pi0 : " << ntrk_exceptpi0
				     << std::endl;
	  
	  // Judgement B
	  if(      ntrk_B1 > ntrk_B2 ) sigb_id = 1;              // 1. # of tracks and pi0
	  else if( ntrk_B1 < ntrk_B2 ) sigb_id = 2;
	  else if( ntrk_lep          ) sigb_id = ntrk_lep;       // 2. # of lepton-tracks
	  else if( ntrk_K            ) sigb_id = ntrk_K;         // 3. # of K-tracks
	  else if( ntrk_exceptpi0    ) sigb_id = ntrk_exceptpi0; // 4. # of tracks except for pi0
	  else                      sigb_id = 1;                                   // 5. unknown
	  if( fl_message ) std::cout << " ==> Fake-B is " << sigb_id << std::endl
				     << " ====================================================================" << std::endl;
	  // Event Information
	  if( sigb_id==1 ){ // Fake-B is B1
	    hist->column( "gb1_semi",   gen_b_decay_info[0][ 1]); // semileptonic Fake-B  decay ?
	    hist->column( "gb2_semi",   gen_b_decay_info[1][ 1]); // semileptonic Other-B decay ?
	    hist->column( "gb1nd",      gen_b_decay_info[0][ 3]); // # of D particles from Fake-B 
	    hist->column( "gb2nd",      gen_b_decay_info[1][ 3]); // # of D particles from Other-B
	    hist->column( "gb1d1_semi", gen_b_decay_info[0][ 5]); // semileptonic 1st D decay from Fake-B ?
	    hist->column( "gb1d2_semi", gen_b_decay_info[0][ 8]); // semileptonic 2nd D decay from Fake-B ?
	    hist->column( "gb2d1_semi", gen_b_decay_info[1][ 5]); // semileptonic 1st D decay from Other-B ?
	    hist->column( "gb2d2_semi", gen_b_decay_info[1][ 8]); // semileptonic 2nd D decay from Other-B ?
	    hist->column( "gb1_cc",     gen_b_decay_info[0][10]); // Charmonium LUND code from Fake-B (if not cc, 0)
	    hist->column( "gb2_cc",     gen_b_decay_info[1][10]); // Charmonium LUND code from Fake-B (if not cc, 0)
	  }else{ // Fake-B is B2
	    hist->column( "gb1_semi",   gen_b_decay_info[1][ 1]); // semileptonic Fake-B  decay ?
	    hist->column( "gb2_semi",   gen_b_decay_info[0][ 1]); // semileptonic Other-B decay ?
	    hist->column( "gb1nd",      gen_b_decay_info[1][ 3]); // # of D particles from Fake-B 
	    hist->column( "gb2nd",      gen_b_decay_info[0][ 3]); // # of D particles from Other-B
	    hist->column( "gb1d1_semi", gen_b_decay_info[1][ 5]); // semileptonic 1st D decay from Fake-B ?
	    hist->column( "gb1d2_semi", gen_b_decay_info[1][ 8]); // semileptonic 2nd D decay from Fake-B ?
	    hist->column( "gb2d1_semi", gen_b_decay_info[0][ 5]); // semileptonic 1st D decay from Other-B ?
	    hist->column( "gb2d2_semi", gen_b_decay_info[0][ 8]); // semileptonic 2nd D decay from Other-B ?
	    hist->column( "gb1_cc",     gen_b_decay_info[1][10]); // Charmonium LUND code from Fake-B (if not cc, 0)
	    hist->column( "gb2_cc",     gen_b_decay_info[0][10]); // Charmonium LUND code from Fake-B (if not cc, 0)
	  }
	}else{ // for evtgen-{uds,charm}
	    hist->column( "gb1_semi",   gen_b_decay_info[0][ 1]); // semileptonic Fake-B  decay ?
	    hist->column( "gb2_semi",   gen_b_decay_info[1][ 1]); // semileptonic Other-B decay ?
	    hist->column( "gb1nd",      gen_b_decay_info[0][ 3]); // # of D particles from Fake-B 
	    hist->column( "gb2nd",      gen_b_decay_info[1][ 3]); // # of D particles from Other-B
	    hist->column( "gb1d1_semi", gen_b_decay_info[0][ 5]); // semileptonic 1st D decay from Fake-B ?
	    hist->column( "gb1d2_semi", gen_b_decay_info[0][ 8]); // semileptonic 2nd D decay from Fake-B ?
	    hist->column( "gb2d1_semi", gen_b_decay_info[1][ 5]); // semileptonic 1st D decay from Other-B ?
	    hist->column( "gb2d2_semi", gen_b_decay_info[1][ 8]); // semileptonic 2nd D decay from Other-B ?
	    hist->column( "gb1_cc",     gen_b_decay_info[0][10]); // Charmonium LUND code from Fake-B (if not cc, 0)
	    hist->column( "gb2_cc",     gen_b_decay_info[1][10]); // Charmonium LUND code from Fake-B (if not cc, 0)
	}
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
	if( sigb_id==1 ){
	  hist->column( "gm_bg1", gen_mode_bg1  );
	  hist->column( "gm_bg2", gen_mode_bg2  );
	  hist->column( "gm_B1",  gen_mode_B1   );
	  hist->column( "gm_B2",  gen_mode_B2   );
	  hist->column( "gm_nu1", gen_mode_nu1  );
	  hist->column( "gm_nu2", gen_mode_nu2  );
	  hist->column( "gm_l1",  gen_mode_lepton1 );
	  hist->column( "gm_l2",  gen_mode_lepton2 );
	}else{
	  hist->column( "gm_bg1", gen_mode_bg2  );
	  hist->column( "gm_bg2", gen_mode_bg1  );
	  hist->column( "gm_B1",  gen_mode_B2   );
	  hist->column( "gm_B2",  gen_mode_B1   );
	  hist->column( "gm_nu1", gen_mode_nu2  );
	  hist->column( "gm_nu2", gen_mode_nu1  );
	  hist->column( "gm_l1",  gen_mode_lepton2 );
	  hist->column( "gm_l2",  gen_mode_lepton1 );
	}
	hist->column( "gm_m_xs",    2 );
	hist->column( "gm_fl_xs",  -1 );

	hist->column( "rm_xs",  rec_mode_xs     );
	hist->column( "rm_l",   rec_mode_lepton );

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
	// [ B ]
	hist->column( "b_m",       B.mass()   );
	hist->column( "blund",     B.lund()   );
	hist->column( "bp",        B.p3().mag()              );
	hist->column( "bpt",       B.p().perp()              );
	hist->column( "bc",        B.p().cosTheta()          );
	hist->column( "bpcm",      info_B.Vcm().vect().mag() );
	hist->column( "bptcm",     info_B.Vcm().perp()       );
	hist->column( "bccm",      info_B.Vcm().cosTheta()   );

	hist->column( "Mbc",       info_B.Mbc() );
	hist->column( "dE",        info_B.dE()  );
	int genbfl = 0;
	if( sigb_id ){
	  if( Gen_hepevt( genMgr(Panther_ID(gen_b_decay_info[sigb_id-1][0])) ).idhep() == antiB0_LUND
	      || Gen_hepevt( genMgr(Panther_ID(gen_b_decay_info[sigb_id-1][0])) ).idhep() == Bminus_LUND ) genbfl = 1;
	  else if( Gen_hepevt( genMgr(Panther_ID(gen_b_decay_info[sigb_id-1][0])) ).idhep() == B0_LUND
		   || Gen_hepevt( genMgr(Panther_ID(gen_b_decay_info[sigb_id-1][0])) ).idhep() == Bplus_LUND ) genbfl = -1;
	}
	  hist->column( "genbfl",    genbfl );

	int recbfl = 0;
	if( B.charge() ) recbfl = int(-B.charge());
	else if( Xs.child(0).charge() ) recbfl = int(-Xs.child(0).charge());
	else recbfl = 2; // unknown flaver
	hist->column( "recbfl", recbfl );
	// [ QQ ]
	double thrust_angle;
	double R2;
	qq_suppress( B, thrust_angle, R2 );
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	// for xsjpsi sigMC (dummy R2)
	//if( abs(Gen_hepevt( genMgr(Panther_ID(gen_b_decay_info[sigb_id-1][0])) ).idhep()) == B0_LUND ) R2 = 1;
	//else                                                                                           R2 = 0;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	hist->column( "thrust",    thrust_angle );
	hist->column( "R2",        R2           );


	

	// [ Xs ]
	hist->column( "xs_m", Xs.mass() );

	// [ Pseudo CC ]
	hist->column( "cc_m",       CC.mass()                  );
	hist->column( "cc_morg",    info_CC.m_org()            );
	hist->column( "ccp",        CC.p3().mag()              );
	hist->column( "ccpt",       CC.p().perp()              );
	hist->column( "ccc",        CC.p().cosTheta()          );
	hist->column( "ccpcm",      info_CC.Vcm().vect().mag() );
	hist->column( "ccptcm",     info_CC.Vcm().perp()       );
	hist->column( "ccccm",      info_CC.Vcm().cosTheta()   );
	/////////////////// added 20121030 for charmonium peaking B.G. study/veto ///////////////
	// Generated Bremsstrahlung Gamma
	if( CC.child(0).genHepevt() && CC.child(0).genHepevt().mother() &&
	    CC.child(1).genHepevt() && CC.child(1).genHepevt().mother() &&
	    CC.child(0).genHepevt().mother().get_ID() == CC.child(1).genHepevt().mother().get_ID()
	    ){
	  int truenchild = CC.child(0).genHepevt().mother().daLast()==0 ? 0 : CC.child(0).genHepevt().mother().daLast() - CC.child(0).genHepevt().mother().daFirst() + 1;
	  hist->column( "gm_ccng", truenchild-2 ); // # of generated bremsstrahlung gamma
	  double e_tot_gam = 0;
	  for( int i=0; i<truenchild; i++ ){
	    if( genMgr( Panther_ID( CC.child(0).genHepevt().mother().daFirst() + i ) ).idhep() == 22 ) e_tot_gam += genMgr( Panther_ID( CC.child(0).genHepevt().mother().daFirst() + i ) ).E();
	  }
	  hist->column( "gm_ccge", e_tot_gam );
	}else{
	  hist->column( "gm_ccng", -1 ); // if CC is not correct,
	  hist->column( "gm_ccge", -1 );
	}
	// Reconstructed Bremsstrahlung Gamma
	hist->column( "cc_ng",      CC.nChildren()-2 ); // # of added bremsstrahlung gamma
	if( CC.nChildren() > 2 ){
	  hist->column( "cc_g1e", CC.child(2).e() );
	  if( CC.child(0).genHepevt() && CC.child(0).genHepevt().mother() &&
	      CC.child(1).genHepevt() && CC.child(1).genHepevt().mother() &&
	      CC.child(2).genHepevt() && CC.child(2).genHepevt().mother() &&
	      CC.child(2).genHepevt().mother().get_ID() == CC.child(0).genHepevt().mother().get_ID() &&
	      CC.child(2).genHepevt().mother().get_ID() == CC.child(1).genHepevt().mother().get_ID()
	      ) hist->column( "cc_g1_self", 1 );
	  else  hist->column( "cc_g1_self", 0 );
	}else{
	  hist->column( "cc_g1e",     -1 );
	  hist->column( "cc_g1_self", -1 );
	}
	if( CC.nChildren() > 3 ){
	  hist->column( "cc_g2e", CC.child(3).e() );
	  if( CC.child(0).genHepevt() && CC.child(0).genHepevt().mother() &&
	      CC.child(1).genHepevt() && CC.child(1).genHepevt().mother() &&
	      CC.child(3).genHepevt() && CC.child(3).genHepevt().mother() &&
	      CC.child(3).genHepevt().mother().get_ID() == CC.child(0).genHepevt().mother().get_ID() &&
	      CC.child(3).genHepevt().mother().get_ID() == CC.child(1).genHepevt().mother().get_ID()
	      ) hist->column( "cc_g2_self", 1 );
	  else  hist->column( "cc_g2_self", 0 );
	}else{
	  hist->column( "cc_g2e",     -1 );
	  hist->column( "cc_g2_self", -1 );
	}
	/////////////////////////////////////////////////////////////////////////////////////////
	
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	// [ lepton ]
	Particle& lp        = CC.child(0);
	Particle& lm        = CC.child(1);
	UserInfo& info_lp   = dynamic_cast<UserInfo&>( lp.userInfo() );
	UserInfo& info_lm   = dynamic_cast<UserInfo&>( lm.userInfo() );
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// correction of LUND-code of Charmonium
	// psi(4040) : 9000443 <- -7776773
	// psi(4160) : 9010443 <- -7766773
	//if( gen_b_decay_info[0][10] == -7776773 ) gen_b_decay_info[0][10] == 9000443; // correction is done in search_daughter_CC(Util_Gen.cc)
	//if( gen_b_decay_info[1][10] == -7776773 ) gen_b_decay_info[1][10] == 9000443; // correction is done in search_daughter_CC(Util_Gen.cc)
	//if( gen_b_decay_info[0][10] == -7766773 ) gen_b_decay_info[0][10] == 9010443; // correction is done in search_daughter_CC(Util_Gen.cc)
	//if( gen_b_decay_info[1][10] == -7766773 ) gen_b_decay_info[1][10] == 9010443; // correction is done in search_daughter_CC(Util_Gen.cc)
	if( info_lp.motherid() == -7776773 ) info_lp.motherid( 9000443 );
	if( info_lm.motherid() == -7776773 ) info_lm.motherid( 9000443 );
	if( info_lp.motherid() == -7766773 ) info_lp.motherid( 9010443 );
	if( info_lm.motherid() == -7766773 ) info_lm.motherid( 9010443 );
		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
	mapping_delete   ( lp, child_id_map1, n_recon1,    0, "l+(B1)",     fl_message );
	mapping_delete   ( lm, child_id_map1, n_recon1,    0, "l-(B1)",     fl_message );
	mapping_delete_sw( lp, child_id_map1, n_recon1_sw, 0, "l+(B1)[sw]", fl_message );
	mapping_delete_sw( lm, child_id_map1, n_recon1_sw, 0, "l-(B1)[sw]", fl_message );
	mapping_delete   ( lp, child_id_map2, n_recon2,    0, "l+(B2)",     fl_message );
	mapping_delete   ( lm, child_id_map2, n_recon2,    0, "l-(B2)",     fl_message );
	mapping_delete_sw( lp, child_id_map2, n_recon2_sw, 0, "l+(B2)[sw]", fl_message );
	mapping_delete_sw( lm, child_id_map2, n_recon2_sw, 0, "l-(B2)[sw]", fl_message );

	if( sigb_id ){
	  if( which_B( lp.genHepevt(), gen_b_decay_info[sigb_id-1][0] ) > 0 ) hist->column( "lporg", 1 );
	  else  hist->column( "lporg", 0 );
	  if( which_B( lm.genHepevt(), gen_b_decay_info[sigb_id-1][0] ) > 0 ) hist->column( "lmorg", 1 );
	  else  hist->column( "lmorg", 0 );
	}
	
	hist->column( "lpself",   info_lp.self()     );
	hist->column( "lpselfID", info_lp.id()       );
	hist->column( "lpmoID",   info_lp.motherid() );
	hist->column( "lmself",   info_lm.self()     );
	hist->column( "lmselfID", info_lm.id()       );
	hist->column( "lmmoID",   info_lm.motherid() );

	// lepton origin
	if( abs(info_lp.motherid()) == B0_LUND || abs(info_lp.motherid()) == Bplus_LUND ){
	  hist->column( "lpgt", 1 );
	}else if( abs(info_lp.motherid()) == D0_LUND || abs(info_lp.motherid()) == Dplus_LUND || abs(info_lp.motherid()) == Dsplus_LUND ){
	  hist->column( "lpgt", 2 );	  
	}else if( info_lp.motherid() == JPsi_LUND       || info_lp.motherid() == Psi2S_LUND   || info_lp.motherid() == Psi3770_LUND
		  || info_lp.motherid() == Psi4040_LUND || info_lp.motherid() == Psi4160_LUND || info_lp.motherid() == Psi4415_LUND ){
	  hist->column( "lpgt", 3 );
	}else if( info_lp.motherid() == Gamma_LUND ){
	  hist->column( "lpgt", 4 );
	}else{
	  hist->column( "lpgt", 5 );
	}
	
	if( abs(info_lm.motherid()) == B0_LUND || abs(info_lm.motherid()) == Bplus_LUND ){
	  hist->column( "lmgt", 1 );
	}else if( abs(info_lm.motherid()) == D0_LUND || abs(info_lm.motherid()) == Dplus_LUND || abs(info_lm.motherid()) == Dsplus_LUND ){
	  hist->column( "lmgt", 2 );	  
	}else if( info_lm.motherid() == JPsi_LUND       || info_lm.motherid() == Psi2S_LUND   || info_lm.motherid() == Psi3770_LUND
		  || info_lm.motherid() == Psi4040_LUND || info_lm.motherid() == Psi4160_LUND || info_lm.motherid() == Psi4415_LUND ){
	  hist->column( "lmgt", 3 );
	}else if( info_lm.motherid() == Gamma_LUND ){
	  hist->column( "lmgt", 4 );
	}else{
	  hist->column( "lmgt", 5 );
	}

	// A_{FB}
	Hep3Vector dilep_boost = -CC.p().boostVector();
	HepLorentzVector lp_4V = lp.p();
	HepLorentzVector B_4V  = B.p();
	lp_4V.boost( dilep_boost ); //   l+  momentum at dilepton-rest-frame
	B_4V.boost ( dilep_boost ); // rec-B momentum at dilepton-rest-frame
	double coslp = cos( lp_4V.vect().angle(B_4V.vect()) );

	// modified at 20120821
	if( recbfl == 1 ) ;
	else if( recbfl == -1 ) coslp *= -1.0;

	
	// The definition of coslp is reversed at 20120411 <= wrong (modification is done in root code.)
	/*
	if     ( recbfl ==  1 ) coslp *= -1.0;
	else if( recbfl == -1 ) ;
	*/
	hist->column( "coslp", coslp );
	
	double drmax = -1; // dr(max) of charged kaon or pion
	double dzmax = -1; // dz(max) of charged kaon or pion
	hist->column( "dr_lp",      info_lp.dr()               );
	hist->column( "dr_lm",      info_lm.dr()               );
	hist->column( "dz_lp",      info_lp.dz()               );
	hist->column( "dz_lm",      info_lm.dz()               );

	hist->column( "epp",        info_lp.ptot_ee()          );
	hist->column( "emp",        info_lm.ptot_ee()          );
	
	//hist->column( "lpp",        lp.p3().mag()              );
	hist->column( "lppt",       lp.p().perp()              );
	hist->column( "lpc",        lp.p().cosTheta()          );
	hist->column( "lppcm",      info_lp.Vcm().vect().mag() );
	hist->column( "lpptcm",     info_lp.Vcm().perp()       );
	hist->column( "lpccm",      info_lp.Vcm().cosTheta()   );
	hist->column( "lpph",       lp.p().phi()               );
	hist->column( "lpphcm",     info_lp.Vcm().phi()        );
	//hist->column( "lmp",        lm.p3().mag()              );
	hist->column( "lmpt",       lm.p().perp()              );
	hist->column( "lmc",        lm.p().cosTheta()          );
	hist->column( "lmpcm",      info_lm.Vcm().vect().mag() );
	hist->column( "lmptcm",     info_lm.Vcm().perp()       );
	hist->column( "lmccm",      info_lm.Vcm().cosTheta()   );
	hist->column( "lmph",       lm.p().phi()               );
	hist->column( "lmphcm",     info_lm.Vcm().phi()        );

	hist->column( "lp_muid",    info_lp.muonLikelihood() );
	hist->column( "lm_muid",    info_lm.muonLikelihood() );
	hist->column( "lp_eid",     info_lp.eidProb()        );
	hist->column( "lm_eid",     info_lm.eidProb()        );
	if( rec_mode_lepton == 1 ){ // electron
	  hist->column( "lp_kid",     -1                     );
	  hist->column( "lm_kid",     -1                     );
	  hist->column( "mpp",        10                     );
	  hist->column( "mmp",        10                     );
	}else{ // muon
	  hist->column( "lp_kid",     info_lp.selKPI()       );
	  hist->column( "lm_kid",     info_lm.selKPI()       );
	  hist->column( "mpp",        info_lp.ptot_mm()      );
	  hist->column( "mmp",        info_lm.ptot_mm()      );
	}
	
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
	// [ kinematic fit for B ]
	kvertexfitter kf_b;
	addTrack2fit( kf_b,  lp );
	addTrack2fit( kf_b,  lm );
	addTube2fit(kf_b); // for IP tube constraint
	
	// [ kinematic fit for ll ]
	Vector3 vtx_pos_ll(0.,0.,0.);
	
	kvertexfitter kf_ll;
	addTrack2fit( kf_ll, lp );
	addTrack2fit( kf_ll, lm );
	addTube2fit(kf_ll); // for IP tube constraint
	
	unsigned err_ll = kf_ll.fit();
	
	if( err_ll==0 ){ // success.
	  hist->column( "kflcl",  kf_ll.cl()    );
	  hist->column( "kflchi", kf_ll.chisq() );
	  hist->column( "kfldgf", kf_ll.dgf()   );
	  vtx_pos_ll.setX( kf_ll.vertex().x() );
	  vtx_pos_ll.setY( kf_ll.vertex().y() );
	  vtx_pos_ll.setZ( kf_ll.vertex().z() );
	}else{ // false.
	  hist->column( "kflcl",  -1  );
	  hist->column( "kflchi", -1  );
	  hist->column( "kfldgf", 0.5 );
	  //std::cout << "false kvertexfitter : error code " << err_ll << std::endl;
	}
	
	// [ dzll at closest ]
	double new_dz[2];
	HepPoint3D pivot_vtx_ll( vtx_pos_ll.x(), vtx_pos_ll.y(), vtx_pos_ll.z() );
	for( int ii=0; ii<2; ii++ ){
	  Mdst_trk_fit &trkfit_lep = CC.child(ii).mdstCharged().trk().mhyp( abs(CC.child(ii).lund()) == Electron_LUND ? 0 : 1 ); // multiple mass hypotheses(e:0, mu:1)
	  //save old helix
	  const HepPoint3D oldpivot( trkfit_lep.pivot_x(),
				     trkfit_lep.pivot_y(),
				     trkfit_lep.pivot_z() );
	  HepVector  oldhelix(5);
	  for( int i=0; i<5; i++ ) oldhelix[i] = trkfit_lep.helix(i);
	  HepSymMatrix oldhelix_err(5,0);
	  for( int i=0; i<5; i++ ) 
	    for( int j=0; j<=i; j++ )
	      oldhelix_err[i][j] = trkfit_lep.error(i*(i+1)/2+j);
	  //printf("oldhelix1   = %f\n", trkfit_lep.helix(3));
	  //printf("oldhelix2   = %f\n", oldhelix[3]);
	  
	  Helix newhelix( oldpivot, oldhelix, oldhelix_err );  //copy to new helix 
	  
	  newhelix.pivot( pivot_vtx_ll ); //move to new Helix by pivot
	  //printf("newhelix    = %f\n", newhelix.dz());
	  new_dz[ii]=newhelix.dz();
	}
	double dzll   = lp.x().z()-lm.x().z();
	double dzll3D = new_dz[0] - new_dz[1];
	hist->column( "dzll",   abs(dzll)   );
	hist->column( "dzll3d", abs(dzll3D) );
	//printf("dzll3D=%f, dz0=%f,dz1=%f\n",dzll3D,new_dz[0],new_dz[1]);
	//printf("dzll  =%f, \n",dzll );

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
	// [ charged K ]
	if( n_charged_k > 0 ){
	  Particle& chargedK       = Xs.child(0);
	  UserInfo& info_chargedK  = dynamic_cast<UserInfo&>( chargedK.userInfo()  );
	  mapping_delete   ( chargedK, child_id_map1, n_recon1,    0, "charged K(B1)",     fl_message );
	  mapping_delete_sw( chargedK, child_id_map1, n_recon1_sw, 0, "charged K(B1)[sw]", fl_message );
	  mapping_delete   ( chargedK, child_id_map2, n_recon2,    0, "charged K(B2)",     fl_message );
	  mapping_delete_sw( chargedK, child_id_map2, n_recon2_sw, 0, "charged K(B2)[sw]", fl_message );
	  hist->column( "kchg",     chargedK.charge()                );
	  hist->column( "k_kid",    info_chargedK.selKPI()           );
	  hist->column( "k_eid",    info_chargedK.eidProb()          );
	  hist->column( "k_muid",   info_chargedK.muonLikelihood()   );
	  hist->column( "k_ep",     info_chargedK.ptot_ee()          );
	  hist->column( "k_mp",     info_chargedK.ptot_mm()          );
	  hist->column( "kp",       chargedK.p3().mag()              );
	  hist->column( "kpt",      chargedK.p().perp()              );
	  hist->column( "kc",       chargedK.p().cosTheta()          );
	  hist->column( "kpcm",     info_chargedK.Vcm().vect().mag() );
	  hist->column( "kptcm",    info_chargedK.Vcm().perp()       );
	  hist->column( "kccm",     info_chargedK.Vcm().cosTheta()   );
	  hist->column( "kself",    info_chargedK.self()             );
	  hist->column( "kselfID",  info_chargedK.id()               );
	  hist->column( "kmoID",    info_chargedK.motherid()         );
	  hist->column( "kph",      chargedK.p().phi()               );
	  hist->column( "kphcm",    info_chargedK.Vcm().phi()        );
	  if( sigb_id && which_B( chargedK.genHepevt(), gen_b_decay_info[sigb_id-1][0] ) > 0 ) hist->column( "korg", 1 );
	  else hist->column( "korg", 0 );
	  if( drmax < info_chargedK.dr() ) drmax = info_chargedK.dr();
	  if( dzmax < info_chargedK.dz() ) dzmax = info_chargedK.dz();
	  addTrack2fit( kf_b, chargedK );
	}else{
	  hist->column( "k_kid",    2 );
	  hist->column( "k_eid",   -1 );
	  hist->column( "k_muid",  -1 );
	  hist->column( "k_ep",   -10 );
	  hist->column( "k_mp",   -10 );
	  hist->column( "kselfID",  0 );
	  hist->column( "kmoID",    0 );
	  hist->column( "kph",     10 );
	  hist->column( "kphcm",   10 );
	}
	// [ Ks ]
	if( n_Ks > 0 ){
	  Particle& Ks          = Xs.child(0);
	  UserInfo& info_Ks     = dynamic_cast<UserInfo&>( Ks.userInfo()           );
	  UserInfo& info_Ks_pi1 = dynamic_cast<UserInfo&>( Ks.child(0).userInfo()  );
	  UserInfo& info_Ks_pi2 = dynamic_cast<UserInfo&>( Ks.child(1).userInfo()  );
	  mapping_delete   ( Ks, child_id_map1, n_recon1,    0, "Ks(B1)",     fl_message );
	  mapping_delete_sw( Ks, child_id_map1, n_recon1_sw, 0, "Ks(B1)[sw]", fl_message );
	  mapping_delete   ( Ks, child_id_map2, n_recon2,    0, "Ks(B2)",     fl_message );
	  mapping_delete_sw( Ks, child_id_map2, n_recon2_sw, 0, "Ks(B2)[sw]", fl_message );
	  hist->column( "ks_m",     Ks.mass()            );
	  hist->column( "kchg",     Ks.charge()          );
	  hist->column( "kspi1id",  info_Ks_pi1.selKPI() );
	  hist->column( "kspi2id",  info_Ks_pi2.selKPI() );
	  hist->column( "kp",       Ks.p3().mag()              );
	  hist->column( "kpt",      Ks.p().perp()              );
	  hist->column( "kc",       Ks.p().cosTheta()          );
	  hist->column( "kpcm",     info_Ks.Vcm().vect().mag() );
	  hist->column( "kptcm",    info_Ks.Vcm().perp()       );
	  hist->column( "kccm",     info_Ks.Vcm().cosTheta()   );
	  hist->column( "kself",    info_Ks.self()             );
	  if( Ks.genHepevt() ){
	    if( which_B( Ks.genHepevt(), gen_b_decay_info[sigb_id-1][0] ) > 0 ) hist->column( "korg", 1 );
	    else  hist->column( "korg", 0 );
	  }else{
	    hist->column( "korg", -1 );
	  }
	}else{
	  hist->column( "ks_m",     -10 );
	  hist->column( "kspi1id",  -1  );
	  hist->column( "kspi2id",  -1  );
	}

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	// [ 1st charged pi ]
	if( n_charged_pi > 0 ){
	  Particle& Pi1      = Xs.child(1);
	  UserInfo& info_Pi1 = dynamic_cast<UserInfo&>( Pi1.userInfo()  );
	  mapping_delete   ( Pi1, child_id_map1, n_recon1,    0, "1st charged pi(B1)    ", fl_message );
	  mapping_delete_sw( Pi1, child_id_map1, n_recon1_sw, 0, "1st charged pi(B1)[sw]", fl_message );
	  mapping_delete   ( Pi1, child_id_map2, n_recon2,    0, "1st charged pi(B2)",     fl_message );
	  mapping_delete_sw( Pi1, child_id_map2, n_recon2_sw, 0, "1st charged pi(B2)[sw]", fl_message );
	  hist->column( "pi1_kid",     info_Pi1.selKPI()           );
	  hist->column( "pi1_eid",     info_Pi1.eidProb()          );
	  hist->column( "pi1_muid",    info_Pi1.muonLikelihood()   );
	  hist->column( "pi1_ep",      info_Pi1.ptot_ee()          );
	  hist->column( "pi1_mp",      info_Pi1.ptot_mm()          );
	  hist->column( "pi1p",        Pi1.p3().mag()              );
	  hist->column( "pi1pt",       Pi1.p().perp()              );
	  hist->column( "pi1c",        Pi1.p().cosTheta()          );
	  hist->column( "pi1pcm",      info_Pi1.Vcm().vect().mag() );
	  hist->column( "pi1ptcm",     info_Pi1.Vcm().perp()       );
	  hist->column( "pi1ccm",      info_Pi1.Vcm().cosTheta()   );
	  hist->column( "pi1chg",      Pi1.charge()                );
	  hist->column( "pi1self",     info_Pi1.self()             );
	  hist->column( "pi1selfID",   info_Pi1.id()               );
	  hist->column( "pi1moID",     info_Pi1.motherid()         );
	  hist->column( "pi1ph",       Pi1.p().phi()               );
	  hist->column( "pi1phcm",     info_Pi1.Vcm().phi()        );
	  /*
	  std::cout << "[check] " << std::endl
		    << Pi1.p() << std::endl
		    << " P  = " << Pi1.p3().mag()     << std::endl
		    << "Pt  = " << Pi1.p().perp()     << std::endl
		    << "cos = " << Pi1.p().cosTheta() << std::endl
		    << "phi = " << Pi1.p().phi()      << std::endl
		    << " Px = " << Pi1.p3().mag()*sqrt(1-Pi1.p().cosTheta()*Pi1.p().cosTheta())*cos(Pi1.p().phi()) << std::endl
		    << " Py = " << Pi1.p3().mag()*sqrt(1-Pi1.p().cosTheta()*Pi1.p().cosTheta())*sin(Pi1.p().phi()) << std::endl
		    << " Pz = " << Pi1.p3().mag()*Pi1.p().cosTheta() << std::endl
		    << std::endl;
	  */
	  if( sigb_id && which_B( Pi1.genHepevt(), gen_b_decay_info[sigb_id-1][0] ) > 0 ) hist->column( "pi1org", 1 );
	  else hist->column( "pi1org", 0 );
	  hist->column( "pi1trk",      info_Pi1.trk()              );
	  //hist->column( "pi1cdcr",     Pi1.mdstCharged().trk().mhyp(2).nhits(0) );
	  //hist->column( "pi1cdcz",     Pi1.mdstCharged().trk().mhyp(2).nhits(1) );
	  hist->column( "pi1svdr",     Pi1.mdstCharged().trk().mhyp(2).nhits(3) );
	  hist->column( "pi1svdz",     Pi1.mdstCharged().trk().mhyp(2).nhits(4) );
	  if( drmax < info_Pi1.dr() ) drmax = info_Pi1.dr();
	  if( dzmax < info_Pi1.dz() ) dzmax = info_Pi1.dz();
	  addTrack2fit( kf_b, Pi1 );
	}else{
	  hist->column( "pi1_kid",    -1 );
	  hist->column( "pi1_eid",    -1 );
	  hist->column( "pi1_muid",   -1 );
	  hist->column( "pi1_ep",    -10 );
	  hist->column( "pi1_mp",    -10 );
	  hist->column( "pi1p",       10 );
	  hist->column( "pi1pt",      10 );
	  hist->column( "pi1c",       10 );
	  hist->column( "pi1pcm",     10 );
	  hist->column( "pi1ptcm",    10 );
	  hist->column( "pi1ccm",     10 );
	  hist->column( "pi1chg",      0 );
	  hist->column( "pi1self",    10 );
	  hist->column( "pi1selfID",   0 );
	  hist->column( "pi1moID",     0 );
	  hist->column( "pi1ph",      10 );
	  hist->column( "pi1phcm",    10 );
	  hist->column( "pi1org",     -1 );
	  hist->column( "pi1trk",     10 );
	  //hist->column( "pi1cdcr",   200 );
	  //hist->column( "pi1cdcz",   200 );
	  hist->column( "pi1svdr",   200 );
	  hist->column( "pi1svdz",   200 );
	}

	// [ 2nd charged pi ]
	if( n_charged_pi > 1 ){
	  Particle& Pi2      = Xs.child(2);
	  UserInfo& info_Pi2 = dynamic_cast<UserInfo&>( Pi2.userInfo()  );
	  mapping_delete   ( Pi2, child_id_map1, n_recon1,    0, "2nd charged pi(B1)",     fl_message );
	  mapping_delete_sw( Pi2, child_id_map1, n_recon1_sw, 0, "2nd charged pi(B1)[sw]", fl_message );
	  mapping_delete   ( Pi2, child_id_map2, n_recon2,    0, "2nd charged pi(B2)",     fl_message );
	  mapping_delete_sw( Pi2, child_id_map2, n_recon2_sw, 0, "2nd charged pi(B2)[sw]", fl_message );
	  hist->column( "pi2_kid",     info_Pi2.selKPI()           );
	  hist->column( "pi2_eid",     info_Pi2.eidProb()          );
	  hist->column( "pi2_muid",    info_Pi2.muonLikelihood()   );
	  hist->column( "pi2_ep",      info_Pi2.ptot_ee()          );
	  hist->column( "pi2_mp",      info_Pi2.ptot_mm()          );
	  hist->column( "pi2p",        Pi2.p3().mag()              );
	  hist->column( "pi2pt",       Pi2.p().perp()              );
	  hist->column( "pi2c",        Pi2.p().cosTheta()          );
	  hist->column( "pi2pcm",      info_Pi2.Vcm().vect().mag() );
	  hist->column( "pi2ptcm",     info_Pi2.Vcm().perp()       );
	  hist->column( "pi2ccm",      info_Pi2.Vcm().cosTheta()   );
	  hist->column( "pi2chg",      Pi2.charge()                );
	  hist->column( "pi2self",     info_Pi2.self()             );
	  hist->column( "pi2selfID",   info_Pi2.id()               );
	  hist->column( "pi2moID",     info_Pi2.motherid()         );
	  hist->column( "pi2ph",       Pi2.p().phi()               );
	  hist->column( "pi2phcm",     info_Pi2.Vcm().phi()        );
	  if( sigb_id && which_B( Pi2.genHepevt(), gen_b_decay_info[sigb_id-1][0] ) > 0 ) hist->column( "pi2org", 1 );
	  else hist->column( "pi2org", 0 );
	  hist->column( "pi2trk",      info_Pi2.trk()              );
	  //hist->column( "pi2cdcr",     Pi2.mdstCharged().trk().mhyp(2).nhits(0) );
	  //hist->column( "pi2cdcz",     Pi2.mdstCharged().trk().mhyp(2).nhits(1) );
	  hist->column( "pi2svdr",     Pi2.mdstCharged().trk().mhyp(2).nhits(3) );
	  hist->column( "pi2svdz",     Pi2.mdstCharged().trk().mhyp(2).nhits(4) );
	  if( drmax < info_Pi2.dr() ) drmax = info_Pi2.dr();
	  if( dzmax < info_Pi2.dz() ) dzmax = info_Pi2.dz();
	  addTrack2fit( kf_b, Pi2 );
	}else{
	  hist->column( "pi2_kid",   -1  );
	  hist->column( "pi2_eid",   -1  );
	  hist->column( "pi2_muid",  -1  );
	  hist->column( "pi2_ep",    -10 );
	  hist->column( "pi2_mp",    -10 );
	  hist->column( "pi2p",       10 );
	  hist->column( "pi2pt",      10 );
	  hist->column( "pi2c",       10 );
	  hist->column( "pi2pcm",     10 );
	  hist->column( "pi2ptcm",    10 );
	  hist->column( "pi2ccm",     10 );
	  hist->column( "pi2chg",      0 );
	  hist->column( "pi2self",    10 );
	  hist->column( "pi2selfID",   0 );
	  hist->column( "pi2moID",     0 );
	  hist->column( "pi2ph",      10 );
	  hist->column( "pi2phcm",    10 );
	  hist->column( "pi2org",     -1 );
	  hist->column( "pi2trk",     10 );
	  //hist->column( "pi2cdcr",   200 );
	  //hist->column( "pi2cdcz",   200 );
	  hist->column( "pi2svdr",   200 );
	  hist->column( "pi2svdz",   200 );
	}
		
	// [ 3rd charged pi ]
	if( n_charged_pi > 2 ){
	  Particle& Pi3      = Xs.child(3);
	  UserInfo& info_Pi3 = dynamic_cast<UserInfo&>( Pi3.userInfo()  );
	  mapping_delete   ( Pi3, child_id_map1, n_recon1,    0, "3rd charged pi(B1)",     fl_message );
	  mapping_delete_sw( Pi3, child_id_map1, n_recon1_sw, 0, "3rd charged pi(B1)[sw]", fl_message );
	  mapping_delete   ( Pi3, child_id_map2, n_recon2,    0, "3rd charged pi(B2)",     fl_message );
	  mapping_delete_sw( Pi3, child_id_map2, n_recon2_sw, 0, "3rd charged pi(B2)[sw]", fl_message );
	  hist->column( "pi3_kid",     info_Pi3.selKPI()           );
	  hist->column( "pi3_eid",     info_Pi3.eidProb()          );
	  hist->column( "pi3_muid",    info_Pi3.muonLikelihood()   );
	  hist->column( "pi3_ep",      info_Pi3.ptot_ee()          );
	  hist->column( "pi3_mp",      info_Pi3.ptot_mm()          );
	  hist->column( "pi3p",        Pi3.p3().mag()              );
	  hist->column( "pi3pt",       Pi3.p().perp()              );
	  hist->column( "pi3c",        Pi3.p().cosTheta()          );
	  hist->column( "pi3pcm",      info_Pi3.Vcm().vect().mag() );
	  hist->column( "pi3ptcm",     info_Pi3.Vcm().perp()       );
	  hist->column( "pi3ccm",      info_Pi3.Vcm().cosTheta()   );
	  hist->column( "pi3chg",      Pi3.charge()                );
	  hist->column( "pi3self",     info_Pi3.self()             );
	  hist->column( "pi3selfID",   info_Pi3.id()               );
	  hist->column( "pi3moID",     info_Pi3.motherid()         );
	  hist->column( "pi3ph",       Pi3.p().phi()               );
	  hist->column( "pi3phcm",     info_Pi3.Vcm().phi()        );
	  if( sigb_id && which_B( Pi3.genHepevt(), gen_b_decay_info[sigb_id-1][0] ) > 0 ) hist->column( "pi3org", 1 );
	  else hist->column( "pi3org", 0 );
	  hist->column( "pi3trk",      info_Pi3.trk()              );
	  //hist->column( "pi3cdcr",     Pi3.mdstCharged().trk().mhyp(2).nhits(0) );
	  //hist->column( "pi3cdcz",     Pi3.mdstCharged().trk().mhyp(2).nhits(1) );
	  hist->column( "pi3svdr",     Pi3.mdstCharged().trk().mhyp(2).nhits(3) );
	  hist->column( "pi3svdz",     Pi3.mdstCharged().trk().mhyp(2).nhits(4) );
	  if( drmax < info_Pi3.dr() ) drmax = info_Pi3.dr();
	  if( dzmax < info_Pi3.dz() ) dzmax = info_Pi3.dz();
	  addTrack2fit( kf_b, Pi3 );
	}else{
	  hist->column( "pi3_kid",   -1  );
	  hist->column( "pi3_eid",   -1  );
	  hist->column( "pi3_muid",  -1  );
	  hist->column( "pi3_ep",    -10 );
	  hist->column( "pi3_mp",    -10 );
	  hist->column( "pi3p",       10 );
	  hist->column( "pi3pt",      10 );
	  hist->column( "pi3c",       10 );
	  hist->column( "pi3pcm",     10 );
	  hist->column( "pi3ptcm",    10 );
	  hist->column( "pi3ccm",     10 );
	  hist->column( "pi3chg",      0 );
	  hist->column( "pi3self",    10 );
	  hist->column( "pi3selfID",   0 );
	  hist->column( "pi3moID",     0 );
	  hist->column( "pi3ph",      10 );
	  hist->column( "pi3phcm",    10 );
	  hist->column( "pi3org",     -1 );
	  hist->column( "pi3trk",     10 );
	  //hist->column( "pi3cdcr",   200 );
	  //hist->column( "pi3cdcz",   200 );
	  hist->column( "pi3svdr",   200 );
	  hist->column( "pi3svdz",   200 );
	}
	
	// [ 4th charged pi ]
	if( n_charged_pi > 3 ){
	  Particle& Pi4      = Xs.child(4);
	  UserInfo& info_Pi4 = dynamic_cast<UserInfo&>( Pi4.userInfo()  );
	  mapping_delete   ( Pi4, child_id_map1, n_recon1,    0, "4th charged pi(B1)",     fl_message );
	  mapping_delete_sw( Pi4, child_id_map1, n_recon1_sw, 0, "4th charged pi(B1)[sw]", fl_message );
	  mapping_delete   ( Pi4, child_id_map2, n_recon2,    0, "4th charged pi(B2)",     fl_message );
	  mapping_delete_sw( Pi4, child_id_map2, n_recon2_sw, 0, "4th charged pi(B2)[sw]", fl_message );
	  hist->column( "pi4_kid",     info_Pi4.selKPI()           );
	  hist->column( "pi4_eid",     info_Pi4.eidProb()          );
	  hist->column( "pi4_muid",    info_Pi4.muonLikelihood()   );
	  hist->column( "pi4_ep",      info_Pi4.ptot_ee()          );
	  hist->column( "pi4_mp",      info_Pi4.ptot_mm()          );
	  hist->column( "pi4p",        Pi4.p3().mag()              );
	  hist->column( "pi4pt",       Pi4.p().perp()              );
	  hist->column( "pi4c",        Pi4.p().cosTheta()          );
	  hist->column( "pi4pcm",      info_Pi4.Vcm().vect().mag() );
	  hist->column( "pi4ptcm",     info_Pi4.Vcm().perp()       );
	  hist->column( "pi4ccm",      info_Pi4.Vcm().cosTheta()   );
	  hist->column( "pi4chg",      Pi4.charge()                );
	  hist->column( "pi4self",     info_Pi4.self()             );
	  hist->column( "pi4selfID",   info_Pi4.id()               );
	  hist->column( "pi4moID",     info_Pi4.motherid()         );
	  hist->column( "pi4ph",       Pi4.p().phi()               );
	  hist->column( "pi4phcm",     info_Pi4.Vcm().phi()        );
	  if( sigb_id && which_B( Pi4.genHepevt(), gen_b_decay_info[sigb_id-1][0] ) > 0 ) hist->column( "pi4org", 1 );
	  else hist->column( "pi4org", 0 );
	  hist->column( "pi4trk",      info_Pi4.trk()              );
	  //hist->column( "pi4cdcr",     Pi4.mdstCharged().trk().mhyp(2).nhits(0) );
	  //hist->column( "pi4cdcz",     Pi4.mdstCharged().trk().mhyp(2).nhits(1) );
	  hist->column( "pi4svdr",     Pi4.mdstCharged().trk().mhyp(2).nhits(3) );
	  hist->column( "pi4svdz",     Pi4.mdstCharged().trk().mhyp(2).nhits(4) );
	  if( drmax < info_Pi4.dr() ) drmax = info_Pi4.dr();
	  if( dzmax < info_Pi4.dz() ) dzmax = info_Pi4.dz();
	  addTrack2fit( kf_b, Pi4 );
	}else{
	  hist->column( "pi4_kid",   -1  );
	  hist->column( "pi4_eid",   -1  );
	  hist->column( "pi4_muid",  -1  );
	  hist->column( "pi4_ep",    -10 );
	  hist->column( "pi4_mp",    -10 );
	  hist->column( "pi4p",       10 );
	  hist->column( "pi4pt",      10 );
	  hist->column( "pi4c",       10 );
	  hist->column( "pi4pcm",     10 );
	  hist->column( "pi4ptcm",    10 );
	  hist->column( "pi4ccm",     10 );
	  hist->column( "pi4chg",      0 );
	  hist->column( "pi4self",    10 );
	  hist->column( "pi4selfID",   0 );
	  hist->column( "pi4moID",     0 );
	  hist->column( "pi4ph",      10 );
	  hist->column( "pi4phcm",    10 );
	  hist->column( "pi4org",     -1 );
	  hist->column( "pi4trk",     10 );
	  //hist->column( "pi4cdcr",   200 );
	  //hist->column( "pi4cdcz",   200 );
	  hist->column( "pi4svdr",   200 );
	  hist->column( "pi4svdz",   200 );
	}
	
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
	
	// [ neutral pi ]
	if( n_neutral_pi > 0 ){
	  Particle& Pi0      = Xs.child( Xs.nChildren()-1 );
	  UserInfo& info_Pi0 = dynamic_cast<UserInfo&>( Pi0.userInfo() );
	  Particle& Pi0_gam1 = Pi0.child(0);
	  Particle& Pi0_gam2 = Pi0.child(1);
	  mapping_delete   ( Pi0, child_id_map1, n_recon1,    0, "pi0(B1)",     fl_message );
	  mapping_delete_sw( Pi0, child_id_map1, n_recon1_sw, 0, "pi0(B1)[sw]", fl_message );
	  mapping_delete   ( Pi0, child_id_map2, n_recon2,    0, "pi0(B2)",     fl_message );
	  mapping_delete_sw( Pi0, child_id_map2, n_recon2_sw, 0, "pi0(B2)[sw]", fl_message );
	  hist->column( "pi0self",  info_Pi0.self()     );
	  hist->column( "pi0_m",    (Pi0_gam1.p() + Pi0_gam2.p()).m() );
	  hist->column( "pi0e",     Pi0.e()             );
	  hist->column( "pi0gam1E", Pi0_gam1.p3().mag() );
	  hist->column( "pi0gam2E", Pi0_gam2.p3().mag() );
	  if( Pi0.genHepevt() ){
	    if( which_B( Pi0.genHepevt(), gen_b_decay_info[sigb_id-1][0] ) > 0 ) hist->column( "pi0org", 1 );
	    else  hist->column( "pi0org", 0 );
	  }else{
	    hist->column( "pi0org", -1 );
	  }
	  /////////////////// added 20121030 for charmonium peaking B.G. study/veto ///////////////
	  int fl_heg = 0; // which is higher energy gamma ? 1(Pi0_gam1), 2(Pi0_gam2)
	  if( Pi0_gam1.p3().mag() > Pi0_gam2.p3().mag() ) fl_heg = 1;
	  else                                            fl_heg = 2;
	  
	  int fl_gam1 = 0; // Is gamma(from pi0)'s mother same with dilepton's mother ? 
	  int fl_gam2 = 0;
	  if( Pi0_gam1.genHepevt() && Pi0_gam1.genHepevt().mother() && 
	      lp.genHepevt() && lp.genHepevt().mother() &&
	      lm.genHepevt() && lm.genHepevt().mother() &&
	      Pi0_gam1.genHepevt().mother().get_ID() == lp.genHepevt().mother().get_ID() &&
	      Pi0_gam1.genHepevt().mother().get_ID() == lm.genHepevt().mother().get_ID()
	      ) fl_gam1 = 1;
	  
	  if( Pi0_gam2.genHepevt() && Pi0_gam2.genHepevt().mother() &&
	      lp.genHepevt() && lp.genHepevt().mother() &&
	      lm.genHepevt() && lm.genHepevt().mother() &&
	      Pi0_gam2.genHepevt().mother().get_ID() == lp.genHepevt().mother().get_ID() &&
	      Pi0_gam2.genHepevt().mother().get_ID() == lm.genHepevt().mother().get_ID()
	      ) fl_gam2 = 1;

	  int gam1_mother = 0;
	  int gam2_mother = 0;
	  if( Pi0_gam1.genHepevt() && Pi0_gam1.genHepevt().mother() ) gam1_mother = Pi0_gam1.genHepevt().mother().idhep();
	  if( Pi0_gam2.genHepevt() && Pi0_gam2.genHepevt().mother() ) gam2_mother = Pi0_gam2.genHepevt().mother().idhep();

	  HepLorentzVector CC_4V         = CC.p();
	  HepLorentzVector CCorg_4V      = lp.p() + lm.p();
	  HepLorentzVector Pi0_gam1_4V   = Pi0.child(0).p();
	  HepLorentzVector Pi0_gam2_4V   = Pi0.child(1).p();
	  HepLorentzVector CC_gam1_4V    = CC_4V    + Pi0_gam1_4V;
	  HepLorentzVector CC_gam2_4V    = CC_4V    + Pi0_gam2_4V;
	  HepLorentzVector CCorg_gam1_4V = CCorg_4V + Pi0_gam1_4V;
	  HepLorentzVector CCorg_gam2_4V = CCorg_4V + Pi0_gam2_4V;
	  if( fl_heg==1 ){ // high energy = gam1
	    hist->column( "heg_self",   fl_gam1             );
	    hist->column( "leg_self",   fl_gam2             );
	    hist->column( "heg_moid",   gam1_mother         );
	    hist->column( "leg_moid",   gam2_mother         );
	    hist->column( "cc_mheg",    CC_gam1_4V.mag()    );
	    hist->column( "cc_mleg",    CC_gam2_4V.mag()    );
	    hist->column( "cc_morgheg", CCorg_gam1_4V.mag() );
	    hist->column( "cc_morgleg", CCorg_gam2_4V.mag() );
	  }else{ // high energy = gam2
	    hist->column( "heg_self",   fl_gam2             );
	    hist->column( "leg_self",   fl_gam1             );
	    hist->column( "heg_moid",   gam2_mother         );
	    hist->column( "leg_moid",   gam1_mother         );
	    hist->column( "cc_mheg",    CC_gam2_4V.mag()    );
	    hist->column( "cc_mleg",    CC_gam1_4V.mag()    );
	    hist->column( "cc_morgheg", CCorg_gam2_4V.mag() );
	    hist->column( "cc_morgleg", CCorg_gam1_4V.mag() );
	  }
	  /////////////////////////////////////////////////////////////////////////////////////////
	}else{
	  hist->column( "pi0self",   10 );
	  hist->column( "pi0_m",    -10 );
	  hist->column( "pi0e",     -10 );
	  hist->column( "pi0gam1E", -10 );
	  hist->column( "pi0gam2E", -10 );
	  hist->column( "pi0org",     0 );
	  
	  hist->column( "heg_self",   -1        );
	  hist->column( "leg_self",   -1        );
	  hist->column( "heg_moid",   0         );
	  hist->column( "leg_moid",   0         );
	  hist->column( "cc_mheg",    CC.mass() );
	  hist->column( "cc_mleg",    CC.mass() );
	  hist->column( "cc_morgheg", CC.mass() );
	  hist->column( "cc_morgleg", CC.mass() );
	}

	
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
	hist->column( "drmax", drmax );
	hist->column( "dzmax", dzmax );
	
	// [ kinematic fit for charged K and pi ]
	unsigned err_b = kf_b.fit();
	
	if( err_b==0 ){ // success.
	  hist->column( "kfbcl",  kf_b.cl()    );
	  hist->column( "kfbchi", kf_b.chisq() );
	  hist->column( "kfbdgf", kf_b.dgf()   );
	}else{ // false.
	  hist->column( "kfbcl",  -1  );
	  hist->column( "kfbchi", -1  );
	  hist->column( "kfbdgf", 0.5 );
	  //std::cout << "false kvertexfitter : error code " << er_kpir << std::endl;
	}

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
	// [ self ]
	if( sigb_id==1 ){
	  hist->column( "rest",     n_recon1        );
	  hist->column( "rest_sw",  n_recon1_sw     );
	  hist->column( "rest2",    n_recon2        );
	  hist->column( "rest2_sw", n_recon2_sw     );
	  hist->column( "dntrk",    ntrk_B1-ntrk_B2 );
	  hist->column( "ntrk",     ntrk_B1         );
	}else{
	  hist->column( "rest",     n_recon2    );
	  hist->column( "rest_sw",  n_recon2_sw );
	  hist->column( "rest2",    n_recon1        );
	  hist->column( "rest2_sw", n_recon1_sw     );
	  hist->column( "dntrk",    ntrk_B2-ntrk_B1 );
	  hist->column( "ntrk",     ntrk_B2         );
	}
	if( fl_message ) std::cout << "n_recon1 = "     << n_recon1     << ", "
				   << "n_recon1_sw = "  << n_recon1_sw  << ", "
				   << "n_recon2 = "     << n_recon2     << ", "
				   << "n_recon2_sw = "  << n_recon2_sw  << ", "
				   << std::endl;




	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	

	// [ QQ Suppression ]
	ksfwmoments_xsll km0(B, eb, cmboost, !true ); // modified for my xsll modules
	km0.usefinal(0);
	hist->column( "k0mm2",   km0.mm2()    );
	hist->column( "k0et",    km0.et()     );
	hist->column( "k0hso00", km0.Hso(0,0) );
	hist->column( "k0hso01", km0.Hso(0,1) );
	hist->column( "k0hso02", km0.Hso(0,2) );
	hist->column( "k0hso03", km0.Hso(0,3) );
	hist->column( "k0hso04", km0.Hso(0,4) );
	hist->column( "k0hso10", km0.Hso(1,0) );
	hist->column( "k0hso12", km0.Hso(1,2) );
	hist->column( "k0hso14", km0.Hso(1,4) );
	hist->column( "k0hso20", km0.Hso(2,0) );
	hist->column( "k0hso22", km0.Hso(2,2) );
	hist->column( "k0hso24", km0.Hso(2,4) );
	hist->column( "k0hoo0",  km0.Hoo(0)   );
	hist->column( "k0hoo1",  km0.Hoo(1)   );
	hist->column( "k0hoo2",  km0.Hoo(2)   );
	hist->column( "k0hoo3",  km0.Hoo(3)   );
	hist->column( "k0hoo4",  km0.Hoo(4)   );
	/*
	ksfwmoments_xsll km1(B, eb, cmboost, true ); // modified for my xsll modules
	km1.usefinal(0);
	hist->column( "k1mm2",   km1.mm2()    );
	hist->column( "k1et",    km1.et()     );
	hist->column( "k1hso00", km1.Hso(0,0) );
	hist->column( "k1hso01", km1.Hso(0,1) );
	hist->column( "k1hso02", km1.Hso(0,2) );
	hist->column( "k1hso03", km1.Hso(0,3) );
	hist->column( "k1hso04", km1.Hso(0,4) );
	hist->column( "k1hso10", km1.Hso(1,0) );
	hist->column( "k1hso12", km1.Hso(1,2) );
	hist->column( "k1hso14", km1.Hso(1,4) );
	hist->column( "k1hso20", km1.Hso(2,0) );
	hist->column( "k1hso22", km1.Hso(2,2) );
	hist->column( "k1hso24", km1.Hso(2,4) );
	hist->column( "k1hoo0",  km1.Hoo(0)   );
	hist->column( "k1hoo1",  km1.Hoo(1)   );
	hist->column( "k1hoo2",  km1.Hoo(2)   );
	hist->column( "k1hoo3",  km1.Hoo(3)   );
	hist->column( "k1hoo4",  km1.Hoo(4)   );
	*/
	make_Fmiss( trk_list, gamma_list, ks_list, b );
	
	hist->dumpData();
      }
    if( fl_message ) std::cout << "ANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANA" << std::endl;
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
