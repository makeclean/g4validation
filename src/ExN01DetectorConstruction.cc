//
//
// $Id$
//

#include "ExN01DetectorConstruction.hh"
#include "ExN01SensitiveDetector.hh"
#include "ExN01Analysis.hh"

#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Orb.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"

#include "G4SDManager.hh"
#include "G4SDChargedFilter.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4VPrimitiveScorer.hh"
#include "G4PSEnergyDeposit.hh"
#include "G4PSTrackLength.hh"
#include "G4PSCellFlux.hh"

#include "G4GeometryManager.hh"
#include "G4ParticleTable.hh"
//

// constructor
ExN01DetectorConstruction::ExN01DetectorConstruction()
  :  world_volume_log(0) {
}

// destructor
ExN01DetectorConstruction::~ExN01DetectorConstruction() {
}

// the main method - takes the problem and loads
G4VPhysicalVolume* ExN01DetectorConstruction::Construct() {

  G4VisAttributes* invis = new G4VisAttributes(G4VisAttributes::Invisible);

  // vacuum material
  G4double atomicNumber = 1.; 
  G4double massOfMole = 1.008*g/mole; 
  G4double density = 1.e-25*g/cm3; 
  G4double temperature = 2.73*kelvin; 
  G4double pressure = 3.e-18*pascal; 
  G4Material *vacuum = new G4Material("interGalactic", atomicNumber, 
                                       massOfMole, density,kStateGas,temperature, pressure);

  //------------------------------------------------------ volumes
  // -- World Volume in which we place other volumes
  // and use that as the size for the world vol
  G4double world_width  = 100.0 * cm;
  G4GeometryManager::GetInstance()->SetWorldMaximumExtent(2.*world_width);

  G4Box* world_volume = new G4Box("world_volume_box", world_width, world_width, 
				  world_width);
  world_volume_log = new G4LogicalVolume(world_volume, vacuum,
					 "world_vol_log", 0, 0, 0);
  world_volume_log->SetVisAttributes(invis);
  G4PVPlacement* world_volume_phys = new G4PVPlacement(0, G4ThreeVector(), world_volume_log,
                                                       "world_vol", 0, false, 0);

  // material for sphere
  G4Isotope* li6_iso = new G4Isotope("Li-6", 3, 6, 6. * g / mole);
  G4Element* li6_el = new G4Element("Li-6","Li-6",1);
  li6_el->AddIsotope(li6_iso,100.*perCent);
  G4Material* li6 = new G4Material("Li-6",density=1.0*g/cm3,1);
  li6->AddElement(li6_el,1);

  G4cout << *(G4Material::GetMaterialTable()) << G4endl;

  // build the sphere
  G4Orb* sphere = new G4Orb("sphere",30.*cm);
  G4LogicalVolume *sphere_log = new G4LogicalVolume(sphere, li6, "sphere_log", 0, 0, 0);
  G4PVPlacement* sphere_phys = new G4PVPlacement(0,G4ThreeVector(),sphere_log,
						 "sphere",world_volume_log,false,0);
  return world_volume_phys;
}

// Constructs the tallies
void ExN01DetectorConstruction::ConstructSDandField() {

  G4SDManager::GetSDMpointer()->SetVerboseLevel(1);
}