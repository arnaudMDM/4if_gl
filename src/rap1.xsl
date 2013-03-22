<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">


<xsl:template match="/">
<html>
<head>
<title>XML XSL Example</title>
<style type="text/css">
body
{
margin:10px;
background-color:#ccff00;
font-family:verdana,helvetica,sans-serif;
}

.tutorial-name
{
display:block;
font-weight:bold;
}

.tutorial-url
{
display:block;
color:#636363;
font-size:small;
font-style:italic;
}
</style>
</head>
<body>
 <xsl:apply-templates/>
</body>
</html>
</xsl:template>

<xsl:template match="//auteur">
  <p>
  <xsl:apply-templates select="./nom"/>
  <xsl:apply-templates select="./prenom"/>
  </p>
</xsl:template>

<xsl:template match="//auteur/nom">
  Nom: <span style="color:#ff0000">
  <xsl:value-of select="."/></span>
  <br />
</xsl:template>

<xsl:template match="//auteur/prenom">
  Prenom: <span style="color:#00ff00">
  <xsl:value-of select="."/></span>
  <br />
</xsl:template>


</xsl:stylesheet>
