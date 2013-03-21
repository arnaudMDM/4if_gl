%{

using namespace std;

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <map>
#include <list>

#include "structureDTD/DocumentDTD.h"
#include "structureDTD/ElementSequence.h"
#include "structureDTD/ElementSimple.h"

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
   ElementSequence * elementSeq;
   Quantificateur quantificateur;
   list<GroupeSubElement*> * listeElt;
   set<AttributDTD*> * setAttDTD;
}

%token ELEMENT ATTLIST SUP OUVREPAR FERMEPAR VIRGULE BARRE FIXED EMPTY ANY PCDATA AST PTINT PLUS CDATA
%token <s> DTDNOM TOKENTYPE DECLARATION DTDVALEUR
%type  <s>att_type defaut_declaration
%type  <mapElementDTD> dtd_list_opt
%type  <attributDTD> attribut
%type  <elementDTD> children
%type  <groupeSubElt> cp
%type  <quantificateur> card_opt
%type  <listeElt> liste_seq_opt seq
%type  <setAttDTD> att_definition_opt


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
: choice card_opt {$$=NULL;}
| seq card_opt {$$=new ElementDTD(false,new ElementSequence($1,$2));}
| OUVREPAR PCDATA FERMEPAR {$$=new ElementDTD(true,NULL);}
;

choice
: OUVREPAR cp liste_choice FERMEPAR
;

cp
: DTDNOM card_opt {$$=new ElementSimple(string($1),$2);}
| choice card_opt {$$=NULL;}
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
: liste_choice BARRE cp
| BARRE cp
;

liste_seq_opt
: liste_seq_opt VIRGULE cp {$$=$1 ; $$->push_back($3);}
| /*vide*/{$$=new list<GroupeSubElement*>();}

att_definition_opt
: att_definition_opt attribut {$$=$1 ; $$->insert($2);}
| /* vide */{$$=new set<AttributDTD*>();}
;

attribut
: DTDNOM att_type defaut_declaration {$$=new AttributDTD(string($1),string($2),string($3));}
;

att_type
: CDATA {$$="CDATA";}
| TOKENTYPE {$$="TOKENTYPE";}
| type_enumere {$$="";}
;

type_enumere
: OUVREPAR liste_enum_plus FERMEPAR
;

liste_enum_plus
: liste_enum BARRE DTDNOM
;

liste_enum
: DTDNOM
| liste_enum BARRE DTDNOM
;

defaut_declaration
: DECLARATION {$$=$1;}
| DTDVALEUR {$$=$1;}
| FIXED DTDVALEUR {$$="";}
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

