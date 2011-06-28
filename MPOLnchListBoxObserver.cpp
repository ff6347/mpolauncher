//========================================================================================
//  
//  $File: //depot/indesign_6.0/highprofile/source/sdksamples/wlistboxcomposite/WLBCmpListBoxObserver.cpp $
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
#include "IControlView.h"
#include "ITreeViewController.h"

// Implem includes
#include "CAlert.h"
#include "CObserver.h"
#include "K2Vector.tpp" // For NodeIDList to compile
#include "WLBCmpNodeID.h"
#include "WLBCmpID.h"


/**

	Observes the listbox via IID_ITREEVIEWCONTROLLER.

	@ingroup wlistboxcomposite
	
*/
class WLBCmpListBoxObserver : public CObserver
{
public:
	
	/**
		Constructor for WLBListBoxObserver class.
		@param interface ptr from boss object on which this interface is aggregated.
	*/
	WLBCmpListBoxObserver(IPMUnknown *boss);

	/**
		Destructor for WLBCmpListBoxObserver class
		
	*/	
	~WLBCmpListBoxObserver();

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
		This class is interested in changes along IID_ILISTCONTROLDATA protocol with classID of
		kListSelectionChangedMessage. This message is sent when a user clicks on an element
		in the list-box.

	
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

CREATE_PMINTERFACE(WLBCmpListBoxObserver, kWLBCmpListBoxObserverImpl)


WLBCmpListBoxObserver::WLBCmpListBoxObserver(IPMUnknown* boss)
: CObserver(boss)
{
	
}


WLBCmpListBoxObserver::~WLBCmpListBoxObserver()
{
	
}


void WLBCmpListBoxObserver::AutoAttach()
{
	InterfacePtr<ISubject> subject(this, UseDefaultIID());
	if (subject != nil)
	{
		subject->AttachObserver(this, IID_ITREEVIEWCONTROLLER);
	}
}


void WLBCmpListBoxObserver::AutoDetach()
{
	InterfacePtr<ISubject> subject(this, UseDefaultIID());
	if (subject != nil)
	{
		subject->DetachObserver(this, IID_ITREEVIEWCONTROLLER);
	}
}


void WLBCmpListBoxObserver::Update
(
	const ClassID& theChange, 
	ISubject* theSubject, 
	const PMIID &protocol, 
	void* changedBy
)
{
	if ((protocol == IID_ITREEVIEWCONTROLLER) && (theChange == kListSelectionChangedMessage) ) {
		do {
			InterfacePtr<ITreeViewController> 	controller(this, UseDefaultIID());
			ASSERT(controller);
			if(!controller)
			{
				break;
			}

			NodeIDList selectedItems;
			controller->GetSelectedItems(selectedItems);
			const int kSelectionLength =  selectedItems.size() ;
			if (kSelectionLength> 0 )
			{
				PMString dbgInfoString("Selected item(s): ");
				K2Vector<NodeID>::const_iterator iter, startIter, endIter;
				startIter = selectedItems.begin();
				endIter = selectedItems.end();
				for(iter = startIter; iter != endIter; ++iter)
				{
					const WLBCmpNodeID* oneNode = static_cast<const WLBCmpNodeID*>(iter->Get());
					PMString item = oneNode->GetName();
					item.Translate();
					dbgInfoString.Append(item);
					dbgInfoString += ", ";
				}
				dbgInfoString.Truncate(2); //remove the last ', '
				dbgInfoString.SetTranslatable(kFalse);	// only for debug- not real code
				CAlert::InformationAlert(dbgInfoString);
			}

		} while(0);
	}
}


 

