#ifndef OpticalPropertiesSteppingAction_HH
#define OpticalPropertiesSteppingAction_HH 1

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "DetectorConstruction.hh"
#include "EventAction.hh"

class G4Step; 
class DetectorConstruction; 
class EventAction;

class SteppingAction : public G4UserSteppingAction {
    public:
        SteppingAction(const DetectorConstruction* detConstruction, EventAction* eventAction);
        //note naming the memeber vairables here is different from what we've done in the past, it's just for readability
        ~SteppingAction() override;

        void UserSteppingAction(const G4Step*) override; 

    private:
        const DetectorConstruction* fDetConstruction = nullptr; 
        EventAction* fEventAction = nullptr; 
};

#endif