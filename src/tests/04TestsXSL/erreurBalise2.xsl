<?xml version='1.0'?>
<xsl:stylesheet version="1.0"
      xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <HTML>
    <BODY>
      <TABLE>
          <TR>
            <xsl:apply-templates select="//nom" />
            <xsl:apply-templates select="//prenom" />
            <xsl:apply-templates select="//titre" />
          </TR>
      </TABLE>
    </BODY>
  </HTML>
</xsl:template>

<xsl:template match="//nom">
  <TD STYLE="font-size:14pt font-family:serif">
    <xsl:apply-templates >
  </TD>
</xsl:template>

<xsl:template match="//prenom">
  <TD> <xsl:apply-templates /> </TD>
</xsl:template>

<xsl:template match="//titre">
  <TD> <xsl:apply-templates /> </TD>
</xsl:template>

<xsl:template match="text()">
  <xsl:value-of select='.'/>
</xsl:template>

</xsl:stylesheet>
