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
    if( fl_message ) std::cout << "XSK0PIXSK0PIXSK0PIXSK0PIXSK0PIXSK0PIXSK0PIXSK0PIXSK0PIXSK0PIXSK0PIXSK0PIXSK0PI" << std::endl
      			       << "<rec_mode_xs> :  " << rec_mode_xs << std::endl;

    for( std::vector<Particle>::iterator k = k_list.begin(); k != k_list.end(); k++ ){
      // reconstruction
      Particle Xs( k->p(), Ptype(k->lund()) );

      // masscut
      if( Xs.momentum().mass() > masscut_Xs ){
	if( fl_message ) std::cout << " -> too large Xs mass " << std::endl;
	continue;
      }
      
      Xs.relation().append( *k );
      setUserInfo( Xs );
      UserInfo& info = dynamic_cast<UserInfo&>( Xs.userInfo() );
      info.rec_mode( rec_mode_xs );
      
      if( fl_message ) std::cout << "K_LUND = "
				 << std::setw(4)   << std::right << k->lund() << "("
				 << std::setw(2)   << std::right << k->mdstCharged().get_ID() << ")"
				 << " -> rec_mode_xs = "
				 << std::setw(5)   << std::right << rec_mode_xs
				 << ", Xs_LUND = " 
				 << std::setw(8)   << std::right << Xs.lund()
				 << std::endl;
      xs_list.push_back( Xs );
    }
    if( fl_message ) std::cout << "XSK0PIXSK0PIXSK0PIXSK0PIXSK0PIXSK0PIXSK0PIXSK0PIXSK0PIXSK0PIXSK0PIXSK0PIXSK0PI" << std::endl;
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
