#include <stdio.h>
#include <string>
#include <set>
#include <iterator>
#include <iostream>
#include <boost/regex.hpp>

#include "xml/structureXML/AbstractElement.h"
#include "xml/structureXML/AttributXML.h"
#include "xml/structureXML/Document.h"
#include "xml/structureXML/ElementBalise.h"
#include "xml/structureXML/ElementTexte.h"

#include "dtd/structureDTD/AttributDTD.h"
#include "dtd/structureDTD/DocumentDTD.h"
#include "dtd/structureDTD/ElementDTD.h"


#include "xsl/structureXSL/AbstractElementXSL.h"
#include "xsl/structureXSL/AttributXSL.h"
#include "xsl/structureXSL/DocumentXSL.h"
#include "xsl/structureXSL/ElementTextuel.h"

using namespace boost;


int xmlparse(Document * xml);
int dtdparse(DocumentDTD * dtd);
int xslparse(DocumentXSL * xsl); 
bool verifXml(DocumentDTD * dtd, Document * xml);
bool verifNoeud(AbstractElement * noeud, map<string, ElementDTD*> * elts);
bool parserXML(Document * docXML, char* nomFic);
bool parserDTD(DocumentDTD * docDTD, char* nomFic);
void ajouterTexteTemplate(AbstractElement* abstXML,AbstractElementXSL* abstXSL,list<AbstractElementXSL*>lstAbstXSL, list<string>* lstString);
bool parserXSL(DocumentXSL * docXML, char* nomFic);


extern int xmldebug;
extern int dtddebug;
extern int xsldebug; 
extern FILE * dtdin; // sert a recuperer la dtd a partir du fichier xml ou xsl
extern FILE * xmlin; // sert a passer le fichier xml a bison
extern FILE * xslin; // sert a passer le fichier xsl a bison


/* --- CONSTRUCTION ------------------------------------------*/

bool construirXML(char* nomXML)
{
	Document * docXML = new Document();
	bool a = parserXML(docXML, nomXML);
	docXML->afficher();
	delete(docXML);

	return a;
}

bool construirDTD(char* nomDTD)
{
	DocumentDTD * docDTD = new DocumentDTD();
	bool a = parserDTD(docDTD, nomDTD);
	docDTD->Afficher();
	delete(docDTD);

	return a;
}

bool VerifXmletDtd(char* nomXML)
{
	Document * docXML = new Document();
	DocumentDTD * docDTD = new DocumentDTD();

	bool a = parserXML(docXML, nomXML);
	docXML->afficher();
	bool b = parserDTD(docDTD, (char*)(docXML->getNomDtd()).c_str());
	docDTD->Afficher();
	bool c = verifXml(docDTD, docXML);

	delete(docXML);
	delete(docDTD);

	if (a == true && b == true && c == true) return true;
	else return false;
}

bool construirXSL(char* nomXSL)
{
	DocumentXSL * docXSL = new DocumentXSL();
	bool a = parserXSL(docXSL, nomXSL);
	delete(docXSL);

	return a;
}

// --- PROGRAM BEGIN -------------------

int main(int argc, char **argv)
{
	if (argc < 3) return -1;

	int choix;
	if (strcmp(*(argv+1), "-cxml") == 0) choix = 0;
	else if (strcmp(*(argv+1), "-cdtd") == 0) choix = 1;
	else if (strcmp(*(argv+1), "-check") == 0) choix = 2;
	else if (strcmp(*(argv+1), "-all") == 0) choix = 3;
	else choix = 999;

	switch (choix)
	{
		case 0 : // construction de l'arbre xml
		{
			if (construirXML(argv[2]))
				cout << "XML tree construction successfull" << endl;
			else
				cout << "Error : XML tree" << endl;
			break;
		}		
		case 1 : // construction de l'arbre dtd
		{
			if (construirDTD(argv[2]))
				cout << "DTD tree construction successfull" << endl;
			else
				cout << "Error : DTD tree" << endl;
			break;
		}
		case 2 : // construction des arbres et verif coherence
		{
			if (VerifXmletDtd(argv[2]))
				cout << "Check XML and DTD successfull" << endl;
			else
				cout << "Error : XML with DTD" << endl;
			break;
		}
		case 3 : // construction de l'arbre xsl
		{
			if (construirXSL(argv[2]))
				cout << "XSL tree construction successfull" << endl;
			else
				cout << "Error : XSL tree" << endl;
			break;
		}
		default : cout << "Erreur à l'appel" << endl;
	}

	return 0;
}





