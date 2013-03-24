#!/bin/bash

lot1OK="01TestsXML/01Ok.xml"
lot1KO="01TestsXML/02ErreurBalise.xml 01TestsXML/03ErreurNomBalise.xml"

lot2OK="02TestsDTD"
lot2KO=""

lot3OK=""
lot3KO=""

lot4OK=""
lot4KO=""

erreur=0

option="-cxml"

for fichier in lot1OK
do
	../analyse $option $fichier
	if [$? -ne 0]
	then
		echo "Résultat inattendu pour $fichier"
		erreur=1
	fi
done


