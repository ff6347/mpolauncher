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

PMString MPOLnchHelper::GetScriptFile(int i){
	
	PMString theFileName[12] = {
		"newscriptfile01.jsx",
		"newscriptfile02.jsx",
		"newscriptfile03.jsx",
		"newscriptfile04.jsx",
		"newscriptfile05.jsx",
		"newscriptfile06.jsx",
		"newscriptfile07.jsx",
		"newscriptfile08.jsx",
		"newscriptfile09.jsx",
		"newscriptfile10.jsx",
		"newscriptfile11.jsx",
		"newscriptfile12.jsx"};
	

	if (i > 12) {
		i = 12; 
	}
	return theFileName[i];
}

PMString MPOLnchHelper::GetHelpFile(int i){
	
	PMString theFileName[12] = {
		"help_newscriptfile01.jsx",
		"help_newscriptfile02.jsx",
		"help_newscriptfile03.jsx",
		"help_newscriptfile04.jsx",
		"help_newscriptfile05.jsx",
		"help_newscriptfile06.jsx",
		"help_newscriptfile07.jsx",
		"help_newscriptfile08.jsx",
		"help_newscriptfile09.jsx",
		"help_newscriptfile10.jsx",
		"help_newscriptfile11.jsx",
		"help_newscriptfile12.jsx"};
	
	
	
	if (i > 12) {
		i = 12; 
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
