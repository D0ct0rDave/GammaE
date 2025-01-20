//## begin module%3B65CB11028A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B65CB11028A.cm

//## begin module%3B65CB11028A.cp preserve=no
//## end module%3B65CB11028A.cp

//## Module: CHTMLParser%3B65CB11028A; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\CHTMLParser.cpp

//## begin module%3B65CB11028A.additionalIncludes preserve=no
//## end module%3B65CB11028A.additionalIncludes

//## begin module%3B65CB11028A.includes preserve=yes
//## end module%3B65CB11028A.includes

// CHTMLParser
#include "CHTMLParser.h"
#include <ekhtml.h>
//## begin module%3B65CB11028A.additionalDeclarations preserve=yes

// #include "Game/GameGlobals/globals.h"

//## end module%3B65CB11028A.additionalDeclarations

static CHUD* s_poHUD = NULL;
static char* s_szRootDir = NULL;
// --------------------------------------------------------------
static char s_szStr[1024];
char* szHTMLStr(ekhtml_string_t& str)
{
	memcpy(s_szStr,str.str,str.len);
	s_szStr[str.len] = 0;

	return(s_szStr);
}
static char s_szStr2[1024];
char* szFullFilename(char* _szFilename)
{
	sprintf(s_szStr2,"%s/%s",s_szRootDir,_szFilename);
	return(s_szStr2);
}
// --------------------------------------------------------------
static void handle_starttag_way(void *cbdata, ekhtml_string_t *tag, ekhtml_attr_t *attrs)
{
    CSystemLC::I()->Write("GOT WAY START!\n");
}

static void handle_starttag(void *cbdata, ekhtml_string_t *tag, ekhtml_attr_t *attrs)
{
    ekhtml_attr_t *attr;
/*
    tester_cbdata *tdata = cbdata;
    
    assert(tdata->magic_doodie == MAGIC_DOODIE);
    tdata->n_starttags++;
    if(tdata->only_parse)
        return;
*/    
    CSystemLC::I()->Write("START: \"%.*s\"\n", tag->len, tag->str);
    for(attr=attrs; attr; attr=attr->next)
    {
        CSystemLC::I()->Write("ATTRIBUTE: \"%.*s\" = ", attr->name.len, attr->name.str);

        if(! attr->isBoolean)
            CSystemLC::I()->Write("\"%.*s\"\n", attr->val.len, attr->val.str);
        else
            CSystemLC::I()->Write("\"%.*s\"\n", attr->name.len, attr->name.str);

		// Body tag    
		if (! stricmp(szHTMLStr(*tag),"BODY"))
		{
			// body attributes
			if (! stricmp(szHTMLStr(attr->name),"style"))
			{
				//
			}
		}

		// Image tag

	else if (! stricmp(szHTMLStr(*tag),"IMG"))
		{
			// body attributes
			if (! stricmp(szHTMLStr(attr->name),"src"))
			{
				char* szStr = szFullFilename( szHTMLStr(attr->val) );
				CHUDIcon* poIcon = mNew CHUDIcon();
				poIcon->SetIcon( CE3D_ShaderWH::I()->poCreateShader( szStr ) );
				
				
				// Hay que concatenar el directorio data/textures a las strings de las imágenes
			}
		}
	}
}

static void handle_endtag(void *cbdata, ekhtml_string_t *str){
/*
    tester_cbdata *tdata = cbdata;
    
    assert(tdata->magic_doodie == MAGIC_DOODIE);
    tdata->n_endtags++;
    if(tdata->only_parse)
        return;
*/    
    CSystemLC::I()->Write("END: \"%.*s\"\n", str->len, str->str);
}

static void handle_comment(void *cbdata, ekhtml_string_t *str){
/*
    tester_cbdata *tdata = cbdata;
    
    assert(tdata->magic_doodie == MAGIC_DOODIE);
    tdata->n_comments++;
    if(tdata->only_parse)
        return;
*/    
    CSystemLC::I()->Write("COMMENT: \"%.*s\"\n", str->len, str->str);
}

static void handle_data(void *cbdata, ekhtml_string_t *str){
/*
    tester_cbdata *tdata = cbdata;
    
    assert(tdata->magic_doodie == MAGIC_DOODIE);
    tdata->n_data++;
    if(tdata->only_parse)
        return;
*/    
    fwrite(str->str, str->len, 1, stdout);
}

//## Other Operations (implementation)
CObject3D* CHTMLParser::poInit(char* _szFilename,char* _szRootDir)
{
  //## begin CHTMLParser::InitScene%997655858.body preserve=yes
	s_szRootDir = _szRootDir;
    char *szFile = ParseUtils_ReadFile( szFullFilename(_szFilename) );

	if (! szFile)
	{
		return(NULL);
	}
	
	
	s_poHUD = mNew CHeadUpDisplay(100);


	ekhtml_parser_t *ekparser;
    char *buf;
    size_t nbuf;
    int feedsize;

    ekparser = ekhtml_parser_new(NULL);
    
    ekhtml_parser_datacb_set(ekparser, handle_data);
    ekhtml_parser_commentcb_set(ekparser, handle_comment);
    ekhtml_parser_startcb_add(ekparser, "WAY", handle_starttag_way);
    ekhtml_parser_startcb_add(ekparser, NULL, handle_starttag);
    ekhtml_parser_endcb_add(ekparser, NULL, handle_endtag);
    
    // ekhtml_parser_cbdata_set(ekparser, &cbdata);
    
    //
	char *szLine      = szFile;
	char *szNextLine  = szFile;
	    
	while (*szLine)
	{
		ekhtml_string_t str;

        str.str = szLine;
        str.len = strlen(szLine);

        ekhtml_parser_feed(ekparser, &str);
        ekhtml_parser_flush(ekparser, 0);

		NextLine(szLine,szNextLine);
		szLine = szNextLine;
	}
	   
    ekhtml_parser_flush(ekparser, 1);
    ekhtml_parser_destroy(ekparser);

	mFree(szFile);
    
    return(s_poHUD);
  //## end CHTMLParser::InitScene%997655858.body
}

// Additional Declarations
  //## begin CHTMLParser%3B65CB11028A.declarations preserve=yes
  //## end CHTMLParser%3B65CB11028A.declarationsT

//## begin module%3B65CB11028A.epilog preserve=yes
//## end module%3B65CB11028A.epilog
