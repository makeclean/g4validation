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
// $Id: ExN01SensitiveDetector.cc 68058 2013-03-13 14:47:43Z gcosmo $
//
/// \file ExN01SensitiveDetector.cc
/// \brief Implementation of the ExN01SensitiveDetector class

#include "ExN01SensitiveDetector.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "ExN01Analysis.hh"
#include "G4ios.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ExN01SensitiveDetector::ExN01SensitiveDetector(const G4String& name,
                                               const G4String& hit_coll_name,
                                               const G4int     detector_index)
  : G4VSensitiveDetector(name),
    collectionID(-1),
    DetectorIndex(-1) {

  DetectorName = name;
  collectionName.insert(hit_coll_name);
  DetectorIndex = detector_index;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ExN01SensitiveDetector::~ExN01SensitiveDetector() {
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ExN01SensitiveDetector::Initialize(G4HCofThisEvent* hce) {
  // Create hits collection
  fHitsCollection = new ExN01DetectorHitsCollection(SensitiveDetectorName, collectionName[0]);

  // Add this collection in hce
  G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
  hce->AddHitsCollection(hcID, fHitsCollection);
  fHitsCollection->insert(new ExN01DetectorHit());
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool ExN01SensitiveDetector::ProcessHits(G4Step* aStep,
                                           G4TouchableHistory*) {
  // TrackLike Scoring
  // G4double edep = aStep->GetTotalEnergyDeposit();

  ExN01DetectorHit* newHit = new ExN01DetectorHit();
  /*
  newHit->SetEdep( aStep->GetTotalEnergyDeposit());
  newHit->SetTrackID  (aStep->GetTrack()->GetTrackID());
  newHit->SetPos (aStep->GetPostStepPoint()->GetPosition());
  */
  //newHit->SetParticleEnergy(aStep->GetTrack()->GetKineticEnergy());
  newHit->SetParticleEnergy(aStep->GetPreStepPoint()->GetKineticEnergy());
  newHit->SetTrackLength(aStep->GetTrack()->GetStepLength());
  newHit->SetWeight(aStep->GetTrack()->GetWeight());
  newHit->SetParticleName(aStep->GetTrack()->GetDefinition()->GetParticleName());
  newHit->SetParticlePDG(aStep->GetTrack()->GetDefinition()->GetPDGEncoding());

  fHitsCollection->insert(newHit);

  return true;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ExN01SensitiveDetector::EndOfEvent(G4HCofThisEvent*) {
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

  G4int nofHits = fHitsCollection->entries();
  /*
  G4cout << "Detector = " << DetectorName << G4endl;
  G4cout << "\n-------->Hits Collection: in this event they are " << nofHits
         << G4endl;
         */
  //  G4cout << "processing hits" << G4endl;
  G4double score = 0.0;
//  G4cout << DetectorName << " " << nofHits << G4endl;
//  G4cout << nofHits << G4endl;
  for (G4int i = 0; i < nofHits; i++) {
      score = (*fHitsCollection)[i]->GetWeight() *
              (*fHitsCollection)[i]->GetTrackLength()
              * cm / (DetectorVolume);
      G4double erg = (*fHitsCollection)[i]->GetKE();

      analysisManager->FillH1(0, erg, score);

      //    G4cout << hist_index << " " << DetectorIndex << " " << score << "  " << erg << G4endl;
    }
    //G4cout << DetectorIndex << " " << score << G4endl;
 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
