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

#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// TODO: Maybe get material data from the outside by a seperate file ala
// OpenMC - A amaterials file and in here set the material
// by a custom commandUIMessenger G4UICcmdWithAStringString ?
// maybe hijack G4's own text format?

ExN01DetectorMessenger::ExN01DetectorMessenger(ExN01DetectorConstruction* Det)
 : G4UImessenger(),
   fDetectorConstruction(Det)
{
  fExN01Directory = new G4UIdirectory("/grant/");
  fExN01Directory->SetGuidance("UI commands specific to this example.");

  fDetDirectory = new G4UIdirectory("/grant/det/");
  fDetDirectory->SetGuidance("Detector construction control");

  fTargMatCmd = new G4UIcmdWithAString("/grant/det/setRegionMaterial",this);
  fTargMatCmd->SetGuidance("Select Material of a Given Region.");
  fTargMatCmd->SetParameterName("choice",false);
  fTargMatCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  fChamMatCmd = new G4UIcmdWithAString("/grant/det/setChamberMaterial",this);
  fChamMatCmd->SetGuidance("Select Material of the Chamber.");
  fChamMatCmd->SetParameterName("choice",false);
  fChamMatCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  fStepMaxCmd = new G4UIcmdWithADoubleAndUnit("/grant/det/stepMax",this);
  fStepMaxCmd->SetGuidance("Define a step max");
  fStepMaxCmd->SetParameterName("stepMax",false);
  fStepMaxCmd->SetUnitCategory("Length");
  fStepMaxCmd->AvailableForStates(G4State_Idle);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ExN01DetectorMessenger::~ExN01DetectorMessenger()
{
  delete fTargMatCmd;
  delete fChamMatCmd;
  delete fStepMaxCmd;
  delete fExN01Directory;
  delete fDetDirectory;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ExN01DetectorMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{
  /*
  if( command == fTargMatCmd )
   { fDetectorConstruction->SetTargetMaterial(newValue);}

  if( command == fChamMatCmd )
   { fDetectorConstruction->SetChamberMaterial(newValue);}

  if( command == fStepMaxCmd ) {
    fDetectorConstruction
      ->SetMaxStep(fStepMaxCmd->GetNewDoubleValue(newValue));
  } 
  */  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
