//========================================================================================
//  
//  $File: //depot/indesign_6.0/highprofile/source/sdksamples/wlistboxcomposite/MPOLnchEyeballObserver.cpp $
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

// Implementation includes
#include "widgetid.h"

// Interface includes
#include "ISubject.h"
#include "ITriStateControlData.h"
#include "IControlView.h"
#include "ITreeViewController.h"
#include "IWidgetParent.h"
#include "IPanelControlData.h"
#include "ITextControlData.h"



// Implem includes
#include "CAlert.h"
#include "CObserver.h"
#include "MPOLnchID.h"

// Implem includes
#include "K2Vector.tpp" // For NodeIDList to compile
#include "MPOLnchNodeID.h"

// Scripting includes
#include "FileUtils.h"
#include "IScriptRunner.h"
#include "IScriptUtils.h"
/**
	Observes the "eyeball" widget.
	
	@ingroup wlistboxcomposite
	
*/
class MPOLnchEyeballObserver : public CObserver
{
public:
	
	/**
		Constructor for WLBListBoxObserver class.
		@param interface ptr from boss object on which this interface is aggregated.
	*/
	MPOLnchEyeballObserver(IPMUnknown *boss);

	/**
		Destructor for MPOLnchEyeballObserver class - 
		performs cleanup 
	*/	
	~MPOLnchEyeballObserver();

	/**
		AutoAttach is only called for registered observers
		of widgets.  This method is called by the application
		core when the widget is shown.
	
	*/	
	virtual void AutoAttach();

	/**
		AutoDetach is only called for registered observers
		of widgets. Called when widget hidden.
	*/	
	virtual void AutoDetach();

	/**
		Update when there's been a change on the eyeball widget.
	
		@param theChange this is specified by the agent of change; it can be the class ID of the agent,
		or it may be some specialised message ID.
		@param theSubject this provides a reference to the object which has changed; in this case, the button
		widget boss object that is being observed.
		@param protocol the protocol along which the change occurred.
		@param changedBy this can be used to provide additional information about the change or a reference
		to the boss object that caused the change.
	*/	
	virtual void Update(const ClassID& theChange, ISubject* theSubject, const PMIID &protocol, void* changedBy);

	
};

CREATE_PMINTERFACE(MPOLnchEyeballObserver, kMPOLnchEyeballObserverImpl)


MPOLnchEyeballObserver::MPOLnchEyeballObserver(IPMUnknown* boss)
: CObserver(boss)
{
	
}


MPOLnchEyeballObserver::~MPOLnchEyeballObserver()
{
	
}


void MPOLnchEyeballObserver::AutoAttach()
{
	InterfacePtr<ISubject> subject(this, UseDefaultIID());
	if (subject != nil)
	{
		subject->AttachObserver(this, IID_ITRISTATECONTROLDATA);
	}
	
}


void MPOLnchEyeballObserver::AutoDetach()
{
	InterfacePtr<ISubject> subject(this, UseDefaultIID());
	if (subject != nil)
	{
		subject->DetachObserver(this,IID_ITRISTATECONTROLDATA);
	}
}


