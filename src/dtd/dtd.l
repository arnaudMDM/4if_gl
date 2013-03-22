%option 8bit

%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "structureDTD/DocumentDTD.h"
#include "structureDTD/ElementSequence.h"
#include "structureDTD/ElementSimple.h"
#include "structureDTD/ElementChoix.h"
#include "dtd.tab.h"



#define YYTEXT dtdtext
#define YYLVAL dtdlval

static char* skipSpace(char *s) {
  char *buf;
  int i,lastnonspace;
  for (buf=s;isspace(*buf);buf++) ;
  for (i=0,lastnonspace=0;buf[i];i++) {
     if (!isspace(buf[i]))
        lastnonspace = i;
  }
  buf[lastnonspace+1] = '\0';
  return strdup(buf);
}
  
/* affecte la valeur de la chaine de caractère et renvoie le token */
#define stringreturn(tokenval) YYLVAL.s=skipSpace(YYTEXT);return(tokenval)

%}
%option noyywrap

nl		      (\r\n|\r|\n)
esp		   [ \t\r\n]+
inf		   {nl}?"<"
sup		   ">"{nl}?
ouvrepar    "("
fermepar    ")"
virgule     ","
barre       "|"
echap		   "&#"[0-9]+";"|"&#x"[0-9a-fA-F]+";"
debutnom	   [A-Za-z\200-\377_]
caracnom	   [A-Za-z\200-\377_0-9.-]
tokentype   "ID"|"IDREF"|"IDREFS"|"ENTITY"|"ENTITIES"|"NMTOKEN"|"NMTOKENS"
nom		   {debutnom}{caracnom}*
comment     {inf}"!--"([^-]|"-"[^-])*"--"{sup}
chaine      \"([^"&]|{echap})*\"|\'([^'&]|{echap})*\'
element     {inf}"!ELEMENT"{esp}
listeatt    {inf}"!ATTLIST"{esp}
declaration "#"("REQUIRED"|"IMPLIED"){esp}?
fixed       "#FIXED"{esp}
pcdata      "#PCDATA"{esp}?
cdata       "CDATA"{esp}?
ptint       "?"
ast         "*"
plus        "+"
empty       "EMPTY"
any         "ANY"

%s DEDANS

/* 
   INITIAL : en dehors d'un bloc ELEMENT ou ATTLIST
   DEDANS : dans un bloc ELEMENT ou ATTLIST
*/

%%

<INITIAL>{esp}		           { /* les espaces ne comptent pas */}
<INITIAL>{element}           { BEGIN(DEDANS); return ELEMENT; }
<INITIAL>{listeatt}          { BEGIN(DEDANS); return ATTLIST; }
<DEDANS>{sup}                { BEGIN(INITIAL); return SUP; }
<DEDANS>{ouvrepar}           { return OUVREPAR; }
<DEDANS>{fermepar}{esp}?     { return FERMEPAR; }
<DEDANS>{virgule}{esp}?      { return VIRGULE; }
<DEDANS>{barre}{esp}?        { return BARRE; }
<DEDANS>{declaration}        { stringreturn(DECLARATION); }
<DEDANS>{fixed}              { stringreturn(FIXED); }
<DEDANS>{ast}                { return AST ; }
<DEDANS>{ptint}              { return PTINT ; }
<DEDANS>{plus}               { return PLUS ; }
<DEDANS>{empty}              { return EMPTY; }
<DEDANS>{any}                { return ANY; }
<DEDANS>{pcdata}             { stringreturn(PCDATA); }
<DEDANS>{cdata}              { stringreturn(CDATA); }
<DEDANS>{chaine}             { stringreturn(DTDVALEUR); }
<DEDANS>{tokentype}{esp}?    { stringreturn(TOKENTYPE); }
<DEDANS>{nom}{esp}?          { stringreturn(DTDNOM); }
{comment}		              { /* les commentaires sont ignorés */ }

.			{fprintf(stderr, "!ERROR(%c)\n", *YYTEXT);}
