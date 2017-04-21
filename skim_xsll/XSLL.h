#ifndef XSLL_H
#define XSLL_H

#include "belle.h"
#include "eid/eid.h"
#include "kid/atc_pid.h"
#include "mdst/Muid_mdst.h"

#include "event/BelleEvent.h"
#include "tuple/BelleTupleManager.h"

#include "basf/module.h"
#include "basf/module_descr.h"
#include "basf/basfout.h"

#include "panther/panther.h"

#include "particle/Particle.h"
#include "particle/utility.h"

#include "toolbox/FuncPtr.h"
#include "FoxWolfr.h"
#include "ksfwmoments.h"

#include "toolbox/Thrust.h"

#include <vector>
#include <map>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>

#include MDST_H
#include BELLETDF_H
#include EVTCLS_H

#include "benergy/BeamEnergy.h"
#include "ip/IpProfile.h"

#include "mdst/mdst.h"
#include "mdst/findKs.h"

#include "exkfitter/ExKFitter.h"
#include "tables/hepevt.h"

#include "CLHEP/Vector/ThreeVector.h"
#include "CLHEP/Vector/LorentzVector.h"

#include "UserInfo.h"

class BelleEvent;

#if defined(BELLE_NAMESPACE)
namespace Belle {
#endif
  
  // define parameter 
  // CODE
  const int EE_CODE     = 0;
  const int MUON_CODE   = 1;
  const int PION_CODE   = 2;
  const int KAON_CODE   = 3;
  const int PROTON_CODE = 4;
  // Mass
  // B
  const double PDG_B0Mass     =  5.27953;
  const double PDG_BplusMass  =  5.27915;
  const double PDG_BminusMass =  PDG_BplusMass;
  // D
  const double PDG_D0Mass     =  1.86484;
  const double PDG_DplusMass  =  1.86962;
  const double PDG_DminusMass =  PDG_DplusMass;
  // other
  const double PDG_JPsiMass   =  3.096916;
  const double PDG_KsMass     =  0.497614;
  const double PDG_Kstr0Mass  =  0.89600;
  const double PDG_KstrpMass  =  0.89166;
  const double PDG_KstrmMass  =  PDG_KstrpMass;
  const double PDG_PIplusMass =  0.13957018;
  const double PDG_PI0Mass    =  0.1349766;
  const double PDG_MUMass     =  0.105658367;
  // Lund
  const int Upsilon5S_LUND = 9000553;
  const int Upsilon4S_LUND = 300553;
  // B
  const int B0_LUND        =  511;
  const int B0str_LUND     =  513;
  const int antiB0_LUND    = -511;
  const int antiB0str_LUND = -513;
  const int Bplus_LUND     =  521;
  const int Bpstr_LUND     =  523;
  const int Bminus_LUND    = -521;
  const int Bmstr_LUND     = -523;
  // Xs
  const int Xsd_LUND       =  30343;
  const int antiXsd_LUND   = -30343;
  const int Xsu_LUND       =  30353;
  const int antiXsu_LUND   = -30353;
  const int Xss_LUND       =  30363;
  const int antiXss_LUND   = -30363;
  // D*
  const double PDG_D0strMass =  2.00696;
  const double PDG_DpstrMass =  2.01025;
  const double PDG_DmstrMass =  PDG_DpstrMass;
  // D*
  const int D0str_LUND =  423;
  const int Dpstr_LUND =  413;
  const int Dmstr_LUND = -413;
  // D
  const int D0_LUND     =  421;
  const int antiD0_LUND = -421;
  const int Dplus_LUND  =  411;
  const int Dminus_LUND = -411;
  // charmonium
  const int JPsi_LUND     =  443;
  // Lepton + gamma
  const int Electron_LUND =   11;
  const int Positron_LUND =  -11; 
  const int MUplus_LUND   =  -13;
  const int MUminus_LUND  =   13;
  const int Gamma_LUND    =   22;
  // Kaon
  const int Kstr0_LUND     =  313;
  const int antiKstr0_LUND = -313;
  const int Kstrp_LUND     =  323;
  const int Kstrm_LUND     = -323;
  const int K0_LUND        =  311;
  const int antiK0_LUND    = -311;
  const int Ks_LUND        =  310;
  const int Kl_LUND        =  130;
  const int Kplus_LUND     =  321;
  const int Kminus_LUND    = -321;
  // Pion
  const int PI0_LUND     =  111;
  const int PIplus_LUND  =  211;
  const int PIminus_LUND = -211;
  // Light Mesons
  const int Eta_LUND     =  221;
  const int antiEta_LUND = -221;
  // Baryons
  const int Proton_LUND      =  2212;
  const int antiProton_LUND  = -2212;
  const int Neutron_LUND     =  2112;
  const int antiNeutron_LUND = -2112;

