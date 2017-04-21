#include "belle.h"
#include "XSLL.h"

#include <vector>
#include <iostream>
#include <stdlib.h>

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  void XSLL::Pi0_cand( std::vector<Particle>& pi0_list, const bool fl_message )
  {
    Mdst_pi0_Manager& pi0Mgr = Mdst_pi0_Manager::get_manager();
    for( Mdst_pi0_Manager::iterator p = pi0Mgr.begin(); p != pi0Mgr.end(); p++ ){
      // make particle
      Particle pi0( (*p), true );
      //if( !masscut(pi0, masscut_pi0_L, masscut_pi0_H, PDG_PI0Mass) ) continue;
      double morg = (pi0.child(0).p() + pi0.child(1).p()).m();
      if( !(morg - PDG_PI0Mass < masscut_pi0_H && morg - PDG_PI0Mass >= masscut_pi0_L) ) continue;
      setUserInfo( pi0 );
      UserInfo& info = dynamic_cast<UserInfo&>(pi0.userInfo());
      
      
      Particle& gam0 = pi0.child(0);
      Particle& gam1 = pi0.child(1);
      
      setUserInfo( gam0 );
      setUserInfo( gam1 );
      UserInfo& info0 = dynamic_cast<UserInfo&>( gam0.userInfo() );
      UserInfo& info1 = dynamic_cast<UserInfo&>( gam1.userInfo() );
      
      pi0_list.push_back( pi0 );
    }
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
