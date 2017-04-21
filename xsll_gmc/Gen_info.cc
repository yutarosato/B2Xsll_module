#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif
  
  void XSLL::Gen_info( std::map<int,int>& child_id_map1, std::multiset<int>& n_particle_set1,
		       std::map<int,int>& child_id_map2, std::multiset<int>& n_particle_set2,
		       int gen_b_decay_info[][30],       const int fl_message )
  {
    //std::cout << "Gen start!" << std::endl;
    if( mc != 1 ){
      //std::cout << "Data is Real Data. Gen Function skip. "
      //<< std::endl;
      return;
    }
    
    Gen_hepevt_Manager& genMgr = Gen_hepevt_Manager::get_manager();
    if( fl_message==2 ) genMgr.dump();
    
    
    // +++++++++++++++++++++++++++ event type check +++++++++++++++++++++++++++++++
    Gen_hepevt& Upsilon4S( genMgr( Panther_ID(1) ) );
    
    // ROOT PARTICLE check
    if( Upsilon4S.idhep() == vpho_LUND ) bb = 0;
    else if( Upsilon4S.idhep() == Upsilon4S_LUND ){
      int nchild_4s  = Upsilon4S.daLast() ==0 ? 0 : Upsilon4S.daLast() - Upsilon4S.daFirst() + 1;
      if( nchild_4s==2 ){
	int B1_id = Gen_hepevt( genMgr( Panther_ID( Upsilon4S.daFirst() ) ) ).idhep();
	int B2_id = Gen_hepevt( genMgr( Panther_ID( Upsilon4S.daLast()  ) ) ).idhep();
	if( abs(B1_id*B2_id) == B0_LUND* B0_LUND || B1_id*B2_id == Bplus_LUND*Bminus_LUND ){
	  bb = 1;
	  gen_b_decay_info[0][0] = Gen_hepevt( genMgr( Panther_ID( Upsilon4S.daFirst() ) ) ).get_ID();
	  gen_b_decay_info[1][0] = Gen_hepevt( genMgr( Panther_ID( Upsilon4S.daLast()  ) ) ).get_ID();
	}else bb = 2;
      }else bb = 2;
    }
    if( fl_message ) std::cout << "[Event Type(bb)] : " << bb << std::endl;

    if( bb==0 ){
      // search D from vpho
      gen_b_decay_info[0][3] = search_daughter_D( Upsilon4S, gen_b_decay_info[0][4], gen_b_decay_info[0][7], fl_message );
      // semileptonic D decay ?
      if( gen_b_decay_info[0][3] > 0 ){
	Gen_hepevt& D( genMgr( Panther_ID(gen_b_decay_info[0][4]) ) );
	gen_b_decay_info[0][5] = semilept_dec( D, gen_b_decay_info[0][6], fl_message );	
      }
      if( gen_b_decay_info[0][3] > 1 ){
	Gen_hepevt& D( genMgr( Panther_ID(gen_b_decay_info[0][7]) ) );
	gen_b_decay_info[0][8] = semilept_dec( D, gen_b_decay_info[0][9], fl_message );
      }
      // search Charmonium( ->dilepton ) from vpho
      gen_b_decay_info[0][10] = search_daughter_CC( Upsilon4S, gen_b_decay_info[0][11], gen_b_decay_info[0][12], fl_message );
    }
    
    
    if( bb==1 ){
      Gen_hepevt& B1( genMgr( Panther_ID(Upsilon4S.daFirst()) ) );
      Gen_hepevt& B2( genMgr( Panther_ID(Upsilon4S.daLast() ) ) );
      
      // semileptonic B decay ?
      gen_b_decay_info[0][1] = semilept_dec( B1, gen_b_decay_info[0][2], fl_message );
      gen_b_decay_info[1][1] = semilept_dec( B2, gen_b_decay_info[1][2], fl_message );
      
      // search D from B decay
      gen_b_decay_info[0][3] = search_daughter_D( B1, gen_b_decay_info[0][4], gen_b_decay_info[0][7], fl_message );
      gen_b_decay_info[1][3] = search_daughter_D( B2, gen_b_decay_info[1][4], gen_b_decay_info[1][7], fl_message );
      // semileptonic D decay ?
      for( int i=0; i<2; i++ ){
	if( gen_b_decay_info[i][3] > 0 ){
	  Gen_hepevt& D( genMgr( Panther_ID(gen_b_decay_info[i][4]) ) );
	  gen_b_decay_info[i][5] = semilept_dec( D, gen_b_decay_info[i][6], fl_message );	
	}
	if( gen_b_decay_info[i][3] > 1 ){
	  Gen_hepevt& D( genMgr( Panther_ID(gen_b_decay_info[i][7]) ) );
	  gen_b_decay_info[i][8] = semilept_dec( D, gen_b_decay_info[i][9], fl_message );	
	}
      }
      // search Charmonium( ->dilepton ) from B decay
      gen_b_decay_info[0][10] = search_daughter_CC( B1, gen_b_decay_info[0][11], gen_b_decay_info[0][12], fl_message );
      gen_b_decay_info[1][10] = search_daughter_CC( B2, gen_b_decay_info[1][11], gen_b_decay_info[1][12], fl_message );
      
      // search all-particles from B decay
      find_fin_child( B1, child_id_map1, n_particle_set1, fl_message );
      if( fl_message ){
	std::cout << "------------------------------------------------------------------------------"
		  << std::endl;
	std::cout << " # of B1 rec-child : " << child_id_map1.size() << " [ ";
	for (std::map<int, int>::iterator i = child_id_map1.begin(); i != child_id_map1.end(); i++){
	  std::cout << i->second << "(" << i->first << ") ";
	}
	std::cout << " ] " << std::endl;
	std::cout << " # of B1 all-child : " <<  n_particle_set1.size() << " [ ";
	int count=0;
	for (std::multiset<int>::iterator i = n_particle_set1.begin(); i != n_particle_set1.end(); i++){
	  std::cout << *i << " ";
	}
	std::cout << " ]" << std::endl;
      }
      
      find_fin_child( B2, child_id_map2, n_particle_set2, fl_message );
      if( fl_message ){
	std::cout << "------------------------------------------------------------------------------"
		  << std::endl;
	std::cout << " # of B2 rec-child : " << child_id_map2.size() << " [ ";
	for (std::map<int, int>::iterator i = child_id_map2.begin(); i != child_id_map2.end(); i++){
	  std::cout << i->second << "(" << i->first << ") ";
	}
	std::cout << " ] " << std::endl;
	std::cout << " # of B2 all-child : " <<  n_particle_set2.size() << " [ ";
	int count=0;
	for (std::multiset<int>::iterator i = n_particle_set2.begin(); i != n_particle_set2.end(); i++){
	  std::cout << *i << " ";
	}
	std::cout << " ]" << std::endl;
      }
      
      //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      // [ EVENT ]
      double exprunNo = expNo*10000+runNo;
      Gen_dist->column( "exprun",    exprunNo );
      Gen_dist->column( "event",     evtNo    );
      Gen_dist->column( "bb",        bb       );
      //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      // Judgement of gen_mode(B1)
      int n_total      = n_particle_set1.size();
      int n_charged_pi = n_particle_set1.count( PIplus_LUND   );
      int n_neutral_pi = n_particle_set1.count( PI0_LUND      );
      int n_charged_k  = n_particle_set1.count( Kplus_LUND    );
      int n_ks         = n_particle_set1.count( Ks_LUND       );   
      int n_electron   = n_particle_set1.count( Electron_LUND );
      int n_muon       = n_particle_set1.count( MUminus_LUND  );
      
      int n_kl         = n_particle_set1.count( Kl_LUND       );
      int n_gamma      = n_particle_set1.count( Gamma_LUND    );
      int n_proton     = n_particle_set1.count( Proton_LUND   );
      int n_neutron    = n_particle_set1.count( Neutron_LUND  );
      int n_nu_e       = n_particle_set1.count( Nu_E_LUND     );
      int n_nu_mu      = n_particle_set1.count( Nu_MU_LUND    );
      int n_nu_tau     = n_particle_set1.count( Nu_TAU_LUND   );
      
      int n_rest       = n_total - (n_charged_pi + n_neutral_pi ) - ( n_charged_k + n_ks ) - ( n_electron + n_muon )
	- ( n_kl + n_gamma + n_proton + n_neutron ) - ( n_nu_e + n_nu_mu + n_nu_tau );
      
      if( n_charged_pi > 9 ) n_charged_pi = 9;
      if( n_neutral_pi > 9 ) n_neutral_pi = 9;
      if( n_charged_k  > 9 ) n_charged_k  = 9;
      if( n_ks         > 9 ) n_ks         = 9;
      if( n_kl         > 9 ) n_kl         = 9;
      if( n_gamma      > 9 ) n_gamma      = 9;
      if( n_proton     > 9 ) n_proton     = 9;
      if( n_neutron    > 9 ) n_neutron    = 9;
      if( n_electron   > 9 ) n_electron   = 9;
      if( n_muon       > 9 ) n_muon       = 9;
      if( n_nu_e       > 9 ) n_nu_e       = 9;
      if( n_nu_mu      > 9 ) n_nu_mu      = 9;
      if( n_nu_tau     > 9 ) n_nu_tau     = 9;
      if( n_rest       > 9 ) n_rest       = 9;
      
      gen_mode_bg1     = 10000*n_rest + 1000*n_kl + 100*n_proton + 10*n_neutron + n_gamma;
      gen_mode_lepton1 = 10*n_electron + n_muon;
      gen_mode_B1      = 1000*n_neutral_pi + 100*n_charged_pi + 10*n_ks + n_charged_k;
      gen_mode_nu1     = n_nu_e + n_nu_mu + n_nu_tau;
      if( fl_message ){
	std::cout << "gen_mode_bg1     = " << gen_mode_bg1     << std::endl
		  << "gen_mode_lepton1 = " << gen_mode_lepton1 << std::endl
		  << "gen_mode_B1      = " << gen_mode_B1      << std::endl
		  << "gen_mode_nu1     = " << gen_mode_nu1     << std::endl;
      }
      
      Gen_dist->column( "gm_B1",       gen_mode_B1  );
      Gen_dist->column( "gm_nu1",      gen_mode_nu1 );
      Gen_dist->column( "gm_bg1",      gen_mode_bg1 );
      Gen_dist->column( "gm_l1",       gen_mode_lepton1 );

      Gen_dist->column( "gb1_semi",   gen_b_decay_info[0][ 1]); // semileptonic Fake-B  decay ?
      Gen_dist->column( "gb2_semi",   gen_b_decay_info[1][ 1]); // semileptonic Other-B decay ?
      Gen_dist->column( "gb1nd",      gen_b_decay_info[0][ 3]); // # of D particles from Fake-B 
      Gen_dist->column( "gb2nd",      gen_b_decay_info[1][ 3]); // # of D particles from Other-B
      Gen_dist->column( "gb1d1_semi", gen_b_decay_info[0][ 5]); // semileptonic 1st D decay from Fake-B ?
      Gen_dist->column( "gb1d2_semi", gen_b_decay_info[0][ 8]); // semileptonic 2nd D decay from Fake-B ?
      Gen_dist->column( "gb2d1_semi", gen_b_decay_info[1][ 5]); // semileptonic 1st D decay from Other-B ?
      Gen_dist->column( "gb2d2_semi", gen_b_decay_info[1][ 8]); // semileptonic 2nd D decay from Other-B ?
      Gen_dist->column( "gb1_cc",     gen_b_decay_info[0][10]); // Charmonium LUND code from Fake-B (if not, 0)
      Gen_dist->column( "gb2_cc",     gen_b_decay_info[1][10]); // Charmonium LUND code from Fake-B (if not, 0)
      
      Gen_dist->column( "n1_total",    n_total      );
      Gen_dist->column( "n1_pi",       n_charged_pi );
      Gen_dist->column( "n1_pi0",      n_neutral_pi );
      Gen_dist->column( "n1_k",        n_charged_k  );
      Gen_dist->column( "n1_ks",       n_ks         );
      Gen_dist->column( "n1_kl",       n_kl         );
      Gen_dist->column( "n1_gamma",    n_gamma      );
      Gen_dist->column( "n1_proton",   n_proton     );
      Gen_dist->column( "n1_neutron",  n_neutron    );
      Gen_dist->column( "n1_electron", n_electron   );
      Gen_dist->column( "n1_muon",     n_muon       );
      Gen_dist->column( "n1_nu_e",     n_nu_e       );
      Gen_dist->column( "n1_nu_mu",    n_nu_mu      );
      Gen_dist->column( "n1_nu_tau",   n_nu_tau     );
      Gen_dist->column( "n1_rest",     n_rest       );
      
      //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      // Judgement of gen_mode(B2)
      n_total      = n_particle_set2.size();
      n_charged_pi = n_particle_set2.count( PIplus_LUND   );
      n_neutral_pi = n_particle_set2.count( PI0_LUND      );
      n_charged_k  = n_particle_set2.count( Kplus_LUND    );
      n_ks         = n_particle_set2.count( Ks_LUND       );   
      n_electron   = n_particle_set2.count( Electron_LUND );
      n_muon       = n_particle_set2.count( MUminus_LUND  );
      
      n_kl         = n_particle_set2.count( Kl_LUND       );
      n_gamma      = n_particle_set2.count( Gamma_LUND    );
      n_proton     = n_particle_set2.count( Proton_LUND   );
      n_neutron    = n_particle_set2.count( Neutron_LUND  );
      n_nu_e       = n_particle_set2.count( Nu_E_LUND     );
      n_nu_mu      = n_particle_set2.count( Nu_MU_LUND    );
      n_nu_tau     = n_particle_set2.count( Nu_TAU_LUND   );
      
      n_rest       = n_total - (n_charged_pi + n_neutral_pi ) - ( n_charged_k + n_ks ) - ( n_electron + n_muon )
	- ( n_kl + n_gamma + n_proton + n_neutron ) - ( n_nu_e + n_nu_mu + n_nu_tau );
      
      if( n_charged_pi > 9 ) n_charged_pi = 9;
      if( n_neutral_pi > 9 ) n_neutral_pi = 9;
      if( n_charged_k  > 9 ) n_charged_k  = 9;
      if( n_ks         > 9 ) n_ks         = 9;
      if( n_kl         > 9 ) n_kl         = 9;
      if( n_gamma      > 9 ) n_gamma      = 9;
      if( n_proton     > 9 ) n_proton     = 9;
      if( n_neutron    > 9 ) n_neutron    = 9;
      if( n_electron   > 9 ) n_electron   = 9;
      if( n_muon       > 9 ) n_muon       = 9;
      if( n_nu_e       > 9 ) n_nu_e       = 9;
      if( n_nu_mu      > 9 ) n_nu_mu      = 9;
      if( n_nu_tau     > 9 ) n_nu_tau     = 9;
      if( n_rest       > 9 ) n_rest       = 9;
      
      gen_mode_bg2     = 10000*n_rest + 1000*n_kl + 100*n_proton + 10*n_neutron + n_gamma;
      gen_mode_lepton2 = 10*n_electron + n_muon;
      gen_mode_B2      = 1000*n_neutral_pi + 100*n_charged_pi + 10*n_ks + n_charged_k;
      gen_mode_nu2     = n_nu_e + n_nu_mu + n_nu_tau;
      if( fl_message ){
	std::cout << "gen_mode_bg2     = " << gen_mode_bg2     << std::endl
		  << "gen_mode_lepton2 = " << gen_mode_lepton2 << std::endl
		  << "gen_mode_B2      = " << gen_mode_B2      << std::endl
		  << "gen_mode_nu2     = " << gen_mode_nu2     << std::endl
		  << "------------------------------------------------------------------------------"
		  << std::endl;
      }
      
      Gen_dist->column( "gm_B2",       gen_mode_B2  );
      Gen_dist->column( "gm_nu2",      gen_mode_nu2 );
      Gen_dist->column( "gm_bg2",      gen_mode_bg2 );
      Gen_dist->column( "gm_l2",       gen_mode_lepton2 );
      
      Gen_dist->column( "n2_total",    n_total      );
      Gen_dist->column( "n2_pi",       n_charged_pi );
      Gen_dist->column( "n2_pi0",      n_neutral_pi );
      Gen_dist->column( "n2_k",        n_charged_k  );
      Gen_dist->column( "n2_ks",       n_ks         );
      Gen_dist->column( "n2_kl",       n_kl         );
      Gen_dist->column( "n2_gamma",    n_gamma      );
      Gen_dist->column( "n2_proton",   n_proton     );
      Gen_dist->column( "n2_neutron",  n_neutron    );
      Gen_dist->column( "n2_electron", n_electron   );
      Gen_dist->column( "n2_muon",     n_muon       );
      Gen_dist->column( "n2_nu_e",     n_nu_e       );
      Gen_dist->column( "n2_nu_mu",    n_nu_mu      );
      Gen_dist->column( "n2_nu_tau",   n_nu_tau     );
      Gen_dist->column( "n2_rest",     n_rest       );
      
      //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      
      if( flag_mode == 1 || flag_mode == 9999 ) Gen_dist->dumpData();
      
      if( fl_message ){
	for( int i=0; i<13; i++){
	  std::cout << std::setw(2) << std::right << i << " : "
		    << std::setw(7) << std::right << gen_b_decay_info[0][i]
		    << ", "
		    << std::setw(7) << std::right << gen_b_decay_info[1][i] << std::endl; 
	}
      }
    }
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