  class XSLL : public Module {
  public:
    XSLL( void );
    ~XSLL( void );
    void init( int* );
    void begin_run( BelleEvent*, int* );
    void disp_stat( const char* ){};
    void hist_def( void );
    void event( BelleEvent*, int* );
    void end_run( BelleEvent*, int* );
    void term( void );

    bool mc;
    int  expNo;
    int  runNo;
    int  evtNo;

    int numberOfEvent;
    int numberOfSkim;
    
    int  gen_mode_xs;
    int  gen_xs_id;
    int  gen_mode_lepton; // e -> 1, mu -> 0
    int  gen_mode_bg;
    int  genbfl;
    std::set<int> recon_set;  // reconstruction particles(Ks, K+, K-, pi0, pi+, pi-)
    std::set<int> nonrecon_set; // not reconstruction particles but final particles (KL, gamma, neutron, proton, e, mu)
    std::set<int> Xs_set;   // Xs particles
                            // (Xsd, Xsu, anti-Xsd, anti-Xsu)
                            // (K0  anti-K0  K+  K-)
                            // (K*0 anti-K*0 K*+ K*-)
    int gen_fl_llg; // Xs ee -> +1, other -> -1
    double gen_m_llg;
    
    //std::set<int>      tmp_set;      // RRRRRRRRRRRRRRRRRRRR
    //std::multiset<int> tmp_multiset; // RRRRRRRRRRRRRRRRRRRR

    // parameter
    int flag_mode;
    char SkimFileName[256];

    HepPoint3D   m_IP;
    HepSymMatrix m_IP_err;

    // cut
    double Dr_cut;
    double Dz_cut;
    double electron_P_cut;
    double muon_P_cut;
    double min_e_dilep_cut;
    double eidprob_cut;
    double muLH_cut;
    double masscut_pi0_L;
    double masscut_pi0_H;
    double dE_cut;
    double Mbc_cut_L;
    double Mbc_cut_H;

    double Rad_angle_cut;      

  private:
    double E_LER, E_HER, X_ANGLE;
    HepLorentzVector lab; // 4-momentum in lab-frame
    Hep3Vector cmboost; //
    double eb; // the half of CM energy = B energy

    // histogram
    BelleTuple* Skim_dist;
    BasfOutput* SkimFile;
    //BelleTuple* t1_dist;
    //BelleTuple* t2_dist;
    
  protected:
    int  event_start();                                          // XSLL_event.cc
    int  Skim_ana(std::vector<Particle> recb_list); // XSLL_event.cc
    
    void Gamma_cand( std::vector<Particle>& gamma_list, const bool fl_message=0 ); // Gamma.cc
    void EE_cand   ( std::vector<Particle>& lep_list,   const bool fl_message=0 ); // EE.cc
    void Mu_cand   ( std::vector<Particle>& lep_list,   const bool fl_message=0 ); // Mu.cc
    void Kaon_cand ( std::vector<Particle>& kaon_list,  const bool fl_message=0 ); // Kaon.cc    
    void Pion_cand ( std::vector<Particle>& pion_list,  const bool fl_message=0 ); // Pion.cc
    void Pi0_cand  ( std::vector<Particle>& pi0_list,   const bool fl_message=0 ); // Pi0.cc
    
    void Ks_cand   ( std::vector<Particle>& ks_list, int flag_kfitter=0, const bool fl_message=0 );   // Ks.cc
    void Rec_Pseudo_CC( std::vector<Particle>& pseudo_cc_list,
			std::vector<Particle>& lep_list,
			std::vector<Particle>& gamma_list,
			int flag_correct_rad=0 );                        // Rec_Pseudo_CC.cc
    
