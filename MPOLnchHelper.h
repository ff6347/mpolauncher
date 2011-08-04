/*
 *  MPOLnchHelpfiles.h
 *  MPOLauncher
 *
 *  Created by fabiantheblind on 01.08.11.
 *  Copyright 2011 tmn. All rights reserved.
 *
 */

#ifndef MPOLNCHHELPER_H
#define MPOLNCHHELPER_H

#include "IPMStream.h"
#include "FileUtils.h"


class MPOLnchHelper
{
public:

	
    MPOLnchHelper() { }; //  default constructor
	
	PMString ReadAllAsText(IPMStream *s);

	PMString GetScriptFile(int i);
	PMString GetHelpFile(int i);
	PMString GetMetaFile(int i);

	IDFile GetInternalResourceFolder();
	
	IDFile GetScriptFilesFolder();
	
	
	static int MAXITEMS;
	static int METAMAXITEMS;
	
};

#endif