//========================================================================================
//  
//  $File: //depot/indesign_6.0/highprofile/source/sdksamples/wlistboxcomposite/MPOLnchID.h $
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
//  Defines IDs used by the MPOLnch plug-in.
//  
//========================================================================================

#ifndef __MPOLnchID_h__
#define __MPOLnchID_h__

#include "SDKDef.h"

// Company:
#define kMPOLnchCompanyKey	kSDKDefPlugInCompanyKey		// Company name used internally for menu paths and the like. Must be globally unique, only A-Z, 0-9, space and "_".
#define kMPOLnchCompanyValue	kSDKDefPlugInCompanyValue	// Company name displayed externally.

// Plug-in:
#define kMPOLnchPluginName	"MPOLauncher"			// Name of this plug-in.
#define kMPOLnchPrefixNumber	0x174600 					// Unique prefix number for this plug-in(*Must* be obtained from Adobe Developer Support).
#define kMPOLnchVersion		kSDKDefPluginVersionString						// Version of this plug-in (for the About Box).
#define kMPOLnchAuthor		"fabiantheblind"				// Author of this plug-in (for the About Box).

// Plug-in Prefix: (please change kMPOLnchPrefixNumber above to modify the prefix.)
#define kMPOLnchPrefix		RezLong(kMPOLnchPrefixNumber)			// The unique numeric prefix for all object model IDs for this plug-in.
#define kMPOLnchStringPrefix	SDK_DEF_STRINGIZE(kMPOLnchPrefixNumber)	// The string equivalent of the unique prefix number for  this plug-in.

// PluginID:
DECLARE_PMID(kPlugInIDSpace, kMPOLnchPluginID, kMPOLnchPrefix + 0)

// ClassIDs:
DECLARE_PMID(kClassIDSpace, kMPOLnchActionComponentBoss,	kMPOLnchPrefix + 0)
DECLARE_PMID(kClassIDSpace, kMPOLnchStringRegisterBoss,	kMPOLnchPrefix + 1)
DECLARE_PMID(kClassIDSpace, kMPOLnchPanelRegisterBoss,	kMPOLnchPrefix + 2)
DECLARE_PMID(kClassIDSpace, kMPOLnchMenuRegisterBoss,	kMPOLnchPrefix + 3)
DECLARE_PMID(kClassIDSpace, kMPOLnchActionRegisterBoss,	kMPOLnchPrefix + 4)
DECLARE_PMID(kClassIDSpace, kMPOLnchPanelWidgetBoss,		kMPOLnchPrefix + 5)
DECLARE_PMID(kClassIDSpace, kMPOLnchListBoxWidgetBoss,	kMPOLnchPrefix + 6)
DECLARE_PMID(kClassIDSpace, kMPOLnchTextWidgetBoss,		kMPOLnchPrefix + 7)
DECLARE_PMID(kClassIDSpace, kMPOLnchEyeballWidgetBoss,	kMPOLnchPrefix + 8)
DECLARE_PMID(kClassIDSpace, kMPOLnchPenWidgetBoss,	kMPOLnchPrefix + 9)
// InterfaceIDs:
// None in this plug-in.

