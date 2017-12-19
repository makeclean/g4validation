//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: ExN01DetectorMessenger.cc 69706 2013-05-13 09:12:40Z gcosmo $
// 
/// \file ExN01DetectorMessenger.cc
/// \brief Implementation of the ExN01DetectorMessenger class

#include "ExN01DetectorMessenger.hh"
#include "ExN01DetectorConstruction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// TODO: Maybe get material data from the outside by a seperate file ala
// OpenMC - A amaterials file and in here set the material
// by a custom commandUIMessenger G4UICcmdWithAStringString ?
// maybe hijack G4's own text format?

ExN01DetectorMessenger::ExN01DetectorMessenger(ExN01DetectorConstruction* Det)
 : G4UImessenger(),
   fDetectorConstruction(Det)
{
  fExN01Directory = new G4UIdirectory("/benchmark/");
  fExN01Directory->SetGuidance("UI commands specific to this example.");

  fDetDirectory = new G4UIdirectory("/benchmark/material/");
  fDetDirectory->SetGuidance("Detector construction control");

  fTargMatCmd = new G4UIcmdWithAString("/benchmark/material/setRegionMaterial",this);
  fTargMatCmd->SetGuidance("Select Material of a Given Region.");
  fTargMatCmd->SetParameterName("choice",false);
  fTargMatCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  fTargAtomicNumber = new G4UIcmdWithADouble("/benchmark/material/setRegionAtomicNumber",this);
  fTargAtomicNumber->SetGuidance("Set the atomic number of the material.");
  fTargAtomicNumber->SetParameterName("atomicNumber",false);
  fTargAtomicNumber->AvailableForStates(G4State_PreInit,G4State_Idle);

  fTargNucleonNumber = new G4UIcmdWithADouble("/benchmark/material/setRegionNucleonNumber",this);
  fTargNucleonNumber->SetGuidance("Set the atomic number of the material.");
  fTargNucleonNumber->SetParameterName("nucleonNumber",false);
  fTargNucleonNumber->AvailableForStates(G4State_PreInit,G4State_Idle);

  fTargAtomicMass = new G4UIcmdWithADouble("/benchmark/material/setRegionAtomicMass",this);
  fTargAtomicMass->SetGuidance("Set the atomic number of the material.");
  fTargAtomicMass->SetParameterName("atomicMass",false);
  fTargAtomicMass->AvailableForStates(G4State_PreInit,G4State_Idle);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ExN01DetectorMessenger::~ExN01DetectorMessenger()
{
  delete fTargMatCmd;
  delete fTargAtomicNumber;
  delete fTargNucleonNumber;
  delete fTargAtomicMass;
  delete fDetDirectory;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ExN01DetectorMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{  
  if( command == fTargMatCmd ) {
    fDetectorConstruction -> SetMaterialName(newValue);
  }
  if ( command == fTargAtomicNumber ) {
    G4double atomic_number = fTargAtomicNumber->GetNewDoubleValue(newValue);
    fDetectorConstruction -> SetAtomicNumber(atomic_number);
  }
  if ( command == fTargNucleonNumber ) {
    G4double nucleon_number = fTargNucleonNumber->GetNewDoubleValue(newValue);
    fDetectorConstruction -> SetNucleonNumber(nucleon_number);
  }
  if ( command == fTargAtomicMass ) {
    G4double atomic_mass = fTargAtomicMass->GetNewDoubleValue(newValue);
    fDetectorConstruction -> SetAtomicMass(atomic_mass);
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
