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
#include <fstream>
#include <cstdlib>
#include <string>


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
	/*
	InterfacePtr<IControlView> treeWidget(static_cast<IControlView*>(Utils<IWidgetUtils>()->QueryRelatedWidget(invokedWidget, kMPOLnchListBoxWidgetID, IID_ICONTROLVIEW)));
	InterfacePtr<ITreeViewMgr> treeMgr(treeWidget, UseDefaultIID());
	InterfacePtr<IStringListData> iListData(treeWidget, IID_ISTRINGLISTDATA);
	K2Vector<PMString> lists = iListData->GetStringList();
	PMString item(kMPOLnchAddedElementKey);
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
        NodeID node = MPOLnchNodeID::Create(item);
		
		//create a file in script the directory
		IDFile file; 
		FileUtils::GetAppInstallationFolder(&file); 
		FileUtils::AppendPath(&file, PMString("Scripts"));                
		FileUtils::AppendPath(&file, PMString("Scripts Panel"));
		PMString fn("newscriptfile");
		PMString ext(".jsx");
		
		FileUtils::AppendPath(&file, fn  + ext); 
		FileUtils::OpenFile(file, "wt"); 
		
		treeMgr->NodeAdded(node);
	}
	 */
	
	// building the scripts
	

	
	using namespace std;
	
		const int MAXITEMS = 12;
		
		PMString scriptfiles[MAXITEMS] = {
			"scriptfile01.jsx",
			"scriptfile02.jsx",
			"scriptfile03.jsx",
			"scriptfile04.jsx",
			"scriptfile05.jsx",
			"scriptfile06.jsx",
			"scriptfile07.jsx",
			"scriptfile08.jsx",
			"scriptfile09.jsx",
			"scriptfile10.jsx",
			"scriptfile11.jsx",
			"scriptfile12.jsx"};
		
		PMString newscriptfiles[MAXITEMS] = {
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
		
		//string source = "incoming.txt";
		//string clone = "outgoing.txt";
		
		//	cout << "Enter the source file: ";
		//	cin >> source;
		//	cout << "Enter the name of the new file: ";
		//	cin >> clone;
		
		for (int i = 0; i < MAXITEMS ; i++) {
			

			IDFile theSource;//scriptfiles[i];
			
			FileUtils::GetAppInstallationFolder(&theSource); 
			FileUtils::AppendPath(&theSource, PMString("Plug-Ins"));                
			FileUtils::AppendPath(&theSource, PMString("tmn"));                
			FileUtils::AppendPath(&theSource, PMString("MPOLauncher.InDesignPlugin"));                
//			
			FileUtils::AppendPath(&theSource, PMString("Versions"));                
			FileUtils::AppendPath(&theSource, PMString("A"));                
			FileUtils::AppendPath(&theSource, PMString("Resources"));                
			FileUtils::AppendPath(&theSource, PMString(scriptfiles[i]));
			
			PMString sourceFileStringUrl = FileUtils::SysFileToFileURL(theSource);

			if(!FileUtils::DoesFileExist(theSource)){
				CAlert::InformationAlert(" could not find the Source File. I am Here-> " + sourceFileStringUrl 
										 +"\n"+
										 " Please report this bug to: fabiantheblind@the-moron.net");
				break;
			}
			

				
			
			IDFile theTarget; 
			FileUtils::GetAppInstallationFolder(&theTarget); 
			FileUtils::AppendPath(&theTarget, PMString("Scripts"));                
			FileUtils::AppendPath(&theTarget, PMString("Scripts Panel"));
			FileUtils::AppendPath(&theTarget, PMString("MPO Launcher"));

			FileUtils::CreateFolderIfNeeded(theTarget,kTrue);

			PMString fn(newscriptfiles[i]);
			
			FileUtils::AppendPath(&theTarget, fn);

			//FileUtils::OpenFile(theTarget, "w");
			if(!FileUtils::DoesFileExist(theTarget)){
				
				CAlert::InformationAlert("I will try to copy "+fn+ " to the folder: Scripts Panel/MPO Launcher");
					
				if(!FileUtils::CopyFile(theSource, theTarget)){
			
					CAlert::InformationAlert("Could not copy "+fn+". Sorry");

			
				}
			}
			
		//	PMString sourceFileStringUrl = FileUtils::SysFileToFileURL(theSource);
//			string sfurl = sourceFileStringUrl.GrabCString();
//
//			PMString targetFileStringUrl = FileUtils::SysFileToFileURL(theTarget);
//			string tfurl = targetFileStringUrl.GrabCString();
//			
//			    std::ifstream src; // the source file
//			    std::ofstream dest; // the destination file
//			
//				src.open (sfurl.c_str(), std::ios::binary); // open in binary to prevent jargon at the end of the buffer
//			    dest.open (tfurl.c_str(), std::ios::binary); // same again, binary
//			    if (src.is_open() && dest.is_open())
//				{
//			    dest << src.rdbuf (); // copy the content
//			    dest.close (); // close destination file
//			    src.close (); // close source file
				}
			
	//		if(!copyFile(sfurl.c_str(),tfurl.c_str())){
//				
//				CAlert::InformationAlert("Could not copy the scriptfiles. Sorry");
//
//			}
			
			//FileUtils::CopyFile(theSource, theTarget);
			//FileUtils::OpenFile(file, "wt");

			//PMString sourcefile = FileUtils::SysFileToFileURL(theSource);
//			PMString targetfile = FileUtils::SysFileToFileURL(theTarget);
//			ifstream in(sourcefile.GetPlatformString().c_str()); // Open for reading
//			ofstream out( targetfile.GetPlatformString().c_str()); // Open for writing
//			
//			//printf("wrote file newscriptfile with number %do to disc\n",i);
//			string s;
//			while(getline(in, s))
//			out << s << "\n";
			//in->Close();
			//out->Close();
			
			//}
		
		
	
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


