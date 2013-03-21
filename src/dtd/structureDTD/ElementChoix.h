#ifndef ELEMENTCHOIX_H_
#define ELEMENTCHOIX_H_

#include <list>
#include "GroupeSubElement.h"

using namespace std;

class ElementChoix : public GroupeSubElement{
public:
	ElementChoix(list<GroupeSubElement*> * l,Quantificateur q);
	virtual ~ElementChoix();
protected:
	list<GroupeSubElement*> * listGroupeSubElement;
};

#endif