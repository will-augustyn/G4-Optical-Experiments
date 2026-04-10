#include "PrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4ThreeVector.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction(
    // create the constructor. note that : is like super in python where we call the base class contructor
    const G4String& particleName, G4double energy, 
    G4ThreeVector position, G4ThreeVector momentumDirection) : G4VUserPrimaryGeneratorAction(), fParticleGun(0) { //fparticlegun(0) basically initiliazes particle gun to a null pointer 
        G4int nofParticles = 1;
        fParticleGun = new G4ParticleGun(nofParticles);
        G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
        G4ParticleDefinition* particle = particleTable->FindParticle(particleName);
        fParticleGun->SetParticleDefinition(particle);
        fParticleGun->SetParticleEnergy(energy);
        fParticleGun->SetParticlePosition(position);
        fParticleGun->SetParticleMomentumDirection(momentumDirection);
    }

PrimaryGeneratorAction::~PrimaryGeneratorAction(){
    delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent){ //function that overrides a virtual function from the base class
    //G4Event a class representing one event, so * is a pointer to the current event object 
    fParticleGun->GeneratePrimaryVertex(anEvent);
}
    