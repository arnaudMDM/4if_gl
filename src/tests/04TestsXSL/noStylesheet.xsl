<xsl:template match="/">
  <HTML>
    <BODY>
      <TABLE>
          <TR>
            <xsl:apply-templates />
          </TR>
      </TABLE>
    </BODY>
  </HTML>
</xsl:template>

<xsl:template match="nom">
  <TD STYLE="font-size:14pt font-family:serif">
    <xsl:apply-templates />
  </TD>
</xsl:template>

<xsl:template match="prenom">
  <TD> <xsl:apply-templates /> </TD>
</xsl:template>

<xsl:template match="titre">
  <TD> <xsl:apply-templates /> </TD>
</xsl:template>

