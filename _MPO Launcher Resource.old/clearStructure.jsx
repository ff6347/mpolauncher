// a quick script for removing everything in the structure the safe way
// written by fabian theblind
// needs glue code for softies 
#include "./meta/glue code.jsx";
main();

// SOME TEXT
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



function main(){

	try {
	var myDoc = app.activeDocument;
	
	} catch(e){
	alert("No no no, you have no document.\nMaybe you should drink some coffee");
	return;
	}
//	the soft way?
	try{
	untagAllxmlElements(myDoc);
	}catch(e){
	
	
	}
//	the hard way?

	myDoc.xmlElements.everyItem().remove();
	
	
}


function untagAllxmlElements(myDoc){

	var myRuleSet = new Array(new allElements());
	with(myDoc){
	var elements = xmlElements;
	__processRuleSet(elements.everyItem(), myRuleSet);
	
}
}

function allElements(){

	this.name = "allElements";
	this.xpath = "/Root/*";
	this.apply = function(myElement, myRuleProcessor){
		__skipChildren(myRuleProcessor);
		myElement.untag();
		};
	
}