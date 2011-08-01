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