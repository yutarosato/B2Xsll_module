#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  void XSLL::Pion_cand( std::vector<Particle>& pion_list, const bool fl_message )
  {
    if( fl_message ) std::cout << "PIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPI" << std::endl;
    
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

	// atckpi
	double atcKPI = selKPI.prob( *c );
	if( atcKPI > selKPI_cut ) continue;
	
	// make particle
	Particle pion( (*c), Ptype(c->charge() > 0 ? PIplus_LUND : PIminus_LUND) );
	setUserInfo( pion );
	UserInfo& info = dynamic_cast<UserInfo&>( pion.userInfo() );
	info.dr( fabs(dr) );
	info.dz( fabs(dz) );
	info.selKPI( atcKPI );

	// gen_hepevt
	info.self    ( check_selfF(pion)     );
	info.id      ( check_idF(pion)       );
	info.motherid( check_motheridF(pion) );	
	// eid
	eid e( *c );
	info.eidProb( e.prob(3,-1,5) );
	Particle electron( (*c), Ptype(c->charge() > 0 ? Positron_LUND : Electron_LUND) );
	info.ptot_ee( electron.p3().mag() );
	if( info.eidProb() > eidprob_cut && info.ptot_ee() > electron_P_cut ) continue; // added at 20120615 for data suppression
	
	// muid
	Muid_mdst muid( *c );
	if( muid.Chi_2() <= 0 ){
	  info.muonLikelihood( -1 );
	}else{
	  info.muonLikelihood( muid.Muon_likelihood() );
	}
	Particle muon( (*c), Ptype(c->charge() > 0 ? MUplus_LUND : MUminus_LUND) );
	info.trk( good_charged(*c) );
	info.ptot_mm( muon.p3().mag() );
	if( info.muonLikelihood() > muLH_cut && info.ptot_mm() > muon_P_cut ) continue; // added at 20120615 for data suppression
	
	HepLorentzVector pion_4Vcm = pion.p();
	pion_4Vcm.boost( cmboost );
	info.Vcm( pion_4Vcm );

	if( fl_message ) std::cout << "                          Pion cand : "
				   << "gen-ID = " << std::setw(3)  << std::right << pion.genHepevt().get_ID() << ", "
				   << "K-ID = "   << std::setw(15) << std::right << info.selKPI()
				   << std::endl;
	pion_list.push_back( pion );
      }
    if( fl_message ) std::cout << "------------------------------------------------------------------------------" << std::endl
			       << "                          # of charged pi candidates : " << pion_list.size()    << std::endl
			       << "PIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPIPI" << std::endl;
  }

#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
