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
  //   this function is supported for only charged tracks( not gamma).
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
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