void MPOLnchEyeballObserver::Update
(
	const ClassID& theChange, 
	ISubject* theSubject, 
	const PMIID &protocol, 
	void* changedBy
)
{
	if(theChange == kTrueStateMessage) {
		// Then the button has been activated.
		do {
			InterfacePtr<ITriStateControlData> data(this, IID_ITRISTATECONTROLDATA);

			InterfacePtr<IWidgetParent>	widgetParent(this, IID_IWIDGETPARENT);
			if(widgetParent == nil){ 
				
				CAlert::InformationAlert("widgetParent is nil");

				break;
			}

			InterfacePtr<IPanelControlData>	panelData((IPanelControlData*)widgetParent->QueryParentFor(IID_IPANELCONTROLDATA));
			if(panelData == nil) {
				
				CAlert::InformationAlert("panelData is nil");

				break;
			
			}
			
			IControlView* nameView = panelData->FindWidget(kMPOLnchTextWidgetID);
			InterfacePtr<ITextControlData>	textControlData( nameView, UseDefaultIID() );
			
			if( (textControlData== nil)) {
				break;
				CAlert::InformationAlert("textControlData is nil");

			}
			PMString myText(textControlData->GetString());
			
			CAlert::InformationAlert(myText);

		//	InterfacePtr<IControlView> myTextWidget(panelData->FindWidget(kMPOLnchTextWidgetID), UseDefaultIID());
//			if(myTextWidget == nil){ 
//			
//				CAlert::InformationAlert("myTextWidget is nil");
//				
//				
//				break;
//			
//			}
//			PMString myText = myTextWidget->getString();
//			
//			CAlert::InformationAlert(myText);
			
//			InterfacePtr<ITreeViewController>  myController(widgetParent->GetParent(), IID_ITREEVIEWCONTROLLER);
			
			//ASSERT(myController);
	//		if(!myController)
//			{
//				CAlert::InformationAlert("myController is nil");
//				break;
//			
//			}
//			
//			NodeIDList selectedItems;
//			myController->GetSelectedItems(selectedItems);
//			const int kSelectionLength =  selectedItems.size() ;
//			CAlert::InformationAlert(PMString("length "+kSelectionLength));
				
				PMString dbgInfoString("MPOLnchEyeballObserver::Update() ");
				dbgInfoString.SetTranslatable(kFalse);	// only for debug- not real code
				CAlert::InformationAlert(dbgInfoString);
			
			
		} while(0);
	}
	
	
//	if ((protocol == IID_ITREEVIEWCONTROLLER) && (theChange == kListSelectionChangedMessage) ) {
//		do {
//			
//			//	CAlert::InformationAlert("You pressed the something");
//			
//			InterfacePtr<ITreeViewController> 	controller(this, UseDefaultIID());
//			ASSERT(controller);
//			if(!controller)
//			{
//				break;
//			}
//			
//			NodeIDList selectedItems;
//			controller->GetSelectedItems(selectedItems);
//			const int kSelectionLength =  selectedItems.size() ;
//			if (kSelectionLength> 0 )
//			{
//				PMString nodeName("");
//				K2Vector<NodeID>::const_iterator iter, startIter, endIter;
//				startIter = selectedItems.begin();
//				endIter = selectedItems.end();
//				for(iter = startIter; iter != endIter; ++iter)
//				{
//					const MPOLnchNodeID* oneNode = static_cast<const MPOLnchNodeID*>(iter->Get());
//					PMString item = oneNode->GetName();
//					item.Translate();
//					nodeName.Append(item);
//					//dbgInfoString += ", ";
//				}
//				
//				
//				//dbgInfoString.Truncate(2); //remove the last ', '
//				nodeName.SetTranslatable(kFalse);	// only for debug- not real code
//				CAlert::InformationAlert(nodeName);
//				
//				IDFile scriptFile;
//				
//				FileUtils::GetAppInstallationFolder(&scriptFile);                    //application folder path
//				FileUtils::AppendPath(&scriptFile, PMString("Scripts"));                
//				FileUtils::AppendPath(&scriptFile, PMString("Scripts Panel"));
//				FileUtils::AppendPath(&scriptFile, PMString("MPO Launcher"));
//				if (FileUtils::DoesFileExist(scriptFile)) {
//					
//					PMString fn(nodeName);
//					PMString ext(".jsx");
//					
//					
//					FileUtils::AppendPath(&scriptFile, fn + ext);
//					
//					InterfacePtr<IScriptRunner>scriptRunner(Utils<IScriptUtils>()->QueryScriptRunner(scriptFile));	
//					bool filestatus=scriptRunner->CanHandleFile(scriptFile);
//					
//					RunScriptParams scriptParams(scriptRunner);
//					scriptParams.SetShowErrorAlert(kTrue);
//					scriptParams.SetInvokeDebugger(kFalse);
//					
//					
//					
//					if(filestatus==1)
//					{
//						scriptRunner->RunFile(scriptFile,scriptParams);
//					}// close filestatus
//				}else {
//					CAlert::InformationAlert("Got an error. You need the MPO Launcher Folder in the Scripts Panel");
//				}
//				
//				
//			}
//			
//		} while(0);
//	}
	
}




