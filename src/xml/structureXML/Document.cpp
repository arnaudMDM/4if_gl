/*
 * Document.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "Document.h"

Document::Document() {
	// TODO Auto-generated constructor stub

}

Document::~Document() {
	// TODO Auto-generated destructor stub
}

Document::Document(string version, string encoding, ElementBalise elementBalise) : version(version), encoding(encoding), elementBalise(elementBalise){

}

string Document::getEncoding() const
{
   return encoding;
}

string Document::getVersion() const
{
   return version;
}
