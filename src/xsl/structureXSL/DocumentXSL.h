/*
 * DocumentXSL.h
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#ifndef DOCUMENTXSL_H_
#define DOCUMENTXSL_H_

using namespace std;

// Includes
#include <string>
#include "ElementXSL.h"
#include <list>

class DocumentXSL
 {
protected:
    string version;
    string stylesheet;
    ElementXSL * elementXSL;
public:
    DocumentXSL();
    virtual ~DocumentXSL();

    void afficher();
    void setElementXSL(ElementXSL * elementXSL);
    void setVersion(string version);

    string getVersion();
    string getStylesheet();
    ElementXSL * getElementXSL();
};

#endif /* DOCUMENTXSL_H_ */
