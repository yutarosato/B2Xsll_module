#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  void XSLL::Gamma_cand( std::vector<Particle>& gamma_list, const bool fl_message )
  {
    if( fl_message ) std::cout << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG" << std::endl;
    
    Mdst_gamma_Manager& gamMgr = Mdst_gamma_Manager::get_manager();
    for( Mdst_gamma_Manager::iterator g = gamMgr.begin(); g!=gamMgr.end(); g++ ){
      // make particle
      Particle gamma( *g );
      gamma.relation().mdstEcl( g->ecl() );
      setUserInfo( gamma );
      UserInfo& info = dynamic_cast<UserInfo&>( gamma.userInfo() );
      
      gamma_list.push_back( gamma );
    }
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
