#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  void XSLL::Rec_Xs_KPi( std::vector<Particle>& xs_list,
			 std::vector<Particle>& k_list,
			 std::vector<Particle>& p_list,
			 const bool fl_message
			 )
  {
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if( k_list.size()==0 ) return;
    if( p_list.size()==0 ) return;
    int rec_mode_xs=0;
    
    if( k_list.begin()->charge()!=0 && p_list.begin()->charge()!=0 ){ // [charged K + charged pi]
      rec_mode_xs = 101;
    }else if( k_list.begin()->charge()==0 && p_list.begin()->charge()==0 ){ // [Ks + pi0]
      rec_mode_xs = 1010; 
    }else if( k_list.begin()->charge()!=0 && p_list.begin()->charge()==0 ){ // [charged K + pi0]
      rec_mode_xs = 1001;
    }else if( k_list.begin()->charge()==0 && p_list.begin()->charge()!=0 ){ // [Ks + charged pi]
      rec_mode_xs = 110; 
    }else{
      if( fl_message ) std::cout << " -> wrong charge " << std::endl;
      abort();
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if( fl_message ) std::cout << "XSK1PIXSK1PIXSK1PIXSK1PIXSK1PIXSK1PIXSK1PIXSK1PIXSK1PIXSK1PIXSK1PIXSK1PIXSK1PI" << std::endl
      			       << "<rec_mode_xs> :  " << rec_mode_xs << std::endl;
    for( std::vector<Particle>::iterator k = k_list.begin(); k != k_list.end(); k++ ){
      for( std::vector<Particle>::iterator p = p_list.begin(); p != p_list.end(); p++ ){
	if( fl_message ) std::cout << "K_LUND = "
				   << std::setw(4) << std::right << k->lund() << "("
				   << std::setw(2) << std::right << k->mdstCharged().get_ID() << ")"
				   << ", Pi_LUND = "
				   << std::setw(4) << std::right << p->lund() << "("
				   << std::setw(2) << std::right << p->mdstCharged().get_ID() << ")";
	
	int chg  = int( k->charge() + p->charge() ); // total charge
	int kchg = int( k->charge() ); // kaon charge
	
	// charge check
	if( abs(chg) > 1 ){
	  if( fl_message ) std::cout << " -> not allowed charge : " << chg << std::endl;
	  continue;
	}
	
	// Check duplication
	if( !check_dupli_daughter(k,p) ){
	  if( fl_message ) std::cout << " -> duplication " << std::endl;
	  continue;
	}
	
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	    
	int xs_lund=0;
	if( chg==1 ){
	  xs_lund = Kstrp_LUND;
	}else if( chg==-1 ){
	  xs_lund = Kstrm_LUND;
	}else{
	  if( kchg==-1 ) xs_lund = antiKstr0_LUND;
	  else xs_lund = Kstr0_LUND; // Unknown falvors are also assigned to B0.
	}
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++    
	
	// reconstruction
	Particle Xs( k->p() + p->p(), Ptype(xs_lund) );
	
	Xs.relation().append( *k );
	Xs.relation().append( *p );
	setUserInfo( Xs );
	UserInfo& info = dynamic_cast<UserInfo&>( Xs.userInfo() );
	info.rec_mode( rec_mode_xs );
	
	if( fl_message ) std::cout << " -> rec_mode_xs = "
				   << std::setw(5) << std::right << rec_mode_xs
				   << ", Xs_LUND = "
				   << std::setw(8)   << std::right << Xs.lund()
				   << std::endl;
	
	xs_list.push_back( Xs );
	
      }
    }
    if( fl_message ) std::cout << "XSK1PIXSK1PIXSK1PIXSK1PIXSK1PIXSK1PIXSK1PIXSK1PIXSK1PIXSK1PIXSK1PIXSK1PIXSK1PI" << std::endl;
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
