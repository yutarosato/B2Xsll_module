#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  void XSLL::Ks_cand( std::vector<Particle>& ks_list, const bool fl_message )
  {
    if( fl_message ) std::cout << "KSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKS" << std::endl;
    
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

	HepLorentzVector ks_4Vcm = ks.p();
	ks_4Vcm.boost( cmboost );
	info.Vcm( ks_4Vcm );
	
	Particle& pip = ks.child( 0 );
	setUserInfo( pip );
	UserInfo& infop = dynamic_cast<UserInfo&>( pip.userInfo() );
	infop.self  ( check_selfF(pip) );
	infop.trk   ( good_charged(pip.mdstCharged()) );
	infop.selKPI( selKPI.prob(pip.mdstCharged())  );
	infop.dr    ( fabs(correct_dr(pip.mdstCharged(), m_IP, PION_CODE)) );
	infop.dz    ( fabs(correct_dz(pip.mdstCharged(), m_IP, PION_CODE)) );
	
	Particle& pim = ks.child(1);
	setUserInfo( pim );
	UserInfo& infom = dynamic_cast<UserInfo&>( pim.userInfo() );
	infom.self  ( check_selfF(pim) );
	infom.trk   ( good_charged(pim.mdstCharged()) );
	infom.selKPI( selKPI.prob(pim.mdstCharged())  );
	infom.dr    ( fabs(correct_dr(pim.mdstCharged(), m_IP, PION_CODE)) );
	infom.dz    ( fabs(correct_dz(pim.mdstCharged(), m_IP, PION_CODE)) );

	
	// gen_Hepevt
	info.self( check_selfR(ks, Ks_LUND, 2) );
	
	if( fl_message ) std::cout << "                          Ks cand : "
				   << "pi+ ( "
				   << "gen-ID = " << std::setw(3) << std::right << pip.genHepevt().get_ID() << ", "
				   << "self = "   << infop.self()              << "), "
				   << "pi- ( "
				   << "gen-ID = " << std::setw(3) << std::right << pim.genHepevt().get_ID() << ", "
				   << "self = "   << infom.self()              << ") "
				   << "-> "
				   << "Ks ( "
				   << "self = " << info.self() << ") "
				   << std::endl;

	ks_list.push_back( ks );
      }
    if( fl_message ) std::cout << "------------------------------------------------------------------------------" << std::endl
			       << "                          # of Ks candidates : " << ks_list.size()              << std::endl
			       << "KSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKSKS" << std::endl;
    
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
