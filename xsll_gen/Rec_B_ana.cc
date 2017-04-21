#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif
  
  void XSLL::Rec_B_ana( std::vector<Particle> b_list,    std::map<int, int>& child_id_map,
			std::vector<Particle>& trk_list, std::vector<Particle>& gamma_list,
			std::vector<Particle>& ks_list,
			BelleTuple* hist, const bool fl_message )
  {
    //const double calib_vtx = 1.27;
    //const double calib_vtx = sqrt(1.27);
    const double calib_vtx = 1.0;
    if( fl_message ) std::cout << "ANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANA" << std::endl;
    
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
	
	int n_recon    = child_id_map.size();
	int n_recon_sw = child_id_map.size(); // including "switch"
	if( fl_message ) std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl
				   << " # of gen_children(n_recon) = " << n_recon
				   << ", # of recB_children = "        << CC.nChildren() + Xs.nChildren()
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

	hist->column( "gm_xs",     gen_mode_xs          );
	hist->column( "gm_xsid",   gen_xs_id            );
	hist->column( "gm_l",      gen_mode_lepton      );
	hist->column( "gm_bg",     gen_mode_bg          );
	hist->column( "gm_m_llg",  gen_m_llg            );
	hist->column( "gm_m_ll",   gen_m_ll             ); // added at 20120725
	hist->column( "gm_m_xs",   gen_m_xs             );
	hist->column( "gm_fl_xs",  gen_fl_xs            );
	hist->column( "gm_coslp",  gen_coslp            ); // added at 20120725 ( gm_coslp[gen] is right but, the sign of coslp[rec] is flip)
	hist->column( "rm_xs",     rec_mode_xs          );
	hist->column( "rm_l",      rec_mode_lepton      );

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
	hist->column( "thrust",    thrust_angle );
	hist->column( "R2",        R2           );

	// [ Xs ]
	hist->column( "xs_m", Xs.mass() );
	hist->column( "xsp",        Xs.p3().mag()              ); // added at 20120725
	hist->column( "xspt",       Xs.p().perp()              ); // added at 20120725
	hist->column( "xsc",        Xs.p().cosTheta()          ); // added at 20120725
	HepLorentzVector Xs_4Vcm = Xs.p();
	Xs_4Vcm.boost( cmboost );
	hist->column( "xspcm",      Xs_4Vcm.vect().mag() ); // added at 20120725
	hist->column( "xsptcm",     Xs_4Vcm.perp()       ); // added at 20120725
	hist->column( "xsccm",      Xs_4Vcm.cosTheta()   ); // added at 20120725

	// [ Pseudo CC ]
	hist->column( "cc_m",       CC.mass()                  );
	hist->column( "cc_morg",    info_CC.m_org()            );
	hist->column( "ccp",        CC.p3().mag()              );
	hist->column( "ccpt",       CC.p().perp()              );
	hist->column( "ccc",        CC.p().cosTheta()          );
	hist->column( "ccpcm",      info_CC.Vcm().vect().mag() );
	hist->column( "ccptcm",     info_CC.Vcm().perp()       );
	hist->column( "ccccm",      info_CC.Vcm().cosTheta()   );

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
	
	// [ lepton ]
	Particle& lp        = CC.child(0);
	Particle& lm        = CC.child(1);
	UserInfo& info_lp   = dynamic_cast<UserInfo&>( lp.userInfo() );
	UserInfo& info_lm   = dynamic_cast<UserInfo&>( lm.userInfo() );
	
	int q2self = n_recon;
	int lpself = n_recon;
	mapping_delete   ( lp, child_id_map, n_recon,    gen_mode_bg, "l+",     fl_message );
	lpself -= n_recon;
	int lmself = n_recon;
	mapping_delete   ( lm, child_id_map, n_recon,    gen_mode_bg, "l-",     fl_message );
	lmself -= n_recon;
	mapping_delete_sw( lp, child_id_map, n_recon_sw, gen_mode_bg, "l+[sw]", fl_message );
	mapping_delete_sw( lm, child_id_map, n_recon_sw, gen_mode_bg, "l-[sw]", fl_message );


	if( q2self-2 == n_recon ) q2self = 1;
	else q2self = 0;
	hist->column( "q2self", q2self );
	
	if( which_B( lp.genHepevt(), sigb_id ) > 0 ) hist->column( "lporg", 1 );
	else  hist->column( "lporg", 0 );
	if( which_B( lm.genHepevt(), sigb_id ) > 0 ) hist->column( "lmorg", 1 );
	else  hist->column( "lmorg", 0 );
	
	hist->column( "lpself",   lpself             );
	hist->column( "lpselfID", info_lp.id()       );
	hist->column( "lpmoID",   info_lp.motherid() );
	hist->column( "lmself",   lmself             );
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
	//hist->column( "lmp",        lm.p3().mag()              );
	hist->column( "lmpt",       lm.p().perp()              );
	hist->column( "lmc",        lm.p().cosTheta()          );
	hist->column( "lmpcm",      info_lm.Vcm().vect().mag() );
	hist->column( "lmptcm",     info_lm.Vcm().perp()       );
	hist->column( "lmccm",      info_lm.Vcm().cosTheta()   );

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

	kvertexfitter kf_b_calib; // calibrated vertex fit
	Particle lp_calib = lp;
	Particle lm_calib = lm;
	lp_calib.momentum().momentumPosition(lp.momentum().p(), lp.momentum().x(), calib_trk_err(lp, 1/calib_vtx)  );
	lm_calib.momentum().momentumPosition(lm.momentum().p(), lm.momentum().x(), calib_trk_err(lm, 1/calib_vtx)  );
	
	addTrack2fit( kf_b_calib,  lp_calib );
	addTrack2fit( kf_b_calib,  lm_calib );
	addTube2fit(kf_b_calib); // for IP tube constraint

	kvertexfitter kf_b_calib2; // calibrated vertex fit
	Particle lp_calib2 = lp;
	Particle lm_calib2 = lm;
	lp_calib2.momentum().momentumPosition(lp.momentum().p(), lp.momentum().x(), calib_trk_err2(lp, 1/calib_vtx)  );
	lm_calib2.momentum().momentumPosition(lm.momentum().p(), lm.momentum().x(), calib_trk_err2(lm, 1/calib_vtx)  );
	
	addTrack2fit( kf_b_calib2,  lp_calib2 );
	addTrack2fit( kf_b_calib2,  lm_calib2 );
	addTube2fit(kf_b_calib2); // for IP tube constraint

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
	
	int kself = n_recon;
	// [ charged K ]
	if( n_charged_k > 0 ){
	  Particle& chargedK       = Xs.child(0);
	  UserInfo& info_chargedK  = dynamic_cast<UserInfo&>( chargedK.userInfo()  );
	  mapping_delete   ( chargedK, child_id_map, n_recon,    gen_mode_bg, "charged K",     fl_message );
	  mapping_delete_sw( chargedK, child_id_map, n_recon_sw, gen_mode_bg, "charged K[sw]", fl_message );
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
	  hist->column( "kselfID",  info_chargedK.id()               );
	  hist->column( "kmoID",    info_chargedK.motherid()         );
	  if( which_B( chargedK.genHepevt(), sigb_id ) > 0 ) hist->column( "korg", 1 );
	  else  hist->column( "korg", 0 );
	  if( drmax < info_chargedK.dr() ) drmax = info_chargedK.dr();
	  if( dzmax < info_chargedK.dz() ) dzmax = info_chargedK.dz();
	  addTrack2fit( kf_b, chargedK );

	  Particle chargedK_calib = chargedK;
	  chargedK_calib.momentum().momentumPosition(chargedK.momentum().p(), chargedK.momentum().x(), calib_trk_err(chargedK, 1/calib_vtx) );
	  addTrack2fit( kf_b_calib, chargedK_calib );
	  Particle chargedK_calib2 = chargedK;
	  chargedK_calib2.momentum().momentumPosition(chargedK.momentum().p(), chargedK.momentum().x(), calib_trk_err2(chargedK, 1/calib_vtx) );
	  addTrack2fit( kf_b_calib2, chargedK_calib2 );
	}else{
	  hist->column( "k_kid",    2 );
	  hist->column( "k_eid",   -1 );
	  hist->column( "k_muid",  -1 );
	  hist->column( "k_ep",   -10 );
	  hist->column( "k_mp",   -10 );
	  hist->column( "kselfID",  0 );
	  hist->column( "kmoID",    0 );
	}
	// [ Ks ]
	if( n_Ks > 0 ){
	  Particle& Ks          = Xs.child(0);
	  UserInfo& info_Ks     = dynamic_cast<UserInfo&>( Ks.userInfo()           );
	  UserInfo& info_Ks_pi1 = dynamic_cast<UserInfo&>( Ks.child(0).userInfo()  );
	  UserInfo& info_Ks_pi2 = dynamic_cast<UserInfo&>( Ks.child(1).userInfo()  );
	  mapping_delete   ( Ks, child_id_map, n_recon,    gen_mode_bg, "Ks",     fl_message );
	  mapping_delete_sw( Ks, child_id_map, n_recon_sw, gen_mode_bg, "Ks[sw]", fl_message );
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
	  if( Ks.genHepevt() ){
	    if( which_B( Ks.genHepevt(), sigb_id ) > 0 ) hist->column( "korg", 1 );
	    else  hist->column( "korg", 0 );
	  }else{
	    hist->column( "korg", -1 );
	  }
	}else{
	  hist->column( "ks_m",     -10 );
	  hist->column( "kspi1id",  -1  );
	  hist->column( "kspi2id",  -1  );
	}

	kself -= n_recon;

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	// [ 1st charged pi ]
	if( n_charged_pi > 0 ){
	  Particle& Pi1      = Xs.child(1);
	  UserInfo& info_Pi1 = dynamic_cast<UserInfo&>( Pi1.userInfo()  );
	  int pi1self = n_recon;
	  mapping_delete   ( Pi1, child_id_map, n_recon,    gen_mode_bg, "1st charged pi",     fl_message );
	  mapping_delete_sw( Pi1, child_id_map, n_recon_sw, gen_mode_bg, "1st charged pi[sw]", fl_message );
	  pi1self -= n_recon;
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
	  hist->column( "pi1self",     pi1self                     );
	  hist->column( "pi1selfID",   info_Pi1.id()               );
	  hist->column( "pi1moID",     info_Pi1.motherid()         );
	  if( which_B( Pi1.genHepevt(), sigb_id ) > 0 ) hist->column( "pi1org", 1 );
	  else  hist->column( "pi1org", 0 );
	  hist->column( "pi1trk",      info_Pi1.trk()              );
	  //hist->column( "pi1cdcr",     Pi1.mdstCharged().trk().mhyp(2).nhits(0) );
	  //hist->column( "pi1cdcz",     Pi1.mdstCharged().trk().mhyp(2).nhits(1) );
	  hist->column( "pi1svdr",     Pi1.mdstCharged().trk().mhyp(2).nhits(3) );
	  hist->column( "pi1svdz",     Pi1.mdstCharged().trk().mhyp(2).nhits(4) );
	  if( drmax < info_Pi1.dr() ) drmax = info_Pi1.dr();
	  if( dzmax < info_Pi1.dz() ) dzmax = info_Pi1.dz();
	  addTrack2fit( kf_b, Pi1 );
	  Particle Pi1_calib = Pi1;
	  Pi1_calib.momentum().momentumPosition(Pi1.momentum().p(), Pi1.momentum().x(), calib_trk_err(Pi1, 1/calib_vtx)  );
	  addTrack2fit( kf_b_calib, Pi1_calib );
	  Particle Pi1_calib2 = Pi1;
	  Pi1_calib2.momentum().momentumPosition(Pi1.momentum().p(), Pi1.momentum().x(), calib_trk_err2(Pi1, 1/calib_vtx)  );
	  addTrack2fit( kf_b_calib2, Pi1_calib2 );
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
	  hist->column( "pi1self",    10 );
	  hist->column( "pi1chg",      0 );
	  hist->column( "pi1selfID",   0 );
	  hist->column( "pi1moID",     0 );
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
	  int pi2self = n_recon;
	  mapping_delete   ( Pi2, child_id_map, n_recon,    gen_mode_bg, "2nd charged pi",     fl_message );
	  mapping_delete_sw( Pi2, child_id_map, n_recon_sw, gen_mode_bg, "2nd charged pi[sw]", fl_message );
	  pi2self -= n_recon;
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
	  hist->column( "pi2self",     pi2self                     );
	  hist->column( "pi2selfID",   info_Pi2.id()               );
	  hist->column( "pi2moID",     info_Pi2.motherid()         );
	  if( which_B( Pi2.genHepevt(), sigb_id ) > 0 ) hist->column( "pi2org", 1 );
	  else  hist->column( "pi2org", 0 );
	  hist->column( "pi2trk",      info_Pi2.trk()              );
	  //hist->column( "pi2cdcr",     Pi2.mdstCharged().trk().mhyp(2).nhits(0) );
	  //hist->column( "pi2cdcz",     Pi2.mdstCharged().trk().mhyp(2).nhits(1) );
	  hist->column( "pi2svdr",     Pi2.mdstCharged().trk().mhyp(2).nhits(3) );
	  hist->column( "pi2svdz",     Pi2.mdstCharged().trk().mhyp(2).nhits(4) );
	  if( drmax < info_Pi2.dr() ) drmax = info_Pi2.dr();
	  if( dzmax < info_Pi2.dz() ) dzmax = info_Pi2.dz();
	  addTrack2fit( kf_b, Pi2 );
	  Particle Pi2_calib = Pi2;
	  Pi2_calib.momentum().momentumPosition(Pi2.momentum().p(), Pi2.momentum().x(), calib_trk_err(Pi2, 1/calib_vtx)  );
	  addTrack2fit( kf_b_calib, Pi2_calib );
	  Particle Pi2_calib2 = Pi2;
	  Pi2_calib2.momentum().momentumPosition(Pi2.momentum().p(), Pi2.momentum().x(), calib_trk_err2(Pi2, 1/calib_vtx)  );
	  addTrack2fit( kf_b_calib2, Pi2_calib2 );
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
	  int pi3self = n_recon;
	  mapping_delete   ( Pi3, child_id_map, n_recon,    gen_mode_bg, "3rd charged pi",     fl_message );
	  mapping_delete_sw( Pi3, child_id_map, n_recon_sw, gen_mode_bg, "3rd charged pi[sw]", fl_message );
	  pi3self -= n_recon;
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
	  hist->column( "pi3self",     pi3self                     );
	  hist->column( "pi3selfID",   info_Pi3.id()               );
	  hist->column( "pi3moID",     info_Pi3.motherid()         );
	  if( which_B( Pi3.genHepevt(), sigb_id ) > 0 ) hist->column( "pi3org", 1 );
	  else  hist->column( "pi3org", 0 );
	  hist->column( "pi3trk",      info_Pi3.trk()              );
	  //hist->column( "pi3cdcr",     Pi3.mdstCharged().trk().mhyp(2).nhits(0) );
	  //hist->column( "pi3cdcz",     Pi3.mdstCharged().trk().mhyp(2).nhits(1) );
	  hist->column( "pi3svdr",     Pi3.mdstCharged().trk().mhyp(2).nhits(3) );
	  hist->column( "pi3svdz",     Pi3.mdstCharged().trk().mhyp(2).nhits(4) );
	  if( drmax < info_Pi3.dr() ) drmax = info_Pi3.dr();
	  if( dzmax < info_Pi3.dz() ) dzmax = info_Pi3.dz();
	  addTrack2fit( kf_b, Pi3 );
	  Particle Pi3_calib = Pi3;
	  Pi3_calib.momentum().momentumPosition(Pi3.momentum().p(), Pi3.momentum().x(), calib_trk_err(Pi3, 1/calib_vtx)  );
	  addTrack2fit( kf_b_calib, Pi3_calib );
	  Particle Pi3_calib2 = Pi3;
	  Pi3_calib2.momentum().momentumPosition(Pi3.momentum().p(), Pi3.momentum().x(), calib_trk_err2(Pi3, 1/calib_vtx)  );
	  addTrack2fit( kf_b_calib2, Pi3_calib2 );
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
	  hist->column( "pi3self",    10 );
	  hist->column( "pi3chg",      0 );
	  hist->column( "pi3selfID",   0 );
	  hist->column( "pi3moID",     0 );
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
	  int pi4self = n_recon;
	  mapping_delete   ( Pi4, child_id_map, n_recon,    gen_mode_bg, "4th charged pi",     fl_message );
	  mapping_delete_sw( Pi4, child_id_map, n_recon_sw, gen_mode_bg, "4th charged pi[sw]", fl_message );
	  pi4self -= n_recon;
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
	  hist->column( "pi4self",     pi4self                     );
	  hist->column( "pi4selfID",   info_Pi4.id()               );
	  hist->column( "pi4moID",     info_Pi4.motherid()         );
	  if( which_B( Pi4.genHepevt(), sigb_id ) > 0 ) hist->column( "pi4org", 1 );
	  else  hist->column( "pi4org", 0 );
	  hist->column( "pi4trk",      info_Pi4.trk()              );
	  //hist->column( "pi4cdcr",     Pi4.mdstCharged().trk().mhyp(2).nhits(0) );
	  //hist->column( "pi4cdcz",     Pi4.mdstCharged().trk().mhyp(2).nhits(1) );
	  hist->column( "pi4svdr",     Pi4.mdstCharged().trk().mhyp(2).nhits(3) );
	  hist->column( "pi4svdz",     Pi4.mdstCharged().trk().mhyp(2).nhits(4) );
	  if( drmax < info_Pi4.dr() ) drmax = info_Pi4.dr();
	  if( dzmax < info_Pi4.dz() ) dzmax = info_Pi4.dz();
	  addTrack2fit( kf_b, Pi4 );
	  Particle Pi4_calib = Pi4;
	  Pi4_calib.momentum().momentumPosition(Pi4.momentum().p(), Pi4.momentum().x(), calib_trk_err(Pi4, 1/calib_vtx)  );
	  addTrack2fit( kf_b_calib, Pi4_calib );
	  Particle Pi4_calib2 = Pi4;
	  Pi4_calib2.momentum().momentumPosition(Pi4.momentum().p(), Pi4.momentum().x(), calib_trk_err2(Pi4, 1/calib_vtx)  );
	  addTrack2fit( kf_b_calib2, Pi4_calib2 );
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
	  int pi0self = mapping_delete   ( Pi0, child_id_map, n_recon,    gen_mode_bg, "pi0",     fl_message );
	                mapping_delete_sw( Pi0, child_id_map, n_recon_sw, gen_mode_bg, "pi0[sw]", fl_message );
	  hist->column( "pi0_m",    (Pi0_gam1.p() + Pi0_gam2.p()).m() );
	  hist->column( "pi0e",     Pi0.e()             );
	  hist->column( "pi0gam1E", Pi0_gam1.p3().mag() );
	  hist->column( "pi0gam2E", Pi0_gam2.p3().mag() );
	  hist->column( "pi0self",  pi0self             );
	  if( Pi0.genHepevt() ){
	    if( which_B( Pi0.genHepevt(), sigb_id ) > 0 ) hist->column( "pi0org", 1 );
	    else  hist->column( "pi0org", 0 );
	  }else{
	    hist->column( "pi0org", -1 );
	  }
	}else{
	  hist->column( "pi0_m",    -10 );
	  hist->column( "pi0e",     -10 );
	  hist->column( "pi0gam1E", -10 );
	  hist->column( "pi0gam2E", -10 );
	  hist->column( "pi0self",   10 );
	  hist->column( "pi0org",     0 );
	}

	
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	
	hist->column( "drmax", drmax );
	hist->column( "dzmax", dzmax );
	
	// [ kinematic fit for charged K and pi ]
	unsigned err_b = kf_b.fit();
	
	if( err_b==0 ){ // success.
	  hist->column( "kfbclorg",  kf_b.cl()    );
	  hist->column( "kfbchiorg", kf_b.chisq() );
	  hist->column( "kfbdgforg", kf_b.dgf()   );
	}else{ // false.
	  hist->column( "kfbclorg",  -1  );
	  hist->column( "kfbchiorg", -1  );
	  hist->column( "kfbdgforg", 0.5 );
	}

	///*
	// [ calibrated kinematic fit for charged K and pi ]
	unsigned err_b_calib = kf_b_calib.fit();
	
	if( err_b_calib==0 ){ // success.
	  hist->column( "kfbcl",  kf_b_calib.cl()    );
	  hist->column( "kfbchi", kf_b_calib.chisq() );
	  hist->column( "kfbdgf", kf_b_calib.dgf()   );
	}else{ // false.
	  hist->column( "kfbcl",  -1  );
	  hist->column( "kfbchi", -1  );
	  hist->column( "kfbdgf", 0.5 );
	}
	//*/
	// [ calibrated kinematic fit for charged K and pi ]
	unsigned err_b_calib2 = kf_b_calib2.fit();
	
	if( err_b_calib2==0 ){ // success.
	  hist->column( "kfbcl2",  kf_b_calib2.cl()    );
	  hist->column( "kfbchi2", kf_b_calib2.chisq() );
	  hist->column( "kfbdgf2", kf_b_calib2.dgf()   );
	}else{ // false.
	  hist->column( "kfbcl2",  -1  );
	  hist->column( "kfbchi2", -1  );
	  hist->column( "kfbdgf2", 0.5 );
	}
	//*/
	// [ self ]
	int self = 0;
	if( gen_mode_bg == 0 && gen_mode_xs==rec_mode_xs && gen_mode_lepton==rec_mode_lepton ){
	  if( n_recon == 0 ) self = 1;
	}
	if( fl_message ) std::cout << "n_recon = "     << n_recon     << ", "
				   << "n_recon_sw = "  << n_recon_sw  << ", "
				   << "gen_mode_bg = " << gen_mode_bg << " --> "
				   << "self = "        << self        << std::endl;

	hist->column( "self",    self       );
	hist->column( "kself",   kself      );
	hist->column( "rest",    n_recon    );
	hist->column( "rest_sw", n_recon_sw );

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
