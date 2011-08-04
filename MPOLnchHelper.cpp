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
MPOLnchHelper::MPOLnchHelper();
//{
//}

// Helpfile function

int MPOLnchHelper::MAXITEMS = 12;

int MPOLnchHelper::METAMAXITEMS = 1;

PMString MPOLnchHelper::GetScriptFile(int i){
	
	PMString theFileName[12] = {
		"theNumbers.jsx",
		"clearStructure.jsx",
		"color_KEY.jsx",
		"color_PAPER.jsx",
		"color_XXX.jsx",
		"theFindChange.jsx",
		"newscriptfile07.jsx",
		"newscriptfile08.jsx",
		"newscriptfile09.jsx",
		"newscriptfile10.jsx",
		"newscriptfile11.jsx",
		"QUICKY.jsx"};
	

	if (i > 12) {
		i = 12; 
	}
	return theFileName[i];
}

PMString MPOLnchHelper::GetHelpFile(int i){
	
	PMString theFileName[12] = {
		"theNumbers.txt",
		"clearStructure.txt",
		"color_KEY.txt",
		"color_PAPER.txt",
		"color_XXX.txt",
		"theFindChange.txt",
		"newscriptfile07.txt",
		"newscriptfile08.txt",
		"newscriptfile09.txt",
		"newscriptfile10.txt",
		"newscriptfile11.txt",
		"QUICKY.txt"};
	
	
	
	if (i > 12) {
		i = 12; 
	}
	return theFileName[i];
}

PMString MPOLnchHelper::GetMetaFile(int i){
	
	PMString theFileName[1] = {
		"glue code.jsx"};
	
	
	
	if (i > 1) {
		i = 1; 
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
	FileUtils::AppendPath(&theSource, PMString("tmn"));                
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


