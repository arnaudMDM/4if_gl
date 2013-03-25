%option 8bit nodefault
%option noyywrap

%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "commun.h"
#include "structureXSL/DocumentXSL.h"
#include "xsl.tab.h"

// si vous activez l'option -P de flex, changez les deux lignes suivantes
#define YYTEXT xsltext
#define YYLVAL xsllval
// exemple avec -Pxml
//#define YYTEXT xmltext
//#define YYLVAL xmllval

// supprime les espaces en début et fin de chaine
static char* supprimeEspaces(char *s) {
  char *buf;
  int i,lastnonspace;
  for (buf=s;isspace(*buf);buf++) ;
  for (i=0,lastnonspace=0;buf[i];i++) {
     if (!isspace(buf[i]))
        lastnonspace = i;
  }
  buf[lastnonspace+1] = '\0';
  return buf;
}

// enlève les " au début et à la fin
static char * enleveGuillemets(char *s) {
   s++;
   s[strlen(s)-1] = '\0';
   return s;
}

// extrait le mot
static char* mot(char *s)
{
  char *buf;
  int i, k;
  for (k = 0; !isalpha(s[k]); k++) ;
  for (i = k; isalpha(s[i])||s[i]=='-'; i++) ;
  buf = (char *) malloc((i - k + 1) * sizeof(char));
  strncpy(buf, &s[k], i - k);
  buf[i - k] = '\0';
  return buf;
}

/* extrait la première partie, l'espace de nom */
static char * espaceDeNom(char *s)  
{
   char *name;
   int i,k;
   for (k = 0; isspace(s[k]) || s[k]=='<' || s[k]=='/'; k++) ;
   for (i=k;s[i]!=':';i++) ;
   name = (char*) malloc((i-k+1)*sizeof(char));
   strncpy(name,s+k,i-k);
   name[i-k] = '\0';
   return name;
}

/* extrait la deuxième partie après l'espace de nom */
static char * separeNom(char *s) 
{ 
   char *name;
   int i,k;
   for (i=0;s[i]!=':';i++) ;
   i++;
   name = (char*) malloc((strlen(s+i)+1)*sizeof(char));
   strcpy(name,s+i);
   return name;
}

%}

nl		(\r\n|\r|\n)
esp		[ \t\r\n]+
inf		{esp}?"<"
sup		">"{nl}?
debutnom	[A-Za-z\200-\377_]
caracnom	[A-Za-z\200-\377_0-9.-]
esc		"&#"[0-9]+";"|"&#x"[0-9a-fA-F]+";"
nom		{debutnom}{caracnom}*
comment		{inf}"!--"([^-]|"-"[^-])*"--"{sup}
chaine		\"([^"&]|{esc})*\"|\'([^'&]|{esc})*\'
xsl "xsl:"
stylesheet "stylesheet"
template "template"
applytemplates "apply-templates"
data (([^<])|("<"[^/x])|("<x"[^s])|("<xs"[^l])|("</"[^x])|("</x"[^s])|("</xs"[^l]))+

/*
 * Le mode CONTENU est utilisé entre les balises ouvrantes et fermantes
 * Le mode INITIAL est utilisé en dehors de la balise racine ou entre les < >
 */

%s CONTENU

%%

<INITIAL>{esp}		{/* skip */}
<INITIAL>"/"		{return SLASH;}
<INITIAL>"="		{return EGAL;}
<INITIAL>{sup}	{BEGIN(CONTENU); return SUP;}
<INITIAL>{nom}		{YYLVAL.s = strdup(YYTEXT); return NOM;}
<INITIAL>{chaine}	{YYLVAL.s = strdup(enleveGuillemets(YYTEXT)); return VALEUR;}

{inf}{xsl}{stylesheet}	{BEGIN(INITIAL); YYLVAL.s = separeNom(YYTEXT); return OSTYLESHEET;}
{inf}{xsl}{template}  {BEGIN(INITIAL); YYLVAL.s = separeNom(YYTEXT); return OTEMPLATE;}
{inf}{xsl}{applytemplates}  {BEGIN(INITIAL); YYLVAL.s = separeNom(YYTEXT); return OAPPLYTEMPLATES;}
{inf}"/"{xsl}{stylesheet}		{BEGIN(INITIAL); YYLVAL.s = separeNom(YYTEXT); return FSTYLESHEET;}
{inf}"/"{xsl}{template}    {BEGIN(INITIAL); YYLVAL.s = separeNom(YYTEXT); return FTEMPLATE;}

{comment}		{YYLVAL.s = strdup(YYTEXT); return COMMENT;}

<CONTENU>{esp}?{data}    {YYLVAL.s = strdup(supprimeEspaces(YYTEXT)); return DATA;}

.			{fprintf(stderr, "!ERROR(%c)\n", *YYTEXT);}
