#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif
  
  void XSLL::Rec_Pseudo_CC(std::vector<Particle>& pseudo_cc_list,
			   std::vector<Particle>& lep_list,
			   std::vector<Particle>& gamma_list,
			   int flag_correct_rad // 0->not correct, 1->correct all rad-gam, 2->correct only one rad-gam
			   )
  {
    double min_e_dilep=0;
    for(std::vector<Particle>::iterator p = lep_list.begin();
	p != lep_list.end();
	p++)
      {
	for(std::vector<Particle>::iterator m = lep_list.begin();
	    m != lep_list.end();
	    m++)
	  {
	    // calculation at CM frame
	    HepLorentzVector p_4Vcm = p->p();
	    HepLorentzVector m_4Vcm = m->p();
	    p_4Vcm.boost( cmboost );
	    m_4Vcm.boost( cmboost );
	    if( min_e_dilep < (p_4Vcm + m_4Vcm).e() ) min_e_dilep = ( p_4Vcm + m_4Vcm ).e();
	    // charge check
	    if( !(p->charge()>0 && m->charge()<0) ) continue;

	    // reconstruction from lepton pair
	    Particle pseudo_cc( p->p() + m->p(), Ptype(JPsi_LUND) ); // JPsi_LUND is arbitrary.
	    if( !((p->lund()*m->lund()==-121) || (p->lund()*m->lund()==-169)) ) continue;

	    pseudo_cc.relation().append( *p );
	    pseudo_cc.relation().append( *m );

	    // userinfo
	    setUserInfo( pseudo_cc );
	    UserInfo& info = dynamic_cast<UserInfo&>( pseudo_cc.userInfo() );
	    info.rec_mode( m->lund() == Electron_LUND ? 1 : 0 );

	    // ****************************************************************************
	    // correct the radiation gamma
	    if( flag_correct_rad == 1 && info.rec_mode() ){ // all gamma add
	      add_bremsstrahlung( pseudo_cc, gamma_list );
	    }
	    // ****************************************************************************
	    
	    pseudo_cc_list.push_back( pseudo_cc );
	  }
      }
    if( min_e_dilep < min_e_dilep_cut ) pseudo_cc_list.clear();
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
