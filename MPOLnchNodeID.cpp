//========================================================================================
//  
//  $File: //depot/indesign_6.0/highprofile/source/sdksamples/wlistboxcomposite/WLBCmpNodeID.cpp $
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
#include "WLBCmpNodeID.h"
/**
	@ingroup wlistboxcomposite
*/

/* Compare
*/
int32 WLBCmpNodeID::Compare(const NodeIDClass* nodeID) const
{
	const WLBCmpNodeID* oneNode = static_cast<const WLBCmpNodeID*>(nodeID);
	ASSERT(nodeID);
    return fName.Compare(kTrue, oneNode->GetName());

}


/* Clone
*/
NodeIDClass* WLBCmpNodeID::Clone() const
{
	return new WLBCmpNodeID(this->GetName());
}


/* Read
*/
void WLBCmpNodeID::Read(IPMStream* stream)
{
	fName.ReadWrite(stream);
}


/* Write
*/
void WLBCmpNodeID::Write(IPMStream* stream) const
{
	(const_cast<WLBCmpNodeID*>(this)->fName).ReadWrite(stream);
}

//	end, File:	PnlTrvDataNode.cpp
