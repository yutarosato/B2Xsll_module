#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  int XSLL::event_start()
  {

    std::vector<Particle> kaon_list;
    std::vector<Particle> ks_list;
    std::vector<Particle> lep_list;
    std::vector<Particle> gamma_list;
    std::vector<Particle> pion_list;
    std::vector<Particle> pi0_list;
    
    std::vector<Particle> pseudo_cc_list;
    std::vector<Particle> xs_list;
    std::vector<Particle> recb_list;
    
    std::map<int,int>  child_id_map;   // < hep.get_ID(), hep.idhep() >
    std::multiset<int> n_particle_set; // < LUND >

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    const int  fl_message_gen   = 0; // 0(no-message),1(gen),2(gen+table)
    const bool fl_message_funda = !true;
    const bool fl_message_xs    = !true;
    const bool fl_message_b_ana = !true;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    int n_neutral_pi    = int( flag_mode/1000 );
    int n_charged_pi    = int( (flag_mode-1000*n_neutral_pi)/100 );
    int n_Ks            = int( (flag_mode-1000*n_neutral_pi-100*n_charged_pi)/10 );
    int n_charged_k     =       flag_mode-1000*n_neutral_pi-100*n_charged_pi-10*n_Ks;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++    
    if( fl_message_gen || fl_message_funda || fl_message_xs || fl_message_b_ana )
      std::cout << "*******************************"
		<< " [ XSLL ] "
		<< "expNo = "   << expNo
		<< ", runNo = " << runNo
		<< ", evtNo = " << evtNo
		<< " ******************************"
		<< std::endl;

    //Gen_info( child_id_map, n_particle_set, fl_message_gen );
    
    EE_cand   ( lep_list,            fl_message_funda );
    Mu_cand   ( lep_list,            fl_message_funda );
    Gamma_cand( gamma_list,          fl_message_funda );
    
    Pion_cand ( pion_list,    fl_message_funda );
    Kaon_cand ( kaon_list,    fl_message_funda );
    Pi0_cand  ( pi0_list,     fl_message_funda );
    Ks_cand   ( ks_list,   0, fl_message_funda );
    
    Rec_Pseudo_CC( pseudo_cc_list, lep_list, gamma_list, 1 );
    if( pseudo_cc_list.size() == 0 ) return 0;

    // 1body
    Rec_Xs_K        ( xs_list, kaon_list,                      fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();
    Rec_Xs_K        ( xs_list, ks_list,                        fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();
    // 2body
    Rec_Xs_KPi      ( xs_list, kaon_list, pion_list,           fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();    
    Rec_Xs_KPi      ( xs_list, ks_list,   pion_list,           fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();    
    Rec_Xs_KPi      ( xs_list, kaon_list, pi0_list,            fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();    
    Rec_Xs_KPi      ( xs_list, ks_list,   pi0_list,            fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();    
    // 3body
    Rec_Xs_KPiPi    ( xs_list, kaon_list, pion_list,           fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();    
    Rec_Xs_KPiPi    ( xs_list, ks_list,   pion_list,           fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();    
    Rec_Xs_KPiPi    ( xs_list, kaon_list, pion_list, pi0_list, fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();    
    Rec_Xs_KPiPi    ( xs_list, ks_list,   pion_list, pi0_list, fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();    
    // 4body
    Rec_Xs_KPiPiPi  ( xs_list, kaon_list, pion_list,           fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();    
    Rec_Xs_KPiPiPi  ( xs_list, ks_list,   pion_list,           fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();    
    Rec_Xs_KPiPiPi  ( xs_list, kaon_list, pion_list, pi0_list, fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();    
    Rec_Xs_KPiPiPi  ( xs_list, ks_list,   pion_list, pi0_list, fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();    
    // 5body
    Rec_Xs_KPiPiPiPi( xs_list, kaon_list, pion_list,           fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();    
    Rec_Xs_KPiPiPiPi( xs_list, ks_list,   pion_list,           fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();    
    Rec_Xs_KPiPiPiPi( xs_list, kaon_list, pion_list, pi0_list, fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();    
    Rec_Xs_KPiPiPiPi( xs_list, ks_list,   pion_list, pi0_list, fl_message_xs );
    Rec_B ( recb_list, pseudo_cc_list, xs_list );
    if( Skim_ana(recb_list) ) return 1;
    xs_list.clear();    
  }

  int XSLL::Skim_ana( std::vector<Particle> recb_list ){
    if( recb_list.size() > 0 ){
      Skim_dist->column("exp",   expNo);
      Skim_dist->column("run",   runNo);
      Skim_dist->column("evt",   evtNo);
      Skim_dist->column("skim",  numberOfSkim++);
      Skim_dist->column("event", numberOfEvent);
      Skim_dist->dumpData();
      SkimFile->write();
      
      return 1;
    }
    return 0;
  }
  
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
