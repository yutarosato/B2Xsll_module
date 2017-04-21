#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  void XSLL::Gamma_cand( std::vector<Particle>& gamma_list, const bool fl_message )
  {
    if( fl_message ) std::cout << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG" << std::endl;
    
    Mdst_gamma_Manager& gamMgr = Mdst_gamma_Manager::get_manager();
    for( Mdst_gamma_Manager::iterator g = gamMgr.begin(); g!=gamMgr.end(); g++ ){
      // make particle
      Particle gamma( *g );
      gamma.relation().mdstEcl( g->ecl() );
      setUserInfo( gamma );
      UserInfo& info = dynamic_cast<UserInfo&>( gamma.userInfo() );

      // gen_Hepevt
      info.self( check_selfG(gamma) );
      
      if( fl_message ){
	std::cout << "                          Gamma cand : "
		  << "gam-ID = " << std::setw(3)  << std::right << gamma.mdstEcl().get_ID();
	if( gamma.genHepevt() ) std::cout << ", "
					  << " gen-ID = " << std::setw(3)  << std::right << gamma.genHepevt().get_ID() << ", "
					  << " E = "      << std::setw(10) << std::right << gamma.mdstEcl().energy()   << ", "
					  << "self = "    << info.self();
	std::cout << std::endl;
      }
      
      HepLorentzVector gamma_4Vcm = gamma.p();
      gamma_4Vcm.boost( cmboost );
      info.Vcm( gamma_4Vcm );
      
      setGammaError(gamma, IpProfile::position(), IpProfile::position_err());
      //t2_dist->column( "Egam",   gamma.e()      );
      //t2_dist->column( "Egamcm", gamma_4Vcm.e() );
      //t2_dist->column( "self",   info.self()    );
      //Evtcls_hadronic_flag_Manager& HadMan = Evtcls_hadronic_flag_Manager::get_manager();
      //Evtcls_hadronic_flag& Had = *HadMan.begin();
      //t2_dist->column( "had", Had.hadronic_flag(0) );
      //t2_dist->dumpData();
      
      gamma_list.push_back( gamma );
    }
    if( fl_message ){
      std::cout << "------------------------------------------------------------------------------" << std::endl
		<< "                          # of gamma candidates : " << gamma_list.size()        << std::endl
		<< "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG" << std::endl;
    }
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
