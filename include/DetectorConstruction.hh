#ifndef OpticalPropertiesDetectorConstruction_h
#define OpticalPropertiesDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4Material.hh"

class G4VPhysicalVolume;

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction();
    virtual ~DetectorConstruction();

    virtual G4VPhysicalVolume* Construct();

    const G4VPhysicalVolume* GetDetectorPhysicalVolume() const; 
    //first const says user can't modify the physical volume through this pointer 
    //second one says this function does not modify the object it belongs to 

  private:
    //methods 
    void DefineMaterials();
    G4VPhysicalVolume* DefineVolumes();

    //member data
    G4Material* worldMat; 
    G4Material* detMat; 

    G4VPhysicalVolume* fDetectorPhysicalVolume = nullptr; 
};

inline const G4VPhysicalVolume* DetectorConstruction::GetDetectorPhysicalVolume() const {
  return fDetectorPhysicalVolume; 
}

#endif