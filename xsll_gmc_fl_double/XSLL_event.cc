#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  void XSLL::event_start()
  {
    std::vector<Particle> trk_list;
    std::vector<Particle> kaon_list;
    std::vector<Particle> ks_list;
    std::vector<Particle> lep_list;
    std::vector<Particle> gamma_list;
    std::vector<Particle> pion_list;
    std::vector<Particle> pi0_list;
    
    std::vector<Particle> pseudo_cc_list;
    std::vector<Particle> xs_list;
    std::vector<Particle> recb_list;
    
    std::map<int,int>  child_id_map1;   // < hep.get_ID(), hep.idhep() >
    std::multiset<int> n_particle_set1; // < LUND >
    std::map<int,int>  child_id_map2;   // < hep.get_ID(), hep.idhep() >
    std::multiset<int> n_particle_set2; // < LUND >
    int gen_b_decay_info[2][30]={{0},{0}};
    // [0][] is Fake-B, [1][] is Other-B
    // [][ 0] B->Get_ID()
    // [][ 1] B semi-decay : 0(no lepton), 1(e-nu), 2(mu-nu), 3(tau-nu), -1(other two leptons), -2(others)
    // [][ 2] lepton->Get_ID(), lepton from B
    // [][ 3] # of D from B
    // [][ 4] 1st-D->Get_ID()
    // [][ 5] 1st-D semi-decay
    // [][ 6] lepton->Get_ID(), lepton from 1st-D
    // [][ 7] 2nd-D->Get_ID()
    // [][ 8] 2nd-D semi-decay
    // [][ 9] lepton->Get_ID(), lepton from 2nd-D
    // [][10] LUND code of charmonium from B
    // [][11] lepton1->Get_ID(), lepton1 from charmonium
    // [][12] lepton2->Get_ID(), lepton2 from charmonium
    // For evtgen-charm, only [][0,1,2] are invalid.
    // For evtgen-uds,         [][all]  are invalid.
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    const int  fl_message_gen   = 0; // 0(no-message),1(gen),2(gen+table)
    const bool fl_message_funda = !true;
    const bool fl_message_xs    = !true;
    const bool fl_message_cc    = !true;
    const bool fl_message_b_ana = !true;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    int n_neutral_pi    = int( flag_mode/1000 );
    int n_charged_pi    = int( (flag_mode-1000*n_neutral_pi)/100 );
    int n_Ks            = int( (flag_mode-1000*n_neutral_pi-100*n_charged_pi)/10 );
    int n_charged_k     =       flag_mode-1000*n_neutral_pi-100*n_charged_pi-10*n_Ks;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    if( fl_message_gen || fl_message_funda || fl_message_xs || fl_message_cc || fl_message_b_ana )
      std::cout << "*******************************"
		<< " [ XSLL ] "
		<< "expNo = "   << expNo
		<< ", runNo = " << runNo
		<< ", evtNo = " << evtNo
		<< " ******************************"
		<< std::endl;

    Gen_info( child_id_map1,    n_particle_set1,
	      child_id_map2,    n_particle_set2,
	      gen_b_decay_info, fl_message_gen );

    Tracks_cand( trk_list,   fl_message_funda );
    EE_cand    ( lep_list,   fl_message_funda );
    Mu_cand    ( lep_list,   fl_message_funda );
    Gamma_cand ( gamma_list, fl_message_funda );

    if(      1       ) Pion_cand ( pion_list, fl_message_funda );
    if( n_charged_k  ) Kaon_cand ( kaon_list, fl_message_funda );
    if( n_neutral_pi ) Pi0_cand  ( pi0_list,  fl_message_funda );
    if(      1       ) Ks_cand   ( ks_list,   fl_message_funda );
    
    Rec_Pseudo_CC( pseudo_cc_list, lep_list, gamma_list, 1, fl_message_cc );

    // 1body
    if( flag_mode ==    1 || flag_mode == 9999 ) Rec_Xs_K        ( xs_list, kaon_list,                      fl_message_xs );
    if( flag_mode ==   10 || flag_mode == 9999 ) Rec_Xs_K        ( xs_list, ks_list,                        fl_message_xs );
    // 2body
    if( flag_mode ==  101 || flag_mode == 9999 ) Rec_Xs_KPi      ( xs_list, kaon_list, pion_list,           fl_message_xs );
    if( flag_mode ==  110 || flag_mode == 9999 ) Rec_Xs_KPi      ( xs_list, ks_list,   pion_list,           fl_message_xs );
    if( flag_mode == 1001 || flag_mode == 9999 ) Rec_Xs_KPi      ( xs_list, kaon_list, pi0_list,            fl_message_xs );
    if( flag_mode == 1010 || flag_mode == 9999 ) Rec_Xs_KPi      ( xs_list, ks_list,   pi0_list,            fl_message_xs );
    // 3body
    if( flag_mode ==  201 || flag_mode == 9999 ) Rec_Xs_KPiPi    ( xs_list, kaon_list, pion_list,           fl_message_xs );
    if( flag_mode ==  210 || flag_mode == 9999 ) Rec_Xs_KPiPi    ( xs_list, ks_list,   pion_list,           fl_message_xs );
    if( flag_mode == 1101 || flag_mode == 9999 ) Rec_Xs_KPiPi    ( xs_list, kaon_list, pion_list, pi0_list, fl_message_xs );
    if( flag_mode == 1110 || flag_mode == 9999 ) Rec_Xs_KPiPi    ( xs_list, ks_list,   pion_list, pi0_list, fl_message_xs );
    // 4body
    if( flag_mode ==  301 || flag_mode == 9999 ) Rec_Xs_KPiPiPi  ( xs_list, kaon_list, pion_list,           fl_message_xs );
    if( flag_mode ==  310 || flag_mode == 9999 ) Rec_Xs_KPiPiPi  ( xs_list, ks_list,   pion_list,           fl_message_xs );
    if( flag_mode == 1201 || flag_mode == 9999 ) Rec_Xs_KPiPiPi  ( xs_list, kaon_list, pion_list, pi0_list, fl_message_xs );
    if( flag_mode == 1210 || flag_mode == 9999 ) Rec_Xs_KPiPiPi  ( xs_list, ks_list,   pion_list, pi0_list, fl_message_xs );
    // 5body
    if( flag_mode ==  401 || flag_mode == 9999 ) Rec_Xs_KPiPiPiPi( xs_list, kaon_list, pion_list,           fl_message_xs );
    if( flag_mode ==  410 || flag_mode == 9999 ) Rec_Xs_KPiPiPiPi( xs_list, ks_list,   pion_list,           fl_message_xs );
    if( flag_mode == 1301 || flag_mode == 9999 ) Rec_Xs_KPiPiPiPi( xs_list, kaon_list, pion_list, pi0_list, fl_message_xs );
    if( flag_mode == 1310 || flag_mode == 9999 ) Rec_Xs_KPiPiPiPi( xs_list, ks_list,   pion_list, pi0_list, fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );

    Rec_B_ana( recb_list, child_id_map1, child_id_map2, trk_list, gamma_list, ks_list, B_dist, gen_b_decay_info, fl_message_b_ana );
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
