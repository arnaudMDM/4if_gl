%{

using namespace std;

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <map>
#include <list>
#include <string.h>

#include "structureDTD/DocumentDTD.h"
#include "structureDTD/ElementSequence.h"
#include "structureDTD/ElementSimple.h"
#include "structureDTD/ElementChoix.h"

void dtderror(DocumentDTD * documentDtd, char *msg);
int dtdwrap(void);
int dtdlex(void);

%}

%union { 
   char *s; 
   map<string, ElementDTD*> * mapElementDTD;
   AttributDTD * attributDTD;
   ElementDTD * elementDTD;
   GroupeSubElement * groupeSubElt;
   Quantificateur quantificateur;
   list<GroupeSubElement*> * listeElt;
   set<AttributDTD*> * setAttDTD;
   list<string> * listeString;
}

%token ELEMENT ATTLIST SUP OUVREPAR FERMEPAR VIRGULE BARRE EMPTY ANY AST PTINT PLUS
%token <s> DTDNOM TOKENTYPE DECLARATION DTDVALEUR CDATA FIXED PCDATA
%type  <s> att_type_non_enum defaut_declaration
%type  <mapElementDTD> dtd_list_opt
%type  <attributDTD> attribut
%type  <elementDTD> children
%type  <groupeSubElt> cp
%type  <quantificateur> card_opt
%type  <listeElt> liste_seq_opt liste_choice seq choice
%type  <setAttDTD> att_definition_opt
%type  <listeString> liste_enum liste_enum_plus type_enumere


/* Pour recuperer le document en entier */ 
%parse-param {DocumentDTD * docDtd}

%%

main: dtd_list_opt{docDtd->setMapElementDTD((map<string,ElementDTD*>*)$1);}
;

dtd_list_opt
: dtd_list_opt ATTLIST DTDNOM att_definition_opt SUP {$$=$1 ; ($$->find($3)->second)->ajouterAttribut($4);}//si on trouve pas la déclaration de l'élément retourner faux.
| dtd_list_opt ELEMENT DTDNOM children SUP{$$=$1 ; $4->setNom(string($3)) ; $$->insert(pair<string,ElementDTD*>(string($3),$4));}//il faut tester si l'élément n'a pas été déjà déclaré
| /* vide */{$$=new map<string, ElementDTD*>();}
;

children
: choice card_opt {$$=new ElementDTD(new ElementChoix($1,$2));}
| seq card_opt {$$=new ElementDTD(new ElementSequence($1,$2));}
;

choice
: OUVREPAR cp liste_choice FERMEPAR {$3->push_front($2);$$=$3;}
;

cp
: PCDATA card_opt {$$=new ElementSimple(string($1),$2);}
| DTDNOM card_opt {$$=new ElementSimple(string($1),$2);}
| choice card_opt {$$=new ElementChoix($1,$2);}
| seq card_opt {$$=new ElementSequence($1,$2);}
;

card_opt
: PTINT {$$=INTERROGATION;}
| AST {$$=ETOILE;}
| PLUS {$$=CROIX;}
| /*vide*/{$$=AUCUN;}
;

seq
: OUVREPAR cp liste_seq_opt FERMEPAR {$3->push_front($2);$$=$3;}
;

liste_choice
: liste_choice BARRE cp {$$=$1 ; $$->push_back($3);}
| BARRE cp {$$=new list<GroupeSubElement*>();$$->push_back($2);}
;

liste_seq_opt
: liste_seq_opt VIRGULE cp {$$=$1 ; $$->push_back($3);}
| /*vide*/{$$=new list<GroupeSubElement*>();}

att_definition_opt
: att_definition_opt attribut {$$=$1 ; $$->insert($2);}
| /* vide */{$$=new set<AttributDTD*>();}
;

attribut
: DTDNOM att_type_non_enum defaut_declaration {$$=new AttributDTD(string($1),string($2),string($3));}
| DTDNOM type_enumere defaut_declaration {$$=new AttributDTD(string($1),$2,string($3));}
;

att_type_non_enum
: CDATA {$$=$1;}
| TOKENTYPE {$$=$1;}
;

type_enumere
: OUVREPAR liste_enum_plus FERMEPAR {$$=$2;}
;

liste_enum_plus
: liste_enum BARRE DTDNOM {$$->push_front(string($3));}
;

liste_enum
: DTDNOM {$$=new list<string>();$$->push_front(string($1));}
| liste_enum BARRE DTDNOM {$$->push_front(string($3));}
;

defaut_declaration
: DECLARATION {$$=$1;}
| DTDVALEUR {$$=$1;}
| FIXED DTDVALEUR {$$=strcat(strcat($1," "), $2);}//peut ne pas marcher
;

%%

int dtdwrap(void)
{
  return 1;
}

void dtderror(DocumentDTD * documentDtd, char *msg)
{
  fprintf(stderr, "%s\n", msg);
}

