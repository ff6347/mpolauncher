//========================================================================================
//  
//  $File: //depot/indesign_6.0/highprofile/source/sdksamples/wlistboxcomposite/MPOLnchPenObserver.cpp $
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
// Implem includes
#include "CAlert.h"
#include "CObserver.h"
#include "MPOLnchID.h"



// Interface includes
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

#include "IScriptRunner.h"
#include "IScriptUtils.h"

// file handling
#include "FileUtils.h"
#include "StreamUtil.h"
#include "IPMStream.h"

#include <iostream>
#include <fstream>
#include <string>

/**

	Observes the "pen" buttons in the widget list.

	@ingroup wlistboxcomposite
	
*/
class MPOLnchPenObserver : public CObserver
{
public:
	
	/**
		Constructor for WLBListBoxObserver class.
		@param interface ptr from boss object on which this interface is aggregated.
	*/
	MPOLnchPenObserver(IPMUnknown *boss);

	/**
		Destructor.
	*/	
	~MPOLnchPenObserver();

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
		Update when there's been a change on the pen widget.
	
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

CREATE_PMINTERFACE(MPOLnchPenObserver, kMPOLnchPenObserverImpl)


MPOLnchPenObserver::MPOLnchPenObserver(IPMUnknown* boss)
: CObserver(boss)
{
	
}


MPOLnchPenObserver::~MPOLnchPenObserver()
{
	
}


void MPOLnchPenObserver::AutoAttach()
{
	InterfacePtr<ISubject> subject(this, UseDefaultIID());
	if (subject != nil)
	{
		subject->AttachObserver(this, IID_ITRISTATECONTROLDATA);
	}
	
}


void MPOLnchPenObserver::AutoDetach()
{
		InterfacePtr<ISubject> subject(this, UseDefaultIID());
	if (subject != nil)
	{
		subject->DetachObserver(this,IID_ITRISTATECONTROLDATA);
	}
}


void MPOLnchPenObserver::Update
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
			
			// now look for the parent of the widget
			InterfacePtr<IWidgetParent>	widgetParent(this, IID_IWIDGETPARENT);
			if(widgetParent == nil){ 
				
				CAlert::InformationAlert("widgetParent is nil");
				
				break;
			}
			//found it
			// Query the parent for the panel
			InterfacePtr<IPanelControlData>	panelData((IPanelControlData*)widgetParent->QueryParentFor(IID_IPANELCONTROLDATA));
			if(panelData == nil) {
				
				CAlert::InformationAlert("panelData is nil");
				
				break;
				
			}
			// found it
			
			// look for the TextWidget that holds the name
			IControlView* nameView = panelData->FindWidget(kMPOLnchTextWidgetID);
			InterfacePtr<ITextControlData>	textControlData( nameView, UseDefaultIID() );
			
			if( (textControlData== nil)) {
				break;
				CAlert::InformationAlert("textControlData is nil");
				
			}
			// Thats great. found it
			// get the name of the node. The associated PMString
			
			PMString nodeName(textControlData->GetString());
			
			// Show it only for debug
			//nodeName.SetTranslatable(kFalse);	// only for debug- not real code
			//CAlert::InformationAlert(nodeName);
			
					
			
			
			
			IDFile helpFile;
			FileUtils::GetAppInstallationFolder(&helpFile);                    //application folder path
			FileUtils::AppendPath(&helpFile, PMString("Scripts"));                
			FileUtils::AppendPath(&helpFile, PMString("Scripts Panel"));
			FileUtils::AppendPath(&helpFile, PMString("MPO Launcher"));
			FileUtils::AppendPath(&helpFile, PMString("help"));

			PMString pre("help_");
			PMString fn(nodeName);
			PMString exth(".jsx");
			
			FileUtils::AppendPath(&helpFile, pre + fn + exth);
			
						
			
			if (FileUtils::DoesFileExist(helpFile)) {
				
				
				
				
				// for debug
				//FileUtils::OpenFile(scriptFile);
				InterfacePtr<IScriptRunner>scriptRunner(Utils<IScriptUtils>()->QueryScriptRunner(helpFile));	
				bool filestatus=scriptRunner->CanHandleFile(helpFile);
				
				RunScriptParams scriptParams(scriptRunner);
				scriptParams.SetShowErrorAlert(kTrue);
				scriptParams.SetInvokeDebugger(kFalse);
				
				
				
				if(filestatus==1)
				{
					scriptRunner->RunFile(helpFile,scriptParams);
				}// close filestatus
			}else {
				CAlert::InformationAlert("Got an error. You need the MPO Launcher Folder in the Scripts Panel");
			}
			
			
			
			
				//PMString dbgInfoString("MPOLnchPenObserver::Update() ");
//				dbgInfoString.SetTranslatable(kFalse);	// only for debug- not real code
//				CAlert::InformationAlert(dbgInfoString);
		
		} while(0);
	}
}




