#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

ActionInitialization::ActionInitialization(DetectorConstruction* detConstruction)
  : fDetConstruction(detConstruction) //set fDetConstruction (which is a member variable in DetectorConstruction class)
{}
ActionInitialization::~ActionInitialization(){};

void ActionInitialization::BuildForMaster() const{
    //this should only be used for defining UserRunAction
    // SetUserAction(new RunAction);
};

void ActionInitialization::Build() const {
    SetUserAction(new PrimaryGeneratorAction());
    SetUserAction(new RunAction());
    auto eventAction = new EventAction;
    SetUserAction(eventAction);
    SetUserAction(new SteppingAction(fDetConstruction, eventAction));
};