//========================================================================================
//  
//  $File: //depot/indesign_6.0/highprofile/source/sdksamples/wlistboxcomposite/WLBCmpActionComponent.cpp $
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
#include "IWidgetUtils.h"
#include "IPanelControlData.h"
#include "IControlView.h"
#include "IActionStateList.h"
#include "ITreeViewController.h"
#include "ITreeViewMgr.h"
#include "ITreeViewHierarchyAdapter.h"
#include "IStringListData.h"

// General includes:
#include "CActionComponent.h"
#include "CAlert.h"
#include "WLBCmpNodeID.h"

#include "K2Vector.tpp" // For NodeIDList to compile

// Project includes:
#include "WLBCmpID.h"


/** WLBCmpActionComponent
	All about the user actions

	@ingroup wlistboxcomposite
	
*/
class WLBCmpActionComponent : public CActionComponent
{
	public:
		/**
			Constructor.
			@param boss interface ptr from boss object on which this interface is aggregated.
		*/
		WLBCmpActionComponent(IPMUnknown* boss);

		/**
			The action component should do the requested action.
			This is where the menu item's action is taken.
			When a menu item is selected, the Menu Manager determines
			which plug-in is responsible for it, and calls its DoAction
			with the ID for the menu item chosen.

			@param actionID identifies the menu item that was selected.
			*/
		virtual void DoAction(IActiveContext *myContext, ActionID actionID, GSysPoint mousePoint, IPMUnknown *widget);
		/**

			Framework will call this method to ask us to update the states of the items.
		*/
		virtual void	UpdateActionStates(IActiveContext *myContext, IActionStateList *listToUpdate, GSysPoint mousePoint, IPMUnknown *widget);

	private:
		/** Encapsulates functionality for the about menu item. */
		void DoAbout();

		/** Encapsulates functionality for the AddItem menu item. 
			
			@param invokedWidget Widget that initiated the event (the panel menu), useful for getting the panel & other widgets.
		*/
		void DoAddItem(IPMUnknown *invokedWidget);

		/** Encapsulates functionality for the RemoveItem menu item. 
		
			@param invokedWidget Widget that initiated the event. (The panel menu.)
		*/
		void DoRemoveItem(IPMUnknown *invokedWidget);

};

/* CREATE_PMINTERFACE
 Binds the C++ implementation class onto its
 ImplementationID making the C++ code callable by the
 application.
*/
CREATE_PMINTERFACE(WLBCmpActionComponent, kWLBCmpActionComponentImpl)

/* WLBCmpActionComponent Constructor
*/
WLBCmpActionComponent::WLBCmpActionComponent(IPMUnknown* boss)
: CActionComponent(boss)
{
}

/* DoAction
*/
void WLBCmpActionComponent::DoAction(IActiveContext *myContext, ActionID actionID, GSysPoint mousePoint, IPMUnknown *widget)
{
	switch (actionID.Get())
	{
		case kWLBCmpPopupAboutThisActionID:
		case kWLBCmpAboutActionID:
		{
			this->DoAbout();
			break;
		}

		case kWLBCmpAddItemActionID:
		{
			this->DoAddItem(widget);
			break;
		}

		case kWLBCmpRemoveItemActionID:
		{
			this->DoRemoveItem(widget);
			break;
		}

		default:
		{
			break;
		}
	}
}


/* UpdateActionStates

*/

void WLBCmpActionComponent::UpdateActionStates(IActiveContext *myContext, IActionStateList *listToUpdate, GSysPoint mousePoint, IPMUnknown *widget)
{
	do {

		int listElementCount = 0;
		InterfacePtr<IControlView> treeWidget(static_cast<IControlView*>(Utils<IWidgetUtils>()->QueryRelatedWidget(widget, kWLBCmpListBoxWidgetID, IID_ICONTROLVIEW)));
		ASSERT(treeWidget);
		if(!treeWidget) {
			break;
		}

		InterfacePtr<ITreeViewController> 	controller(treeWidget, UseDefaultIID());
		ASSERT(controller);
		if(!controller)
		{
			break;
		}

		NodeIDList selectedItems;
		controller->GetSelectedItems(selectedItems);
		listElementCount = selectedItems.size();

		for(int i=0; i < listToUpdate->Length(); i++) {

			ActionID action = listToUpdate->GetNthAction(i);
			switch (action.Get())
			{

				case kWLBCmpRemoveItemActionID:
					if(listElementCount>0) {
						listToUpdate->SetNthActionState(i,kEnabledAction);
					}
					else {
						listToUpdate->SetNthActionState(i,kDisabled_Unselected);
					}
					break;
			}
		}

	} while(0);


}



