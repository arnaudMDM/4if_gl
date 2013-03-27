<xsl:stylesheet version="1.0">
<xsl:template match="/">
<hl>
<xsl:apply-templates/>
<hl>
</xsl:template>
<xsl:template match="address">
<xsl:apply-templates/>
</xsl:template>
</xsl:stylesheet>
