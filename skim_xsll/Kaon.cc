#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  void XSLL::Kaon_cand( std::vector<Particle>& kaon_list, const bool fl_message )
  {
    Mdst_charged_Manager& chgMgr = Mdst_charged_Manager::get_manager();
    for( Mdst_charged_Manager::iterator c = chgMgr.begin();
	c != chgMgr.end();
	c++ )
      {
	// reduce beam B.G.
	double dr = correct_dr( (*c), m_IP, KAON_CODE );
	double dz = correct_dz( (*c), m_IP, KAON_CODE );
	if( fabs(dr) > Dr_cut ) continue;
	if( fabs(dz) > Dz_cut ) continue;

	// make particle
	Particle kaon( (*c), Ptype(c->charge() > 0 ? Kplus_LUND : Kminus_LUND) );
	setUserInfo( kaon );
	UserInfo& info = dynamic_cast<UserInfo&>( kaon.userInfo() );
	
	kaon_list.push_back( kaon );
      }
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
