#include "belle.h"
#include "XSLL.h"
//#include "toolbox/FoxWolfr.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif
  
  int XSLL::check_selfF(Particle& particle){ // final state particle(K,PI,E,MU,Proton)
    if( mc==0 ) return -1;
    int self=0;
    if( particle.mdstCharged() ){
      const Gen_hepevt & hep( get_hepevt(particle.mdstCharged()) );
      particle.relation().genHepevt( hep );
      if ( hep && particle.pType().lund() == hep.idhep() ) self=1;
    }
    return self;
  }

  int XSLL::check_selfF(Particle& particle, int self_LUND, int mother_LUND, int mothermother_LUND){ // particle originated from specific decay mode?
    if( mc==0 ) return -1;
    if( particle.mdstCharged() ){
      const Gen_hepevt & hep( get_hepevt(particle.mdstCharged()) );
      if ( !(hep && abs(particle.pType().lund())==self_LUND && particle.pType().lund()==hep.idhep()) ){ // self
	return 0;
      }else{
	if( mother_LUND==0 ){
	  return 1;
	}else{
	  if( !(hep.mother() && hep.mother().idhep()==mother_LUND) ){ // mother
	    return 0;
	  }else{
	    if( mothermother_LUND==0 ){
	      return 1;
	    }else{
	      if( !(hep.mother().mother() && hep.mother().mother().idhep() == mothermother_LUND) ){ // mother-mohter
		return 0;
	      }else{
		return 1;
	      }
	    }
	  }
	}
      }
    }
    return 0;
  }

  int XSLL::check_idF(Particle& particle){ // final state particle(K,PI,E,MU,Proton)
    if( mc==0 ) return -1;
    int id=0;
    if( particle.mdstCharged() ){
      const Gen_hepevt & hep( get_hepevt(particle.mdstCharged()) );
      if( hep ) id = hep.idhep();
    }
    return id;
  }

  int XSLL::check_motheridF(Particle& particle){ // final state particle(K,PI,E,MU,Proton)
    if( mc==0 ) return -1;
    int motherid=0;
    if( particle.mdstCharged() ){
      const Gen_hepevt & hep( get_hepevt(particle.mdstCharged()) );
      if( hep && hep.mother() ) motherid = hep.mother().idhep();
    }
    return motherid;
  }

  int XSLL::check_selfG(Particle& particle){ // gamma
    if( mc==0 ) return -1;
    int self=0;
    if( particle.mdstGamma() ){
      const Gen_hepevt & hep( gen_level(get_hepevt(particle.mdstGamma())) );
      if( hep && particle.pType().lund() == hep.idhep() ){
	particle.relation().genHepevt( hep );
	self=1;
      }
    }
    return self;
  }
    
  int XSLL::check_selfR(Particle& particle, int id, int nchild){ // reconstructed particles (we must specify the number of children)
    if( mc==0 ) return -1;
    
    // check that genHep references exist;
    for(int i=0; i<nchild; ++i){
      if( !particle.child(i).genHepevt() ) return 0;
    }
    
    // check duplication and same mother(we do not distinguish B0-antiB0 and D0-antiD0)
    for(int i=0; i<nchild-1; ++i){
      for(int j=i+1; j<nchild; ++j){
	if( particle.child(i).genHepevt().get_ID() == particle.child(j).genHepevt().get_ID() ) return 0;
	if( particle.child(i).genHepevt().mother().get_ID() != particle.child(j).genHepevt().mother().get_ID()  ) return 0;
	if(  abs(particle.pType().lund()) == B0_LUND || abs(particle.pType().lund()) == D0_LUND ){
	  if( abs(particle.pType().lund()) != abs(particle.child(i).genHepevt().mother().idhep()) ) return 0;
	}else{
	  if( particle.pType().lund() != particle.child(i).genHepevt().mother().idhep() ) return 0;
	}
      }
    }

    // check the number of children
    int truenchild = particle.child(0).genHepevt().mother().daLast()==0 ? 0 : particle.child(0).genHepevt().mother().daLast() - particle.child(0).genHepevt().mother().daFirst() + 1;
    
    if( nchild != truenchild ){ // allow the non-reconstructed gamma
      Gen_hepevt_Manager& genMgr = Gen_hepevt_Manager::get_manager();
      //std::cout << " ************** " << particle.pType().name() << " **********************" << std::endl;
      //for(int i=0; i <= particle.child(0).genHepevt().mother().daLast() - particle.child(0).genHepevt().mother().daFirst(); i++){
      //std::cout << particle.child(0).genHepevt().mother().daFirst()+i << " : " << genMgr( Panther_ID( particle.child(0).genHepevt().mother().daFirst()+i ) ).idhep() << std::endl;
      //}
      if( genMgr( Panther_ID( particle.child(0).genHepevt().mother().daFirst() + nchild ) ).idhep() != 22 ) return 0;
    }
    
    particle.relation().genHepevt( particle.child(0).genHepevt().mother() );
    return 1;
  }

  void XSLL::display_particle(Particle particle){
    std::cout << " ******* < display particle > *************************************** " << std::endl
	      << "   < position >   : " << particle.x()
	      << particle.momentum().dx()
	      << "   < momentum >   : " << particle.p()
	      << particle.momentum().dp()
	      << " < error matrix > "   << particle.momentum().dpx()
	      << " < prod. vertex > : " << particle.momentum().vertex()
	      << particle.momentum().dVertex()
	      << " < decay vertex > : " << particle.momentum().decayVertex()
	      << particle.momentum().dDecayVertex()
	      << "LUND = " << particle.pType().lund() << "(" << particle.pType().name() << ")" << std::endl
	      << "nChildren = " << particle.nChildren() << std::endl;
    for(int i=0; i<particle.nChildren(); i++)
      std::cout << "child " << i << " : " << particle.child(i).pType().lund() << "(" << particle.child(i).pType().name() << ")" << std::endl;
    //std::cout << "nFinalStateParticles = " << particle.relation().nFinalStateParticles() << std::endl;
    return;
  }
  
  void XSLL::display_hepevt(Gen_hepevt gen){
    if( mc==0 ) return;
    Gen_hepevt_Manager& genMgr = Gen_hepevt_Manager::get_manager();
    int nchild = gen.daLast()==0 ? 0 : gen.daLast() - gen.daFirst() + 1;
    std::cout << " ******* < display hepevt > *************************************** " << std::endl
	      << " <    self ID    > : " << gen.idhep()
	      << " ( " << gen.get_ID() << " ) " << std::endl
	      << " < # of children > : " << nchild       << std::endl;
    for( int i=0; i<nchild; i++)
      std::cout << "    " << i << " : "
		<< std::setw(6) << genMgr( Panther_ID(gen.daFirst()+i) ).idhep()
		<< " ( "
		<< genMgr( Panther_ID(gen.daFirst()+i) ).get_ID()
		<< " )"
		<< std::endl;
    return;
  }

  void XSLL::display_list( std::set<int> set, std::multiset<int> multiset ){
    std::cout << "=============================================================================" << std::endl
	      << "# of particles :  LUND code" << std::endl
	      << "-----------------------------------------------------------------------------" << std::endl;
    for (std::set<int>::iterator i = set.begin(); i != set.end(); i++){
      Ptype tmp( *i );
      std::cout << std::setw(14) << std::right << multiset.count( *i ) << " : "
		<< std::setw(10) << std::right << *i                   << " ( "
		<< std::setw(20) << std::left  << tmp.name()           << " ) "
		<< std::endl;
    }
    std::cout << "-----------------------------------------------------------------------------" << std::endl;
    return;
  }

  void XSLL::find_fin_child( Gen_hepevt gen,
			     std::map<int, int>& child_id_map,
			     std::multiset<int>& n_particle_set,
			     bool fl_message, // if fl_message = true, messages are displayed.
			     int indent       // the number of indent. Users do not handle it.
			     ){
    if( mc==0 ) return;
    Gen_hepevt_Manager& genMgr = Gen_hepevt_Manager::get_manager();
    int nchild = gen.daLast()==0 ? 0 : gen.daLast() - gen.daFirst() + 1;
    if( fl_message && indent==1 ){
      std::cout << "==============================================================================" << std::endl
		<< " idhep() [ get_ID(), nchild ]    " << std::endl
		<< "------------------------------------------------------------------------------" << std::endl;
      std::cout << gen.idhep()  << "[ "
		<< gen.get_ID() << ", "
		<< nchild       << " ] "
		<< std::endl;
    }
    
    if( abs(gen.idhep()) == Kplus_LUND ){
      if( child_id_map.count(gen.get_ID()) != 0) std::cout << "error ????? duplication" << std::endl;
      child_id_map.insert( std::pair<int, int> (gen.get_ID(),gen.idhep()) );
      n_particle_set.insert( abs(gen.idhep()) );
      return;
    }
    
    if( nchild==0 ){
      std::cout << " particles not having child" << std::endl;
      if( gen.idhep() ) n_particle_set.insert( abs(gen.idhep()) );
    }

    for(int i=0; i<nchild; i++){
      Gen_hepevt& daughter( genMgr(Panther_ID(gen.daFirst() + i)) );
      int nchildchild = daughter.daLast()==0 ? 0 : daughter.daLast() - daughter.daFirst() + 1;
      if( fl_message ){
	std::cout << std::setw(indent*6) << std::right << " +-> "
		  << daughter.idhep()  << " [ "
		  << daughter.get_ID() << " , "
		  << nchildchild       << " ] ";
	  }
      
      if ( recon_set.count( daughter.idhep()) ){ // recon_particles
	if( fl_message ) std::cout << " --> recon_particles" << std::endl;
	if( child_id_map.count(gen.get_ID()) != 0) std::cout << "error ????? duplication" << std::endl;
	child_id_map.insert( std::pair<int, int> (daughter.get_ID(), daughter.idhep() ) );
	n_particle_set.insert( abs(daughter.idhep()) );
      }else if( nonrecon_set.count( daughter.idhep()) ){ // nonrecont_particles
	if( daughter.idhep() == Gamma_LUND && daughter.E() < 0.050 ){ // low energy gamma is neglected.
	  if( fl_message ) std::cout << "--> FSR gamma" << std::endl;
	  continue;
	}
	if( fl_message ) std::cout << "--> nonrecon_particles" << std::endl;
	n_particle_set.insert( abs(daughter.idhep()) );	
      }else{ // other particle --> continue iterations.
	if( fl_message ) std::cout << " --> other particles --> continue iterations" << std::endl;
	  find_fin_child( daughter, child_id_map, n_particle_set, fl_message, indent+1 );
	}
    }
    return;
  }

  int XSLL::mapping_delete( Particle particle, std::map<int, int>& child_id_map,
			     int& n_recon, int gen_mode_bg,
			     char* name, const bool fl_message ){
    int fl=0;
    UserInfo& info_particle = dynamic_cast<UserInfo&>( particle.userInfo() );
    if( gen_mode_bg == 0 && particle.genHepevt() && child_id_map.count( particle.genHepevt().get_ID() ) ){
      if( child_id_map[ particle.genHepevt().get_ID() ] == particle.lund() ){
	n_recon -= 1;
	fl=1;
	if( fl_message ) std::cout << "[ ERASE  : "
				   << std::setw(25) << std::right << name
				   << "] : "
				   << std::setw(10) << std::right << particle.lund() << "("
				   << std::setw(3)  << std::right << particle.genHepevt().get_ID() << ") : "
				   << n_recon     << std::endl;
      }else{
	if( fl_message ) std::cout << "[ REMAIN : "
				   << std::setw(25) << std::right << name
				   << "] : "
				   << std::setw(10) << std::right << particle.lund() << "("
				   << std::setw(3)  << std::right << particle.genHepevt().get_ID() << ") : "
				   << n_recon       << std::endl;
      }
    }
    return fl;
  }

  int XSLL::mapping_delete_sw( Particle particle, std::map<int, int>& child_id_map,
			       int& n_recon, int gen_mode_bg,
			       char* name, const bool fl_message ){
    int fl=0;
    UserInfo& info_particle = dynamic_cast<UserInfo&>( particle.userInfo() );
    if( gen_mode_bg == 0 && particle.genHepevt() && child_id_map.count( particle.genHepevt().get_ID() ) ){
      //if( child_id_map[ particle.genHepevt().get_ID() ] == particle.lund() ){
      n_recon -= 1;
      fl=1;
      if( fl_message ) std::cout << "[ ERASE  : "
				 << std::setw(25) << std::right << name
				 << "] : "
				 << std::setw(10) << std::right << particle.lund() << "("
				 << std::setw(3)  << std::right << particle.genHepevt().get_ID() << ") : "
				 << n_recon     << std::endl;
      else{
	if( fl_message ) std::cout << "[ REMAIN : "
				   << std::setw(25) << std::right << name
				   << "] : "
				   << std::setw(10) << std::right << particle.lund() << "("
				   << std::setw(3)  << std::right << particle.genHepevt().get_ID() << ") : "
				   << n_recon       << std::endl;
      }
      //}
    }
    return fl;
  }
  
  void XSLL::pi0_matching( Particle pi0, std::map<int, int>& id_map,
			   int& pi0self,    int& pi0decay, 
			   int& gam1_self,  int& gam2_self,
			   int& gam1_conv,  int& gam2_conv ){
    // initialize
    pi0self = 2;
    int pi_id, gam1_id, gam2_id, gam1_e1_id, gam1_e2_id, gam2_e1_id, gam2_e2_id;
    UserInfo& info_pi0 = dynamic_cast<UserInfo&>( pi0.userInfo() );
    Particle& pi0_gam1 = pi0.child(0);
    Particle& pi0_gam2 = pi0.child(1);

    // search pi0(gen)
    std::map<int,int>::iterator it = id_map.begin();
    int cnt_pi0 = 0;
    while( it != id_map.end() ){
      if( it->second == PI0_LUND ) pi_id = it->first, cnt_pi0++;
      it++;
    }

    if( cnt_pi0 != 1 ){ // # of pi0(gen) is not 1
      pi0self  = 0;
      pi0decay = -1;
      return;
    }
    
    // judgement pi0(gen) decay mode
    Gen_hepevt_Manager& genMgr = Gen_hepevt_Manager::get_manager();
    Gen_hepevt& true_pi0( genMgr( Panther_ID(pi_id) ) );
    int nchild_pi0 = true_pi0.daLast() ==0 ? 0 : true_pi0.daLast() - true_pi0.daFirst() + 1;

    if( nchild_pi0!=2 ){ // not two-body decay
      pi0self  = 0;
      pi0decay = 0;
      return;
    }
    
    gam1_id = true_pi0.daFirst();
    gam2_id = true_pi0.daFirst()+1;
    Gen_hepevt& g1( genMgr(Panther_ID(gam1_id)) );
    Gen_hepevt& g2( genMgr(Panther_ID(gam2_id)) );

    if( g1.idhep()!=Gamma_LUND || g2.idhep()!=Gamma_LUND ){ // not gamma gamma
      pi0self  = 0;
      pi0decay = 0;
      return;
    }

    // conversion check
    int nchild_gam1 = g1.daLast() ==0 ? 0 : g1.daLast() - g1.daFirst() + 1;
    if( nchild_gam1==2 && Gen_hepevt( genMgr(Panther_ID(g1.daFirst())) ).idhep()*Gen_hepevt( genMgr(Panther_ID(g1.daFirst()+1)) ).idhep()==-121 ){
      gam1_conv = 1; // conversion
      gam1_e1_id = g1.daFirst();
      gam1_e2_id = g1.daFirst()+1;
    }else if( nchild_gam1==1 && abs( Gen_hepevt( genMgr(Panther_ID(g1.daFirst())) ).idhep() ) == 11 ){
      gam1_conv = 2; // hadronic ?
      gam1_e1_id = g1.daFirst();
    }else if( nchild_gam1==0 ) gam1_conv = 0; // normal
    else gam1_conv = 3; // ohter

    int nchild_gam2 = g2.daLast()==0 ? 0 : g2.daLast() - g2.daFirst() + 1;
    if( nchild_gam2==2 && Gen_hepevt( genMgr(Panther_ID(g2.daFirst())) ).idhep()*Gen_hepevt( genMgr(Panther_ID(g2.daFirst()+1)) ).idhep()==-121 ){
      gam2_conv = 1; // conversion
      gam2_e1_id = g2.daFirst();
      gam2_e2_id = g2.daFirst()+1;
    }else if( nchild_gam2==1 && abs( Gen_hepevt( genMgr(Panther_ID(g2.daFirst())) ).idhep() ) == 11 ){
      gam2_conv = 2; // hadronic ?
      gam2_e1_id = g2.daFirst();
    }else if( nchild_gam2==0 ) gam2_conv=0; // normal
    else gam2_conv = 3; // ohter
    
    pi0decay  = 1;
    gam1_self = 2;
    gam2_self = 2;
    int combi = 0; // 1 --> g1=gam1 & g2=gam2, 2--> g1=gam2 & g2=gam1

    if( pi0_gam1.genHepevt().get_ID() && (pi0_gam1.genHepevt().get_ID()!=g1.get_ID() || pi0_gam1.genHepevt().get_ID()!=g2.get_ID()) ) gam1_self = 0;
    if( pi0_gam2.genHepevt().get_ID() && (pi0_gam2.genHepevt().get_ID()!=g1.get_ID() || pi0_gam2.genHepevt().get_ID()!=g2.get_ID()) ) gam2_self = 0;

    if( pi0_gam1.genHepevt().get_ID() && pi0_gam1.genHepevt().get_ID()==g1.get_ID() ){
      gam1_self = 1;
      combi     = 1;
    }
    if( pi0_gam1.genHepevt().get_ID() && pi0_gam1.genHepevt().get_ID()==g2.get_ID() ){
      gam1_self = 1;
      combi     = 2;
    }
    
    if( pi0_gam2.genHepevt().get_ID() && pi0_gam2.genHepevt().get_ID()==g1.get_ID() ){
      gam2_self = 1;
      combi     = 2;
    }
    if( pi0_gam2.genHepevt().get_ID() && pi0_gam2.genHepevt().get_ID()==g2.get_ID() ){
      gam2_self = 1;
      combi     = 1;
    }
    
    //B_dist->column( "combi", combi );
    //B_dist->column( "g1recid", (int)pi0_gam1.genHepevt().get_ID() );
    //B_dist->column( "g2recid", (int)pi0_gam2.genHepevt().get_ID() );
    //B_dist->column( "g1genid", (int)g1.get_ID() );
    //B_dist->column( "g2genid", (int)g2.get_ID() );
    //B_dist->column( "g1e1id",  gam1_e1_id );
    //B_dist->column( "g1e2id",  gam1_e2_id );
    //B_dist->column( "g2e1id",  gam2_e1_id );
    //B_dist->column( "g2e2id",  gam2_e2_id );
  
    if( gam1_self==0 || gam2_self==0 ){
      pi0self = 0;
      return;
    }
    //if( gam1_self==1 && gam2_self==1 ) pi0self = 1; // < g1==g2 should be false !

    if( combi==1 ){
      if( gam1_conv==0 && pi0_gam1.genHepevt().get_ID()==0 ){
	pi0self = 0;
	return;
      }
      if( gam2_conv==0 && pi0_gam2.genHepevt().get_ID()==0 ){
	pi0self = 0;
	return;
      }
    }else if( combi==2 ){
      if( gam1_conv==0 && pi0_gam2.genHepevt().get_ID()==0 ){
	pi0self = 0;
	return;
      }
      if( gam2_conv==0 && pi0_gam1.genHepevt().get_ID()==0 ){
	pi0self = 0;
	return;
      }
    }else{
      if( gam1_conv==0 && gam2_conv==0 && (pi0_gam1.genHepevt().get_ID()==0 || pi0_gam2.genHepevt().get_ID()==0) ){
	pi0self = 0;
	return;
      }
    }
    /*
    if( gam1_conv ){
      Gen_hepevt& gam1_e1( genMgr( Panther_ID(gam1_e1_id) ) );
      double r1  = sqrt( gam1_e1.VX()*gam1_e1.VX() + gam1_e1.VY()*gam1_e1.VY() );
      double z1  = gam1_e1.VZ();
    }
    if( gam2_conv ){
      Gen_hepevt& gam2_e1( genMgr( Panther_ID(gam2_e1_id) ) );
      double r2  = sqrt( gam2_e1.VX()*gam2_e1.VX() + gam2_e1.VY()*gam2_e1.VY() );
      double z2  = gam2_e1.VZ();
    }
    */

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
    //+++++++++++++++++++++++++++++++++ test +++++++++++++++++++++++++++++
    /*
    if( gam1_conv ){
      Gen_hepevt& gam1_e1( genMgr( Panther_ID(gam1_e1_id) ) );
      double r1  = sqrt( gam1_e1.VX()*gam1_e1.VX() + gam1_e1.VY()*gam1_e1.VY() );
      if( gam1_e1.VY() < 0 ) r1 *= -1;
      double z1  = gam1_e1.VZ();
      double pr1 = sqrt( gam1_e1.PX()*gam1_e1.PX() + gam1_e1.PY()*gam1_e1.PY() );
      if( gam1_e1.PY() < 0 ) pr1 *= -1;
      double pz1 = gam1_e1.PZ();
      t1_dist->column( "r",    r1 );
      t1_dist->column( "z",    z1 );
      t1_dist->column( "conv", gam1_conv );
      t1_dist->column( "cnt",  1 );
      t1_dist->dumpData();
      
      if( gam1_conv == 1 ){
	Gen_hepevt& gam1_e2( genMgr( Panther_ID(gam1_e2_id) ) );
	double r2  = sqrt( gam1_e2.VX()*gam1_e2.VX() + gam1_e2.VY()*gam1_e2.VY() );
	if( gam1_e2.VY() < 0 ) r2 *= -1;
	double z2  = gam1_e2.VZ();
	double pr2 = sqrt( gam1_e2.PX()*gam1_e2.PX() + gam1_e2.PY()*gam1_e2.PY() );
	if( gam1_e2.PY() < 0 ) pr2 *= -1;
	double pz2 = gam1_e2.PZ();
	t1_dist->column( "r",    r2 );
	t1_dist->column( "z",    z2 );
	t1_dist->column( "conv", gam1_conv );
	t1_dist->column( "cnt",  2 );
	t1_dist->dumpData();
      }
    }
    //+++++++++++++++++++++++++++++++++

    if( gam2_conv ){
      Gen_hepevt& gam2_e1( genMgr( Panther_ID(gam2_e1_id) ) );
      double r1  = sqrt( gam2_e1.VX()*gam2_e1.VX() + gam2_e1.VY()*gam2_e1.VY() );
      if( gam2_e1.VY() < 0 ) r1 *= -1;
      double z1  = gam2_e1.VZ();
      
      double pr1 = sqrt( gam2_e1.PX()*gam2_e1.PX() + gam2_e1.PY()*gam2_e1.PY() );
      if( gam2_e1.PY() < 0 ) pr1 *= -1;
      double pz1 = gam2_e1.PZ();
      t1_dist->column( "r",    r1 );
      t1_dist->column( "z",    z1 );
      t1_dist->column( "conv", gam2_conv );
      t1_dist->column( "cnt",  1 );
      t1_dist->dumpData();
      
      if( gam2_conv == 1 ){
	Gen_hepevt& gam2_e2( genMgr( Panther_ID(gam2_e2_id) ) );
	double r2  = sqrt( gam2_e2.VX()*gam2_e2.VX() + gam2_e2.VY()*gam2_e2.VY() );
	if( gam2_e2.VY() < 0 ) r2 *= -1;
	double z2  = gam2_e2.VZ();
	double pr2 = sqrt( gam2_e2.PX()*gam2_e2.PX() + gam2_e2.PY()*gam2_e2.PY() );
	if( gam2_e2.PY() < 0 ) pr2 *= -1;
	double pz2 = gam2_e2.PZ();
	t1_dist->column( "r",    r2 );
	t1_dist->column( "z",    z2 );
	t1_dist->column( "conv", gam2_conv );
	t1_dist->column( "cnt",  2 );
	t1_dist->dumpData();
      }
    }
    */
    return;
  }

  int XSLL::which_B( Gen_hepevt gen, int id1, int id2 ){ // 1 : B1, 2 : B2, -1 : not B
    Gen_hepevt_Manager& genMgr = Gen_hepevt_Manager::get_manager();
    if( abs(gen.idhep()) == B0_LUND || abs(gen.idhep()) == Bplus_LUND ){
      if( gen.get_ID() == id1 ){
	return 1;
      }else if( gen.get_ID() == id2 ){
	return 2;
      }else{
	return -1;
      }
    }else{
      int flag = 0;
      if( gen.moFirst() ) flag = which_B( genMgr(Panther_ID(gen.moFirst())), id1, id2 );
      else flag = -1;
      if( flag ) return flag;
    }
  }
  
#if defined(BELLE_NAMESPACE)
      } //namespace Belle
#endif
