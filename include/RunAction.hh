#ifndef OpticalPropertiesRunAction_HH
#define OpticalPropertiesRunAction_HH 1

#include "G4UserRunAction.hh"
#include "G4Run.hh"

class G4Run; 
class RunAction : public G4UserRunAction {
    public:
        RunAction();
        ~RunAction() override;

        void BeginOfRunAction(const G4Run*) override;
        void EndOfRunAction(const G4Run*) override;

};

#endif