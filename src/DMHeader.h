////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Name: DMMaster.h                                                          //
//                                                                            //
//  Creator: Andrew Hard                                                      //
//  Email: ahard@cern.ch                                                      //
//  Date: 10/03/2015                                                          //
//                                                                            //
//  This header file stores all of the global information for the H->gg + DM  //
//  search with 13 TeV data in 2015. It also has all of the includes that are //
//  necessary for the analysis.                                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////
// GLOBAL PARAMETERS
////////////////////////////////////////

// Set True for final analysis on data:
bool doBlind = false;

// Luminosity in fb-1:
double analysisLuminosity = 20.3;

double DMMassRangeLo = 105.0;
double DMMassRangeHi = 160.0;

int const nProdModes = 6;
TString sigProdModes[nProductionModes] = {"ggH","VBF","WH","ZH","ttH","bbH"};

std::map<TString,TString> prodToSample= { {"ggH", "sampleName_ggH"}, 
					  {"VBF", "sampleName_VBF"},
					  {"WH", "sampleName_WH"},
					  {"ZH", "sampleName_ZH"},
					  {"ttH", "sampleName_ttH"},
					  {"bbH","sampleName_bbH"} };

////////////////////////////////////////
// INPUT AND OUTPUT DIRECTORIES
////////////////////////////////////////

// Location of global input files:
TString masterInput = "/afs/cern.ch/work/a/ahard/files_HDM/GlobalInputs";

// Location of output directory:
TString masterOutput = "/afs/cern.ch/work/a/ahard/files_HDM/FullAnalysis";

////////////////////////////////////////
// FILE LOCATIONS
////////////////////////////////////////

// Ntuple locations:
//TString ntuple_input_background_gamma = "/afs/cern.ch/work/a/ahard/files_HDM/GlobalInputs/list_background_gamma.txt";

// Signal cross-sections file:
//TString cross_sections_file = "/afs/cern.ch/work/a/ahard/files_HDM/GlobalInputs/cross_sections_8TeV.txt";

////////////////////////////////////////
// SCRIPT LOCATIONS
////////////////////////////////////////

// Various job scripts:
//TString ws_jobscript = "/afs/cern.ch/user/a/ahard/work_directory/analysis/51_HDM/scripts/ws_jobfile.sh";
//TString toy_jobscript = "/afs/cern.ch/user/a/ahard/work_directory/analysis/51_HDM/scripts/toy_jobfile.sh";
