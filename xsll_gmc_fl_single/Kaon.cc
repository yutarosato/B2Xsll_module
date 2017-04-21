#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  void XSLL::Kaon_cand( std::vector<Particle>& kaon_list, const bool fl_message )
  {
    if( fl_message ) std::cout << "KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK" << std::endl;

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

 	// atckpi
	double atcKPI = selKPI.prob( *c );
	if( atcKPI <= selKPI_cut ) continue;
	
	// make particle
	Particle kaon( (*c), Ptype(c->charge() > 0 ? Kplus_LUND : Kminus_LUND) );
	setUserInfo( kaon );
	UserInfo& info = dynamic_cast<UserInfo&>( kaon.userInfo() );
	info.dr( fabs(dr) );
	info.dz( fabs(dz) );
	info.trk( good_charged(*c) );
	info.selKPI( atcKPI );

	// gen_hepevt
	info.self    ( check_selfF(kaon)     );
	info.id      ( check_idF(kaon)       );
	info.motherid( check_motheridF(kaon) );

	// eid
	eid e( *c );
	info.eidProb( e.prob(3,-1,5) );
	Particle electron( (*c), Ptype(c->charge() > 0 ? Positron_LUND : Electron_LUND) );
	info.ptot_ee( electron.p3().mag() );
	
	// muid
	Muid_mdst muid( *c );
	if( muid.Chi_2() <= 0 ){
	  info.muonLikelihood( -1 );
	}else{
	  info.muonLikelihood( muid.Muon_likelihood() );
	}
	Particle muon( (*c), Ptype(c->charge() > 0 ? MUplus_LUND : MUminus_LUND) );
	info.ptot_mm( muon.p3().mag() );
		
	HepLorentzVector kaon_4Vcm = kaon.p();
	kaon_4Vcm.boost( cmboost );
	info.Vcm( kaon_4Vcm );

	if( fl_message ) std::cout << "                          Kaon cand : "
				   << "gen-ID = " << std::setw(3)  << std::right << kaon.genHepevt().get_ID() << ", "
				   << "K-ID = "   << std::setw(15) << std::right << info.selKPI()
				   << std::endl;
	
	kaon_list.push_back( kaon );
      }
    if( fl_message ) std::cout << "------------------------------------------------------------------------------" << std::endl
			       << "                          # of charged K candidates : " << kaon_list.size()     << std::endl
			       << "KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK" << std::endl;
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
