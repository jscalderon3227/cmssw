#ifndef HLTSmartSinglet_h
#define HLTSmartSinglet_h

/** \class HLTSmartSinglet
 *
 *  
 *  This class is an HLTFilter (-> EDFilter) implementing a smart HLT
 *  trigger cut, specified as a string such as "pt>15 && -3<eta<3",
 *  for single objects of the same physics type, allowing to cut on
 *  variables relating to their 4-momentum representation
 *
 *  $Date: 2006/08/14 16:29:11 $
 *  $Revision: 1.16 $
 *
 *  \author Martin Grunewald
 *
 */

#include "HLTrigger/HLTcore/interface/HLTFilter.h"
#include<vector>

#include "PhysicsTools/Parser/interface/SingleObjectSelector.h"
#include<string>

//
// class decleration
//

template<typename T>
class HLTSmartSinglet : public HLTFilter {

   public:

      explicit HLTSmartSinglet(const edm::ParameterSet&);
      ~HLTSmartSinglet();
      virtual bool filter(edm::Event&, const edm::EventSetup&);

   private:
      edm::InputTag inputTag_; // input tag identifying product
      std::string   cut_;      // smart cut
      int    Min_N_;           // number of objects passing cuts required

      SingleObjectSelector<T> select_; // smart selector
};

#endif //HLTSmartSinglet_h
