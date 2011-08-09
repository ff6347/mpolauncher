//========================================================================================
//  
//  $File: //depot/indesign_6.0/highprofile/source/sdksamples/wlistboxcomposite/MPOLnchTreeViewWidgetMgr.cpp $
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

#include "IControlView.h"
#include "IInLineEditController.h"
#include "IPanelControlData.h"
#include "ITextControlData.h"

#include "CTreeViewWidgetMgr.h"
#include "MPOLnchNodeID.h"
#include "MPOLnchID.h"
#include "MPOLnchRezDefs.h"

//interfaces
#include "IPanelControlData.h"
#include "IPalettePanelUtils.h"
#include "IControlView.h"

// the helper class holds the data for the scripts
#include "MPOLnchHelper.h"

// these are the ID Icons
#include "IconRsrcDefs.h"

/**
 *  Tree view manager
	@ingroup mpolauncher
 */
class MPOLnchTVWidgetMgr : public CTreeViewWidgetMgr
{
public:
	MPOLnchTVWidgetMgr(IPMUnknown *boss);
	virtual ~MPOLnchTVWidgetMgr()
	{}
    
    virtual bool16	ApplyDataToWidget( const NodeID& node, IPanelControlData* widgetList, int32 message ) const;

    void RegisterStyles()
    {
        RegisterStyleWidget(kLargePaletteRowsTreeStyle, kMPOLnchListElementRsrcID, kMPOLnchPluginID);
    }
	
	//void ChangeResourceID(IPanelControlData* widgetList) const ;
//	void calcFristRsrcID()const;
	RsrcID fMPOBtnRsrcID;
	
//private:
	//void ChangeResourceID();
	
};


CREATE_PMINTERFACE(MPOLnchTVWidgetMgr, kMPOLnchTVWidgetMgrImpl)

MPOLnchTVWidgetMgr::MPOLnchTVWidgetMgr(IPMUnknown *boss) :
CTreeViewWidgetMgr(boss, kList),
fMPOBtnRsrcID(kMPOLnchMPOBtnIconRsrcID)
{
}



bool16 MPOLnchTVWidgetMgr::ApplyDataToWidget(const NodeID& node, 
                                            IPanelControlData* widgetList, 
                                            int32 message) const
{
	do
	{
		TreeNodePtr<MPOLnchNodeID> nodeID(node);
		PMString listName = nodeID->GetName();
	      
		IControlView* nameView = widgetList->FindWidget(kMPOLnchTextWidgetID);
		
	        
		InterfacePtr<ITextControlData>	textControlData( nameView, UseDefaultIID() );
		

		ASSERT(textControlData);
		
		if( (textControlData== nil)) {
			break;
		}
		MPOLnchHelper helper;
		
		textControlData->SetString(listName);
		if (listName == helper.GetScriptFile(0)) {

			IControlView* runView = widgetList->FindWidget(kMPOLnchListElementEyeballWidgetID);
		
			runView->SetRsrcID(kMPOLnchMPOBtnIconRsrcID);
			runView->Invalidate();
			InterfacePtr<IControlView> panelView(widgetList, UseDefaultIID());
			panelView->Invalidate();
		}
		
	} while (false);
	return kTrue;
}



//void MPOLnchTVWidgetMgr::ChangeResourceID()
//{
//}

