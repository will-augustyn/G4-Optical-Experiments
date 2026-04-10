#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"

ActionInitialization::ActionInitialization(){};
ActionInitialization::~ActionInitialization(){};

void ActionInitialization::BuildForMaster() const{
    //this should only be used for defining UserRunAction
};

void ActionInitialization::Build() const {
    SetUserAction(new PrimaryGeneratorAction());
    SetUserAction(new RunAction());
};