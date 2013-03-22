#include <stdio.h>
#include <string>
#include <set>
#include <iterator>
#include <iostream>

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
#include "xsl/structureXSL/ElementXSL.h"
#include "xsl/structureXSL/ElementTextuel.h"


//#include "dtd/dtd.tab.h" 
//#include "xml/xml.tab.h"


int xmlparse(Document * xml);
int dtdparse(DocumentDTD * dtd);
bool verifXml(DocumentDTD * dtd, Document * xml);
bool verifNoeud(AbstractElement * noeud, map<string, ElementDTD*> * elts);
bool parser(Document * docXML, DocumentDTD * docDTD);
bool parserXSL(Document * docXML, DocumentXSL * docXSL);


extern int xmldebug;
extern int dtddebug;
extern FILE * dtdin; // sert a recuperer la dtd a partir du fichier xml ou xsl
extern FILE * xmlin; // sert a passer le fichier xml a bison
extern FILE * xslin; // sert a passer le fichier xsl a bison


/* --- CONSTRUCTION ------------------------------------------*/

bool construirXML(char* nomXML)
{
	Document * docXML = new Document();
	DocumentDTD * docDTD = new DocumentDTD();

	bool a = parser(docXML, docDTD);

	delete(docXML);
	delete(docDTD);

	return a;
}

bool construirDTD(char* nomDTD)
{
	Document * docXML = new Document();
	DocumentDTD * docDTD = new DocumentDTD();

	bool a = parser(docXML, docDTD);

	delete(docXML);
	delete(docDTD);

	return a;
}

bool VerifXmletDtd(char* nomXML, char* nomDTD)
{
	Document * docXML = new Document();
	DocumentDTD * docDTD = new DocumentDTD();

	bool a = parser(docXML, docDTD);
	bool b = verifXml(docDTD, docXML);

	delete(docXML);
	delete(docDTD);

	if (a == true && b == true) return true;
	else return false;
}

bool construirXSL(char* nomXML, char* nomXSL)
{
	Document * docXML = new Document();
	DocumentXSL * docXSL = new DocumentXSL();

	bool a = parserXSL(docXML, docXSL);

	delete(docXML);
	delete(docXSL);

	return a;
}

// --- PROGRAM BEGIN -------------------

int main(int argc, char **argv)
{
	if (argc < 3) return -1;
	int choix = atoi(argv[1]);
	cout << "Votre choix : " << choix << endl;

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
			if(argc < 4) return -1;
			if (VerifXmletDtd(argv[2], argv[3]))
				cout << "Check XML and DTD successfull" << endl;
			else
				cout << "Error : XML with DTD" << endl;
			break;
		}
		case 3 : // construction de l'arbre xsl
		{
			if(argc < 4) return -1;
			if (construirXSL(argv[2], argv[3]))
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
bool parserXSL(Document * docXML, DocumentXSL * docXSL)
{
	return false;
}

bool parser(Document * docXML, DocumentDTD * docDTD)
{
	xmldebug = 1; // pour activer l'affichage de l'exécution du parser LALR

	int err;
	err = xmlparse(docXML);
	if (err != 0)
	{
		printf("Parse ended with %d error(s)\n", err);
	}
	else
	{
		printf("Parse ended with success\n", err);
	}

	docXML->afficher();

	string nomDtd = docXML->getNomDtd();
	if (nomDtd == "")
	{
		printf("Aucune dtd associée\n", err);
	}
	else
	{
		dtddebug = 1;
		FILE *file;
		file = fopen(nomDtd.c_str(), "r");
	
		if (!file)
		{
			fprintf(stderr, "Could not open %s \n", nomDtd.c_str());
			return false;
		}
		
		dtdin = file;

		err = dtdparse(docDTD);
		if (err != 0)
		{
			printf("Parse ended with %d error(s)\n", err);
		}
		else
		{
			printf("Parse ended with success\n", err);
		}
		
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

	ElementBalise * noeud = dynamic_cast<ElementBalise*>(abstractNoeud);

	if (noeud == 0)
	{
		// il s'agit d'un élément texte
		return true;
	}

	string nomNoeudCourant = noeud->getNom();

	ElementDTD * noeudDTD = (*elts)[nomNoeudCourant];

	// verification de l'existance du noeud courant dans la dtd
	if (noeudDTD == NULL)
	{
		return false;
	}

	// vérification des attributs du noeud courant
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

	// vérification des sous-éléments*/
	list<AbstractElement*> * lstEltsXML = noeud->getLstAbstractElement();
	list<AbstractElement*>::iterator it3;
	for (it3 = lstEltsXML->begin(); it3 != lstEltsXML->end(); it3++)
	{
		if (!verifNoeud(*(it3), elts))
		{
			return false;
		}
	}

	return true;
}
