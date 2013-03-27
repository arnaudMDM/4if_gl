#!/bin/bash

lot1OK="01TestsXML/01Ok.xml"
lot1KO="01TestsXML/02ErreurBalise.xml 01TestsXML/03ErreurNomBalise.xml"

lot2OK="02TestsDTD/01Ok.dtd 02Ok(desordreOk).dtd 02TestsDTD/05OkDesordreAttributs.dtd"
lot2KO="02TestsDTD/03ElementAuteurManquant.dtd 02TestsDTD/04ErreurBalise.dtd 02TestsDTD/06ErreurAttributManquant.dtd"

lot3OK="03TestsConformes/01Ok.xml 03TestsConformes/04OkOrdreDif.xml"
lot3KO="03TestsConformes/02Ok.xml 03TestsConformes/03Ok.xml 03TestsConformes/05XmlNonConforme.xml"

lot4OK="04TestsXSL/01Ok.xsl"
lot4KO="04TestsXSL/erreurBalise2.xsl 04TestsXSL/noStylesheet.xsl 04TestsXSL/ordreStylesheet.xsl"

erreur=0

nbTest=0
nbTestReussi=0

option="-cxml"
resultat=0

for fichier in $lot1OK
do
	nbTest=`expr $nbTest + 1`
	echo "../analyse $option $fichier"
	../analyse $option $fichier > /dev/null 2> /dev/null
	if [ $? -ne $resultat ]
	then
		echo "$fichier : résultat inattendu"
		erreur=1
	else
		nbTestReussi=`expr $nbTestReussi + 1`
		echo "$fichier : OK"
	fi
	echo
done

resultat=1

for fichier in $lot1KO
do
	nbTest=`expr $nbTest + 1`
	echo "../analyse $option $fichier"
	../analyse $option $fichier > /dev/null 2> /dev/null
	if [ $? -ne $resultat ]
	then
		echo "$fichier : résultat inattendu"
		erreur=1
	else
		nbTestReussi=`expr $nbTestReussi + 1`
		echo "$fichier : OK"
	fi
	echo
done

option="-cdtd"
resultat=0

for fichier in $lot2OK
do
	nbTest=`expr $nbTest + 1`
	echo "../analyse $option $fichier"
	../analyse $option $fichier > /dev/null 2> /dev/null
	if [ $? -ne $resultat ]
	then
		echo "$fichier : résultat inattendu"
		erreur=1
	else
		nbTestReussi=`expr $nbTestReussi + 1`
		echo "$fichier : OK"
	fi
	echo
done

resultat=1

for fichier in $lot2KO
do
	nbTest=`expr $nbTest + 1`
	echo "../analyse $option $fichier"
	../analyse $option $fichier > /dev/null 2> /dev/null
	if [ $? -ne $resultat ]
	then
		echo "$fichier : résultat inattendu"
		erreur=1
	else
		nbTestReussi=`expr $nbTestReussi + 1`
		echo "$fichier : OK"
	fi
	echo
done

option="-check"
resultat=0

for fichier in $lot3OK
do
	nbTest=`expr $nbTest + 1`
	echo "../analyse $option $fichier"
	../analyse $option $fichier > /dev/null 2> /dev/null
	if [ $? -ne $resultat ]
	then
		echo "$fichier : résultat inattendu"
		erreur=1
	else
		nbTestReussi=`expr $nbTestReussi + 1`
		echo "$fichier : OK"
	fi
	echo
done

resultat=1

for fichier in $lot3KO
do
	nbTest=`expr $nbTest + 1`
	echo "../analyse $option $fichier"
	../analyse $option $fichier > /dev/null 2> /dev/null
	if [ $? -ne $resultat ]
	then
		echo "$fichier : résultat inattendu"
		erreur=1
	else
		nbTestReussi=`expr $nbTestReussi + 1`
		echo "$fichier : OK"
	fi
	echo
done

option="-cxsl"
resultat=0

for fichier in $lot4OK
do
	nbTest=`expr $nbTest + 1`
	echo "../analyse $option $fichier"
	../analyse $option $fichier > /dev/null 2> /dev/null
	if [ $? -ne $resultat ]
	then
		echo "$fichier : résultat inattendu"
		erreur=1
	else
		nbTestReussi=`expr $nbTestReussi + 1`
		echo "$fichier : OK"
	fi
	echo
done

resultat=1

for fichier in $lot4KO
do
	nbTest=`expr $nbTest + 1`
	echo "../analyse $option $fichier"
	../analyse $option $fichier > /dev/null 2> /dev/null
	if [ $? -ne $resultat ]
	then
		echo "$fichier : résultat inattendu"
		erreur=1
	else
		nbTestReussi=`expr $nbTestReussi + 1`
		echo "$fichier : OK"
	fi
	echo
done

echo $nbTestReussi " tests sur " $nbTest " sont passés"