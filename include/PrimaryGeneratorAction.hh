#ifndef Mu2ePrimaryGeneratorAction_h
#define Mu2ePrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "G4ParticleGun.hh"
#include "G4Event.hh"

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
    public:
        PrimaryGeneratorAction(
            const G4String& particleName = "e-", //& makes a reference to a string
            G4double energy = 3.*MeV,
            G4ThreeVector position= G4ThreeVector(0,0,0),
            G4ThreeVector momentumDirection = G4ThreeVector(0,0,1)
        );
        ~PrimaryGeneratorAction() override;

        void GeneratePrimaries(G4Event*) override;

        private:
            G4ParticleGun* fParticleGun;
};   

#endif