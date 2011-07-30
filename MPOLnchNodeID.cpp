//========================================================================================
//  
//  $File: //depot/indesign_6.0/highprofile/source/sdksamples/wlistboxcomposite/MPOLnchNodeID.cpp $
//  
//  Owner: Adobe Developer Technologies
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2008/08/19 04:03:07 $
//  
//  $Revision: #1 $
//  
//  $Change: 643572 $
//  
//  Copyright 1997-2008 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

#include "VCPlugInHeaders.h"

// Interface includes:
#include "IPMStream.h"

// Project includes:
#include "MPOLnchNodeID.h"
/**
	@ingroup mpolauncher
*/

/* Compare
*/
int32 MPOLnchNodeID::Compare(const NodeIDClass* nodeID) const
{
	const MPOLnchNodeID* oneNode = static_cast<const MPOLnchNodeID*>(nodeID);
	ASSERT(nodeID);
    return fName.Compare(kTrue, oneNode->GetName());

}


/* Clone
*/
NodeIDClass* MPOLnchNodeID::Clone() const
{
	return new MPOLnchNodeID(this->GetName());
}


/* Read
*/
void MPOLnchNodeID::Read(IPMStream* stream)
{
	fName.ReadWrite(stream);
}


/* Write
*/
void MPOLnchNodeID::Write(IPMStream* stream) const
{
	(const_cast<MPOLnchNodeID*>(this)->fName).ReadWrite(stream);
}



//	end, File:	PnlTrvDataNode.cpp
