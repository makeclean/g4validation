
#ifndef ExN01DetectorConstruction_H
#define ExN01DetectorConstruction_H 1

class G4LogicalVolume;
class G4VPhysicalVolume;

#include "ExN01DetectorMessenger.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4SDParticleFilter.hh"
#include <map>
#include <string>

class ExN01DetectorConstruction : public G4VUserDetectorConstruction {
 public:

  ExN01DetectorConstruction();
  ~ExN01DetectorConstruction();

 public:
  virtual G4VPhysicalVolume* Construct();
  virtual void ConstructSDandField();

  // particle filters for tallies
  std::map<std::string, G4SDParticleFilter*> particle_filters;

  void BuildParticleFilter(std::string particle_name);
  void build_histogram();
  void add_histogram_description(std::string tally_name);
  void end_histogram();
  
  void SetMaterialName(G4String material_name);
  void SetAtomicNumber(G4double atomic_number);
  void SetNucleonNumber(G4double nucleon_number);
  void SetAtomicMass(G4double atomic_mass);

 private:
  std::string _to_string(int var);

 private:

  // Logical volumes
  //
  ExN01DetectorMessenger* detectorMessenger;
  G4LogicalVolume* world_volume_log;

  G4String fMaterialName;
  G4double fAtomicNumber;
  G4double fNucleonNumber;
  G4double fAtomicMass;

  // DAG Logical volumes
  // G4LogicalVolume* dag_vol_log;

  // Physical volumes
  //
  // G4VPhysicalVolume* world_volume_phys;
  // DAG Physical volumes


};

#endif
