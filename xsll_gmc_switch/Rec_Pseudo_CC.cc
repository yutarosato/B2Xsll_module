#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif
  
  void XSLL::Rec_Pseudo_CC(std::vector<Particle>& pseudo_cc_list,
			   std::vector<Particle>& lep_list,
			   std::vector<Particle>& gamma_list,
			   int flag_correct_rad, // 0->not correct, 1->correct all rad-gam, 2->correct only one rad-gam
			   const bool fl_message
			   )
  {
    if( fl_message ) std::cout << "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC" << std::endl;

    for(std::vector<Particle>::iterator p = lep_list.begin();
	p != lep_list.end();
	p++)
      {
	for(std::vector<Particle>::iterator m = lep_list.begin();
	    m != lep_list.end();
	    m++)
	  {
	    if( fl_message ) std::cout << "Lplus_LUND = "
				       << std::setw(4) << std::right << p->lund() << "("
				       << std::setw(2) << std::right << p->mdstCharged().get_ID() << ")"
				       << ", Lminus_LUND = "
				       << std::setw(4) << std::right << m->lund() << "("
				       << std::setw(2) << std::right << m->mdstCharged().get_ID() << ")";
	    
	    // charge check
	    if( !(p->charge()>0 && m->charge()<0) ){
	      if( fl_message ) std::cout << " -> not allowed charge : " << p->charge() << " * " << m->charge() << std::endl;
	      continue;
	    }
	    
	    // reconstruction from lepton pair
	    Particle pseudo_cc( p->p() + m->p(), Ptype(JPsi_LUND) ); // JPsi_LUND is arbitrary.
	    if( !((p->lund()*m->lund()==-121) || (p->lund()*m->lund()==-169)) ){
	      if( fl_message ) std::cout << " -> not allowed e-mu combination : " << p->lund() << " * " << m->lund() << std::endl;
	      continue;
	    }

	    if( pseudo_cc.mass() < pseudo_cc_M_cut ){
	      if( fl_message ) std::cout << " -> not allowed by masscut : " << pseudo_cc.mass() << std::endl;
	      continue;
	    }
	      
	    pseudo_cc.relation().append( *p );
	    pseudo_cc.relation().append( *m );

	    // userinfo
	    setUserInfo( pseudo_cc );
	    UserInfo& info = dynamic_cast<UserInfo&>( pseudo_cc.userInfo() );
	    info.radgam( flag_correct_rad );
	    info.rec_mode( m->lund() == Electron_LUND ? 1 : 0 );

	    HepLorentzVector pseudo_cc_4Vcm = pseudo_cc.p();
	    pseudo_cc_4Vcm.boost( cmboost );
	    info.Vcm( pseudo_cc_4Vcm );
	    
	    info.m_org( pseudo_cc.mass() ); // original mass before correction of radiation gamma
	    // ****************************************************************************
	    // correct the radiation gamma
	    //if( flag_correct_rad == 1 && info.rec_mode() ){ // all gamma add
	    if( flag_correct_rad == 1 ){ // all gamma add // modified at 20120821
	      add_bremsstrahlung( pseudo_cc, gamma_list );
	    }
	    // ****************************************************************************
	    
	    pseudo_cc_list.push_back( pseudo_cc );
	    if( fl_message ) std::cout << std::endl;
	    
	  }
      }
    if( fl_message ) std::cout << "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC" << std::endl
			       << "                          # of CC candidates : " << pseudo_cc_list.size()       << std::endl
			       << "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC" << std::endl;
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
