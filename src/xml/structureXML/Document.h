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
#include <list>

class Document {
protected:
    string nomXml;
    string nomDtd;
    //list<string> nomFeuilleDeStyle;
    ElementBalise elementBalise;
public:
    Document();
    //Document(ElementBalise elementBalise);
    virtual ~Document();
    void afficher();
    void setElementBalise(ElementBalise elementBalise);
    void setNomDtd(string nomDtd);
    //void setNomFeuilleDeStyle(list<string> nomFeuilleDeStyle);
    void setNomXml(string nomXml);

    //ElementBalise * getElementBalise();
};

#endif /* DOCUMENT_H_ */
