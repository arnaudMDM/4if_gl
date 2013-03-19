XMLO=lex.xml.o xml.tab.o
DTDO=dtd.tab.o lex.dtd.o

XMLSTRUCTPATH=xml/structureXML/
XMLSTRUCT= $(XMLSTRUCTPATH)AttributXML.h $(XMLSTRUCTPATH)ElementBalise.cpp $(XMLSTRUCTPATH)ElementTexte.h $(XMLSTRUCTPATH)AbstractElement.h $(XMLSTRUCTPATH)Document.cpp $(XMLSTRUCTPATH)ElementBalise.h $(XMLSTRUCTPATH)makefile $(XMLSTRUCTPATH)AttributXML.cpp $(XMLSTRUCTPATH)Document.h $(XMLSTRUCTPATH)ElementTexte.cpp

DTDSTRUCTPATH=dtd/structureDTD/
DTDSTRUCT=$(DTDSTRUCTPATH)AttributDTD.cpp $(DTDSTRUCTPATH)DocumentDTD.cpp $(DTDSTRUCTPATH)ElementDTD.cpp $(DTDSTRUCTPATH)makefile $(DTDSTRUCTPATH)AttributDTD.h $(DTDSTRUCTPATH)DocumentDTD.h $(DTDSTRUCTPATH)ElementDTD.h

EXEC=analyse

all: $(EXEC)
$(EXEC): analyseXML analyseDTD structureXML structureDTD main.c makefile
	g++ -g -o $(EXEC) *.o main.c
analyseXML: xml/*.l xml/*.y xml/makefile
	echo "xml FILE OK"
	cd xml; make all
analyseDTD: dtd/*.l dtd/*.y dtd/makefile
	cd dtd; make all
structureXML: $(XMLSTRUCT)
	cd xml/structureXML; make all
structureDTD: $(DTDSTRUCT)
	cd dtd/structureDTD; make all
clean:
	rm -rf *.o analyse
	cd xml; make clean
	cd dtd; make clean
	cd $(XMLSTRUCTPATH); make clean
	cd $(DTDSTRUCTPATH); make clean
