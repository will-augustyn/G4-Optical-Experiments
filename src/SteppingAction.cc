#include "SteppingAction.hh"
#include "DetectorConstruction.hh"
#include "RunAction.hh"

SteppingAction::SteppingAction(const DetectorConstruction* detConstruction, EventAction* eventAction) 
: fDetConstruction(detConstruction), fEventAction(eventAction){};
//note what we're doing here. What will get passed into this function are pointers to our detector construction and event action. 
// the : is called the initilizer list and it's a way of ensuring memeber variables are correctly assigned from the start
// It's optinional in some cases, but for const variables it is actually required 

SteppingAction::~SteppingAction(){}; 

void SteppingAction::UserSteppingAction(const G4Step* step){
    auto volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
    auto KEdep = step->GetPreStepPoint()->GetKineticEnergy();

    if (volume == fDetConstruction->GetDetectorPhysicalVolume()){
        G4cout << KEdep << G4endl; 
        fEventAction->addKE(KEdep);//add energy via an inline function in the event action class
    }
}