    void Rec_Xs_K(         std::vector<Particle>& xs_list, std::vector<Particle>& k_list,                                                                    const bool fl_message=false ); // Rec_Xs_1body.cc
    void Rec_Xs_KPi(       std::vector<Particle>& xs_list, std::vector<Particle>& k_list, std::vector<Particle>& p_list,                                     const bool fl_message=false ); // Rec_Xs_2body.cc
    void Rec_Xs_KPiPi(     std::vector<Particle>& xs_list, std::vector<Particle>& k_list, std::vector<Particle>& pion_list,                                  const bool fl_message=false ); // Rec_Xs_3body.cc
    void Rec_Xs_KPiPi(     std::vector<Particle>& xs_list, std::vector<Particle>& k_list, std::vector<Particle>& pion_list, std::vector<Particle>& pi0_list, const bool fl_message=false ); // Rec_Xs_3body.cc
    void Rec_Xs_KPiPiPi(   std::vector<Particle>& xs_list, std::vector<Particle>& k_list, std::vector<Particle>& pion_list,                                  const bool fl_message=false ); // Rec_Xs_4body.cc
    void Rec_Xs_KPiPiPi(   std::vector<Particle>& xs_list, std::vector<Particle>& k_list, std::vector<Particle>& pion_list, std::vector<Particle>& pi0_list, const bool fl_message=false ); // Rec_Xs_4body.cc
    void Rec_Xs_KPiPiPiPi( std::vector<Particle>& xs_list, std::vector<Particle>& k_list, std::vector<Particle>& pion_list,                                  const bool fl_message=false ); // Rec_Xs_5body.cc
    void Rec_Xs_KPiPiPiPi( std::vector<Particle>& xs_list, std::vector<Particle>& k_list, std::vector<Particle>& pion_list, std::vector<Particle>& pi0_list, const bool fl_message=false ); // Rec_Xs_5body.cc
    
    void Rec_B_ana( std::vector<Particle> recb_list, std::map<int, int>& child_id_map,
		    std::vector<Particle> pion_list, std::vector<Particle> gamma_list,
		    BelleTuple* hist, const bool fl_message=false );                       // Rec_B_ana.cc
    
    void Rec_B( std::vector<Particle>& recb_list,
		std::vector<Particle>& pseudo_cc_list,
		std::vector<Particle>& xs_list );                      // Rec_B.cc
   
    double correct_dr( const Mdst_charged chg, HepPoint3D m_ip, int id );  // Util.cc
    double correct_dz( const Mdst_charged chg, HepPoint3D m_ip, int id );  // Util.cc
    
    int add_bremsstrahlung( Particle &particle,
			    std::vector<Particle>& gamma_list );              // Util.cc
    int id_bremsstrahlung( Particle &lepton,
			   std::vector<Particle>& gamma_list );               // Util.cc
    
    int check_dupli_daughter( std::vector<Particle>::iterator i,
			      std::vector<Particle>::iterator j );             // Util.cc
    int kinematic_fit( Particle& particle, int flag_kfitter,
		       int ntrk=0 );                                           // Util.cc
    void qq_suppress( Particle b, double& thrust_angle, double& R2 );          // Util.cc
    
    void setUserInfo( Particle& particle ){
      if(  &(particle.userInfo())==NULL ) particle.userInfo( UserInfo() );
    }

    int masscut( Particle particle, double low, double high, double mass ); // Util.cc
    
    int check_selfF( Particle& particle );                         // Util_Gen.cc
    int check_selfF( Particle& particle, int self_LUND,
		     int mother_LUND=0, int mothermother_LUND=0 ); // Util_Gen.cc
    int check_idF( Particle& particle );                           // Util_Gen.cc
    int check_motheridF( Particle& particle );                     // Util_Gen.cc
    int check_selfG( Particle& particle );                         // Util_Gen.cc
    int check_selfR( Particle& particle, int id, int nchild );     // Util_Gen.cc

    void display_particle( Particle particle );                              // Util_Gen.cc
    void display_hepevt  ( Gen_hepevt gen );                                 // Util_Gen.cc
    void display_list    ( std::set<int> set, std::multiset<int> multiset ); // Util_Gen.cc

    void find_fin_child( Gen_hepevt gen,
			 std::map<int, int>& child_id_map,
			 std::multiset<int>& n_particle_set,
			 bool fl_message = false,
			 int indent = 1 );                                  // Util_Gen.cc
    
    void Gen_info( std::map<int, int>& child_id_map, std::multiset<int>& n_particle_set,
		   const int fl_message=0 );                               // Gen_info.cc
    
    int mapping_delete( Particle particle, std::map<int, int>& child_id_map,
			 int& n_recon, int gen_mode_bg,
			 char* name, const bool fl_message=false );  // Util_Gen.cc
    
    void pi0_matching( Particle pi0, std::map<int, int>& id_map,
		       int& pi0self,   int& pi0_decay,
		       int& gam1_self, int& gam2_self,
		       int& gam1_conv, int& gam2_conv ); // Util_Gen
  };
#if defined(BELLE_NAMESPACE)
}
#endif

#endif
