#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif
  
  void XSLL::Rec_B_ana(std::vector<Particle> b_list, std::map<int, int>& child_id_map,
		       std::vector<Particle> pion_list, std::vector<Particle> gamma_list,
		       BelleTuple* hist, const bool fl_message )
  {
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
	
	int n_recon = child_id_map.size();
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
	hist->column( "gm_m_llg",  gen_fl_llg*gen_m_llg );
	hist->column( "rm_xs",     rec_mode_xs          );
	hist->column( "rm_l",      rec_mode_lepton      );
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

	// [ Pseudo CC ]
	hist->column( "cc_m",    CC.mass()       );
	hist->column( "cc_morg", info_CC.m_org() );
	
	// [ lepton ]
	Particle& lp        = CC.child(0);
	Particle& lm        = CC.child(1);
	UserInfo& info_lp   = dynamic_cast<UserInfo&>( lp.userInfo() );
	UserInfo& info_lm   = dynamic_cast<UserInfo&>( lm.userInfo() );
	
	int q2self = n_recon;
	mapping_delete( lp, child_id_map, n_recon, gen_mode_bg, "l+", fl_message );
	mapping_delete( lm, child_id_map, n_recon, gen_mode_bg, "l-", fl_message );
	if( q2self-2 == n_recon ) q2self = 1;
	else q2self = 0;
	hist->column( "q2self", q2self );

	Hep3Vector dilep_boost = -CC.p().boostVector();
	HepLorentzVector lp_4V = lp.p();
	HepLorentzVector B_4V  = B.p();
	lp_4V.boost( dilep_boost ); //   l+  momentum at dilepton-rest-frame
	B_4V.boost ( dilep_boost ); // rec-B momentum at dilepton-rest-frame
	double coslp = cos( lp_4V.vect().angle(B_4V.vect()) );
	if( recbfl == 1 ) ;
	else if( recbfl == -1 ) coslp *= -1.0;
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

       
	// [ charged K ]
	if( n_charged_k > 0 ){
	  Particle& chargedK       = Xs.child(0);
	  UserInfo& info_chargedK  = dynamic_cast<UserInfo&>( chargedK.userInfo()  );
	  mapping_delete( chargedK, child_id_map, n_recon, gen_mode_bg, "charged K", fl_message );
	  hist->column( "kchg",     chargedK.charge()              );
	  hist->column( "k_kid",    info_chargedK.selKPI()         );
	  hist->column( "k_eid",    info_chargedK.eidProb()        );
	  hist->column( "k_muid",   info_chargedK.muonLikelihood() );
	  hist->column( "k_ep",     info_chargedK.ptot_ee()        );
	  hist->column( "k_mp",     info_chargedK.ptot_mm()        );
	  if( drmax < info_chargedK.dr() ) drmax = info_chargedK.dr();
	  if( dzmax < info_chargedK.dz() ) dzmax = info_chargedK.dz();
	  addTrack2fit( kf_b, chargedK );
	}else{
	  hist->column( "k_kid",     2 );
	  hist->column( "k_eid",    -1 );
	  hist->column( "k_muid",   -1 );
	  hist->column( "k_ep",     -10);
	  hist->column( "k_mp",     -10);
	}
	// [ Ks ]
	if( n_Ks > 0 ){
	  Particle& Ks          = Xs.child(0);
	  UserInfo& info_Ks_pi1 = dynamic_cast<UserInfo&>( Ks.child(0).userInfo()  );
	  UserInfo& info_Ks_pi2 = dynamic_cast<UserInfo&>( Ks.child(1).userInfo()  );
	  mapping_delete( Ks, child_id_map, n_recon, gen_mode_bg, "Ks", fl_message );
	  hist->column( "ks_m",     Ks.mass()            );
	  hist->column( "kchg",     Ks.charge()          );
	  hist->column( "kspi1id",  info_Ks_pi1.selKPI() );
	  hist->column( "kspi2id",  info_Ks_pi2.selKPI() );
	}else{
	  hist->column( "ks_m",     -10 );
	  hist->column( "kspi1id",  -1  );
	  hist->column( "kspi2id",  -1  );
	}

	// [ 1st charged pi ]
	if( n_charged_pi > 0 ){
	  Particle& Pi1      = Xs.child(1);
	  UserInfo& info_Pi1 = dynamic_cast<UserInfo&>( Pi1.userInfo()  );
	  mapping_delete( Pi1, child_id_map, n_recon, gen_mode_bg, "1st charged pi", fl_message );
	  hist->column( "pi1_kid",  info_Pi1.selKPI()         );
	  hist->column( "pi1_eid",  info_Pi1.eidProb()        );
	  hist->column( "pi1_muid", info_Pi1.muonLikelihood() );
	  hist->column( "pi1_ep",   info_Pi1.ptot_ee()        );
	  hist->column( "pi1_mp",   info_Pi1.ptot_mm()        );
	  if( drmax < info_Pi1.dr() ) drmax = info_Pi1.dr();
	  if( dzmax < info_Pi1.dz() ) dzmax = info_Pi1.dz();
	  addTrack2fit( kf_b, Pi1 );
	}else{
	  hist->column( "pi1_kid",  -1  );
	  hist->column( "pi1_eid",  -1  );
	  hist->column( "pi1_muid", -1  );
	  hist->column( "pi1_ep",   -10 );
	  hist->column( "pi1_mp",   -10 );
	}
	// [ 2nd charged pi ]
	if( n_charged_pi > 1 ){
	  Particle& Pi2      = Xs.child(2);
	  UserInfo& info_Pi2 = dynamic_cast<UserInfo&>( Pi2.userInfo()  );
	  mapping_delete( Pi2, child_id_map, n_recon, gen_mode_bg, "2nd charged pi", fl_message );
	  hist->column( "pi2_kid",  info_Pi2.selKPI()         );
	  hist->column( "pi2_eid",  info_Pi2.eidProb()        );
	  hist->column( "pi2_muid", info_Pi2.muonLikelihood() );
	  hist->column( "pi2_ep",   info_Pi2.ptot_ee()        );
	  hist->column( "pi2_mp",   info_Pi2.ptot_mm()        );
	  if( drmax < info_Pi2.dr() ) drmax = info_Pi2.dr();
	  if( dzmax < info_Pi2.dz() ) dzmax = info_Pi2.dz();
	  addTrack2fit( kf_b, Pi2 );
	}else{
	  hist->column( "pi2_kid",  -1  );
	  hist->column( "pi2_eid",  -1  );
	  hist->column( "pi2_muid", -1  );
	  hist->column( "pi2_ep",   -10 );
	  hist->column( "pi2_mp",   -10 );
	}
		
	// [ 3rd charged pi ]
	if( n_charged_pi > 2 ){
	  Particle& Pi3      = Xs.child(3);
	  UserInfo& info_Pi3 = dynamic_cast<UserInfo&>( Pi3.userInfo()  );
	  mapping_delete( Pi3, child_id_map, n_recon, gen_mode_bg, "3rd charged pi", fl_message );
	  hist->column( "pi3_kid",  info_Pi3.selKPI()         );
	  hist->column( "pi3_eid",  info_Pi3.eidProb()        );
	  hist->column( "pi3_muid", info_Pi3.muonLikelihood() );
	  hist->column( "pi3_ep",   info_Pi3.ptot_ee()        );
	  hist->column( "pi3_mp",   info_Pi3.ptot_mm()        );
	  if( drmax < info_Pi3.dr() ) drmax = info_Pi3.dr();
	  if( dzmax < info_Pi3.dz() ) dzmax = info_Pi3.dz();
	  addTrack2fit( kf_b, Pi3 );
	}else{
	  hist->column( "pi3_kid",  -1  );
	  hist->column( "pi3_eid",  -1  );
	  hist->column( "pi3_muid", -1  );
	  hist->column( "pi3_ep",   -10 );
	  hist->column( "pi3_mp",   -10 );
	}
	
	// [ 4th charged pi ]
	if( n_charged_pi > 3 ){
	  Particle& Pi4      = Xs.child(4);
	  UserInfo& info_Pi4 = dynamic_cast<UserInfo&>( Pi4.userInfo()  );
	  mapping_delete( Pi4, child_id_map, n_recon, gen_mode_bg, "4th charged pi", fl_message );
	  hist->column( "pi4_kid",  info_Pi4.selKPI()         );
	  hist->column( "pi4_eid",  info_Pi4.eidProb()        );
	  hist->column( "pi4_muid", info_Pi4.muonLikelihood() );
	  hist->column( "pi4_ep",   info_Pi4.ptot_ee()        );
	  hist->column( "pi4_mp",   info_Pi4.ptot_mm()        );
	  if( drmax < info_Pi4.dr() ) drmax = info_Pi4.dr();
	  if( dzmax < info_Pi4.dz() ) dzmax = info_Pi4.dz();
	  addTrack2fit( kf_b, Pi4 );
	}else{
	  hist->column( "pi4_kid",  -1  );
	  hist->column( "pi4_eid",  -1  );
	  hist->column( "pi4_muid", -1  );
	  hist->column( "pi4_ep",   -10 );
	  hist->column( "pi4_mp",   -10 );
	}
	
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// [ neutral pi ]
	int pi0self    = 0;
	int pi0decay   = -1;
	int gam1_conv  = -1;
	int gam2_conv  = -1;
	int gam1_self  = -10;
	int gam2_self  = -10;
	
	if( n_neutral_pi > 0 ){
	  Particle& Pi0      = Xs.child( Xs.nChildren()-1 );
	  UserInfo& info_Pi0 = dynamic_cast<UserInfo&>( Pi0.userInfo() );
	  Particle& Pi0_gam1 = Pi0.child(0);
	  Particle& Pi0_gam2 = Pi0.child(1);
	  pi0self = mapping_delete( Pi0, child_id_map, n_recon, gen_mode_bg, "pi0", fl_message );
	  hist->column( "pi0_m",    (Pi0_gam1.p() + Pi0_gam2.p()).m() );
	  hist->column( "pi0e",     Pi0.e()             );
	  hist->column( "pi0gam1E", Pi0_gam1.p3().mag() );
	  hist->column( "pi0gam2E", Pi0_gam2.p3().mag() );
	  if( pi0self==0 && n_recon==1 ) pi0_matching( Pi0, child_id_map, pi0self, pi0decay, gam1_self, gam2_self, gam1_conv, gam2_conv );// pi0 conversion ?
	  /*	  
	  std::cout << "pi0-check( "
		    << "pi0self=" << pi0self   << ", "
		    << "pi0decay=" << pi0decay  << ", "
		    << "g1self="  << gam1_self << ", " << "g2self="   << gam2_self << ", "
		    << "g1conv="  << gam1_conv << ", " << "g2conv="   << gam2_conv
		    << " )"
		    << "[ "
		    << "pi_id="    << pi_id      << ", " << "gam1_id="  << gam1_id    << ", " << "gam2_id=" << gam2_id << ", "
		    << "g1_e1_id=" << gam1_e1_id << ", " << "g1_e2_id=" << gam1_e2_id << ", "
		    << "g2_e1_id=" << gam2_e1_id << ", " << "g2_e2_id=" << gam2_e2_id
		    << " ]"
		    << "{ "
		    << Pi0_gam1.genHepevt().get_ID() << ", "
		    << Pi0_gam2.genHepevt().get_ID()
		    << " }"
		    << std::endl;
	  */
	}else{
	  hist->column( "pi0_m",    -10 );
	  hist->column( "pi0e",     -10 );
	  hist->column( "pi0gam1E", -10 );
	  hist->column( "pi0gam2E", -10 );
	}
	hist->column( "pi0self",  pi0self   );
	hist->column( "pi0decay", pi0decay  );
	hist->column( "g1self",   gam1_self );
	hist->column( "g2self",   gam2_self );
	hist->column( "g1conv",   gam1_conv );
	hist->column( "g2conv",   gam2_conv );
	
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
	
	// [ self ]
	int self = 0;
	if( gen_mode_bg == 0 && gen_mode_xs==rec_mode_xs && gen_mode_lepton==rec_mode_lepton ){
	  if( n_recon == 0 ) self = 1;
	  else if( n_recon == 1 && pi0self == 2 ) self = 2;
	}
	if( fl_message ) std::cout << "n_recon = "     << n_recon     << ", "
				   << "gen_mode_bg = " << gen_mode_bg << " --> "
				   << "self = "        << self        << std::endl;
	hist->column( "self", self );


	// [ QQ Suppression ]
	ksfwmoments km(B, eb, cmboost );
	km.usefinal(0);
	hist->column( "k0mm2",   km.mm2()    );
	hist->column( "k0et",    km.et()     );
	hist->column( "k0hso00", km.Hso(0,0) );
	hist->column( "k0hso01", km.Hso(0,1) );
	hist->column( "k0hso02", km.Hso(0,2) );
	hist->column( "k0hso03", km.Hso(0,3) );
	hist->column( "k0hso04", km.Hso(0,4) );
	hist->column( "k0hso10", km.Hso(1,0) );
	hist->column( "k0hso12", km.Hso(1,2) );
	hist->column( "k0hso14", km.Hso(1,4) );
	hist->column( "k0hso20", km.Hso(2,0) );
	hist->column( "k0hso22", km.Hso(2,2) );
	hist->column( "k0hso24", km.Hso(2,4) );
	hist->column( "k0hoo0",  km.Hoo(0)   );
	hist->column( "k0hoo1",  km.Hoo(1)   );
	hist->column( "k0hoo2",  km.Hoo(2)   );
	hist->column( "k0hoo3",  km.Hoo(3)   );
	hist->column( "k0hoo4",  km.Hoo(4)   );
	
	km.usefinal(1);
	hist->column( "k1mm2",   km.mm2()    );
	hist->column( "k1et",    km.et()     );
	hist->column( "k1hso00", km.Hso(0,0) );
	hist->column( "k1hso01", km.Hso(0,1) );
	hist->column( "k1hso02", km.Hso(0,2) );
	hist->column( "k1hso03", km.Hso(0,3) );
	hist->column( "k1hso04", km.Hso(0,4) );
	hist->column( "k1hso10", km.Hso(1,0) );
	hist->column( "k1hso12", km.Hso(1,2) );
	hist->column( "k1hso14", km.Hso(1,4) );
	hist->column( "k1hso20", km.Hso(2,0) );
	hist->column( "k1hso22", km.Hso(2,2) );
	hist->column( "k1hso24", km.Hso(2,4) );
	hist->column( "k1hoo0",  km.Hoo(0)   );
	hist->column( "k1hoo1",  km.Hoo(1)   );
	hist->column( "k1hoo2",  km.Hoo(2)   );
	hist->column( "k1hoo3",  km.Hoo(3)   );
	hist->column( "k1hoo4",  km.Hoo(4)   );
	
	// [ Combinatorial B.G. Suppression ]
	double Evis=0;
	double Eroe=0;
	Hep3Vector Ptot(0);
	double Mmiss=0;
	
	for( std::vector<Particle>::iterator p = pion_list.begin();
	     p != pion_list.end();
	     p++ )
	  {
	    UserInfo& info_allpi  = dynamic_cast<UserInfo&>( p->userInfo()  );
	    Evis += info_allpi.Vcm().e();
	    Ptot += info_allpi.Vcm().vect();
	    if( check_dupli_daughter( p, b ) ) Eroe += info_allpi.Vcm().e();
	  }

	for( std::vector<Particle>::iterator g = gamma_list.begin();
	     g != gamma_list.end();
	     g++ )
	  {
	    UserInfo& info_allgam = dynamic_cast<UserInfo&>( g->userInfo()  );
	    Evis += info_allgam.Vcm().e();
	    Ptot += info_allgam.Vcm().vect();
	    if( check_dupli_daughter( g, b ) ) Eroe += info_allgam.Vcm().e();
	  }
	hist->column( "evis",  Evis                                        );
	double mmiss2 = (2*eb-Evis)*(2*eb-Evis) - Ptot.mag2();
	hist->column( "mmiss", mmiss2 > 0 ? sqrt(mmiss2) : -sqrt(-mmiss2)  );
	hist->column( "deroe", Eroe-eb                                     );
	
	hist->dumpData();
	
      }
    if( fl_message ) std::cout << "ANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANAANA" << std::endl;
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif


















