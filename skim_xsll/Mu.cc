#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  void XSLL::Mu_cand( std::vector<Particle>& mu_list, const bool fl_message )
  {
    Mdst_charged_Manager& chgMgr = Mdst_charged_Manager::get_manager();
    for( Mdst_charged_Manager::iterator c = chgMgr.begin();
	 c != chgMgr.end();
	 c++ )
      {
	// reduce beam B.G.
	double dr = correct_dr( (*c), m_IP, MUON_CODE );
	double dz = correct_dz( (*c), m_IP, MUON_CODE );
	if( fabs(dr) > Dr_cut ) continue;
	if( fabs(dz) > Dz_cut ) continue;

	// muid
	Muid_mdst muid( *c );
	if( muid.Chi_2() <= 0 ) continue;
	if( muid.Muon_likelihood() <= muLH_cut ) continue;

	// make particle
	Particle muon( (*c), Ptype(c->charge() > 0 ? MUplus_LUND : MUminus_LUND) );

	if( muon.ptot() < muon_P_cut ) continue;
		
	setUserInfo( muon );
	UserInfo& info = dynamic_cast<UserInfo&>(muon.userInfo());

	mu_list.push_back( muon );
	
      }
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
