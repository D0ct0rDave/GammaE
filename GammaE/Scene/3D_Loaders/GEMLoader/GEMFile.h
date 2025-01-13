//---------------------------------------------------------------------------
#ifndef GEMFileH
#define GEMFileH
//---------------------------------------------------------------------------
#include "Scene/e3DObjectTypeID.h"

#define				GEM_FILE_IDENTIFIER			MAKE_RIFF_ID('G','E','M','D')

#define				GEM_MAJOR_VERSION			1
#define				GEM_MINOR_VERSION			0

#define				GEM_MESH_IDENTIFIER			MAKE_RIFF_ID('M','E','S','H')

inline unsigned int GEMFile_Translate_TypeID2FileID(unsigned int uiTypeID)
{
	switch (uiTypeID)
	{		
		case e3DObj_NULL:			return ( MAKE_RIFF_ID('N','U','L','L') );
		case e3DObj_Gen:			return ( MAKE_RIFF_ID('G','E','N',' ') );
		case e3DObj_Leaf:			return ( MAKE_RIFF_ID('L','E','A','F') );
		case e3DObj_Node:			return ( MAKE_RIFF_ID('N','O','D','E') );
		
		// Animation nodes
		case e3DObj_AnimGen:		return ( MAKE_RIFF_ID('A','G','E','N') );
		case e3DObj_AnimNode:		return ( MAKE_RIFF_ID('A','N','O','D') );		
		case e3DObj_AnimMesh:		return ( MAKE_RIFF_ID('A','M','S','H') );
		case e3DObj_AnimTransf:		return ( MAKE_RIFF_ID('A','T','R','A') );
		case e3DObj_AnimCfg:		return ( MAKE_RIFF_ID('A','C','F','G') );
		case e3DObj_AnimCfgMgr:		return ( MAKE_RIFF_ID('A','C','M','G') );

		case e3DObj_Camera:			return ( MAKE_RIFF_ID('C','A','M',' ') );
		case e3DObj_BSPNode:		return ( MAKE_RIFF_ID('B','S','P','N') );
		case e3DObj_Mux:			return ( MAKE_RIFF_ID('M','U','X',' ') );
		default:	return (0);
	}

}	

inline unsigned int GEMFile_Translate_FileID2TypeID2(unsigned int uiFileID)
{
	switch (uiFileID)
	{		
		case MAKE_RIFF_ID('N','U','L','L'):	return ( e3DObj_NULL		 );		
		case MAKE_RIFF_ID('G','E','N',' '): return ( e3DObj_Gen			 );
		case MAKE_RIFF_ID('L','E','A','F'): return ( e3DObj_Leaf		 );
		case MAKE_RIFF_ID('N','O','D','E'): return ( e3DObj_Node		 );		

		// Animation nodes
		case MAKE_RIFF_ID('A','G','E','N'):	return ( e3DObj_AnimGen      );
		case MAKE_RIFF_ID('A','N','O','D'):	return ( e3DObj_AnimNode     );
		case MAKE_RIFF_ID('A','M','S','H'):	return ( e3DObj_AnimMesh     );
		case MAKE_RIFF_ID('A','T','R','A'):	return ( e3DObj_AnimTransf   );
		case MAKE_RIFF_ID('A','C','F','G'):	return ( e3DObj_AnimCfg		 );
		case MAKE_RIFF_ID('A','C','M','G'):	return ( e3DObj_AnimCfgMgr	 );
		
		case MAKE_RIFF_ID('C','A','M',' '): return ( e3DObj_Camera		 );
		case MAKE_RIFF_ID('B','S','P','N'): return ( e3DObj_BSPNode		 );		
		case MAKE_RIFF_ID('M','U','X',' '): return ( e3DObj_Mux          );

		default:	return (0);
	}
}	

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------