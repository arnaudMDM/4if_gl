#ifndef DOCUMENTHTML_H_
#define DOCUMENTHTML_H_

#include <list>
#include <string>

using namespace std;

class DocumentHTML
{
public:
	DocumentHTML(list<string>* l);
	virtual ~DocumentHTML();
	void afficher();
private:
	list<string> * listElementHTML;
};

#endif