// ImplementationIDs:
DECLARE_PMID(kImplementationIDSpace, 	kMPOLnchActionComponentImpl,		kMPOLnchPrefix + 0)
DECLARE_PMID(kImplementationIDSpace, 	kMPOLnchListBoxObserverImpl,		kMPOLnchPrefix + 1)
DECLARE_PMID(kImplementationIDSpace,	kMPOLnchEyeballObserverImpl,		kMPOLnchPrefix + 2)
DECLARE_PMID(kImplementationIDSpace,	kMPOLnchPenObserverImpl,		kMPOLnchPrefix + 3)
DECLARE_PMID(kImplementationIDSpace,	kMPOLnchTVWidgetMgrImpl, 	kMPOLnchPrefix + 4)
DECLARE_PMID(kImplementationIDSpace,	kMPOLnchTVHierarchyAdapterImpl, 	kMPOLnchPrefix + 5)
// ActionIDs:
DECLARE_PMID(kActionIDSpace, kMPOLnchAboutActionID,				kMPOLnchPrefix + 0)
DECLARE_PMID(kActionIDSpace, kMPOLnchPanelWidgetActionID,		kMPOLnchPrefix + 1)
DECLARE_PMID(kActionIDSpace, kMPOLnchSeparator1ActionID,			kMPOLnchPrefix + 2)
DECLARE_PMID(kActionIDSpace, kMPOLnchPopupAboutThisActionID,		kMPOLnchPrefix + 3)
DECLARE_PMID(kActionIDSpace, kMPOLnchAddItemActionID,			kMPOLnchPrefix + 11)
DECLARE_PMID(kActionIDSpace, kMPOLnchRemoveItemActionID,			kMPOLnchPrefix + 12)
// WidgetIDs:
DECLARE_PMID(kWidgetIDSpace, kMPOLnchPanelWidgetID,				kMPOLnchPrefix + 0) 
DECLARE_PMID(kWidgetIDSpace, kMPOLnchTextWidgetID,				kMPOLnchPrefix + 1)
DECLARE_PMID(kWidgetIDSpace, kMPOLnchListParentWidgetId,			kMPOLnchPrefix + 2)
DECLARE_PMID(kWidgetIDSpace, kMPOLnchListBoxWidgetID,			kMPOLnchPrefix + 3)
DECLARE_PMID(kWidgetIDSpace, kMPOLnchListElementEyeballWidgetID,	kMPOLnchPrefix + 4)
DECLARE_PMID(kWidgetIDSpace, kMPOLnchListElementPenWidgetID,	kMPOLnchPrefix + 5)
// "About Plug-ins" sub-menu:
#define kMPOLnchAboutMenuKey			kMPOLnchStringPrefix "kMPOLnchAboutMenuKey"
#define kMPOLnchAboutMenuPath		kSDKDefStandardAboutMenuPath kMPOLnchCompanyKey

// "Plug-ins" sub-menu:
#define kMPOLnchPluginsMenuKey 		kMPOLnchStringPrefix "kMPOLnchPluginsMenuKey"
#define kMPOLnchPluginsMenuPath		kSDKDefPlugInsStandardMenuPath kMPOLnchCompanyKey kSDKDefDelimitMenuPath kMPOLnchPluginsMenuKey

// Menu item keys:
#define kMPOLnchAddItemMenuItemKey			kMPOLnchStringPrefix "kMPOLnchAddItemMenuItemKey"
#define kMPOLnchRemoveItemMenuItemKey		kMPOLnchStringPrefix "kMPOLnchRemoveItemMenuItemKey"

// Other StringKeys:
#define kMPOLnchAboutBoxStringKey			kMPOLnchStringPrefix "kMPOLnchAboutBoxStringKey"
#define kMPOLnchAddItemStringKey				kMPOLnchStringPrefix "kMPOLnchAddItemStringKey"
#define kMPOLnchRemoveItemStringKey			kMPOLnchStringPrefix "kMPOLnchRemoveItemStringKey"
#define kMPOLnchPanelTitleKey				kMPOLnchStringPrefix	"kMPOLnchPanelTitleKey"
#define kMPOLnchInternalPopupMenuNameKey		kMPOLnchStringPrefix	"kMPOLnchInternalPopupMenuNameKey"
#define kMPOLnchTargetMenuPath kMPOLnchInternalPopupMenuNameKey
#define kMPOLnchItemBaseKey					kMPOLnchStringPrefix "kMPOLnchItemBaseKey"
#define kMPOLnchAddedElementKey 				kMPOLnchStringPrefix"kMPOLnchAddedElementKey"



// Menu item positions:
#define kMPOLnchAddItemMenuItemPosition			1.0
#define kMPOLnchRemoveItemMenuItemPosition		2.0	
#define	kMPOLnchSeparator1MenuItemPosition		10.0
#define kMPOLnchAboutThisMenuItemPosition		11.0

// Initial data format version numbers
#define kMPOLnchFirstMajorFormatNumber  kSDKDef_30_PersistMajorVersionNumber
#define kMPOLnchFirstMinorFormatNumber  kSDKDef_30_PersistMinorVersionNumber

// Data format version numbers for the PluginVersion resource 
#define kMPOLnchCurrentMajorFormatNumber kMPOLnchFirstMajorFormatNumber // most recent major format change
#define kMPOLnchCurrentMinorFormatNumber kMPOLnchFirstMinorFormatNumber // most recent minor format change

#endif // __MPOLnchID_h__

// End, MPOLnchID.h.


