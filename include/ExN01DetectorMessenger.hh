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
// $Id: ExN01DetectorMessenger.hh 69706 2013-05-13 09:12:40Z gcosmo $
//
/// \file ExN01DetectorMessenger.hh
/// \brief Definition of the ExN01DetectorMessenger class

#ifndef ExN01DetectorMessenger_h
#define ExN01DetectorMessenger_h 1

#include "globals.hh"
#include "G4UIdirectory.hh"
#include "G4UImessenger.hh"
#include "G4UIcmdWithADouble.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithAString.hh"

class ExN01DetectorConstruction;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

/// Messenger class that defines commands for ExN01DetectorConstruction.

class ExN01DetectorMessenger: public G4UImessenger
{
  public:
    ExN01DetectorMessenger(ExN01DetectorConstruction* );
    virtual ~ExN01DetectorMessenger();
    
    virtual void SetNewValue(G4UIcommand*, G4String);
    
  private:
    ExN01DetectorConstruction*  fDetectorConstruction;

    G4UIdirectory*           fExN01Directory;
    G4UIdirectory*           fDetDirectory;

    G4UIcmdWithAString* fTargMatCmd;
    G4UIcmdWithADouble* fTargAtomicNumber;
    G4UIcmdWithADouble* fTargNucleonNumber;
    G4UIcmdWithADouble* fTargAtomicMass;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
