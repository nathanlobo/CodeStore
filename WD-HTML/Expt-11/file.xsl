<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
        <body>
        <h2>Top Youtube Channel</h2>
        <table border="1">
            <tr bgcolor="#9acd32">
                <th>Channel</th>
                <th>Subs</th>
            </tr>
            <xsl:for-each select="top_youtube_channels/cd">
            <tr>
                <td><xsl:value-of select="channel"/></td>
                <td><xsl:value-of select="subs"/></td>
            </tr>
            </xsl:for-each>
        </table>
        </body>
        </html>
    </xsl:template>
</xsl:stylesheet>