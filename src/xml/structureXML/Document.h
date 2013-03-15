/*
 * Document.h
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#ifndef DOCUMENT_H_
#define DOCUMENT_H_

using namespace std;

// Includes
#include <string>
#include "ElementBalise.h"

class Document {

// Attributs de classe
protected:
	string version;
	string encoding;
	ElementBalise elementBalise;

// Constructeurs et Méthodes
public:
	Document();

	Document(string version, string encoding, ElementBalise elementBalise);

	virtual ~Document();

	string getEncoding() const;

    string getVersion() const;
};

#endif /* DOCUMENT_H_ */