/*
//////////////////////////////////////////////////////////////////////////////////////
// try to gamma generator information [part2]
//////////////////////////////////////////////////////////////////////////////////////
std::set<int> gen_gamma_set;
for( std::vector<Gen_hepevt>::iterator gen = genMgr.begin(); gen != genMgr.end(); gen++ ){
if( gen->idhep() == Gamma_LUND ) gen_gamma_set.insert( gen->get_ID() );
}
Mdst_gamma_Manager& gamMgr = Mdst_gamma_Manager::get_manager();
for( Mdst_gamma_Manager::iterator g = gamMgr.begin(); g!=gamMgr.end(); g++ ){
Particle gamma( *g );
check_selfG(gamma);
gen_gamma_set.erase( gamma.genHepevt().get_ID() );
}
for( std::set<int>::iterator it = gen_gamma_set.begin(); it != gen_gamma_set.end(); it++ ){
Gen_hepevt& G( genMgr( Panther_ID(*it) ) );
Hep3Vector v( G.PX(), G.PY(), G.PZ() );
if( gam1self==2 ){
test2_dist->column( "dagam", v.angle(Pi0_gam1.p3())      );
test2_dist->column( "degam", G.E() - Pi0_gam1.p3().mag() );
test2_dist->dumpData();
}
if( gam2self==2 ){
test2_dist->column( "dagam", v.angle(Pi0_gam2.p3())      );
test2_dist->column( "degam", G.E() - Pi0_gam2.p3().mag() );
test2_dist->dumpData();
}
}

//////////////////////////////////////////////////////////////////////////////////////
*/		  




















