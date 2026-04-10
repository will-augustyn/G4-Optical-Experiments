#ifndef MU2E_PRIMARY_GENERATOR_ACTION_HH
#define MU2E_PRIMARY_GENERATOR_ACTION_HH 1

#include "G4VUserActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"

//The point of this class is to register user action classes with the run manager 

class PrimaryGeneratorAction;

class ActionInitialization : public G4VUserActionInitialization {
    public:
        ActionInitialization();
        ~ActionInitialization() override;
        //override is used in a derived class to explicitly state that a member function 
        // is intended to override a virtual function from a base class

    void BuildForMaster() const override;
    void Build() const override;

}; 

#endif