
#include "ExN01RunAction.hh"
#include "ExN01Analysis.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ExN01RunAction::ExN01RunAction()
  : G4UserRunAction() {
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ExN01RunAction::~ExN01RunAction() {
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// This function is called once at the begining of the simulation
void ExN01RunAction::BeginOfRunAction(const G4Run* /*run*/) {
  // Get analysis manager
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  
  G4String fileName = "ExN01";
  analysisManager->OpenFile(fileName);

  analysisManager->SetVerboseLevel(1);
  analysisManager->SetNtupleMerging(true);

  G4double bin_bounds[261] = {1.000000E-14 * GeV, 2.000000E-13 * GeV, 2.929734E-13 * GeV, 4.291671E-13 * GeV, 6.286727E-13 * GeV,
			      9.209218E-13 * GeV, 1.349028E-12 * GeV, 1.976147E-12 * GeV, 2.894792E-12 * GeV, 4.240485E-12 * GeV,
			      6.211746E-12 * GeV, 9.099382E-12 * GeV, 1.332938E-11 * GeV, 1.952578E-11 * GeV, 2.860266E-11 * GeV,
			      4.189910E-11 * GeV, 6.137660E-11 * GeV, 8.990856E-11 * GeV, 1.317041E-10 * GeV, 1.929290E-10 * GeV,
			      2.826153E-10 * GeV, 4.139938E-10 * GeV, 5.315785E-10 * GeV, 6.250621E-10 * GeV, 6.825603E-10 * GeV,
			      8.336811E-10 * GeV, 8.764248E-10 * GeV, 1.125352E-9 * GeV, 1.444980E-9 * GeV, 1.855391E-9 * GeV,
			      2.382370E-9 * GeV, 3.059023E-9 * GeV, 3.927864E-9 * GeV, 5.043477E-9 * GeV, 6.475952E-9 * GeV,
			      8.315287E-9 * GeV, 1.067704E-8 * GeV, 1.370959E-8 * GeV, 1.760346E-8 * GeV, 2.260329E-8 * GeV,
			      2.902320E-8 * GeV, 3.726653E-8 * GeV, 4.785117E-8 * GeV, 6.144212E-8 * GeV, 7.889325E-8 * GeV,
			      1.013009E-7 * GeV, 1.300730E-7 * GeV, 1.670170E-7 * GeV, 2.144541E-7 * GeV, 2.753645E-7 * GeV,
			      3.535750E-7 * GeV, 4.539993E-7 * GeV, 5.829466E-7 * GeV, 7.485183E-7 * GeV, 9.611165E-7 * GeV,
			      1.234098E-6 * GeV, 1.363889E-6 * GeV, 1.507331E-6 * GeV, 1.584613E-6 * GeV, 1.665858E-6 * GeV,
			      1.841058E-6 * GeV, 2.034684E-6 * GeV, 2.248673E-6 * GeV, 2.485168E-6 * GeV, 2.612586E-6 * GeV,
			      2.746536E-6 * GeV, 2.863488E-6 * GeV, 3.035391E-6 * GeV, 3.354626E-6 * GeV, 3.707435E-6 * GeV,
			      4.097350E-6 * GeV, 4.307425E-6 * GeV, 4.528272E-6 * GeV, 5.004514E-6 * GeV, 5.530844E-6 * GeV,
			      6.267267E-6 * GeV, 7.101744E-6 * GeV, 8.047330E-6 * GeV, 9.118820E-6 * GeV, 1.033298E-5 * GeV,
			      1.170880E-5 * GeV, 1.326780E-5 * GeV, 1.503439E-5 * GeV, 1.703620E-5 * GeV, 1.930454E-5 * GeV,
			      2.133482E-5 * GeV, 2.187491E-5 * GeV, 2.357862E-5 * GeV, 2.417552E-5 * GeV, 2.478752E-5 * GeV,
			      2.605841E-5 * GeV, 2.808794E-5 * GeV, 3.182781E-5 * GeV, 3.430669E-5 * GeV, 3.517517E-5 * GeV,
			      3.606563E-5 * GeV, 4.086771E-5 * GeV, 4.630919E-5 * GeV, 5.247518E-5 * GeV, 5.656217E-5 * GeV,
			      5.946217E-5 * GeV, 6.251086E-5 * GeV, 6.737947E-5 * GeV, 7.635094E-5 * GeV, 8.651695E-5 * GeV,
			      9.803655E-5 * GeV, 1.110900E-4 * GeV, 1.167857E-4 * GeV, 1.227734E-4 * GeV, 1.290681E-4 * GeV,
			      1.356856E-4 * GeV, 1.426423E-4 * GeV, 1.499558E-4 * GeV, 1.576442E-4 * GeV, 1.616349E-4 * GeV,
			      1.657268E-4 * GeV, 1.699221E-4 * GeV, 1.742237E-4 * GeV, 1.831564E-4 * GeV, 1.925470E-4 * GeV,
			      2.024191E-4 * GeV, 2.127974E-4 * GeV, 2.237077E-4 * GeV, 2.351775E-4 * GeV, 2.472353E-4 * GeV,
			      2.599113E-4 * GeV, 2.732372E-4 * GeV, 2.801543E-4 * GeV, 2.872464E-4 * GeV, 2.945181E-4 * GeV,
			      3.019738E-4 * GeV, 3.096183E-4 * GeV, 3.174564E-4 * GeV, 3.337327E-4 * GeV, 3.508435E-4 * GeV,
			      3.688317E-4 * GeV, 3.877421E-4 * GeV, 4.076220E-4 * GeV, 4.285213E-4 * GeV, 4.504920E-4 * GeV,
			      4.735892E-4 * GeV, 4.978707E-4 * GeV, 5.104743E-4 * GeV, 5.233971E-4 * GeV, 5.366469E-4 * GeV,
			      5.502322E-4 * GeV, 5.784432E-4 * GeV, 6.081006E-4 * GeV, 6.392786E-4 * GeV, 6.720551E-4 * GeV,
			      7.065121E-4 * GeV, 7.427358E-4 * GeV, 7.808167E-4 * GeV, 8.208500E-4 * GeV, 8.629359E-4 * GeV,
			      9.071795E-4 * GeV, 9.536916E-4 * GeV, 9.616402E-4 * GeV, 9.778344E-4 * GeV, 1.002588E-3 * GeV,
			      1.053992E-3 * GeV, 1.108032E-3 * GeV, 1.164842E-3 * GeV, 1.194330E-3 * GeV, 1.224564E-3 * GeV,
			      1.287349E-3 * GeV, 1.353353E-3 * GeV, 1.422741E-3 * GeV, 1.495686E-3 * GeV, 1.533550E-3 * GeV,
			      1.572372E-3 * GeV, 1.612176E-3 * GeV, 1.652989E-3 * GeV, 1.737739E-3 * GeV, 1.826835E-3 * GeV,
			      1.873082E-3 * GeV, 1.920499E-3 * GeV, 1.969117E-3 * GeV, 2.018965E-3 * GeV, 2.122480E-3 * GeV,
			      2.231302E-3 * GeV, 2.268877E-3 * GeV, 2.306855E-3 * GeV, 2.345703E-3 * GeV, 2.365253E-3 * GeV,
			      2.385205E-3 * GeV, 2.425130E-3 * GeV, 2.465970E-3 * GeV, 2.592403E-3 * GeV, 2.725318E-3 * GeV,
			      2.865048E-3 * GeV, 3.011942E-3 * GeV, 3.088190E-3 * GeV, 3.166368E-3 * GeV, 3.246525E-3 * GeV,
			      3.328711E-3 * GeV, 3.499377E-3 * GeV, 3.678794E-3 * GeV, 3.867410E-3 * GeV, 4.065697E-3 * GeV,
			      4.274149E-3 * GeV, 4.493290E-3 * GeV, 4.607038E-3 * GeV, 4.723666E-3 * GeV, 4.843246E-3 * GeV,
			      4.965853E-3 * GeV, 5.220458E-3 * GeV, 5.488116E-3 * GeV, 5.769498E-3 * GeV, 5.915554E-3 * GeV,
			      6.050000E-3 * GeV, 6.218851E-3 * GeV, 6.376282E-3 * GeV, 6.537698E-3 * GeV, 6.592384E-3 * GeV,
			      6.647595E-3 * GeV, 6.703200E-3 * GeV, 6.872893E-3 * GeV, 7.046881E-3 * GeV, 7.225274E-3 * GeV,
			      7.408182E-3 * GeV, 7.595721E-3 * GeV, 7.788008E-3 * GeV, 7.985162E-3 * GeV, 8.187308E-3 * GeV,
			      8.394570E-3 * GeV, 8.607080E-3 * GeV, 8.824969E-3 * GeV, 9.048374E-3 * GeV, 9.277435E-3 * GeV,
			      9.512294E-3 * GeV, 9.753099E-3 * GeV, 1.000000E-2 * GeV, 1.025315E-2 * GeV, 1.051271E-2 * GeV,
			      1.077884E-2 * GeV, 1.105171E-2 * GeV, 1.133148E-2 * GeV, 1.161834E-2 * GeV, 1.191246E-2 * GeV,
			      1.221403E-2 * GeV, 1.252323E-2 * GeV, 1.284025E-2 * GeV, 1.316531E-2 * GeV, 1.349859E-2 * GeV,
			      1.384031E-2 * GeV, 1.419068E-2 * GeV, 1.454991E-2 * GeV, 1.491825E-2 * GeV, 1.529590E-2 * GeV,
			      1.568312E-2 * GeV, 1.608014E-2 * GeV, 1.648721E-2 * GeV, 1.690459E-2 * GeV, 1.733253E-2 * GeV,
			      1.777131E-2 * GeV, 1.822119E-2 * GeV, 1.868246E-2 * GeV, 1.915541E-2 * GeV, 1.964033E-2 * GeV,
			      2.000000E-2 * GeV};

  // G4 expects a vector
  // but CI doesnt like using the C++11 std
  std::vector<G4double> bin_bounds_v;
  // hence this
  bin_bounds_v.assign(bin_bounds, bin_bounds + 261);

  analysisManager->CreateH1("NeutronSpectrum","Neutron Spectrum in Cell",bin_bounds_v);
  analysisManager->CreateH1("NeutronLeakageSpectrum","Neutron Leakage Spectrum in Cell",bin_bounds_v);
  analysisManager->CreateNtuple("NeutronSpectrum","Neutron Flux and Leakage Spectrum");
  analysisManager->CreateNtupleDColumn("Neutron Flux");
  analysisManager->CreateNtupleDColumn("Neutron Leakage");
  analysisManager->FinishNtuple();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void ExN01RunAction::EndOfRunAction(const G4Run* /*run*/ ) {
  G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
  // print histogram statistics
  G4cout << "Neutron Flux " << analysisManager->GetH1(0)->mean() << " ";
  G4cout << "error " << analysisManager->GetH1(0)->rms() << G4endl;
  
  G4cout << "Neutron Current " << analysisManager->GetH1(0)->mean() << " ";
  G4cout << "error " << analysisManager->GetH1(0)->rms() << G4endl;

  analysisManager->Write();
  analysisManager->CloseFile();

  delete G4AnalysisManager::Instance();
}