/* ---PARSEURS------------------------------------- */
bool parserXSL(DocumentXSL * docXSL, char* nomFic)
{
	int err;
	if (nomFic == "")
	{
		cout << "Nom de fichier xsl vide" << endl;
		return false;
	}
	else
	{
		xsldebug = 1;
		FILE *file;
		file = fopen(nomFic, "r");
	
		if (!file)
		{
			fprintf(stderr, "Could not open %s \n", nomFic);
			return false;
		}
		
		xslin = file;

		err = xslparse(docXSL);
		if (err != 0)
		{
			printf("Parse XSL ended with %d error(s)\n", err);
		}
		else
		{
			printf("Parse XSL ended with success\n", err);
		}
		docXSL->afficher();
		fclose(file);
	}
	return true;
}

bool parserXML(Document * docXML, char* nomFic)
{
	//xmldebug = 1; // active l'affichage de l'exécution du parser LALR

	int err;
	if (nomFic == "")
	{

		printf("Parse XML ended with %d error(s)\n", err);
		cout << "Nom de fichier xml vide" << endl;
		return false;

	}
	else
	{
		//xmldebug = 1;
		FILE *file;
		file = fopen(nomFic, "r");
	
		if (!file)
		{
			fprintf(stderr, "Could not open %s \n", nomFic);
			return false;
		}
		
		xmlin = file;

		err = xmlparse(docXML);
		if (err != 0)
		{
			printf("Parse XML ended with %d error(s)\n", err);
		}
		else
		{
			printf("Parse XML ended with success\n", err);
		}
		
		fclose(file);
	}

	return true;
}

bool parserDTD(DocumentDTD * docDTD, char* nomFic)
{
	int err;
	if (nomFic == "")
	{
		cout << "Nom de fichier dtd vide" << endl;
		return false;
	}
	else
	{
		//dtddebug = 1;
		FILE *file;
		file = fopen(nomFic, "r");
	
		if (!file)
		{
			fprintf(stderr, "Could not open %s \n", nomFic);
			return false;
		}
		
		dtdin = file;

		err = dtdparse(docDTD);
		if (err != 0)
		{
			printf("Parse DTD ended with %d error(s)\n", err);
		}
		else
		{
			printf("Parse DTD ended with success\n", err);
		}
		docDTD->Afficher();
		fclose(file);
	}

	return true;
}


/* ---VERIFICATION------------------------------------- */


bool verifXml(DocumentDTD * dtd, Document * xml)
{
	if (dtd == NULL || xml == NULL)
	{
		return false;
	}

	ElementBalise * noeud;
	map<string, ElementDTD*> * elts;

	noeud = xml->getElementBalise();
	elts = dtd->getElementsDTD();
	
	return verifNoeud(noeud, elts);
}

bool verifNoeud(AbstractElement * abstractNoeud, map<string, ElementDTD*> * elts)
{

	if (abstractNoeud == NULL || elts == NULL)
	{
		return false;
	}

	// On vérifie que l'élément XML n'est pas un élément texte
	ElementBalise * noeud = dynamic_cast<ElementBalise*>(abstractNoeud);
	if (noeud == 0)
	{
		// il s'agit d'un élément texte
		return true;
	}

	// On vérifie qu'il existe une entrée dans la DTD correspondant au noeud XLM courant
	string nomNoeudCourant = noeud->getNom();
	ElementDTD * noeudDTD = (*elts)[nomNoeudCourant];

	if (noeudDTD == NULL)
	{
		return false;
	}

	// On vérifie des attributs du noeud courant
	set<AttributXML*> * attsXML = noeud->getSetAttribut();
	set<AttributDTD*> * attsDTD = noeudDTD->getSetAttributDTD();

	set<AttributXML*>::iterator it;
	set<AttributDTD*>::iterator it2;
	bool trouve;
	for (it = attsXML->begin(); it != attsXML->end(); it++)
	{
		trouve = false;

		for (it2 = attsDTD->begin(); it2 != attsDTD->end(); it2++)
		{
			if ((*it)->getNom() == (*it2)->getNom())
			{
				trouve = true;
				break;
			}
		}

		if (!trouve)
		{
			return false;
		}
	}

	// On vérifie que les sous-éléments XML sont bien des fils aussi dans la DTD puis on applique la vérification totale à chaque sous-élement
	list<AbstractElement*> * lstEltsXML = noeud->getLstAbstractElement();
	list<AbstractElement*>::iterator it3;
	for (it3 = lstEltsXML->begin(); it3 != lstEltsXML->end(); it3++)
	{
		// On vérifie que l'élément XML n'est pas un élément texte
		ElementBalise * ssNoeud = dynamic_cast<ElementBalise*>(*it3);
		if (ssNoeud == 0)
		{
			// il s'agit d'un élément texte
			continue;
		}

		string nomSsNoeud = ssNoeud->getNom();
		regex regexDTD(noeudDTD->getRegEx());

		cmatch inutilise;
		if (!regex_match(nomSsNoeud.c_str(), inutilise, regexDTD))
		{
			return false;
		}

		// On applique la vérification totale sur le sous-élément XML
		if (!verifNoeud(*(it3), elts))
		{
			return false;
		}
	}

	return true;
}

