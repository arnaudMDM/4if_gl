#ifndef ELEMENTSEQUENCE_H_
#define ELEMENTSEQUENCE_H_

#include <list>
#include "GroupeSubElement.h"

using namespace std;

class ElementSequence : public GroupeSubElement{
public:
	ElementSequence(list<GroupeSubElement*> * l,Quantificateur q);
	virtual ~ElementSequence();
	virtual void Afficher() const; 
protected:
	list<GroupeSubElement*> * listGroupeSubElement;
};

#endif