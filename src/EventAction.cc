#include "EventAction.hh"

#include "G4AnalysisManager.hh"
#include "G4Event.hh"
#include "G4SystemOfUnits.hh"

EventAction::EventAction(){};
EventAction::~EventAction(){};

void EventAction::BeginOfEventAction(const G4Event* event){
    KE = 0.; 
}

void EventAction::EndOfEventAction(const G4Event* event){
    auto analysisManager = G4AnalysisManager::Instance();
    G4cout << "total travel length = " << KE/mm << "mm" << G4endl;
    //fill histogram 
    analysisManager->FillH1(0, KE);
}