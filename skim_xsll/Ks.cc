#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  void XSLL::Ks_cand( std::vector<Particle>& ks_list, int flag_kfitter, const bool fl_message )
  {
    Mdst_vee2_Manager &vee2_mgr = Mdst_vee2_Manager::get_manager();
    for( std::vector<Mdst_vee2>::iterator i = vee2_mgr.begin();
	 i != vee2_mgr.end(); i++ )
      {

	Mdst_vee2 &vee2 = *i;
	if ( vee2.kind() != 1 ) continue; // kind: 1(Ks), 2(Lambda), 3(Lambda_bar), 4(gamma->ee)
	
	// FindKs
	FindKs findks;
	findks.candidates( vee2, m_IP );
	if( findks.goodKs() != 1 ) continue; // 1 = good Ks
	
	// make particle
	Particle ks( vee2 );
	setUserInfo( ks );
	UserInfo& info = dynamic_cast<UserInfo&>( ks.userInfo() );

	Particle& pip = ks.child( 0 );
	setUserInfo( pip );
	UserInfo& infop = dynamic_cast<UserInfo&>( pip.userInfo() );
	
	Particle& pim = ks.child(1);
	setUserInfo( pim );
	UserInfo& infom = dynamic_cast<UserInfo&>( pim.userInfo() );

	ks_list.push_back( ks );
      }
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