/*
bool verifTemplate(list<AbstractElementXSL*>*lst)
{
	list<AbstractElementXSL*>::iterator it;
	for(it=lst->begin() ; it!=lst->end() ; it++)
	{
		if((*it)->getType()!=APPLYTEMPLATES)
			return false;
	}
	return true;
}

ElementXSL* trouveTemplate(list<AbstractElementXSL*>*lstXSL,string s)
{
	ElementXSL* retour=NULL;
	list<AbstractElementXSL*>::iterator it;
	for(it=lstXSL->begin() ; it!=lstXSL->end() ; it++)
	{
		if(((((*it)->getAttributXSL())->getValeur()).compare(s))==0) //peut etre caster
			retour=(*it);
	}
	return retour;
}

void ajouterTousTextesXML(ElementBalise* EltXML, list<string>* lstString)
{
	list<AbstractElement*>* lstAbstXML=EltXML->getLstAbstractElement();
	list<AbstractElement*>::iterator it;


	for(it=lstAbstXML->begin() ; it!=lstAbstXML->end() ; it++)
	{
		if((*it)->getIsText())
			lstString->push_back((*it)->getTexte());
		else
			ajouterTousTextesXML((*it),lstString);//peut etre caster
	}
}

void applyTemplates(ElementBalise* EltXML, list<AbstractElementXSL*>* lstAbstXSL,list<string>* lstString)
{
	list<AbstractElement*>* lstAbstXML=EltXML->getLstAbstractElement();
	list<AbstractElement*>::iterator it;
	ElementXSL* EltXSL;

	for(it=lstAbstXML->begin() ; it!=lstAbstXML->end() ; it++)
	{
		if((*it)->getIsText())
			lstString->push_back((*it)->getTexte());
		else if((EltXSL=trouveTemplate(lstAbstXSL,(*it)->getNom()))!=NULL)
			ajouterTexteTemplate((*it),EltXSL,lstAbstXSL,lstString);
		else
			ajouterTousTextesXML((*it),lstString);
	}
}

void ajouterTexteTemplate(ElementBalise* EltXML, ElementXSL* EltXSL,list<AbstractElementXSL*>lstAbstXSL, list<string>* lstString)
{
	list<AbstractElementXSL*>* lstAbstXSL=EltXSL->getLstAbstractElementXSL();

	list<AbstractElementXSL*>::iterator it;
	for(it=lstAbstXSL->begin() ; it!=lstAbstXSL->end() ; it++)
	{
		if((*it)->getType()==TEXT)
			lstString->push_back((*it)->getTexte());
		else if((*it)->getType()==APPLYTEMPLATES)
			applyTemplates(EltXML,lstAbstXSL,lstString)
		else
		{
			cout<<"balise xsl interdite"<<endl;
			return;
		}
	}
}

void transfXML(Document* docXML, DocumentXSL* docXSL)
{
	list<string>* lstString=new list<string>();
	if(docXML==NULL|docXSL==NULL)
	{
		cout<<"erreur pointeur nul"<<endl;
		return;
	}

	ElementXSL * eltXSL = docXSL->getElementXSL();

	if(eltXSL->getType()!=STYLESHEET)
	{
		cout<<"pas de balise stylesheet dans le xsl"<<endl;
		return;
	}

	list<AbstractElementXSL*>* lstAbstXSL=eltXSL->getLstAbstractElementXSL();

	if(!verifTemplate(lstAbstXSL))
	{
		cout<<"élément fils de stylesheet inconnu"<<endl;
		return;
	}

	if((eltXSL=trouveTemplate(lstAbstXSL,"/"))!=NULL)
	{
		ajouterTexteTemplate(docXML->getElementBalise(),eltXSL,lstAbstXSL,lstString);
	}
	else
		applyTemplates(docXML->getElementBalise(),lstAbstXSL,lstString);
}*/

