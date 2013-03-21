#include "ElementChoix.h"

ElementChoix::ElementChoix(list<GroupeSubElement*> * l,Quantificateur q){
	listGroupeSubElement=l;
	quantificateur=q;
}

ElementChoix::~ElementChoix(){
	list<GroupeSubElement*>::iterator it;
	for (it = this->listGroupeSubElement->begin(); it != this->listGroupeSubElement->end(); it++)
	{
		delete(*it);
	}

	delete(this->listGroupeSubElement);
}

void ElementChoix::Afficher() const
{
	cout << nom ; 
	switch(quantificateur)
	{
		case INTERROGATION : cout << "?"; 
		break; 
		case CROIX : cout << "+";
		break;  
		case ETOILE : cout << "*";
		break; 
		default : 
		break;  
	}
}