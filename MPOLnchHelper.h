/*
 *  MPOLnchHelpfiles.h
 *  MPOLauncher
 *
 *  Created by fabiantheblind on 01.08.11.
 *  Copyright 2011 tmn. All rights reserved.
 *
 */

#ifndef MPOLNCHHELPER_H
#define MPOLNCHHELPER_H

#include "IPMStream.h"
#include "FileUtils.h"
#include "CAlert.h"
#include "StreamUtil.h"
#include "ITreeViewController.h"
#include "IPanelControlData.h"
#include "Utils.h"
#include "IPalettePanelUtils.h"


class MPOLnchHelper
{
public:

	
    MPOLnchHelper();//  default constructor
	
	static int MAXITEMS;
	static int METAMAXITEMS;
	static int FCGREPMAXITEMS;
	static int FCOBJECTMAXITEMS;
	static int FCTEXTMAXITEMS;
	static int MISCMAXITEMS;


	void RestoreFCQueries(); // copy the FCQueries to the Preferences
	void ShowHelp(); // copy the FCQueries to the Preferences
	void ShowScripts(); // Show the scripts folder
	void ShowFC(); // show the FC folder
	void RestoreMPOLnchScrpts(); // copy the scripts to the Scripts Panel
	PMString GetScriptFile(int i); // holds also the nodenames
	PMString GetNodeName(int i); // holds also the nodenames


	// these should be private
	// but for that the Scriptrunnner in 
	// EyeballObserver and PenObserver file action has to move into the MPOLnchHelper
	
	PMString ReadAllAsText(IPMStream *s);// Read a filestream to a PMString
	
	IDFile GetInternalResourceFolder(); // this is within the plugin
	IDFile GetScriptFilesFolder(); // this is in the ScriptsPanel the "MPO Launcher" folder
	IDFile GetHelpFilesFolder();
	PMString MissingScrptFileStr(PMString fn); // Error warning
	PMString MissingHelpFileStr(PMString fn); // Error warning
	
	/**	Get a widget from the specified panel by WidgetID, returning nil if it can't be found.
	 @param panelWidgetID [IN] specifies the parent widget
	 @param widgetID [IN] sought dependent widget
	 @return interface ptr to widget found or nil if it can't be found; not a reference incremented one though.
	 */
	static IControlView* GetWidgetOnPanel(
										  const WidgetID& panelWidgetID, const WidgetID& widgetID);
	
	
private:

	PMString GetHelpFile(int i); // filenames
	PMString GetMetaFile(int i); // filenames
	PMString GetTextFCFile(int i); // filenames
	PMString GetMiscFile(int i); // filenames
	PMString GetGrepFCFile(int i); // filenames
	PMString GetObjectFCFile(int i); // filenames

	void CopyQueryFilesToPrefsFolder(PMString fcfilename, PMString fctype);
	void CopyFilesToLauncherFolder(PMString filename , PMString foldername, bool16 subfolder);

	

	


};

#endif