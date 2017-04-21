#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif
  
  void XSLL::Rec_Xs_K( std::vector<Particle>& xs_list,
		       std::vector<Particle>& k_list,
		       const bool fl_message
		       )
  {
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if( k_list.size()==0 ) return;
    int rec_mode_xs = k_list.begin()->charge()==0 ? 10 : 1; // Ks : charged K
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    for( std::vector<Particle>::iterator k = k_list.begin(); k != k_list.end(); k++ ){
      // reconstruction
      Particle Xs( k->p(), Ptype(k->lund()) );
      
      Xs.relation().append( *k );
      setUserInfo( Xs );
      UserInfo& info = dynamic_cast<UserInfo&>( Xs.userInfo() );
      info.rec_mode( rec_mode_xs );
      
      xs_list.push_back( Xs );
    }
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
