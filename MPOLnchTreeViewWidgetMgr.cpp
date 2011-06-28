//========================================================================================
//  
//  $File: //depot/indesign_6.0/highprofile/source/sdksamples/wlistboxcomposite/WLBCmpTreeViewWidgetMgr.cpp $
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
#include "WLBCmpNodeID.h"
#include "WLBCmpID.h"
#include "WLBCmpRezDefs.h"


/**
 *  Tree view manager
	@ingroup wlistboxcomposite
 */
class WLBCmpTVWidgetMgr : public CTreeViewWidgetMgr
{
public:
	WLBCmpTVWidgetMgr(IPMUnknown *boss);
	virtual ~WLBCmpTVWidgetMgr()
	{}
    
    virtual bool16	ApplyDataToWidget( const NodeID& node, IPanelControlData* widgetList, int32 message ) const;

    void RegisterStyles()
    {
        RegisterStyleWidget(kLargePaletteRowsTreeStyle, kWLBCmpListElementRsrcID, kWLBCmpPluginID);
    }
};


CREATE_PMINTERFACE(WLBCmpTVWidgetMgr, kWLBCmpTVWidgetMgrImpl)

WLBCmpTVWidgetMgr::WLBCmpTVWidgetMgr(IPMUnknown *boss) :
CTreeViewWidgetMgr(boss, kList)
{
}



bool16 WLBCmpTVWidgetMgr::ApplyDataToWidget(const NodeID& node, 
                                            IPanelControlData* widgetList, 
                                            int32 message) const
{
	do
	{
		TreeNodePtr<WLBCmpNodeID> nodeID(node);
		PMString listName = nodeID->GetName();
	      
		IControlView* nameView = widgetList->FindWidget(kWLBCmpTextWidgetID);
	        
		InterfacePtr<ITextControlData>	textControlData( nameView, UseDefaultIID() );
		ASSERT(textControlData);
		if( textControlData== nil) {
			break;
		}
		textControlData->SetString(listName);
	} while (false);

	return kTrue;
}