/*
  	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// [ neutral pi ]
	int pi0self = 0;
	hist->column( "pi0decay",   0 );
	hist->column( "ggself",   -10 );
	hist->column( "da0",      -10 );
	hist->column( "de0",      -10 );
	hist->column( "g1self",   -10 );
	hist->column( "g2self",   -10 );
	hist->column( "da11",     -10 );
	hist->column( "de11",     -10 );
	hist->column( "da21",     -10 );
	hist->column( "de21",     -10 );
	hist->column( "da12",     -10 );
	hist->column( "de12",     -10 );
	hist->column( "da22",     -10 );
	hist->column( "de22",     -10 );
	if( n_neutral_pi > 0 ){
	  Particle& Pi0      = Xs.child( Xs.nChildren()-1 );
	  UserInfo& info_Pi0 = dynamic_cast<UserInfo&>( Pi0.userInfo()  );
	  Particle& Pi0_gam1 = Pi0.child(0);
	  Particle& Pi0_gam2 = Pi0.child(1);
	  pi0self = mapping_delete( Pi0, child_id_map, n_recon, gen_mode_bg, "pi0", fl_message );
	  hist->column( "pi0_m",    (Pi0_gam1.p() + Pi0_gam2.p()).m() );
	  hist->column( "pi0e",     Pi0.e()             );
	  hist->column( "pi0gam1E", Pi0_gam1.p3().mag() );
	  hist->column( "pi0gam2E", Pi0_gam2.p3().mag() );
	  
	  if( pi0self==0 && n_recon==1 ){ // pi0 conversion ?
	    pi0self = 2;
	    // search pi0(gen)
	    std::map<int,int>::iterator it = child_id_map.begin();
	    int true_pi0_id = 0;
	    int cnt_pi0 = 0;
	    while( it != child_id_map.end() ){
	      if( it->second == PI0_LUND ) true_pi0_id = it->first, cnt_pi0++;
	      it++;
	    }
	    
	    if( cnt_pi0 != 1 ){ // # of pi0(gen) is not 1
	      pi0self = 0;
	    }else{ // # of pi0(gen) is 1
	      // judgement pi0(gen) decay mode
	      Gen_hepevt_Manager& genMgr = Gen_hepevt_Manager::get_manager();
	      Gen_hepevt& true_pi0( genMgr( Panther_ID(true_pi0_id) ) );
	      int nchild_pi0  = true_pi0.daLast() ==0 ? 0 : true_pi0.daLast() - true_pi0.daFirst() + 1;
	      int pi0_decay = 0;
	    
	      if( nchild_pi0==2 ){ // two-body decay
		Gen_hepevt& g1( genMgr(Panther_ID(true_pi0.daFirst()  )) );
		Gen_hepevt& g2( genMgr(Panther_ID(true_pi0.daFirst()+1)) );
		if( g1.idhep()==Gamma_LUND && g2.idhep()==Gamma_LUND ){ // pi0 -> gamma gamma
		  int gam1self=2;
		  int gam2self=2;
		  if( Pi0_gam1.genHepevt().get_ID() &&  Pi0_gam1.genHepevt().get_ID()!=g1.get_ID() && Pi0_gam1.genHepevt().get_ID()!=g2.get_ID()  ) gam1self = 0;
		  if( Pi0_gam2.genHepevt().get_ID() &&  Pi0_gam2.genHepevt().get_ID()!=g1.get_ID() && Pi0_gam2.genHepevt().get_ID()!=g2.get_ID()  ) gam2self = 0;
		  if( Pi0_gam1.genHepevt().get_ID() && (Pi0_gam1.genHepevt().get_ID()==g1.get_ID() || Pi0_gam1.genHepevt().get_ID()==g2.get_ID()) ) gam1self = 1;
		  if( Pi0_gam2.genHepevt().get_ID() && (Pi0_gam2.genHepevt().get_ID()==g1.get_ID() || Pi0_gam2.genHepevt().get_ID()==g2.get_ID()) ) gam2self = 1;
		  if( gam1self==0 || gam2self==0 ) pi0self = 0;
		  if( gam1self==1 && gam2self==1 ) pi0self = 1;
		  
		  //////////////////////////////////////////////////////////////////////////////////////
		  // try to gamma generator information [part1]
		  //////////////////////////////////////////////////////////////////////////////////////

		  Hep3Vector v0( true_pi0.PX(), true_pi0.PY(), true_pi0.PZ() ); // pi0
		  Hep3Vector v1( g1.PX(),       g1.PY(),       g1.PZ()       ); // gam1
		  Hep3Vector v2( g2.PX(),       g2.PY(),       g2.PZ()       ); // gam2
		  double da0  = v0.angle( Pi0.p3() );
		  double da11 = v1.angle( Pi0_gam1.p3() );
		  double da12 = v1.angle( Pi0_gam2.p3() );
		  double da21 = v2.angle( Pi0_gam1.p3() );
		  double da22 = v2.angle( Pi0_gam2.p3() );
		  double de0  = true_pi0.M() - info_Pi0.m_org();
		  double de11 = g1.E() - Pi0_gam1.p3().mag();
		  double de12 = g1.E() - Pi0_gam2.p3().mag();
		  double de21 = g2.E() - Pi0_gam1.p3().mag();
		  double de22 = g2.E() - Pi0_gam2.p3().mag();
		  //std::cout << "gam1self*gam2self = " << 10*gam1self+gam2self << "( " << Pi0_gam1.genHepevt().get_ID() << ", " << Pi0_gam2.genHepevt().get_ID() << " ) : ( " << g1.get_ID() << ", " << g2.get_ID() << " )" << std::endl;

		  hist->column( "pi0decay", 1       );
		  hist->column( "ggself",   10*gam1self+gam2self );
		  hist->column( "da0",      da0     );
		  hist->column( "de0",      de0     );		  
		  hist->column( "g1self",   gam1self );
		  hist->column( "g2self",   gam2self );
		  hist->column( "da11",     da11     );
		  hist->column( "de11",     de11     );
		  hist->column( "da21",     da21     );
		  hist->column( "de21",     de21     );
		  hist->column( "da12",     da12     );
		  hist->column( "de12",     de12     );
		  hist->column( "da22",     da22     );
		  hist->column( "de22",     de22     );
		  
		}else{ // not pi0 -> gamma gamma
		  pi0self = 0;
		}
	      }else{ // not two-body decay
		pi0self = 0;
	      }
	    }
	  }
	}else{
	  hist->column( "pi0_m",    -10 );
	  hist->column( "pi0e",     -10 );
	  hist->column( "pi0gam1E", -10 );
	  hist->column( "pi0gam2E", -10 );
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
