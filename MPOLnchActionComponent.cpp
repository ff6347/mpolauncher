//========================================================================================
//  
//  $File: //depot/indesign_6.0/highprofile/source/sdksamples/wlistboxcomposite/MPOLnchActionComponent.cpp $
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
#include "MPOLnchNodeID.h"

#include "K2Vector.tpp" // For NodeIDList to compile

// Project includes:
#include "MPOLnchID.h"
// file creation
#include "FileUtils.h"
#include "CoreFileUtils.h"
#include "StreamUtil.h"

#include "MPOLnchHelper.h"


/** MPOLnchActionComponent
	All about the user actions

	@ingroup wlistboxcomposite
	
*/
class MPOLnchActionComponent : public CActionComponent
{
	public:
		/**
			Constructor.
			@param boss interface ptr from boss object on which this interface is aggregated.
		*/
		MPOLnchActionComponent(IPMUnknown* boss);

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
	
	
		/* My personal copyFile
		 * until i get FileUtils::CopyFile() to work
		 */
	//	bool copyFile (const char SRC[], const char DEST[]);


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
CREATE_PMINTERFACE(MPOLnchActionComponent, kMPOLnchActionComponentImpl)

/* MPOLnchActionComponent Constructor
*/
MPOLnchActionComponent::MPOLnchActionComponent(IPMUnknown* boss)
: CActionComponent(boss)
{
}

/* DoAction
*/
void MPOLnchActionComponent::DoAction(IActiveContext *myContext, ActionID actionID, GSysPoint mousePoint, IPMUnknown *widget)
{
	switch (actionID.Get())
	{
		case kMPOLnchPopupAboutThisActionID:
		case kMPOLnchAboutActionID:
		{
			this->DoAbout();
			break;
		}

		case kMPOLnchAddItemActionID:
		{
			this->DoAddItem(widget);
			break;
		}

		case kMPOLnchRemoveItemActionID:
		{
			//this->DoRemoveItem(widget);
			CAlert::InformationAlert("This optin doesn't work right now. Sry");

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

void MPOLnchActionComponent::UpdateActionStates(IActiveContext *myContext, IActionStateList *listToUpdate, GSysPoint mousePoint, IPMUnknown *widget)
{
	do {

		int listElementCount = 0;
		InterfacePtr<IControlView> treeWidget(static_cast<IControlView*>(Utils<IWidgetUtils>()->QueryRelatedWidget(widget, kMPOLnchListBoxWidgetID, IID_ICONTROLVIEW)));
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

				case kMPOLnchRemoveItemActionID:
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
void MPOLnchActionComponent::DoAbout()
{
	

	CAlert::ModalAlert
	(
	   kMPOLnchAboutBoxStringKey,			// Alert string
	   kOKString, 							// OK button
	   kNullString, 						// No second button
	   kNullString, 						// No third button
	   1,									// Set OK button to default
	   CAlert::eInformationIcon				// Information icon.
	);
}

/* DoAddItem
*/
void MPOLnchActionComponent::DoAddItem(IPMUnknown *invokedWidget)
{
	// building the scripts
	
	MPOLnchHelper helper;
	
		
		for (int i = 0; i < helper.MAXITEMS ; i++) {
			

			IDFile theSource = helper.GetInternalResourceFolder();//scriptfiles[i];
			


			IDFile theHelpSource = helper.GetInternalResourceFolder();//scriptfiles[i];
			
			
			FileUtils::AppendPath(&theSource, PMString(helper.GetScriptFile(i)));
			FileUtils::AppendPath(&theHelpSource, PMString(helper.GetHelpFile(i)));
			
			PMString sourceFileStringUrl = FileUtils::SysFileToFileURL(theSource);
			PMString sourceHelpFileStringUrl = FileUtils::SysFileToFileURL(theHelpSource);

			if(!FileUtils::DoesFileExist(theSource)){
				CAlert::InformationAlert(" could not find the Source File. I am Here-> " + sourceFileStringUrl 
										 +"\n"+
										 " Please report this bug to: fabiantheblind@the-moron.net");
				break;
			}
			
			if(!FileUtils::DoesFileExist(theHelpSource)){
				CAlert::InformationAlert(" could not find the Help File. I am Here-> " + sourceHelpFileStringUrl 
										 +"\n"+
										 " Please report this bug to: fabiantheblind@the-moron.net");
				break;
			}
				
			// this gets the MPO Launcher folder within the scripts panel
			IDFile theTarget = helper.GetScriptFilesFolder();
			
			//FileUtils::GetAppInstallationFolder(&theTarget); 
//			FileUtils::AppendPath(&theTarget, PMString("Scripts"));                
//			FileUtils::AppendPath(&theTarget, PMString("Scripts Panel"));
//			FileUtils::AppendPath(&theTarget, PMString("MPO Launcher"));
			
			//FileUtils::CreateFolderIfNeeded(theTarget,kTrue);

			IDFile theHelpTarget = helper.GetScriptFilesFolder(); 
			//FileUtils::GetAppInstallationFolder(&theHelpTarget); 
//			FileUtils::AppendPath(&theHelpTarget, PMString("Scripts"));                
//			FileUtils::AppendPath(&theHelpTarget, PMString("Scripts Panel"));
//			FileUtils::AppendPath(&theHelpTarget, PMString("MPO Launcher"));
			
			FileUtils::AppendPath(&theHelpTarget, PMString("help"));
			
			FileUtils::CreateFolderIfNeeded(theHelpTarget,kTrue);

			PMString fn(helper.GetScriptFile(i));
			PMString fnh(helper.GetHelpFile(i));
			
			
			FileUtils::AppendPath(&theTarget, fn);
			
			FileUtils::AppendPath(&theHelpTarget, fnh);

			
			if(!FileUtils::DoesFileExist(theTarget)){
				CAlert::InformationAlert("I will try to copy "+fn+ " to the folder: Scripts Panel/MPO Launcher");
					if(!FileUtils::CopyFile(theSource, theTarget)){
						CAlert::InformationAlert("Could not copy "+fn+". Sorry");
					}
			}
			
			if(!FileUtils::DoesFileExist(theHelpTarget)){
				CAlert::InformationAlert("I will try to copy "+fnh+ " to the folder: Scripts Panel/MPO Launcher/help");
					if(!FileUtils::CopyFile(theHelpSource, theHelpTarget)){
						CAlert::InformationAlert("Could not copy "+fnh+". Sorry");
					}
				}			
			}

		
	for(int j = 0; j < helper.METAMAXITEMS; j++){
	
		IDFile theMetaSource = helper.GetInternalResourceFolder();//scriptfiles[i];
		
	
		
		FileUtils::AppendPath(&theMetaSource, PMString(helper.GetMetaFile(j)));
		
		PMString metaSourceFileStringUrl = FileUtils::SysFileToFileURL(theMetaSource);
		
		if(!FileUtils::DoesFileExist(theMetaSource)){
			CAlert::InformationAlert(" could not find the Source File. I am Here-> " + metaSourceFileStringUrl 
									 +"\n"+
									 " Please report this bug to: info@the-moron.net");
			break;
		}
		
	
		
		// this gets the MPO Launcher folder within the scripts panel
		IDFile theMetaTarget = helper.GetScriptFilesFolder();
		
	
		FileUtils::AppendPath(&theMetaTarget, PMString("meta"));
		
		FileUtils::CreateFolderIfNeeded(theMetaTarget,kTrue);
		
		PMString fnm(helper.GetMetaFile(j));
		
		
		FileUtils::AppendPath(&theMetaTarget, fnm);
		
		
		
		if(!FileUtils::DoesFileExist(theMetaTarget)){
			CAlert::InformationAlert("I will try to copy "+fnm+ " to the folder: Scripts Panel/MPO Launcher/meta");
			if(!FileUtils::CopyFile(theMetaSource, theMetaTarget)){
				CAlert::InformationAlert("Could not copy "+fnm+". Sorry");
			}
		}
		
	}		
	
}


/* DoRemoveItem
*/
void MPOLnchActionComponent::DoRemoveItem(IPMUnknown *invokedWidget)
{
	InterfacePtr<IControlView> treeWidget(static_cast<IControlView*>(Utils<IWidgetUtils>()->QueryRelatedWidget(invokedWidget, kMPOLnchListBoxWidgetID, IID_ICONTROLVIEW)));
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
			const MPOLnchNodeID* oneNode = static_cast<const MPOLnchNodeID*>(iter->Get());
			PMString item = oneNode->GetName();

			K2Vector<PMString>::iterator s_iter = std::find(lists.begin(), lists.end(), item);
			if (s_iter != lists.end())
				lists.erase(s_iter);
        }
		iListData->SetStringList(lists);
	}
 	
}


// End, MPOLnchActionComponent.cpp.


