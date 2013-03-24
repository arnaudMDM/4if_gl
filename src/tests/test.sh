#!/bin/bash

lot1OK="01TestsXML/01Ok.xml"
lot1KO="01TestsXML/02ErreurBalise.xml 01TestsXML/03ErreurNomBalise.xml"

lot2OK=""
lot2KO=""

lot3OK=""
lot3KO=""

lot4OK=""
lot4KO=""

erreur=0

option="-cxml"
resultat=0

for fichier in $lot1OK
do
	../analyse $option $fichier > /dev/null 2> /dev/null
	if [ $? -ne $resultat ]
	then
		echo "$fichier : résultat inattendu"
		erreur=1
	else
		echo "$fichier : OK"
	fi
done

resultat=1

for fichier in $lot1KO
do
	../analyse $option $fichier > /dev/null 2> /dev/null
	if [ $? -ne $resultat ]
	then
		echo "$fichier : résultat inattendu"
		erreur=1
	else
		echo "$fichier : OK"
	fi
done

option="-cdtd"
resultat=0

for fichier in $lot2OK
do
	../analyse $option $fichier > /dev/null 2> /dev/null
	if [ $? -ne $resultat ]
	then
		echo "$fichier : résultat inattendu"
		erreur=1
	else
		echo "$fichier : OK"
	fi
done

resultat=1

for fichier in $lot2KO
do
	../analyse $option $fichier > /dev/null 2> /dev/null
	if [ $? -ne $resultat ]
	then
		echo "$fichier : résultat inattendu"
		erreur=1
	else
		echo "$fichier : OK"
	fi
done

option="-check"
resultat=0

for fichier in $lot3OK
do
	../analyse $option $fichier > /dev/null 2> /dev/null
	if [ $? -ne $resultat ]
	then
		echo "$fichier : résultat inattendu"
		erreur=1
	else
		echo "$fichier : OK"
	fi
done

resultat=1

for fichier in $lot3KO
do
	../analyse $option $fichier > /dev/null 2> /dev/null
	if [ $? -ne $resultat ]
	then
		echo "$fichier : résultat inattendu"
		erreur=1
	else
		echo "$fichier : OK"
	fi
done

option="-cxsl"
resultat=0

for fichier in $lot4OK
do
	../analyse $option $fichier > /dev/null 2> /dev/null
	if [ $? -ne $resultat ]
	then
		echo "$fichier : résultat inattendu"
		erreur=1
	else
		echo "$fichier : OK"
	fi
done

resultat=1

for fichier in $lot4KO
do
	../analyse $option $fichier > /dev/null 2> /dev/null
	if [ $? -ne $resultat ]
	then
		echo "$fichier : résultat inattendu"
		erreur=1
	else
		echo "$fichier : OK"
	fi
done