/* DoAbout
*/
void WLBCmpActionComponent::DoAbout()
{
	CAlert::ModalAlert
	(
	   kWLBCmpAboutBoxStringKey,			// Alert string
	   kOKString, 							// OK button
	   kNullString, 						// No second button
	   kNullString, 						// No third button
	   1,									// Set OK button to default
	   CAlert::eInformationIcon				// Information icon.
	);
}

/* DoAddItem
*/
void WLBCmpActionComponent::DoAddItem(IPMUnknown *invokedWidget)
{
	InterfacePtr<IControlView> treeWidget(static_cast<IControlView*>(Utils<IWidgetUtils>()->QueryRelatedWidget(invokedWidget, kWLBCmpListBoxWidgetID, IID_ICONTROLVIEW)));
	InterfacePtr<ITreeViewMgr> treeMgr(treeWidget, UseDefaultIID());
	InterfacePtr<IStringListData> iListData(treeWidget, IID_ISTRINGLISTDATA);
	K2Vector<PMString> lists = iListData->GetStringList();
	PMString item(kWLBCmpAddedElementKey);
	item.Translate();
    K2Vector<PMString>::const_iterator iter = std::find(lists.begin(), lists.end(), item);
	int32 addIndex = 2;
	while (iter != lists.end())
	{
		item.Insert("+ ", 2, 2);
		iter = std::find(lists.begin(), lists.end(), item);
	}

    if (iter == lists.end())
	{
		lists.insert(lists.begin(), item);
		iListData->SetStringList(lists);
		//make sure that the node added has been processed
        NodeID node = WLBCmpNodeID::Create(item);
		treeMgr->NodeAdded(node);
	}
}

/* DoRemoveItem
*/
void WLBCmpActionComponent::DoRemoveItem(IPMUnknown *invokedWidget)
{
	InterfacePtr<IControlView> treeWidget(static_cast<IControlView*>(Utils<IWidgetUtils>()->QueryRelatedWidget(invokedWidget, kWLBCmpListBoxWidgetID, IID_ICONTROLVIEW)));
	InterfacePtr<ITreeViewMgr> treeMgr(treeWidget, UseDefaultIID());

	InterfacePtr<ITreeViewController> 	controller(treeWidget, UseDefaultIID());


	NodeIDList selectedItems;
	controller->GetSelectedItems(selectedItems);
	int32 listElementCount = selectedItems.size();
    if (selectedItems.size() > 0)
    {
		//Notify node to be deleted
        treeMgr->BeforeNodesDeleted(selectedItems);

        // delete items
        K2Vector<NodeID>::const_iterator iter, startIter, endIter;
        startIter = selectedItems.begin();
        endIter = selectedItems.end();
 		InterfacePtr<IStringListData> iListData(treeWidget, IID_ISTRINGLISTDATA);
		K2Vector<PMString> lists = iListData->GetStringList();
        for(iter = startIter; iter != endIter; ++iter)
        {
			const WLBCmpNodeID* oneNode = static_cast<const WLBCmpNodeID*>(iter->Get());
			PMString item = oneNode->GetName();

			K2Vector<PMString>::iterator s_iter = std::find(lists.begin(), lists.end(), item);
			if (s_iter != lists.end())
				lists.erase(s_iter);
        }
		iListData->SetStringList(lists);
	}
 	
}


// End, WLBCmpActionComponent.cpp.


