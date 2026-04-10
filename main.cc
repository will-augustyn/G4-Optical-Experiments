#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"

#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
#include "G4VisManager.hh"
#include "G4UImanager.hh"
#include "FTFP_BERT.hh"

int main(int argc, char** argv){
    G4RunManager* runManager = new G4RunManager; //only manager class that needs to be constructed. controls flow of program 
    // & manages event loops within a run

    // set mandatory initialization classes
    runManager->SetUserInitialization(new DetectorConstruction());
    auto PhysicsList = new FTFP_BERT; 
    runManager->SetUserInitialization(PhysicsList);

    runManager->SetUserInitialization(new ActionInitialization);

    // initialize G4 kernel
    runManager->Initialize();

    //basically this class is how we get to use openGL, etc. If we didnt' have it couldn't use any visualization. Techincally, not neccesary though
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();

    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    //argc represents the number of command line arguments passed. If it's one then the user just typed ./mysim
    //meaning they want to run in interactive mode
    if (argc == 1){
        G4UIExecutive* ui = new G4UIExecutive(argc, argv); //launch a terminal that lets us type geant commands in 
        // UImanager->ApplyCommand("/control/execute init.mac"); //optional line that lets us set up a starting visualization file
        ui->SessionStart(); //actually start terminal 
        delete ui; // once session is done, clean up the memory 
    }
    else { // For example, ./mysim run.mac then argc==2
        G4String command = "/control/execute ";
        G4String filename = argv[1]; //ex run1.mac
        UImanager->ApplyCommand(command+filename); //just run the macro then finish 
    }

    delete runManager;
    delete visManager;
    return 0; 
}