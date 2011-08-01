/*
 *  MPOLnchHelpfiles.h
 *  MPOLauncher
 *
 *  Created by fabiantheblind on 01.08.11.
 *  Copyright 2011 tmn. All rights reserved.
 *
 */

#ifndef DATE_H
#define DATE_H
#include "IPMStream.h"

class MPOLnchHelper
{
public:

	
    MPOLnchHelper() { } //  default constructor
	
	PMString ReadAllAsText(IPMStream *s);


};

#endif