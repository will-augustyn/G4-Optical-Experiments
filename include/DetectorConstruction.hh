#ifndef Mu2eDetectorConstruction_h
#define Mu2eDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4Material.hh"

class G4VPhysicalVolume;

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction();
    virtual ~DetectorConstruction();

    virtual G4VPhysicalVolume* Construct();

  private:
    //methods 
    void DefineMaterials();
    G4VPhysicalVolume* DefineVolumes();

    //member data
    G4Material* worldMat; 
    G4Material* detMat; 

};

#endif