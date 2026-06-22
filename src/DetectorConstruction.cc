#include "DetectorConstruction.hh"

#include "G4SystemOfUnits.hh"
#include "G4Box.hh"
#include "G4VPhysicalVolume.hh"
#include "G4NistManager.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4ThreeVector.hh"
#include "G4VisAttributes.hh"
#include "G4MaterialPropertiesTable.hh"
#include "G4PhysicalConstants.hh"

// Start by implementing the constructor

DetectorConstruction::DetectorConstruction()
{
    // leave empty for now...
}

DetectorConstruction::~DetectorConstruction()
{
    // don't have anything to clear from memory yet so leave blank
}

// the heart of this class
G4VPhysicalVolume *DetectorConstruction::Construct()
{

    DefineMaterials();

    return DefineVolumes();
}

void DetectorConstruction::DefineMaterials()
{
    // G4NistManager is a singleton, so need to call it differently. doing 'new G4NistManager' could create many copies
    // If an instance d/n exist, G4 creates it
    // IF an instance already exists, we get the same one
    // Basically we're getting access to the database. Whenever one sees "Instance" it's a singleton
    G4NistManager *nist = G4NistManager::Instance();

    worldMat = nist->FindOrBuildMaterial("G4_AIR");

    auto air_mt = new G4MaterialPropertiesTable();
    air_mt->AddProperty("RINDEX", "Air"); //air is one of the materials with pre-defined properties
    worldMat->SetMaterialPropertiesTable(air_mt);

    detMat = nist->FindOrBuildMaterial("G4_POLYSTYRENE");

    G4MaterialPropertiesTable *scintillator_mt = new G4MaterialPropertiesTable();

    scintillator_mt->AddConstProperty("SCINTILLATIONYIELD", 10. / MeV);
    std::vector<G4double> rindex = {1.59, 1.59, 1.59, 1.59};
    std::vector<G4double> wavelenghts = {550.*nm, 500.*nm, 450.*nm, 410.*nm}; 
    for (auto& num : wavelenghts){
        num = h_Planck * c_light / num ; 
    }
    std::vector<G4double> intensities = {0.1, 0.5, 1, 0.1};
    std::vector<G4double> abslength = {4.0*m, 4.0*m, 4.0*m, 4.0*m};
    scintillator_mt->AddProperty("SCINTILLATIONCOMPONENT1", wavelenghts, intensities);
    scintillator_mt->AddConstProperty("SCINTILLATIONTIMECONSTANT1", 2.8*ns);
    scintillator_mt->AddConstProperty("RESOLUTIONSCALE", 1.0);
    scintillator_mt->AddProperty("RINDEX", wavelenghts, rindex);
    scintillator_mt->AddProperty("ABSLENGTH", wavelenghts, abslength);

    detMat->SetMaterialPropertiesTable(scintillator_mt);


    return;
}

G4VPhysicalVolume *DetectorConstruction::DefineVolumes()
{

    G4double world_x = 50 * cm;
    G4double world_y = 50 * cm;
    G4double world_z = 50 * cm;

    G4Box *worldSolid = new G4Box("World Solid", world_x, world_y, world_z);

    G4LogicalVolume *worldLog = new G4LogicalVolume(worldSolid, worldMat, "World Logical");

    G4PVPlacement *worldPlacement = new G4PVPlacement(0, G4ThreeVector(0, 0, 0), worldLog, "World Placement", nullptr, false, 0);

    G4double det_x = 50 * cm;
    G4double det_y = 50 * cm;
    G4double det_z = 10 * cm;

    G4Box *detSolid = new G4Box("Detector Solid", det_x, det_y, det_z);
    G4LogicalVolume *detLog = new G4LogicalVolume(detSolid, detMat, "Detector Logical");
    fDetectorPhysicalVolume = new G4PVPlacement(0, G4ThreeVector(0, 0, 20 * cm), detLog, "Detector Placement", worldLog, false, 0);

    worldLog->SetVisAttributes(G4VisAttributes::GetInvisible());
    detLog->SetVisAttributes(G4VisAttributes(G4Colour::Blue()));

    return worldPlacement;
}