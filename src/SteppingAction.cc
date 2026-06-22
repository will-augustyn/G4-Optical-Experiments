#include "SteppingAction.hh"
#include "DetectorConstruction.hh"
#include "RunAction.hh"

#include "G4Electron.hh"

SteppingAction::SteppingAction(const DetectorConstruction* detConstruction, EventAction* eventAction) 
: fDetConstruction(detConstruction), fEventAction(eventAction){
};
//note what we're doing here. What will get passed into this function are pointers to our detector construction and event action. 
// the : is called the initilizer list and it's a way of ensuring memeber variables are correctly assigned from the start
// It's optinional in some cases, but for const variables it is actually required 

SteppingAction::~SteppingAction(){}; 

void SteppingAction::UserSteppingAction(const G4Step* step){
    auto volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
    auto Edep = step->GetStepLength();
    auto particleID = step->GetTrack()->GetParticleDefinition(); 
    auto classID = G4Electron::ElectronDefinition(); 
    //note don't have to do G4Electron::Instace() because ElectronDefinition() is a static member of the G4Electron class so we don't need an instance of the class to call it. 
    G4bool result = classID == particleID; //check if the particle we're tracking in the current step is an electron

    if (volume == fDetConstruction->GetDetectorPhysicalVolume() && result == 1){
        G4cout << Edep << G4endl; 
        fEventAction->addKE(Edep);//add energy via an inline function in the event action class
    }
}