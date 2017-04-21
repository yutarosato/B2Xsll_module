#include "belle.h"
#include "XSLL.h"

#if defined(BELLE_NAMESPACE)
namespace Belle{
#endif
  
  void XSLL::Rec_B( std::vector<Particle>& recb_list,   // B
		    std::vector<Particle>& pseudo_cc_list, // pseudo_charmonium
		    std::vector<Particle>& xs_list  // charged Pion
		    )
  {
    for( std::vector<Particle>::iterator cc = pseudo_cc_list.begin();
	 cc != pseudo_cc_list.end();
	 cc++ )
      {
	for( std::vector<Particle>::iterator xs = xs_list.begin();
	     xs != xs_list.end();
	     xs++ )
	  {
	    
	    // Check duplication
	    if( !check_dupli_daughter(cc, xs) ) continue;
	    
	    // reconstruction
	    int b_lund =0;
	    if     ( xs->lund() == Xsd_LUND       ) b_lund = B0_LUND;
	    else if( xs->lund() == antiXsd_LUND   ) b_lund = antiB0_LUND;
	    else if( xs->lund() == Xsu_LUND       ) b_lund = Bplus_LUND;
	    else if( xs->lund() == antiXsu_LUND   ) b_lund = Bminus_LUND;
	    else if( xs->lund() == Xsd1_LUND      ) b_lund = B0_LUND;     // added for xs-spin1 @20130408
	    else if( xs->lund() == antiXsd1_LUND  ) b_lund = antiB0_LUND; // added for xs-spin1 @20130408
	    else if( xs->lund() == Xsu1_LUND      ) b_lund = Bplus_LUND;  // added for xs-spin1 @20130408
	    else if( xs->lund() == antiXsu1_LUND  ) b_lund = Bminus_LUND; // added for xs-spin1 @20130408
	    else if( xs->lund() == Kstrp_LUND     ) b_lund = Bplus_LUND;
	    else if( xs->lund() == Kstrm_LUND     ) b_lund = Bminus_LUND;
	    else if( xs->lund() == Kplus_LUND     ) b_lund = Bplus_LUND;
	    else if( xs->lund() == Kminus_LUND    ) b_lund = Bminus_LUND;
	    else if( xs->lund() == Kstr0_LUND     ) b_lund = B0_LUND;
	    else if( xs->lund() == antiKstr0_LUND ) b_lund = antiB0_LUND;
	    else if( xs->lund() == Ks_LUND        ) b_lund = B0_LUND; // we do not know true flavor. 
	    else{
	      std::cout << "other strange particle ????????" << std::endl
			<< "xs->lund() = " << xs->lund()     << std::endl;
	      abort();
	    }
	    
	    Particle b( cc->p() + xs->p(), Ptype(b_lund) );
	    
	    b.relation().append( *cc );
	    b.relation().append( *xs );
	    setUserInfo( b );
	    UserInfo& info = dynamic_cast<UserInfo&>( b.userInfo() );

	    // calculation at CM frame
	    HepLorentzVector b_4Vcm = b.p();
	    b_4Vcm.boost( cmboost );
	    info.Vcm( b_4Vcm );
	    
	    double Mbc = sqrt( eb*eb - info.Vcm().vect()*info.Vcm().vect() );
	    double dE  = info.Vcm().e() - eb;
	    
	    if( Mbc     < Mbc_cut_L ) continue;
	    if( Mbc     > Mbc_cut_H ) continue;
	    if( abs(dE) > dE_cut    ) continue;
	    
	    info.Mbc( Mbc );
	    info.dE ( dE  );
	    
	    recb_list.push_back( b );
	  }
      }
  }
  
#if defined(BELLE_NAMESPACE)
} //namespace Belle
#endif
