#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif
  
  void XSLL::EE_cand( std::vector<Particle>& ee_list, const bool fl_message )
  {
    Mdst_charged_Manager& chgMgr = Mdst_charged_Manager::get_manager();
    for( Mdst_charged_Manager::iterator c = chgMgr.begin();
	c != chgMgr.end();
	c++ )
      {
	// reduce beam B.G.
	double dr = correct_dr( (*c), m_IP, EE_CODE );
	double dz = correct_dz( (*c), m_IP, EE_CODE );
	if( fabs(dr) > Dr_cut ) continue;
	if( fabs(dz) > Dz_cut ) continue;
	
	// eid
	eid e( *c );
	double eidProb = e.prob( 3,-1,5 );
	if( eidProb <= eidprob_cut ) continue;
	
	// make particle
	Particle electron( (*c), Ptype(c->charge() > 0 ? Positron_LUND : Electron_LUND) );

	if( electron.ptot() < electron_P_cut ) continue;
	
	setUserInfo( electron );
	UserInfo& info = dynamic_cast<UserInfo&>( electron.userInfo() );

	ee_list.push_back( electron );
	
      }
  }

#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
