all: analyse
analyse: dtd.tab.o lex.dtd.o lex.xml.o xml.tab.o analyseXML analyseDTD structureXML structureDTD main.c makefile
	g++ -g -o analyse *.o main.c
analyseXML: xml/*.l xml/*.y xml/makefile
	echo "xml FILE OK"
	cd xml; make all
analyseDTD: dtd/*.l dtd/*.y dtd/makefile
	cd dtd; make all
structureXML: AbstractElement.o Document.o ElementTexte.o AttributXML.o ElementBalise.o
	cd xml/structureXML; make all
structureDTD: ElementDTD.o AttributDTD.o DocumentDTD.o
	cd dtd/structureDTD; make all
clean:
	rm -rf *.o analyse
	cd xml; make clean
	cd dtd; make clean
	cd xml/structureXML; make clean
	cd xml/structureDTD; make clean
