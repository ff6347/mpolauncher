// basic find change.
// relies heavyliy on find change queries
// Copyright (C) 2011 Fabian "fabiantheblind" Morón Zirfas
// http://www.the-moron.net
// info [at] the - moron . net

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/.
main();
//--------------

function main() {
	
	var doc;

		try {
		var doc = app.activeDocument;

		} catch(e){
		alert("No no no, you have no document.\nMaybe you should drink some coffee");
		return;
		}	
	
	var myDate = new Date();
	var logfilebool = true;
	try{
	var myLogFile = myGetFileName();
	var myFileContent = myLogFile.read();
	var myErrorLog = myFileContent +"\n"+"Starting Log file at "+myDate +"\n";
	}catch(e){
		
		var myFileContent = "";
		var myErrorLog = myFileContent +"\n"+"Starting Log file at "+myDate +"\n";
		logfilebool = false;
		
	}

try {
	app.loadFindChangeQuery ('JM__ZOLL_HIN', SearchModes.grepSearch); 
myErrorLog = myErrorLog +  doc.findGrep().toString() +"\n";
app.activeDocument.changeGrep(); 

} catch (e) {

	myErrorLog = myErrorLog + e.toString() + " JM__ZOLL_HIN.xml could not be processed  \n";
	
	
}

try {
	app.loadFindChangeQuery ('JM__ANAB_01', SearchModes.grepSearch); 
myErrorLog = myErrorLog +  doc.findGrep().toString() +"\n";
app.activeDocument.changeGrep(); 

} catch (e) {

	myErrorLog = myErrorLog + e.toString() + " JM__ANAB_01.xml could not be processed  \n";
	
	
}


try {
	 
app.loadFindChangeQuery ('JM__ANAB_02', SearchModes.grepSearch); 
myErrorLog = myErrorLog +  doc.findGrep().toString() +"\n";
app.activeDocument.changeGrep(); 

} catch (e) {
	
		myErrorLog = myErrorLog + e.toString() + " JM__ANAB_02.xml could not be processed  \n";

	
}

try {
	app.loadFindChangeQuery ('JM__ZOLL_ZURUECK', SearchModes.grepSearch); 
myErrorLog = myErrorLog +  doc.findGrep().toString() +"\n";
app.activeDocument.changeGrep(); 

} catch (e) {

	myErrorLog = myErrorLog + e.toString() + " JM__ZOLL_ZURUECK.xml could not be processed  \n";
	
	
}


try {
	app.loadFindChangeQuery ('JM__EURO_hin', SearchModes.grepSearch); 
myErrorLog = myErrorLog +  doc.findGrep().toString() +"\n";
app.activeDocument.changeGrep(); 

} catch (e) {

	myErrorLog = myErrorLog + e.toString() + " JM__EURO_hin.xml could not be processed  \n";
	
	
}








try {
	app.loadFindChangeQuery ('JM__APOSTROPH', SearchModes.grepSearch); 
myErrorLog = myErrorLog +  doc.findGrep().toString() +"\n";
app.activeDocument.changeGrep();


} catch (e) {
		myErrorLog = myErrorLog + e.toString() + " JM__APOSTROPH.xml could not be processed  \n";

	
}

try {
	
app.loadFindChangeQuery ('JM__LEERZEICHEN_DOPPELTE', SearchModes.grepSearch); 
myErrorLog = myErrorLog +  doc.findGrep().toString() +"\n";
app.activeDocument.changeGrep();

} catch (e) {
		myErrorLog = myErrorLog + e.toString() + " JM__LEERZEICHEN_DOPPELTE.xml could not be processed  \n";

	
}

try {
	
app.loadFindChangeQuery ('JM__PUNKTBLANK', SearchModes.grepSearch); 
myErrorLog = myErrorLog +  doc.findGrep().toString() +"\n";
app.activeDocument.changeGrep();

} catch (e) {
		myErrorLog = myErrorLog + e.toString() + " JM__PUNKTBLANK.xml could not be processed  \n";

	
}

try {
	
app.loadFindChangeQuery ('JM__KOMMABLANK', SearchModes.grepSearch); 
myErrorLog = myErrorLog +  doc.findGrep().toString() +"\n";
app.activeDocument.changeGrep();

} catch (e) {
		myErrorLog = myErrorLog + e.toString() + " JM__KOMMABLANK.xml could not be processed  \n";

	
}



try {
	app.loadFindChangeQuery ('JM__MALZEICHEN', SearchModes.grepSearch); 
myErrorLog = myErrorLog +  doc.findGrep().toString() +"\n";
app.activeDocument.changeGrep();

} catch (e) {
		myErrorLog = myErrorLog + e.toString() + " JM__MALZEICHEN.xml could not be processed  \n";

	
}

try {
	
app.loadFindChangeQuery ('JM__EURO_zurueck', SearchModes.grepSearch); 

myErrorLog = myErrorLog +  doc.findGrep().toString() +"\n";
app.activeDocument.changeGrep();


} catch (e) {
		myErrorLog = myErrorLog + e.toString() + " JM__EURO_zurueck.xml could not be processed  \n";

	
}

try {
	
app.loadFindChangeQuery ('JM__PREISSTRICH', SearchModes.grepSearch); 

myErrorLog = myErrorLog +  doc.findGrep().toString() +"\n";
app.activeDocument.changeGrep();


} catch (e) {
		myErrorLog = myErrorLog + e.toString() + " JM__PREISSTRICH.xml could not be processed  \n";

	
}

try {
	

app.loadFindChangeQuery ('JM__ZOLLZEICHEN', SearchModes.grepSearch); 
myErrorLog = myErrorLog +  doc.findGrep().toString() +"\n";
app.activeDocument.changeGrep();
} catch (e) {
		myErrorLog = myErrorLog + e.toString() + " JM__ZOLLZEICHEN.xml could not be processed  \n";
		

	
}

try {
	

app.loadFindChangeQuery ('JM__INTERPUNKTION', SearchModes.grepSearch); 
myErrorLog = myErrorLog +  doc.findGrep().toString() +"\n";
app.activeDocument.changeGrep();
} catch (e) {
		myErrorLog = myErrorLog + e.toString() + " JM__INTERPUNKTION.xml could not be processed  \n";
		

	
}



		if(!logfilebool){
		var myFile = myLogFile;   
		var myData = myErrorLog;
		writeData (myFile, myData );
		}
		
		alert("Done");
}


function myGetFileName()  
{   

	var myFolder = app.activeDocument.filePath;

      var myFile =  new File( myFolder+'/findChangeLog.txt' )  
//      if ( myFile == null ){exit()};  
   return myFile;   
} 

function writeData (myFile , aData )  
{ 
	var myResult;
   if( myFile!='' )  
   {   
      //Open the file for writing.   
      myResult = myFile.open( 'e', undefined, undefined );   
   }  
   if( myResult != false )  
   {     
	   myFile.seek(0);
      myFile.writeln( aData );         
      myFile.close();   
//      myFile.execute();  
   }
}

