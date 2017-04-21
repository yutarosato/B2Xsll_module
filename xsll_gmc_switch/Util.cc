#include "belle.h"
#include "XSLL.h"
//#include "toolbox/FoxWolfr.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  double XSLL::correct_dr( const Mdst_charged chg, HepPoint3D m_ip, int id )
  {
    double co_dr = 10000.;
    Mdst_trk& trk = chg.trk();
    Mdst_trk_fit& fit = trk.mhyp(id);

    if( trk && fit ){

      // Get Helix parameter
      HepVector a(5,0);
      a[0] = fit.helix(0);
      a[1] = fit.helix(1);
      a[2] = fit.helix(2);
      a[3] = fit.helix(3);
      a[4] = fit.helix(4);

      // Get the error matrix
      HepSymMatrix Ea(5,0);
      Ea[0][0] = fit.error(0);
      Ea[1][0] = fit.error(1); Ea[1][1] = fit.error(2);
      Ea[2][0] = fit.error(3); Ea[2][1] = fit.error(4);
      Ea[2][2] = fit.error(5);
      Ea[3][0] = fit.error(6); Ea[3][1] = fit.error(7);
      Ea[3][2] = fit.error(8);
      Ea[3][3] = fit.error(9);
      Ea[4][0] = fit.error(10); Ea[4][1] = fit.error(11);
      Ea[4][2] = fit.error(12);
      Ea[4][3] = fit.error(13); Ea[4][4] = fit.error(14);

      HepPoint3D pivot(fit.pivot(0), fit.pivot(1), fit.pivot(2));
      Helix crtrk(pivot, a, Ea);
      crtrk.pivot(m_ip);

      co_dr=crtrk.dr();
    }
    return(co_dr);
  }

  double XSLL::correct_dz( const Mdst_charged chg, HepPoint3D m_ip, int id )
  {
    double co_dz = 10000.;
    Mdst_trk& trk = chg.trk();
    Mdst_trk_fit& fit = trk.mhyp(id);

    if( trk && fit ){

      // Get Helix parameter
      HepVector a(5,0);
      a[0] = fit.helix(0);
      a[1] = fit.helix(1);
      a[2] = fit.helix(2);
      a[3] = fit.helix(3);
      a[4] = fit.helix(4);

      // Get the error matrix
      HepSymMatrix Ea(5,0);
      Ea[0][0] = fit.error(0);
      Ea[1][0] = fit.error(1); Ea[1][1] = fit.error(2);
      Ea[2][0] = fit.error(3); Ea[2][1] = fit.error(4);
      Ea[2][2] = fit.error(5);
      Ea[3][0] = fit.error(6); Ea[3][1] = fit.error(7);
      Ea[3][2] = fit.error(8);
      Ea[3][3] = fit.error(9);
      Ea[4][0] = fit.error(10); Ea[4][1] = fit.error(11);
      Ea[4][2] = fit.error(12);
      Ea[4][3] = fit.error(13); Ea[4][4] = fit.error(14);

      HepPoint3D pivot(fit.pivot(0), fit.pivot(1), fit.pivot(2));
      Helix crtrk(pivot, a, Ea);
      crtrk.pivot(m_ip);

      co_dz=crtrk.dz();
    }
    return(co_dz);
  }

  int XSLL::add_bremsstrahlung(Particle& particle, std::vector<Particle>& gamma_list)
  {
    int ngam_p   = 0; // the number of added gamma
    int ngam_m   = 0; // the number of added gamma
    HepLorentzVector gamma_momentum;
    for(std::vector<Particle>::iterator gam = gamma_list.begin();
	gam != gamma_list.end();
	gam++)
      {
	double angle_p = particle.child(0).p3().angle( gam->p3() );
	double angle_m = particle.child(1).p3().angle( gam->p3() );
	//std::cout << "angle = " << angle_p << ", " << angle_m << std::endl;
	if( angle_p < Rad_angle_cut ){
	  gamma_momentum += gam->p();
	  particle.relation().append( *gam );
	  ngam_p++;
	}else if( angle_m < Rad_angle_cut ){
	  gamma_momentum += gam->p();
	  particle.relation().append( *gam );
	  ngam_m++;
	}
      }
    particle.momentum().momentum( particle.p() + gamma_momentum );
    dynamic_cast<UserInfo&>(particle.child(0).userInfo()).radgam_n( ngam_p );
    dynamic_cast<UserInfo&>(particle.child(1).userInfo()).radgam_n( ngam_m );
    dynamic_cast<UserInfo&>(particle.userInfo()).radgam_n( ngam_p + ngam_m );
    return ngam_p + ngam_m;
  }

  int XSLL::id_bremsstrahlung(Particle& particle, std::vector<Particle>& gamma_list)
  {
    int       id_p        = -1; // id of nearest gamma
    int       id_m        = -1; // id of nearest gamma
    double    angle_p_min = Rad_angle_cut;
    double    angle_m_min = Rad_angle_cut;
    
    for(std::vector<Particle>::iterator gam = gamma_list.begin();
	gam != gamma_list.end();
	gam++)
      {
	double angle_p = particle.child(0).p3().angle( gam->p3() );
	double angle_m = particle.child(1).p3().angle( gam->p3() );
	//std::cout << "angle = " << angle_p << "( " << gam->mdstGamma().get_ID() << "), " << angle_m << "(" << gam->mdstGamma().get_ID() << ")" << std::endl;
	if( (angle_p < Rad_angle_cut) && (angle_p < angle_p_min) ){
	  angle_p_min = angle_p;
	  id_p = gam->mdstGamma().get_ID();
	}

	if( (angle_m < Rad_angle_cut) && (angle_m < angle_m_min) ){
	  angle_m_min = angle_m;
	  id_m = gam->mdstGamma().get_ID();
	}
      }
    
    for(std::vector<Particle>::iterator gam = gamma_list.begin();
	gam != gamma_list.end();
	gam++){
      //std::cout << id_p << ", " << id_m << std::endl;
      if( gam->mdstGamma().get_ID() == id_p || gam->mdstGamma().get_ID() == id_m ){
	particle.relation().append( *gam );
	particle.momentum().momentum( particle.p() + gam->p() );
      }
    }
    
    if( id_p != -1 ) dynamic_cast<UserInfo&>(particle.child(0).userInfo()).radgam_n( 1 );
    if( id_m != -1 ) dynamic_cast<UserInfo&>(particle.child(1).userInfo()).radgam_n( 1 );
    if( id_p != -1 && id_m != -1 ) dynamic_cast<UserInfo&>(particle.userInfo()).radgam_n( 2 );
    else if ( id_p != -1 || id_m != -1 ) dynamic_cast<UserInfo&>(particle.userInfo()).radgam_n( 1 );

    return dynamic_cast<UserInfo&>(particle.userInfo()).radgam_n();
  }

  
  // ---------------------------------------------------
  //   Check duplications of the final-state particles
  //   1 -> not duplication, 0 -> duplication
  // ---------------------------------------------------
  int XSLL::check_dupli_daughter( std::vector<Particle>::iterator i,
				  std::vector<Particle>::iterator j )
  {
    int b_nonduplication_flag = 1;
    const int chk1_nptcle = i->relation().nFinalStateParticles();
    const int chk2_nptcle = j->relation().nFinalStateParticles();
    for (int  k = 0; k < chk1_nptcle; k++) {
      for (int  l = 0; l < chk2_nptcle; l++) {
	Particle chk1_child = i->relation().finalStateParticle(k);
	Particle chk2_child = j->relation().finalStateParticle(l);

	if ( !chk1_child.mdstCharged() || !chk2_child.mdstCharged() ) continue;
	int chk1_chgID = chk1_child.mdstCharged().get_ID();
	int chk2_chgID = chk2_child.mdstCharged().get_ID();
	if( chk1_chgID * chk2_chgID != 0  && (chk1_chgID == chk2_chgID) ) b_nonduplication_flag = 0;
	if( b_nonduplication_flag == 0 ) break;
      }
      if( b_nonduplication_flag == 0 ) break;
    }

    for (int  k = 0; k < chk1_nptcle; k++) {
      for (int  l = 0; l < chk2_nptcle; l++) {
	Particle chk1_child = i->relation().finalStateParticle(k);
	Particle chk2_child = j->relation().finalStateParticle(l);
	
	if ( !chk1_child.mdstGamma() || !chk2_child.mdstGamma() ) continue;
	int chk1_gamID = chk1_child.mdstGamma().get_ID();
	int chk2_gamID = chk2_child.mdstGamma().get_ID();
	if( chk1_gamID * chk2_gamID != 0  && (chk1_gamID == chk2_gamID) ) b_nonduplication_flag = 0;
	if( b_nonduplication_flag == 0 ) break;
      }
      if( b_nonduplication_flag == 0 ) break;
    }
    
    for (int  m = 0; m < chk1_nptcle; m++) {
      for (int  n = m+1; n < chk1_nptcle; n++) {
	Particle d_child1 = i->relation().finalStateParticle(m);
	Particle d_child2 = i->relation().finalStateParticle(n); 
	if ( !d_child1.mdstCharged() || !d_child2.mdstCharged() ) continue;
	int d_ch1_chgID = d_child1.mdstCharged().get_ID();
	int d_ch2_chgID = d_child2.mdstCharged().get_ID();
	if(d_ch1_chgID * d_ch2_chgID != 0  && (d_ch1_chgID == d_ch2_chgID))
	  b_nonduplication_flag = 0;
	if( b_nonduplication_flag == 0 ) break;
      }
      if( b_nonduplication_flag == 0 ) break;
    }

    for (int  m = 0; m < chk1_nptcle; m++) {
      for (int  n = m+1; n < chk1_nptcle; n++) {
	Particle d_child1 = i->relation().finalStateParticle(m);
	Particle d_child2 = i->relation().finalStateParticle(n); 
	if ( !d_child1.mdstGamma() || !d_child2.mdstGamma() ) continue;
	int d_ch1_gamID = d_child1.mdstGamma().get_ID();
	int d_ch2_gamID = d_child2.mdstGamma().get_ID();
	if(d_ch1_gamID * d_ch2_gamID != 0  && (d_ch1_gamID == d_ch2_gamID))
	  b_nonduplication_flag = 0;
	if( b_nonduplication_flag == 0 ) break;
      }
      if( b_nonduplication_flag == 0 ) break;
    }
    
    for (int  m = 0; m < chk2_nptcle; m++) {
      for (int  n = m+1; n < chk2_nptcle; n++) {
	Particle d_child1 = j->relation().finalStateParticle(m);
	Particle d_child2 = j->relation().finalStateParticle(n); 
	if ( !d_child1.mdstCharged() || !d_child2.mdstCharged() ) continue;
	int d_ch1_chgID = d_child1.mdstCharged().get_ID();
	int d_ch2_chgID = d_child2.mdstCharged().get_ID();
	if(d_ch1_chgID * d_ch2_chgID != 0  && (d_ch1_chgID == d_ch2_chgID))
	  b_nonduplication_flag = 0;
	if( b_nonduplication_flag == 0 ) break;
      }
      if( b_nonduplication_flag == 0 ) break;
    }
    
    for (int  m = 0; m < chk2_nptcle; m++) {
      for (int  n = m+1; n < chk2_nptcle; n++) {
	Particle d_child1 = j->relation().finalStateParticle(m);
	Particle d_child2 = j->relation().finalStateParticle(n); 
	if ( !d_child1.mdstGamma() || !d_child2.mdstGamma() ) continue;
	int d_ch1_gamID = d_child1.mdstGamma().get_ID();
	int d_ch2_gamID = d_child2.mdstGamma().get_ID();
	if(d_ch1_gamID * d_ch2_gamID != 0  && (d_ch1_gamID == d_ch2_gamID))
	  b_nonduplication_flag = 0;
	if( b_nonduplication_flag == 0 ) break;
      }
      if( b_nonduplication_flag == 0 ) break;
    }
    
    return b_nonduplication_flag;
  }

  int XSLL::kinematic_fit( Particle& particle, int flag_kfitter,
			  int ntrk)
  {
    if(!ntrk) ntrk = particle.nChildren();
    //std::cout << "kinematic fitting " << flag_kfitter
    //<< " : Particle( "      << particle.pType().name() << ",  "
    //<< ntrk                 << " tracks, "
    //<< particle.nChildren() << "children )"
    //<< std::endl;
    
    setUserInfo( particle );
    UserInfo& info = dynamic_cast<UserInfo&>( particle.userInfo() );
    info.kf( flag_kfitter );
    if(flag_kfitter==1 || flag_kfitter==2){ // kvertexfitter (+ IP tube) *********************************************************
      kvertexfitter kf;
      for(int i=0; i<particle.nChildren(); i++)	addTrack2fit( kf, particle.child(i) );      
      if(flag_kfitter==2) addTube2fit(kf); // for IP tube constraint
      unsigned err = kf.fit();
      
      if( err==0 ){ // success.
	info.kf_cl( kf.cl() );
	info.kf_chisq( kf.chisq() );
	info.kf_ndf( kf.dgf() );
	makeMother(kf, particle);
      }else{ // false.
	//std::cout << "false kvertexfitter : error code " << err << std::endl;
	return 0;
      }
    }else if(flag_kfitter==3){ // kmassvertexfitter ****************************************************************************
      if(particle.nChildren()-ntrk){ // set gamma error(find vertex)
	kvertexfitter tmp_kf;
	for(int i=0; i<ntrk; i++) addTrack2fit( tmp_kf, particle.child(i) );
	unsigned tmp_err = tmp_kf.fit();
	if(tmp_err != 0) return 0;
	for(int i=ntrk; i<particle.nChildren(); i++){
	  setGammaError( particle.child(i), tmp_kf.vertex(), tmp_kf.errVertex() );
	}
      }
      
      kmassvertexfitter kf;
      for(int i=0; i<particle.nChildren(); i++) addTrack2fit( kf, particle.child(i) );
      kf.invariantMass(particle.pType().mass());
      unsigned err = kf.fit();
      if( err==0 ){ // success.
	info.kf_cl( kf.cl() );
	info.kf_chisq( kf.chisq() );
	info.kf_ndf( kf.dgf() );
	makeMother(kf, particle);
      }else{ // false.
	//std::cout << "false kmassvertexfitter : error code " << err << std::endl;
	return 0;
      }	
    
    }else if(flag_kfitter==4){ // kmassfitter ***********************************************************************************
      kmassfitter kf;
      for(int i=0; i<particle.nChildren(); i++)	addTrack2fit( kf, particle.child(i) );
      kf.invariantMass(particle.pType().mass());
      unsigned err = kf.fit();
      if( err==0 ){ // success.
	info.kf_cl( kf.cl() );
	info.kf_chisq( kf.chisq() );
	info.kf_ndf( kf.dgf() );
	makeMother(kf, particle);
      }else{ // false.
	//std::cout << "false kmassfitter : error code " << err << std::endl;
	return 0;
      }
    }else{
      info.kf_cl(-1);
      info.kf_chisq(-1);
      info.kf_ndf(-1);
    }
    return 1;
  }

  void XSLL::qq_suppress(Particle b, double& thrust_angle, double& R2){
    // signal (rec-B) side
    std::vector<Hep3Vector> alltrk;
    std::vector<Hep3Vector> sigtrk;
    std::vector<Hep3Vector> othtrk;
    std::set<int> sig_id;
    std::set<int> gam_id;
    //std::cout << "**************** < thrust_angle start > *******************"<< std::endl;    
    for(int i=0; i<b.relation().nFinalStateParticles(); i++)
      {
	//std::cout << i << "'th child@ " << b.relation().finalStateParticle(i).pType().name() << "( id = " << b.relation().finalStateParticle(i).mdstCharged().get_ID() << ") " << std::endl;
	HepLorentzVector b_ch(b.relation().finalStateParticle(i).p());
	b_ch.boost( cmboost );
	sigtrk.push_back( b_ch.vect() );
	alltrk.push_back( b_ch.vect() );
	if( b.relation().finalStateParticle(i).mdstCharged().get_ID() ){
	  sig_id.insert( b.relation().finalStateParticle(i).mdstCharged().get_ID() );
	}else{
	  gam_id.insert( b.relation().finalStateParticle(i).mdstGamma().get_ID() );
	}
      }
    /*
    std::cout << "< sig_id [ " << sig_id.size() << " ] )" << std::endl;
    for(std::set<int>::iterator p = sig_id.begin(); p != sig_id.end(); p++){
      std::cout << *p << std::endl;
    }
    std::cout << "< gam_id [ " << gam_id.size() << " ] )" << std::endl;
    for(std::set<int>::iterator p = gam_id.begin(); p != gam_id.end(); p++){
      std::cout << *p << std::endl;
    }
    */
    // remains
    //std::cout << " remains " << std::endl;
    Mdst_charged_Manager& chgMgr = Mdst_charged_Manager::get_manager();
    for(Mdst_charged_Manager::iterator c = chgMgr.begin();
	c != chgMgr.end();
	c++)
      {
	//std::cout << "mdst_charged : " << c->get_ID() << " -> ";
	if( sig_id.find( c->get_ID() ) != sig_id.end() ) {/*std::cout << "continue" << std::endl;*/ continue;}
	Particle tmp( (*c), Ptype(-211) );
	HepLorentzVector tmp_vec( tmp.p());
	tmp_vec.boost( cmboost );
	othtrk.push_back( tmp_vec.vect() );
	alltrk.push_back( tmp_vec.vect() );
	//std::cout << "push_back" << std::endl;
      }
    
    Mdst_gamma_Manager& gamMgr = Mdst_gamma_Manager::get_manager();
    for( Mdst_gamma_Manager::iterator gam = gamMgr.begin(); gam!=gamMgr.end(); gam++){
      //std::cout << "mdst_gamma : " << gam->get_ID() << " -> ";
      if( gam_id.find( gam->get_ID() ) != gam_id.end() ){/*std::cout << "continue(id)" << std::endl;*/ continue;}
      Particle tmp_b_gam( *gam );
      HepLorentzVector b_gam( tmp_b_gam.p() );
      b_gam.boost( cmboost );
      othtrk.push_back( b_gam.vect() );
      alltrk.push_back( b_gam.vect() );
      //std::cout << "push_back" << std::endl;
    }

    Vector3 thrust_signal = thrust( sigtrk.begin(), sigtrk.end(), SelfFunc(Vector3()) );
    Vector3 thrust_other  = thrust( othtrk.begin(), othtrk.end(), SelfFunc(Vector3()) );
    double  costhr        = thrust_signal.unit().dot( thrust_other.unit() );
    thrust_angle          = fabs(costhr);
    FoxWolfram fw( foxwolfram(alltrk.begin(), alltrk.end(), SelfFunc(Vector3())) );
    R2 = fw.R(2);
  }

  int XSLL::masscut(Particle particle, const double low, const double high, const double mass){
    // mass(PDG) + low < mass(REC) < mass(PDG) + high
    // 1 -> masscut through, 0 -> masscut rejection
    if( particle.momentum().mass() - mass < high && particle.momentum().mass() - mass > low ) return 1;
    else return 0;

  }

  void XSLL::make_Fmiss( std::vector<Particle>& trk_list, std::vector<Particle>& gamma_list,
			 std::vector<Particle>& ks_list,
			 std::vector<Particle>::iterator b ){
    // [ Combinatorial B.G. Suppression ]
    const double dr_cut1 = 1;
    const double dz_cut1 = 5;
    const double dr_cut2 = 3;
    const double dz_cut2 = 15;

    double Evis1=0;       // 1st dr-dz category and not from Ks
    double Evis2=0;       // 2nd dr-dz category and not from Ks
    double Evis3=0;       // 3rd dr-dz category and not from Ks
    double Evis1_notKs=0; // 1st dr-dz category and     from Ks
    double Evis2_notKs=0; // 2nd dr-dz category and     from Ks
    double Evis3_notKs=0; // 3rd dr-dz category and     from Ks
    double Evis_Ks=0;     // from Ks
    double Evis_g=0;      // from gamma
    
    Hep3Vector Ptot1(0);
    Hep3Vector Ptot2(0);
    Hep3Vector Ptot3(0);
    Hep3Vector Ptot1_notKs(0);
    Hep3Vector Ptot2_notKs(0);
    Hep3Vector Ptot3_notKs(0);
    Hep3Vector Ptot_Ks(0);
    Hep3Vector Ptot_g(0);

    double E_oth1=0;
    double E_oth2=0;
    double E_oth3=0;
    double E_oth1_notKs=0;
    double E_oth2_notKs=0;
    double E_oth3_notKs=0;
    double E_othKs=0;
    double E_othg=0;
    
    // <Ks>
    for( std::vector<Particle>::iterator k = ks_list.begin(); k != ks_list.end(); k++ ){
      UserInfo& info_ks  = dynamic_cast<UserInfo&>( k->userInfo()  );
      Evis_Ks += info_ks.Vcm().e();
      Ptot_Ks += info_ks.Vcm().vect();
      if( check_dupli_daughter(b,k)==0 ) E_othKs += info_ks.Vcm().e();
    }
    // <tracks>
    for( std::vector<Particle>::iterator p = trk_list.begin();
	 p != trk_list.end();
	 p++ )
      {
	int fl_from_ks = 0;	
	UserInfo& info_trk  = dynamic_cast<UserInfo&>( p->userInfo()  );
	for( std::vector<Particle>::iterator k = ks_list.begin(); k != ks_list.end(); k++ ){
	  if( check_dupli_daughter(p,k)==0 ) fl_from_ks = 1;
	}

	if     ( info_trk.dr() < dr_cut1 && info_trk.dz() < dz_cut1 ) Evis1 += info_trk.Vcm().e(), Ptot1 += info_trk.Vcm().vect(); // 1st drdz category
	else if( info_trk.dr() < dr_cut2 && info_trk.dz() < dz_cut2 ) Evis2 += info_trk.Vcm().e(), Ptot2 += info_trk.Vcm().vect(); // 2nd drdz category
	else                                                          Evis3 += info_trk.Vcm().e(), Ptot3 += info_trk.Vcm().vect(); // 3rd drdz category
	
	if( fl_from_ks==0 ){ // track not from Ks
	  if     ( info_trk.dr() < dr_cut1 && info_trk.dz() < dz_cut1 ) Evis1_notKs += info_trk.Vcm().e(), Ptot1_notKs += info_trk.Vcm().vect(); // 1st drdz category
	  else if( info_trk.dr() < dr_cut2 && info_trk.dz() < dz_cut2 ) Evis2_notKs += info_trk.Vcm().e(), Ptot2_notKs += info_trk.Vcm().vect(); // 2nd drdz category
	  else                                                          Evis3_notKs += info_trk.Vcm().e(), Ptot3_notKs += info_trk.Vcm().vect(); // 3rd drdz category
	}
	
	if( check_dupli_daughter(p,b) ){ 
	  if     ( info_trk.dr() < dr_cut1 && info_trk.dz() < dz_cut1 ) E_oth1 += info_trk.Vcm().e(); // 1st drdz category
	  else if( info_trk.dr() < dr_cut2 && info_trk.dz() < dz_cut2 ) E_oth2 += info_trk.Vcm().e(); // 2nd drdz category
	  else                                                          E_oth3 += info_trk.Vcm().e(); // 3rd drdz category

	  if( fl_from_ks==0 ){ // track not from Ks
	    if     ( info_trk.dr() < dr_cut1 && info_trk.dz() < dz_cut1 ) E_oth1_notKs += info_trk.Vcm().e(); // 1st drdz category
	    else if( info_trk.dr() < dr_cut2 && info_trk.dz() < dz_cut2 ) E_oth2_notKs += info_trk.Vcm().e(); // 2nd drdz category
	    else                                                          E_oth3_notKs += info_trk.Vcm().e(); // 3rd drdz category
	  }
	}
      }
    
    // <gamma>
    for( std::vector<Particle>::iterator g = gamma_list.begin();
	 g != gamma_list.end();
	 g++ )
      {
	UserInfo& info_allgam = dynamic_cast<UserInfo&>( g->userInfo()  );
	Evis_g += info_allgam.Vcm().e();
	Ptot_g += info_allgam.Vcm().vect();
	if( check_dupli_daughter(g,b) ) E_othg += info_allgam.Vcm().e();
      }

    double     mmiss2=0;
    double     Evis=0;
    Hep3Vector Ptot(0);

    // 1st category NOT including Ks
    Evis = Evis_g + Evis1;
    Ptot = Ptot_g + Ptot1;
    mmiss2 = (2*eb-Evis)*(2*eb-Evis) - Ptot.mag2();
    B_dist->column( "evis1",  Evis );
    B_dist->column( "mmiss1", mmiss2 > 0 ? sqrt(mmiss2) : -sqrt(-mmiss2)  );
    /*
    // 1st category including Ks
    Evis = Evis_Ks + Evis_g + Evis1_notKs;
    Ptot = Ptot_Ks + Ptot_g + Ptot1_notKs;
    mmiss2 = (2*eb-Evis)*(2*eb-Evis) - Ptot.mag2();
    B_dist->column( "evis1ks",  Evis );
    B_dist->column( "mmiss1ks", mmiss2 > 0 ? sqrt(mmiss2) : -sqrt(-mmiss2)  );    

    // 2nd category NOT includgin Ks
    Evis = Evis_g + Evis1 + Evis2;
    Ptot = Ptot_g + Ptot1 + Ptot2;
    mmiss2 = (2*eb-Evis)*(2*eb-Evis) - Ptot.mag2();
    B_dist->column( "evis2",  Evis );
    B_dist->column( "mmiss2", mmiss2 > 0 ? sqrt(mmiss2) : -sqrt(-mmiss2)  );

    // 2nd category including Ks
    Evis = Evis_Ks + Evis_g + Evis1_notKs + Evis2_notKs;
    Ptot = Ptot_Ks + Ptot_g + Ptot1_notKs + Ptot2_notKs;
    mmiss2 = (2*eb-Evis)*(2*eb-Evis) - Ptot.mag2();
    B_dist->column( "evis2ks",  Evis );
    B_dist->column( "mmiss2ks", mmiss2 > 0 ? sqrt(mmiss2) : -sqrt(-mmiss2)  );

    // 3rd category NOT including Ks
    Evis = Evis_g + Evis1 + Evis2 + Evis3;
    Ptot = Ptot_g + Ptot1 + Ptot2 + Ptot3;
    mmiss2 = (2*eb-Evis)*(2*eb-Evis) - Ptot.mag2();
    B_dist->column( "evis3",  Evis );
    B_dist->column( "mmiss3", mmiss2 > 0 ? sqrt(mmiss2) : -sqrt(-mmiss2)  );

    // 3rd category includgin Ks
    Evis = Evis_Ks + Evis_g + Evis1_notKs + Evis2_notKs + Evis3_notKs;
    Ptot = Ptot_Ks + Ptot_g + Ptot1_notKs + Ptot2_notKs + Ptot3_notKs;
    mmiss2 = (2*eb-Evis)*(2*eb-Evis) - Ptot.mag2();
    B_dist->column( "evis3ks",  Evis );
    B_dist->column( "mmiss3ks", mmiss2 > 0 ? sqrt(mmiss2) : -sqrt(-mmiss2)  );    
    */
    // NOT including Ks
    B_dist->column( "deroe1",    E_othg + E_oth1                   - eb );
    //B_dist->column( "deroe2",    E_othg + E_oth1 + E_oth2          - eb );
    //B_dist->column( "deroe3",    E_othg + E_oth1 + E_oth2 + E_oth3 - eb );
    // including Ks
    //B_dist->column( "deroe1ks",  E_othKs + E_othg + E_oth1_notKs                               - eb );
    //B_dist->column( "deroe2ks",  E_othKs + E_othg + E_oth1_notKs + E_oth2_notKs                - eb );
    //B_dist->column( "deroe3ks",  E_othKs + E_othg + E_oth1_notKs + E_oth2_notKs + E_oth3_notKs - eb );
    
    return;
  }

  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
