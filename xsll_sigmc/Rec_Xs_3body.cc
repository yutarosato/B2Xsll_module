#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif

  void XSLL::Rec_Xs_KPiPi( std::vector<Particle>& xs_list,
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
    if( k_list.begin()->charge()==0 ){ // [Ks + charged pi + pi0]
      rec_mode_xs = 1110; 
    }else{ // [charged K + charged pi + pi0]
      rec_mode_xs = 1101;
    }
    
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if( fl_message ) std::cout << "XSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PI" << std::endl
			       << "<rec_mode_xs> :  " << rec_mode_xs << std::endl;
    for( std::vector<Particle>::iterator k = k_list.begin(); k != k_list.end(); k++ ){
      for( std::vector<Particle>::iterator p1 = pion_list.begin(); p1 != pion_list.end(); p1++ ){
	for( std::vector<Particle>::iterator p0 = pi0_list.begin(); p0 != pi0_list.end(); p0++ ){

	  if( fl_message ) std::cout << "K_LUND = "
				     << std::setw(4) << std::right << k->lund() << "("
				     << std::setw(2) << std::right << k->mdstCharged().get_ID() << ")"
				     << ", Pi_LUND = "
				     << std::setw(4) << std::right << p1->lund() << "("
				     << std::setw(2) << std::right << p1->mdstCharged().get_ID() << ")"
				     << ", Pi_LUND = "
				     << std::setw(4) << std::right << p0->lund() << "("
				     << std::setw(2) << std::right << p0->mdstCharged().get_ID() << ")";
	  
	  int chg  = int( k->charge() + p1->charge() + p0->charge() );
	  int kchg = int( k->charge() );
	  
	  // charge check
	  if( abs(chg) > 1 ){
	    if( fl_message ) std::cout << " -> not allowed charge : " << chg << std::endl;
	    continue;
	  }
	  /*
	  if( rec_mode_xs == 1110 ){ // [Ks + charged pi + pi0]
	    // no requirement
	  }else if( rec_mode_xs == 1101 ){ // [charged K + charged pi + pi0]
	    // no requirement
	  }else{
	    if( fl_message ) std::cout << " -> wrong charge " << std::endl;
	    abort();
	  }
	  */
	  // Check duplication
	  if( !check_dupli_daughter(k, p1) ){
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
	  Particle Xs( k->p() + p1->p() + p0->p(), Ptype(xs_lund) );
	  
	  Xs.relation().append( *k  );
	  Xs.relation().append( *p1 );
	  Xs.relation().append( *p0 );
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
    }
    if( fl_message ) std::cout << "XSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PI" << std::endl;
  }
  
  //========================================================================================
  //========================================================================================
  
  void XSLL::Rec_Xs_KPiPi( std::vector<Particle>& xs_list,
			   std::vector<Particle>& k_list,
			   std::vector<Particle>& pion_list,
			   const bool fl_message
			   )
  {
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if( k_list.size()==0 )    return;
    if( pion_list.size()==0 ) return;
    if( pion_list.begin()->charge()==0 ){
      std::cout << " -> wrong charge " << std::endl;
      abort();
    }
    
    int rec_mode_xs=0;
    if( k_list.begin()->charge()==0 ){ // [Ks + 2 charged pi]
      rec_mode_xs = 210;
    }else{ // [charged K + 2 charged pi]
      rec_mode_xs = 201;
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if( fl_message ) std::cout << "XSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PI" << std::endl
			       << "<rec_mode_xs> :  " << rec_mode_xs << std::endl;
    for( std::vector<Particle>::iterator k = k_list.begin(); k != k_list.end(); k++ ){
      for( std::vector<Particle>::iterator p1 = pion_list.begin(); p1 != pion_list.end(); p1++ ){
	for( std::vector<Particle>::iterator p2 = p1+1; p2 != pion_list.end(); p2++ ){

	  if( fl_message ) std::cout << "K_LUND = "
				     << std::setw(4) << std::right << k->lund() << "("
				     << std::setw(2) << std::right << k->mdstCharged().get_ID() << ")"
				     << ", Pi_LUND = "
				     << std::setw(4) << std::right << p1->lund() << "("
				     << std::setw(2) << std::right << p1->mdstCharged().get_ID() << ")"
				     << ", Pi_LUND = "
				     << std::setw(4) << std::right << p2->lund() << "("
				     << std::setw(2) << std::right << p2->mdstCharged().get_ID() << ")";
	  
	  int chg  = int( k->charge() + p1->charge() + p2->charge() );
	  int kchg = int( k->charge() );
	  
	  // charge check
	  if( abs(chg) > 1 ){
	    if( fl_message ) std::cout << " -> not allowed charge : " << chg << std::endl;
	    continue;
	  }
	  
	  if( rec_mode_xs == 201){// [charged K + 2 charged pi] 
	    if( chg != kchg ){
	      if( fl_message ) std::cout << " -> not allowed K charge " << std::endl;
	      continue;
	    }
	  }else if( rec_mode_xs == 210 ){ // [Ks + 2 charged pi]
	    // no requirement
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
	  Particle Xs( k->p() + p1->p() + p2->p(), Ptype(xs_lund) );
	  Xs.relation().append( *k  );
	  Xs.relation().append( *p1 );
	  Xs.relation().append( *p2 );
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
    }
    
    if( fl_message ) std::cout << "XSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PIXSK2PI" << std::endl;
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
