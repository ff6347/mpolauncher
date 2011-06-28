//========================================================================================
//  
//  $File: //depot/indesign_6.0/highprofile/source/sdksamples/wlistboxcomposite/WLBCmpID.h $
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
//  
//  Defines IDs used by the WLBCmp plug-in.
//  
//========================================================================================

#ifndef __WLBCmpID_h__
#define __WLBCmpID_h__

#include "SDKDef.h"

// Company:
#define kWLBCmpCompanyKey	kSDKDefPlugInCompanyKey		// Company name used internally for menu paths and the like. Must be globally unique, only A-Z, 0-9, space and "_".
#define kWLBCmpCompanyValue	kSDKDefPlugInCompanyValue	// Company name displayed externally.

// Plug-in:
#define kWLBCmpPluginName	"MPOLauncher"			// Name of this plug-in.
#define kWLBCmpPrefixNumber	0x174600 					// Unique prefix number for this plug-in(*Must* be obtained from Adobe Developer Support).
#define kWLBCmpVersion		kSDKDefPluginVersionString						// Version of this plug-in (for the About Box).
#define kWLBCmpAuthor		"fabiantheblind"				// Author of this plug-in (for the About Box).

// Plug-in Prefix: (please change kWLBCmpPrefixNumber above to modify the prefix.)
#define kWLBCmpPrefix		RezLong(kWLBCmpPrefixNumber)			// The unique numeric prefix for all object model IDs for this plug-in.
#define kWLBCmpStringPrefix	SDK_DEF_STRINGIZE(kWLBCmpPrefixNumber)	// The string equivalent of the unique prefix number for  this plug-in.

// PluginID:
DECLARE_PMID(kPlugInIDSpace, kWLBCmpPluginID, kWLBCmpPrefix + 0)

// ClassIDs:
DECLARE_PMID(kClassIDSpace, kWLBCmpActionComponentBoss,	kWLBCmpPrefix + 0)
DECLARE_PMID(kClassIDSpace, kWLBCmpStringRegisterBoss,	kWLBCmpPrefix + 1)
DECLARE_PMID(kClassIDSpace, kWLBCmpPanelRegisterBoss,	kWLBCmpPrefix + 2)
DECLARE_PMID(kClassIDSpace, kWLBCmpMenuRegisterBoss,	kWLBCmpPrefix + 3)
DECLARE_PMID(kClassIDSpace, kWLBCmpActionRegisterBoss,	kWLBCmpPrefix + 4)
DECLARE_PMID(kClassIDSpace, kWLBCmpPanelWidgetBoss,		kWLBCmpPrefix + 5)
DECLARE_PMID(kClassIDSpace, kWLBCmpListBoxWidgetBoss,	kWLBCmpPrefix + 6)
DECLARE_PMID(kClassIDSpace, kWLBCmpTextWidgetBoss,		kWLBCmpPrefix + 7)
DECLARE_PMID(kClassIDSpace, kWLBCmpEyeballWidgetBoss,	kWLBCmpPrefix + 8)
DECLARE_PMID(kClassIDSpace, kWLBCmpPenWidgetBoss,	kWLBCmpPrefix + 9)
// InterfaceIDs:
// None in this plug-in.

