#include "ElementSequence.h"

ElementSequence::ElementSequence(list<GroupeSubElement*> * l,Quantificateur q){
	listGroupeSubElement=l;
	quantificateur=q;
}

ElementSequence::~ElementSequence(){
	list<GroupeSubElement*>::iterator it;
	for (it = this->listGroupeSubElement->begin(); it != this->listGroupeSubElement->end(); it++)
	{
		delete(*it);
	}

	delete(this->listGroupeSubElement);
}

void ElementSequence::Afficher() const
{
	
}


