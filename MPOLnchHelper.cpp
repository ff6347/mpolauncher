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
int MPOLnchHelper::FCGREPMAXITEMS = 68;
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
	
	PMString theFileName[68] = {
		
		"JM_NEU_SAVE_0_d_blank_zoll.xml",
		"JM_NEU_SAVE_0a_Anfuehrungen_I_hin.xml",
		"JM_NEU_SAVE_0b_Anfuehrungen_II_hin.xml",
		"JM_NEU_SAVE_0c_ABFUEHRUNGEN.xml",
		"JM_NEU_SAVE_0d_AN_AB_ersetzen.xml",
		"JM_NEU_SAVE_0e_ABFUEHRUNGEN.xml",
		"JM_NEU_SAVE_0f_AN_AB_ersetzen.xml",
		"JM_NEU_SAVE_0g_AN_AB_ersetzen.xml",
		"JM_NEU_SAVE_0h_Anab_in_Anab.xml",
		"JM_NEU_SAVE_1e_Zoll.xml",
		"JM_NEU_SAVE_2_aufzaehlungen.xml",
		"JM_NEU_SAVE_2b_ellipse.xml",
		"JM_NEU_SAVE_3a_blank_ellipse.xml",
		"JM_NEU_SAVE_3b_ellipse_blank.xml",
		"JM_NEU_SAVE_4a_blank_mm.xml",
		"JM_NEU_SAVE_4b_blank_cm.xml",
		"JM_NEU_SAVE_4d_blank_interpunktion.xml",
		"JM_NEU_SAVE_4e_komma_blank.xml",
		"JM_NEU_SAVE_4f_punkt_blank.xml",
		"JM_NEU_SAVE_4g_blank_ausrufezeichen.xml",
		"JM_NEU_SAVE_4h_blank_doppelpunkt.xml",
		"JM_NEU_SAVE_4i_blank_semikolon.xml",
		"JM_NEU_SAVE_4j_klammern_blank.xml",
		"JM_NEU_SAVE_4k_klammern_punct.xml",
		"JM_NEU_SAVE_4l_klammern_umbruch.xml",
		"JM_NEU_SAVE_4m_slash_blanks.xml",
		"JM_NEU_SAVE_5a_zoll_blank.xml",
		"JM_NEU_SAVE_5b_malzeichen_I_nach_zoll.xml",
		"JM_NEU_SAVE_5c_malzeichen_breite_hoehe_tiefe.xml",
		"JM_NEU_SAVE_5c1_malzeichen_breite_hoehe_tiefe_in_zahlen.xml",
		"JM_NEU_SAVE_5d_malzeichen_dxddzoll.xml",
		"JM_NEU_SAVE_5e_malzeichen_sdx.xml",
		"JM_NEU_SAVE_5f_malzeichen_sdx.xml",
		"JM_NEU_SAVE_6_Gedankenstrich.xml",
		"JM_NEU_SAVE_7_kHz.xml",
		"JM_NEU_SAVE_8a_X_teilig.xml",
		"JM_NEU_SAVE_8b_X_fach.xml",
		"JM_NEU_SAVE_9a_z_B.xml",
		"JM_NEU_SAVE_9b_aaO.xml",
		"JM_NEU_SAVE_9c_dh.xml",
		"JM_NEU_SAVE_9d_mE.xml",
		"JM_NEU_SAVE_9e_oae.xml",
		"JM_NEU_SAVE_9f_so.xml",
		"JM_NEU_SAVE_9g_su.xml",
		"JM_NEU_SAVE_9h_ua.xml",
		"JM_NEU_SAVE_9i_uU.xml",
		"JM_NEU_SAVE_9j_va.xml",
		"JM_NEU_SAVE_9k_zH.xml",
		"JM_NEU_SAVE_9l_zT.xml",
		"JM_NEU_SAVE_10a_seitenzahl.xml",
		"JM_NEU_SAVE_10b_seitenzahl_1_24stel.xml",
		"JM_NEU_SAVE_13_Apostroph.xml",
		"JM_NEU_SAVE_14c_Preisstrich.xml",
		"JM_NEU_SAVE_15a_Plugin.xml",
		"JM_NEU_SAVE_15b_Midi.xml",
		"JM_NEU_SAVE_15c_specs.xml",
		"JM_NEU_SAVE_15d_Features.xml",
		"JM_NEU_SAVE_16_Bisstrich_Ziffern.xml",
		"JM_NEU_SAVE_17a_Beschreibung_Marke.xml",
		"JM_NEU_SAVE_17a1_Beschreibung_Marke.xml",
		"JM_NEU_SAVE_17b_aufzaehlung_ranziehen.xml",
		"JM_NEU_SAVE_17c_textflussende_ranziehen.xml",
		"JM_NEU_SAVE_18_doubleblanks.xml",
		"JM_NEU_SAVE_19a_Euro_hin.xml",
		"JM_NEU_SAVE_19b_Euro_zurueck.xml",
		"JM_NEU_SAVE_20a_gfL.xml",
		"JM_NEU_SAVE_20b_gfL.xml",
		"JM_FUSS_FIXER.xml"};
	
	
	
	if (i > 68) {
		i = 68; 
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

/* GetWidgetOnPanel
 */
IControlView* MPOLnchHelper::GetWidgetOnPanel(
											const WidgetID& panelWidgetID, const WidgetID& widgetID)
{
	IControlView* controlView=nil;
	do
	{
		InterfacePtr<IPanelControlData> 
		panelData(Utils<IPalettePanelUtils>()->QueryPanelByWidgetID(panelWidgetID));	
		// Don't assert, fail silently, the tree view panel may be closed.
		if(panelData == nil)
		{
			break;
		}
		controlView = panelData->FindWidget(widgetID);
		ASSERT(controlView);
		if(controlView == nil)
		{
			break;
		}
	} while(0);
	
	return controlView;
}

