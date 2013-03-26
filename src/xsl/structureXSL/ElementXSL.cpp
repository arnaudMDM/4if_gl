/*
 * ElementXSL.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "ElementXSL.h"

#include <set>
#include <iostream>
#include <string.h>

using namespace std;

ElementXSL::ElementXSL() {}

ElementXSL::~ElementXSL() 
{
	if(lstAbstractElementXSL!=NULL)
	{
		list<AbstractElementXSL*>::iterator it;
		for(it=lstAbstractElementXSL->begin() ; it!=lstAbstractElementXSL->end() ; it++)
		{
			if((*it)!=NULL)
				delete(*it);
		}
		delete lstAbstractElementXSL;
	}

	if(attributXSL!=NULL) delete(attributXSL);
}

ElementXSL::ElementXSL(string type, list<AbstractElementXSL*> * l, AttributXSL * s)
{
	char * tmp1 = "template";
	char * tmp2 = "apply-templates";
	char * tmp3 = "stylesheet";
	char * tmp4 = "value-of";
	char * tmp5 = "for-each";

	if (strcmp(type.c_str(), tmp1) == 0)
	{
		this->type = TEMPLATE;  
	}
	else if (strcmp(type.c_str(), tmp2) == 0)
	{
		this->type = APPLYTEMPLATES; 
	}
	else if (strcmp(type.c_str(), tmp3) == 0)
	{
		this->type = STYLESHEET; 
	}
	else if (strcmp(type.c_str(), tmp4) == 0)
	{
		this->type = VALUEOF; 
	}
	else if (strcmp(type.c_str(), tmp5) == 0)
	{
		this->type = FOREACH; 
	}
	else 
	{
		this->type = TEXTE;
	}
	
	this->lstAbstractElementXSL = l;
	this->attributXSL = s;
}

void ElementXSL::afficher()
{
	cout << "<xsl:" ;
	switch(type)
	{
		case TEMPLATE : cout << "template ";  
		break; 
		case APPLYTEMPLATES : cout << "apply-templates ";
		break; 
		case STYLESHEET : cout << "stylesheet ";
		break;
		case VALUEOF : cout << "value-of";
		break; 
		case FOREACH : cout << "for-each";
		break;
		default : break;  
	}
	if (attributXSL != NULL)
	{
		attributXSL->afficher();
	}

	if (lstAbstractElementXSL->size() > 0)
	{
		cout << ">" << endl;
		list<AbstractElementXSL*>::iterator it2;
		for (it2 = lstAbstractElementXSL->begin(); it2 != lstAbstractElementXSL->end(); it2++)
		{
			(*it2)->afficher();
		}
		cout << "</xsl:" ; 
		switch(type)
		{
			case TEMPLATE :
				cout << "template";  
				break; 
			case APPLYTEMPLATES :
				cout << "apply-templates";
				break; 
			case STYLESHEET :
				cout << "stylesheet";
				break;
			case VALUEOF :
				cout << "value-of";
				break; 
			case FOREACH :
				cout << "for-each";
				break;
			default :
				break;  
		}
		cout << ">" << endl;
	}
	else
	{
	  cout << "/>" << endl;
	}

}

list<AbstractElementXSL*> * ElementXSL::getLstAbstractElementXSL() const
{
  return lstAbstractElementXSL;
}

AttributXSL* ElementXSL::getAttributXSL() const
{
  return attributXSL;
}
