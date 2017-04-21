#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  void XSLL::Rec_Xs_KPiPiPi( std::vector<Particle>& xs_list,
			     std::vector<Particle>& k_list,
			     std::vector<Particle>& pion_list,
			     std::vector<Particle>& pi0_list,
			   const bool fl_message
			   )
  {
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if( k_list.size()   ==0 ) return;
    if( pion_list.size()==0 ) return;
    if( pi0_list.size() ==0 ) return;
    if( pion_list.begin()->charge()==0 || pi0_list.begin()->charge()!=0 ){
      std::cout << " -> wrong charge " << std::endl;
      abort();
    }
    
    int rec_mode_xs=0;
    if( k_list.begin()->charge()==0 ){ // [Ks + 2 charged pi + pi0]
      rec_mode_xs = 1210; 
    }else{ // [charged K + pi0 + 2 charged pi]
      rec_mode_xs = 1201;
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    for( std::vector<Particle>::iterator k = k_list.begin(); k != k_list.end(); k++ ){
      for( std::vector<Particle>::iterator p1 = pion_list.begin(); p1 != pion_list.end(); p1++ ){
	for( std::vector<Particle>::iterator p2 = p1+1; p2 != pion_list.end(); p2++ ){
	  for( std::vector<Particle>::iterator p0 = pi0_list.begin(); p0 != pi0_list.end(); p0++ ){
	    {
	      int chg    = int( k->charge() + p1->charge() + p2->charge() + p0->charge() );
	      int kchg   = int( k->charge() );
	      
	      // charge check
	      if( abs(chg) > 1 ){
		if( fl_message ) std::cout << " -> not allowed charge : " << chg << std::endl;
		continue;
	      }
	      
	      if( rec_mode_xs == 1210 ){ // [Ks + 2 charged pi + pi0]
		// no requirement
	      }else if( rec_mode_xs == 1201 ){ // [charged K + 2 charged pi + pi0]
		if( chg != kchg ){
		  if( fl_message ) std::cout << " -> not allowed K charge " << std::endl;
		  continue;
		}
	      }else{
		if( fl_message ) std::cout << " -> wrong charge " << std::endl;
		abort();
	      }
	      
	      // Check duplication
	      if( !check_dupli_daughter(k, p1) || !check_dupli_daughter(k, p2) ){
		if( fl_message ) std::cout << " -> duplication " << std::endl;
		continue;
	      }
	      
	      //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
	      int xs_lund=0;
	      if( chg==1 ){
		xs_lund = Kstrp_LUND; // Xsu_LUND;
	      }else if( chg==-1 ){
		xs_lund = Kstrm_LUND; // antiXsu_LUND;
	      }else{
		if( kchg==-1 ) xs_lund = antiKstr0_LUND; // antiXsd_LUND;
		else xs_lund = Kstr0_LUND; // Xsd_LUND; // Unknown falvors are also assigned to B0.
	      }
	      //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	      
	      // reconstruction
	      Particle Xs( k->p() + p1->p() + p2->p() + p0->p(), Ptype(xs_lund) );
	      
	      Xs.relation().append( *k  );
	      Xs.relation().append( *p1 );
	      Xs.relation().append( *p2 );
	      Xs.relation().append( *p0 );
	      setUserInfo( Xs );
	      UserInfo& info = dynamic_cast<UserInfo&>( Xs.userInfo() );
	      info.rec_mode( rec_mode_xs );
	      	      
	      xs_list.push_back( Xs );
	    }
	  }
	}
      }
    }
  }
  
  
  //========================================================================================
  //========================================================================================
  
  void XSLL::Rec_Xs_KPiPiPi( std::vector<Particle>& xs_list,
			     std::vector<Particle>& k_list,
			     std::vector<Particle>& pion_list,
			     const bool fl_message
			     )
  {
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if( k_list.size()  ==0 )  return;
    if( pion_list.size()==0 ) return;
    if( pion_list.begin()->charge()==0 ){
      std::cout << " -> wrong charge " << std::endl;
      abort();
    }
    
    int rec_mode_xs=0;
    if( k_list.begin()->charge()==0 ){ // [Ks + 3 charged pi]
      rec_mode_xs = 310;
    }else{ // [charged K + 3 charged pi]
      rec_mode_xs = 301; 
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    for( std::vector<Particle>::iterator k = k_list.begin(); k != k_list.end(); k++ ){
      for( std::vector<Particle>::iterator p1 = pion_list.begin(); p1 != pion_list.end(); p1++ ){
	for( std::vector<Particle>::iterator p2 = p1+1; p2 != pion_list.end(); p2++ ){
	  for( std::vector<Particle>::iterator p3 = p2+1; p3 != pion_list.end(); p3++ ){
	    int chg    = int( k->charge() + p1->charge() + p2->charge() + p3->charge() );
	    int kchg   = int( k->charge() );
	    
	    // charge check
	    if( abs(chg) > 1 ){
	      if( fl_message ) std::cout << " -> not allowed charge : " << chg << std::endl;
	      continue;
	    }
	    
	    if( rec_mode_xs == 310 ){ // [Ks, 3 charged pi]
	      // no requirement
	    }else if( rec_mode_xs == 301 ){ // [charged K, 3 charged pi]
	      // no requirement
	    }else{
	      if( fl_message ) std::cout << " -> wrong charge " << std::endl;
	      abort();
	    }
	    	    
	    // Check duplication
	    if( !check_dupli_daughter(k, p1) || !check_dupli_daughter(k, p2)  || !check_dupli_daughter(k, p3) ){
	      if( fl_message ) std::cout << " -> duplication " << std::endl;
	      continue;
	    }
	    
	    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	    int xs_lund=0;
	    if( chg==1 ){
	      xs_lund = Kstrp_LUND; // Xsu_LUND;
	    }else if( chg==-1 ){
	      xs_lund = Kstrm_LUND; // antiXsu_LUND;
	    }else{
	      if( kchg==-1 ) xs_lund = antiKstr0_LUND; // antiXsd_LUND;
	      else xs_lund = Kstr0_LUND; // Xsd_LUND; // Unknown falvors are also assigned to B0.
	    }
	    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	    
	    // reconstruction
	    Particle Xs( k->p() + p1->p() + p2->p() + p3->p(), Ptype(xs_lund) );
	    
	    Xs.relation().append( *k  );
	    Xs.relation().append( *p1 );
	    Xs.relation().append( *p2 );
	    Xs.relation().append( *p3 );
	    setUserInfo( Xs );
	    UserInfo& info = dynamic_cast<UserInfo&>( Xs.userInfo() );
	    info.rec_mode( rec_mode_xs );
	    
	    xs_list.push_back( Xs );
	  }
	}
      }
    }
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
  