// ImplementationIDs:
DECLARE_PMID(kImplementationIDSpace, 	kWLBCmpActionComponentImpl,		kWLBCmpPrefix + 0)
DECLARE_PMID(kImplementationIDSpace, 	kWLBCmpListBoxObserverImpl,		kWLBCmpPrefix + 1)
DECLARE_PMID(kImplementationIDSpace,	kWLBCmpEyeballObserverImpl,		kWLBCmpPrefix + 2)
DECLARE_PMID(kImplementationIDSpace,	kWLBCmpPenObserverImpl,		kWLBCmpPrefix + 3)
DECLARE_PMID(kImplementationIDSpace,	kWLBCmpTVWidgetMgrImpl, 	kWLBCmpPrefix + 4)
DECLARE_PMID(kImplementationIDSpace,	kWLBCmpTVHierarchyAdapterImpl, 	kWLBCmpPrefix + 5)
// ActionIDs:
DECLARE_PMID(kActionIDSpace, kWLBCmpAboutActionID,				kWLBCmpPrefix + 0)
DECLARE_PMID(kActionIDSpace, kWLBCmpPanelWidgetActionID,		kWLBCmpPrefix + 1)
DECLARE_PMID(kActionIDSpace, kWLBCmpSeparator1ActionID,			kWLBCmpPrefix + 2)
DECLARE_PMID(kActionIDSpace, kWLBCmpPopupAboutThisActionID,		kWLBCmpPrefix + 3)
DECLARE_PMID(kActionIDSpace, kWLBCmpAddItemActionID,			kWLBCmpPrefix + 11)
DECLARE_PMID(kActionIDSpace, kWLBCmpRemoveItemActionID,			kWLBCmpPrefix + 12)
// WidgetIDs:
DECLARE_PMID(kWidgetIDSpace, kWLBCmpPanelWidgetID,				kWLBCmpPrefix + 0) 
DECLARE_PMID(kWidgetIDSpace, kWLBCmpTextWidgetID,				kWLBCmpPrefix + 1)
DECLARE_PMID(kWidgetIDSpace, kWLBCmpListParentWidgetId,			kWLBCmpPrefix + 2)
DECLARE_PMID(kWidgetIDSpace, kWLBCmpListBoxWidgetID,			kWLBCmpPrefix + 3)
DECLARE_PMID(kWidgetIDSpace, kWLBCmpListElementEyeballWidgetID,	kWLBCmpPrefix + 4)
DECLARE_PMID(kWidgetIDSpace, kWLBCmpListElementPenWidgetID,	kWLBCmpPrefix + 5)
// "About Plug-ins" sub-menu:
#define kWLBCmpAboutMenuKey			kWLBCmpStringPrefix "kWLBCmpAboutMenuKey"
#define kWLBCmpAboutMenuPath		kSDKDefStandardAboutMenuPath kWLBCmpCompanyKey

// "Plug-ins" sub-menu:
#define kWLBCmpPluginsMenuKey 		kWLBCmpStringPrefix "kWLBCmpPluginsMenuKey"
#define kWLBCmpPluginsMenuPath		kSDKDefPlugInsStandardMenuPath kWLBCmpCompanyKey kSDKDefDelimitMenuPath kWLBCmpPluginsMenuKey

// Menu item keys:
#define kWLBCmpAddItemMenuItemKey			kWLBCmpStringPrefix "kWLBCmpAddItemMenuItemKey"
#define kWLBCmpRemoveItemMenuItemKey		kWLBCmpStringPrefix "kWLBCmpRemoveItemMenuItemKey"

// Other StringKeys:
#define kWLBCmpAboutBoxStringKey			kWLBCmpStringPrefix "kWLBCmpAboutBoxStringKey"
#define kWLBCmpAddItemStringKey				kWLBCmpStringPrefix "kWLBCmpAddItemStringKey"
#define kWLBCmpRemoveItemStringKey			kWLBCmpStringPrefix "kWLBCmpRemoveItemStringKey"
#define kWLBCmpPanelTitleKey				kWLBCmpStringPrefix	"kWLBCmpPanelTitleKey"
#define kWLBCmpInternalPopupMenuNameKey		kWLBCmpStringPrefix	"kWLBCmpInternalPopupMenuNameKey"
#define kWLBCmpTargetMenuPath kWLBCmpInternalPopupMenuNameKey
#define kWLBCmpItemBaseKey					kWLBCmpStringPrefix "kWLBCmpItemBaseKey"
#define kWLBCmpAddedElementKey 				kWLBCmpStringPrefix"kWLBCmpAddedElementKey"



// Menu item positions:
#define kWLBCmpAddItemMenuItemPosition			1.0
#define kWLBCmpRemoveItemMenuItemPosition		2.0	
#define	kWLBCmpSeparator1MenuItemPosition		10.0
#define kWLBCmpAboutThisMenuItemPosition		11.0

// Initial data format version numbers
#define kWLBCmpFirstMajorFormatNumber  kSDKDef_30_PersistMajorVersionNumber
#define kWLBCmpFirstMinorFormatNumber  kSDKDef_30_PersistMinorVersionNumber

// Data format version numbers for the PluginVersion resource 
#define kWLBCmpCurrentMajorFormatNumber kWLBCmpFirstMajorFormatNumber // most recent major format change
#define kWLBCmpCurrentMinorFormatNumber kWLBCmpFirstMinorFormatNumber // most recent minor format change

#endif // __WLBCmpID_h__

// End, WLBCmpID.h.


