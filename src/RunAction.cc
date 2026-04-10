#include "RunAction.hh"

#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4Run.hh"

RunAction::RunAction(){
    auto analysisManager = G4AnalysisManager::Instance();

    analysisManager->SetVerboseLevel(1);

    analysisManager->CreateH1("Edep", "Deposited Energy", 10, 0., 5 * MeV);

};

RunAction::~RunAction(){}; 

void RunAction::BeginOfRunAction(const G4Run* run){
    auto analysisManager = G4AnalysisManager::Instance();

    G4String fileName = "histogram1.root";

    analysisManager->OpenFile("histogram1.root");

};

void RunAction::EndOfRunAction(const G4Run* run){
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();

};
