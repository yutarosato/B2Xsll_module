#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif
  
  void XSLL::EE_cand( std::vector<Particle>& ee_list, const bool fl_message )
  {
    if( fl_message ) std::cout << "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE" << std::endl;
    
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
	//if( eidProb <= eidprob_cut ) continue; // REMOVE FOR FAKE LEPTON !!!!!!!!!!!!!!!!!!
	
	// make particle
	Particle electron( (*c), Ptype(c->charge() > 0 ? Positron_LUND : Electron_LUND) );

	if( electron.ptot() < electron_P_cut ) continue;
	
	setUserInfo( electron );
	UserInfo& info = dynamic_cast<UserInfo&>( electron.userInfo() );
	info.dr( fabs(dr) );
	info.dz( fabs(dz) );
	info.trk( good_charged(*c) );
	info.eidProb( eidProb );
	info.ptot_ee( electron.p3().mag() );
	
	// gen_hepevt
	info.self    ( check_selfF(electron)     );
	info.id      ( check_idF(electron)       );
	info.motherid( check_motheridF(electron) );
	
	HepLorentzVector electron_4Vcm = electron.p();
	electron_4Vcm.boost( cmboost );
	info.Vcm( electron_4Vcm );

	if( fl_message ) std::cout << "                          Electron cand : "
				   << "gen-ID = " << std::setw(3)  << std::right << electron.genHepevt().get_ID() << ", "
				   << "e-ID = "   << std::setw(15) << std::right << info.eidProb()
				   << std::endl;
	
	ee_list.push_back( electron );
	
      }
    if( fl_message ) std::cout << "------------------------------------------------------------------------------" << std::endl
			       << "                          # of electron candidates : " << ee_list.size()        << std::endl
			       << "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE" << std::endl;
  }

#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
