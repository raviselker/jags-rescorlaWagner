#include <module/Module.h> // include JAGS module base class
#include <functions/resWagner.h> // include resWagner class

namespace jags {
namespace rescorlaWagner {

  // Module class
  class RESCORLAWAGNERModule : public Module {
    public:
      RESCORLAWAGNERModule(); // constructor
      ~RESCORLAWAGNERModule(); // destructor
  };

  // Constructor function
  RESCORLAWAGNERModule::RESCORLAWAGNERModule() : Module("rescorlaWagner") {
    insert(new resWagner);
  }

  // Destructor function
  RESCORLAWAGNERModule::~RESCORLAWAGNERModule() {
    std::vector<Distribution*> const &dvec = distributions();
    for (unsigned int i = 0; i < dvec.size(); ++i) {
      delete dvec[i]; // delete all instantiated distribution objects
    }

    std::vector<Function*> const &fvec = functions();
    for (unsigned int i = 0; i < fvec.size(); ++i) {
      delete fvec[i];
    }
  }

} // end namespace definition
}

jags::rescorlaWagner::RESCORLAWAGNERModule _rescorlaWagner_module;
