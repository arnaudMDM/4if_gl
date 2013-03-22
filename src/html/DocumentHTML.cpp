#include <iostream>

#include "DocumentHTML.h"

DocumentHTML::DocumentHTML(list<string>* l)
{
	listElementHTML=l;
}

DocumentHTML::~DocumentHTML()
{
	delete(listElementHTML);
}

void DocumentHTML::afficher()
{
	list<string>::iterator it;
	for(it=listElementHTML->begin() ; it!=listElementHTML->end() ; it++)
	{
		cout<<*it<<endl;
	}
}