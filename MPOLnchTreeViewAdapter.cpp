//========================================================================================
//  
//  $File: //depot/indesign_6.0/highprofile/source/sdksamples/wlistboxcomposite/WLBCmpTreeViewAdapter.cpp $
//  
//  Owner: Danielle Darling
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

#include "IStringListData.h"
#include "ListTreeViewAdapter.h"
#include "WLBCmpNodeID.h"
#include "WLBCmpID.h"

/**
 *  TreeViewAdapter.
	@ingroup wlistboxcomposite
 */
class WLBCmpTreeViewAdapter : public ListTreeViewAdapter
{
public:
	WLBCmpTreeViewAdapter(IPMUnknown* boss);
	
	virtual ~WLBCmpTreeViewAdapter()
	{}
	
	virtual int32	GetNumListItems() const;
	NodeID_rv GetRootNode() const;
	virtual NodeID_rv	GetNthListItem(const int32& nth) const;

};

CREATE_PMINTERFACE(WLBCmpTreeViewAdapter, kWLBCmpTVHierarchyAdapterImpl)

WLBCmpTreeViewAdapter::WLBCmpTreeViewAdapter(IPMUnknown* boss):ListTreeViewAdapter(boss)
{
	//initialize the list with the default list string name
	K2Vector<PMString> lists;
	for (int32 i = 0; i< 12; i++)
	{
		PMString name(kWLBCmpItemBaseKey);
		name.AppendNumber(i+1);
		name.Translate();
		lists.push_back(name);
	}
	InterfacePtr<IStringListData> iListData(this, IID_ISTRINGLISTDATA);
	iListData->SetStringList(lists);

}
int32 WLBCmpTreeViewAdapter::GetNumListItems()const
{	
	InterfacePtr<IStringListData> iListData(this, IID_ISTRINGLISTDATA);

	return iListData->GetStringList().size();
}

NodeID_rv WLBCmpTreeViewAdapter::GetRootNode() const
{
	PMString rootString("Root");
	rootString.Translate();
	return WLBCmpNodeID::Create(rootString);
}

NodeID_rv WLBCmpTreeViewAdapter::GetNthListItem(const int32& nth) const
{
	InterfacePtr<IStringListData> iListData(this, IID_ISTRINGLISTDATA);

	return WLBCmpNodeID::Create(iListData->GetStringList()[nth]);	
}
