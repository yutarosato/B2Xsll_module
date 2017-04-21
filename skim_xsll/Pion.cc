#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  void XSLL::Pion_cand( std::vector<Particle>& pion_list, const bool fl_message )
  {
    Mdst_charged_Manager& chgMgr = Mdst_charged_Manager::get_manager();
    for( Mdst_charged_Manager::iterator c = chgMgr.begin();
	c != chgMgr.end();
	c++ )
      {
	// reduce beam B.G.
	double dr = correct_dr( (*c), m_IP, PION_CODE );
	double dz = correct_dz( (*c), m_IP, PION_CODE );
	if( fabs(dr) > Dr_cut ) continue;
	if( fabs(dz) > Dz_cut ) continue;

	// make particle
	Particle pion( (*c), Ptype(c->charge() > 0 ? PIplus_LUND : PIminus_LUND) );
	setUserInfo( pion );
	UserInfo& info = dynamic_cast<UserInfo&>( pion.userInfo() );

	pion_list.push_back( pion );
      }
  }

#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
