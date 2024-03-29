%{

using namespace std;

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "commun.h"
#include "structureXML/AbstractElement.h"
#include "structureXML/ElementTexte.h"
#include "structureXML/ElementBalise.h"
#include "structureXML/Document.h"
#include <list>
#include <set>
#include "xml.tab.h"

// ces trois fonctions devront changer de nom dans le cas où l'otion -p est utilisée
int xmlwrap(void);
void xmlerror(Document * doc, char *msg);
int xmllex(void);

%}

%union {
   char * s;
   ElementName * en;  /* le nom d'un element avec son namespace, cf commun.h */
   AbstractElement * abstractElement; /* C est un element balise uniquement */
   list<AbstractElement *> * lstAbstractElement; /* C est une liste */
   pair<list<AbstractElement*>*,string> * pairAbstElt; 
   set<AttributXML*> * lstAttributXml;
}

/* <?xml version="1.0" encoding="ISO-8859-1"?> */ 

%token EGAL SLASH SUP SUPSPECIAL DOCTYPE
%token <s> ENCODING VALEUR DONNEES COMMENT NOM ENNOM DTD SYSTEM
%token <en> OBALISEEN OBALISE OBALISESPECIALE FBALISE FBALISEEN
%type <abstractElement> element
%type <lstAbstractElement> contenu_opt  
%type <pairAbstElt> vide_ou_contenu ferme_contenu_et_fin
%type <en> ouvre
%type <lstAttributXml> attributs_opt

/* Pour recuperer le document en entier */ 
%parse-param {Document * docXml}

%%

document
 : declarations element misc_seq_opt {docXml->setElementBalise((ElementBalise*)$2)}
 ;
misc_seq_opt
 : misc_seq_opt misc /*  si je ne veux pas stocker, je ne mets rien : { $$ = $1  }; $$->push_back(string($2)) }*/ 
 | /*vide*/ /* {$$ = new list<string>} */ 
 ;
misc
 : COMMENT
 ;

declarations
 : declarations declaration
 | /*vide*/ 
 ;

/*  <?xml version="1.0" encoding="ISO-8859-1"?>
<!DOCTYPE rapport SYSTEM "rap2.dtd">
<?xml-stylesheet type="text/xsl" href="cdcatalog.xsl"?> */  
declaration
 : DOCTYPE NOM SYSTEM DTD SUP {docXml->setNomDtd(string($4)); docXml->setNomXml(string($2))}
 | DOCTYPE NOM NOM VALEUR SUP
 /*: OBALISESPECIALE NOM attributs_opt_declarations SUPSPECIAL */
 ;

 /*attributs_opt_declarations
 : attributs_opt_declarations NOM EGAL VALEUR {docXml->setNomFeuilleDeStyle($4)}
 | /*vide*/ /*{ $$ = new list<string>() }
 ;*/

element
 : ouvre attributs_opt vide_ou_contenu {$$ = new ElementBalise($1->second,$3->second,$3->first,$2)}
 ;
ouvre
 : OBALISE {$$ = $1}
 | OBALISEEN {$$ = $1}
 ;

attributs_opt
 : attributs_opt NOM EGAL VALEUR {$$ = $1 ; $$->insert(new AttributXML(string($2),string($4)))}
 | /*vide*/ {$$ = new set<AttributXML*>()}
 ;

vide_ou_contenu
 : SLASH SUP {$$=new pair<list<AbstractElement*>*,string>()} /*contenu vide*/
 | ferme_contenu_et_fin SUP { $$ = $1 }  /*contenu non vide*/
 ;
ferme_contenu_et_fin
 : SUP contenu_opt FBALISE { $$ =new pair<list<AbstractElement*>*,string>($2,$3->second); }
 ;
contenu_opt /* Regle de construction en commentaire */
 : contenu_opt DONNEES { $$ = $1 ; $$->push_back(new ElementTexte(string($2)))} // delete $2
 | contenu_opt misc { $$ = $1 }
 | contenu_opt element  { $$ = $1 ; $$->push_back($2)} //  delete $2
 | /*vide*/     { $$ = new list<AbstractElement*>() }      
 ;

%%


int xmlwrap(void)
{
  return 1;
}

void xmlerror(Document * doc, char *msg)
{
  fprintf(stderr, "%s\n", msg);
}

