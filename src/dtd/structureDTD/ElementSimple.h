#ifndef ELEMENTSIMPLE_H_
#define ELEMENTEIMPLE_H_

#include <string>
#include "GroupeSubElement.h"

using namespace std;

class ElementSimple : public GroupeSubElement{
public:
	ElementSimple(string n,Quantificateur q);
	virtual ~ElementSimple();
	virtual void Afficher() const; 
protected:
	string nom;
};

#endif