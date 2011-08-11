/*
 *  MPOLnchHelpfiles.cpp
 *  MPOLauncher
 *
 *  Created by fabiantheblind on 01.08.11.
 *  Copyright 2011 tmn. All rights reserved.
 *
 */

#include "MPOLnchHelper.h"

//  constructor
MPOLnchHelper::MPOLnchHelper(){
}
int MPOLnchHelper::MAXITEMS = 13;
int MPOLnchHelper::METAMAXITEMS = 3;
int MPOLnchHelper::FCGREPMAXITEMS = 19;
int MPOLnchHelper::FCOBJECTMAXITEMS = 1;
int MPOLnchHelper::FCTEXTMAXITEMS = 1;
int MPOLnchHelper::MISCMAXITEMS = 5;


PMString MPOLnchHelper::MissingScrptFileStr(PMString fn){
	PMString s("Got an error reading in the "+fn 
			   + " function. You need the MPO Launcher Scripts in the Scripts Panel. Use the scriptfile restore option");
	return s;
}

PMString MPOLnchHelper::MissingHelpFileStr(PMString fn){

	PMString s("Got an error reading in the "+fn
	+" help. Something went terribly wrong."+
			 " Contact info@themoron.net for more help");
	
	return s;
}


PMString MPOLnchHelper::GetScriptFile(int i){
	
//	PMString theFileName[13] = {
//		"MPO_Importer.jsx",
//		"theNumbers.jsx",
//		"clearAllStyles.jsx",
//		"theFindChange.jsx",
//		"theItemFinder.jsx",
//		"theLinkButton.jsx",
//		"theImagePlacer.jsx",
//		"clearStructure.jsx",
//		"color_KEY.jsx",
//		"color_PAPER.jsx",
//		"color_XXX.jsx",
//		"color_MIXEDBLACK.jsx",
//
//		"QUICKY.jsx"};
	

	if (i > 13) {
		i = 13; 
	}
	PMString tfn = this->GetNodeName(i);
	tfn.Append(".jsx");
	return tfn;
	return tfn;
}

PMString MPOLnchHelper::GetHelpFile(int i){
	
//	PMString theFileName[13] = {
//		"MPO_Importer.txt",
//		"theNumbers.txt",
//		"clearAllStyles.txt",
//		"theFindChange.txt",
//		"theItemFinder.txt",
//		"theLinkButton.txt",
//		"theImagePlacer.txt",
//		"clearStructure.txt",
//		"color_KEY.txt",
//		"color_PAPER.txt",
//		"color_XXX.txt",
//		"color_MIXEDBLACK.jsx",
//		"QUICKY.txt"};
	
	
	
	if (i > 13) {
		i = 13; 
	}
	PMString tfn = this->GetNodeName(i);
	tfn.Append(".txt");
	return tfn;
}

// holds also the nodenames
PMString MPOLnchHelper::GetNodeName(int i){
	
	PMString NN[13] = {
		"MPO Importer",
		"The Numbers",
		"Clear All Styles",
		"Find and Change",
		"Find Items",
		"Build Link Button",
		"Place All Images",
		"Clear xml Structure",
		"Tint-2-Key",
		"Tint-2-Paper",
		"Tint-2-Swatch",
		"Tint-2-Mixedblack",
		"Quick Scribble"};
	
	
	
	if (i > 13) {
		i = 13; 
	}
	return NN[i];
	
	


} 

// the find change queries need to be installed in the resources

PMString MPOLnchHelper::GetObjectFCFile(int i){
	
	PMString theFileName[1] = {
		"change_100K_To_MixedK.xml"};
	
	
	
	if (i > 1) {
		i = 1; 
	}
	return theFileName[i];
}

PMString MPOLnchHelper::GetGrepFCFile(int i){
	
	PMString theFileName[19] = {
		
		"__JMRaute 2 Raute whitespace.xml",
		"JM__ANAB_01.xml",
		"JM__ANAB_02.xml",
		"JM__APOSTROPH.xml",
		"JM__BISSTRICH.xml",
		"JM__EURO_hin.xml",
		"JM__EURO_zurueck.xml",
		"JM__INTERPUNKTION.xml",
		"JM__KOMMABLANK.xml",
		"JM__LEERZEICHEN_DOPPELTE.xml",
		"JM__MALZEICHEN.xml",
		"JM__PREISSTRICH.xml",
		"JM__PUNKTBLANK.xml",
		"JM__ZOLL_HIN.xml",
		"JM__ZOLL_ZURUECK.xml",
		"JM__ZOLLZEICHEN.xml",
		"JM_MIDI.xml",
		"JM_Plug-in.xml",
		"mySpecsFinder.xml"};
	
	
	
	if (i > 19) {
		i = 19; 
	}
	return theFileName[i];
}

PMString MPOLnchHelper::GetTextFCFile(int i){
	
	PMString theFileName[1] = {
		"changeFooter_v01.xml"};
	
	
	
	if (i > 1) {
		i = 1; 
	}
	return theFileName[i];
}

PMString MPOLnchHelper::GetMetaFile(int i){
	
	PMString theFileName[3] = {
		"glue code.jsx",
		"processXML_v02.jsx",
		"setupStyles.jsx"};
	
	
	
	if (i > 3) {
		i = 3; 
	}
	return theFileName[i];
}

PMString MPOLnchHelper::GetMiscFile(int i){
	
	PMString theFileName[5] = {
		"change100k.jsx",
		"changeFooterText.jsx",
		"createOutlineSchwarz.jsx",
		"removeGroupLabel.jsx",
		"specsCleanerFindChange.jsx"};
	
	
	
	if (i > 3) {
		i = 3; 
	}
	return theFileName[i];
}


PMString MPOLnchHelper::ReadAllAsText(IPMStream *s)
{
	PMString text;
	uchar oneChar;
	s->XferByte(oneChar);
	while (s->GetStreamState() == kStreamStateGood)
	{
		text.Append((char)oneChar);        
		
		// Read the next character
		s->XferByte(oneChar);
		
    } // end while streamstategood
	
    return text; 
}

IDFile MPOLnchHelper::GetInternalResourceFolder(){
	IDFile theSource;
	
	FileUtils::GetAppInstallationFolder(&theSource); 
	FileUtils::AppendPath(&theSource, PMString("Plug-Ins"));                
	FileUtils::AppendPath(&theSource, PMString("mpo"));                
	FileUtils::AppendPath(&theSource, PMString("MPOLauncher.InDesignPlugin"));                
	//			
	FileUtils::AppendPath(&theSource, PMString("Versions"));                
	FileUtils::AppendPath(&theSource, PMString("A"));                
	FileUtils::AppendPath(&theSource, PMString("Resources"));

	return theSource;
}

IDFile MPOLnchHelper::GetScriptFilesFolder(){

	IDFile theTarget; 
	FileUtils::GetAppInstallationFolder(&theTarget); 
	FileUtils::AppendPath(&theTarget, PMString("Scripts"));                
	FileUtils::AppendPath(&theTarget, PMString("Scripts Panel"));
	FileUtils::AppendPath(&theTarget, PMString("MPO Launcher"));
	
	FileUtils::CreateFolderIfNeeded(theTarget,kTrue);
	
	return theTarget;

}

IDFile MPOLnchHelper::GetHelpFilesFolder(){
	
	IDFile theTarget; 
	FileUtils::GetAppInstallationFolder(&theTarget); 
	FileUtils::AppendPath(&theTarget, PMString("Scripts"));                
	FileUtils::AppendPath(&theTarget, PMString("Scripts Panel"));
	FileUtils::AppendPath(&theTarget, PMString("MPO Launcher"));
	FileUtils::AppendPath(&theTarget, PMString("help"));
	
	
	FileUtils::CreateFolderIfNeeded(theTarget,kTrue);
	
	return theTarget;
	
}
void MPOLnchHelper::CopyQueryFilesToPrefsFolder(PMString fcfilename, PMString fctype){
	
	//MPOLnchHelper helper;
	PMString logStr("");
	
	IDFile theGRPSource = this->GetInternalResourceFolder();
	
	FileUtils::AppendPath(&theGRPSource, fcfilename);
	PMString grpFileStringUrl = FileUtils::SysFileToFileURL(theGRPSource);
	if(!FileUtils::DoesFileExist(theGRPSource)){
		
		CAlert::InformationAlert(" could not find the Source File. I am Here-> " + grpFileStringUrl 
								 +"\n"+
								 " Please report this bug to: info@the-moron.net");
		return;
	}
	
	// this gets the GREP folder within the Library/Preferences/Adobe InDesign/ ...
	IDFile theGRPTarget;
	FileUtils::GetAppRoamingDataFolder(&theGRPTarget, "Find-Change Queries");
	FileUtils::AppendPath(&theGRPTarget,fctype);
	FileUtils::CreateFolderIfNeeded(theGRPTarget,kTrue);
	PMString fngrp(fcfilename);
	FileUtils::AppendPath(&theGRPTarget, fngrp);
	
	if(!FileUtils::DoesFileExist(theGRPTarget)){
				
		//CAlert::InformationAlert("I will try to copy "+fngrp+ " to your Preferences");
		
		if(!FileUtils::CopyFile(theGRPSource, theGRPTarget)){
			CAlert::InformationAlert("Could not copy "+fngrp+". Sorry");
		}
	}
}


void MPOLnchHelper::CopyFilesToLauncherFolder(PMString filename , PMString foldername, bool16 subfolder){
	
	//MPOLnchHelper helper;
	
	IDFile source = this->GetInternalResourceFolder();
	
	FileUtils::AppendPath(&source, filename);
	PMString fileStringUrl = FileUtils::SysFileToFileURL(source);
	if(!FileUtils::DoesFileExist(source)){
		CAlert::InformationAlert(" could not find the Source File. I am Here-> " + fileStringUrl 
								 +"\n"+
								 " Please report this bug to: info@the-moron.net");
		return;
	}
	
	IDFile target = this->GetScriptFilesFolder();
	if (subfolder) {
		
		FileUtils::AppendPath(&target, foldername);
		FileUtils::CreateFolderIfNeeded(target,kTrue);
		
	}
	
	PMString fn(filename);
	
	FileUtils::AppendPath(&target, fn);
	
	if(!FileUtils::DoesFileExist(target)){
		if (subfolder) {
			//CAlert::InformationAlert("I will try to copy "+fn
								//	 + " to the folder: Scripts Panel/MPO Launcher/"
								//	 +foldername);
		}else{
			//CAlert::InformationAlert("I will try to copy "+fn
			//						 + " to the folder: Scripts Panel/MPO Launcher");
		}
		if(!FileUtils::CopyFile(source, target)){
			CAlert::InformationAlert("Could not copy "+fn
									 +". Sorry");
		}
	}
	
}

void MPOLnchHelper::ShowScripts(){
	// look for the internal resource files
	IDFile helpFile  = this->GetScriptFilesFolder();
	

	if (FileUtils::DoesFileExist(helpFile)) {
		
		
		FileUtils::ShowFile(helpFile);
		
		
	}else {
		CAlert::InformationAlert(this->MissingHelpFileStr(helpFile.GetFileName()));
	}
	
}

void MPOLnchHelper::ShowFC(){
	// look for the internal resource files
	
	// this gets the GREP folder within the Library/Preferences/Adobe InDesign/ ...
	IDFile target;
	FileUtils::GetAppRoamingDataFolder(&target, "Find-Change Queries");
	
	if (FileUtils::DoesFileExist(target)) {
		
		
		FileUtils::ShowFile(target);
		
		
	}else {
		CAlert::InformationAlert(this->MissingHelpFileStr(target.GetFileName()));
	}
	
}
void MPOLnchHelper::ShowHelp(){
	// look for the internal resource files
	IDFile helpFile  = this->GetHelpFilesFolder();

	
	//PMString pre("help_");
	PMString fn("help");
	PMString exth(".txt");
	
	FileUtils::AppendPath(&helpFile, fn + exth);
	
	
	
	if (FileUtils::DoesFileExist(helpFile)) {
		InterfacePtr<IPMStream> s(StreamUtil::CreateFileStreamRead(helpFile));
		
		
		//CAlert::InformationAlert(helper.ReadAllAsText(s));
		CAlert::ModalAlert(this->ReadAllAsText(s),
						   kOKString, 
						   kNullString, 
						   kNullString, 
						   1,                        // pass in 1, 2, or 3 to make that button the default button or 0 for no default
						   CAlert::eWarningIcon);
		
		FileUtils::OpenFileInEditor(helpFile,kNullAppInfo,nil);
		
		
	}else {
		CAlert::InformationAlert(this->MissingHelpFileStr(fn + exth));
	}
	
	}

void MPOLnchHelper::RestoreFCQueries(){

	for (int i = 0; i < this->FCGREPMAXITEMS ; i++) {
		
		this->CopyQueryFilesToPrefsFolder(this->GetGrepFCFile(i), PMString("GREP"));
		
	} // end of for FCGREPMAXITEMS
	
	for (int j = 0; j < this->FCTEXTMAXITEMS ; j++) {
		
		this->CopyQueryFilesToPrefsFolder(this->GetTextFCFile(j), PMString("Text"));
		
		
	} // end of for FCTEXTMAXITEMS	
	
	for (int k = 0; k < this->FCOBJECTMAXITEMS ; k++) {
		
		this->CopyQueryFilesToPrefsFolder(this->GetObjectFCFile(k), PMString("Object"));
		
		
	} // end of for FCGREPMAXITEMS
	CAlert::InformationAlert("Copied the missing files");

}

void MPOLnchHelper::RestoreMPOLnchScrpts(){
	
	this->CopyFilesToLauncherFolder(PMString("help.txt") , "help",kTrue);

	for (int i = 0; i < this->MAXITEMS ; i++) {
		
		// The Scriptfiles
		this->CopyFilesToLauncherFolder(this->GetScriptFile(i) , "NOFOLDER",kFalse);
		// the helper files
		this->CopyFilesToLauncherFolder(this->GetHelpFile(i) , "help",kTrue);
		
	}// end for MAXITEMS
	
	
	//THE META FILES
	//
	
	for(int j = 0; j < this->METAMAXITEMS; j++){
		
		this->CopyFilesToLauncherFolder(this->GetMetaFile(j) , "meta",kTrue);
		
	}	

	//THE MISC FILES
	//
	
	for(int k = 0; k < this->MISCMAXITEMS; k++){
		
		this->CopyFilesToLauncherFolder(this->GetMiscFile(k) , "misc",kTrue);
		
	}
	CAlert::InformationAlert("Copied the missing files");

}
