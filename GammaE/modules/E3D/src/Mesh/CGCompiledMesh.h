// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CCompiledMeshH
#define CCompiledMeshH
// ----------------------------------------------------------------------------
#include "Mesh\CGBaseMesh.h"
#include "GammaE_Math.h"
// ----------------------------------------------------------------------------
class CGCompiledMesh : public CGBaseMesh
{
    public:
        CGCompiledMesh();
        ~CGCompiledMesh();

        // / Sets up the compiled mesh
        void Init(handler _hHandler,E3D_PrimitiveType _ePrimitiveType,uint _uiNumVXs,uint _uiNumPrims)
        {
            m_hHandler = _hHandler;
            m_uiNumVXs = _uiNumVXs;
            m_uiNumPrims = _uiNumPrims;
            m_ePrimitiveType = _ePrimitiveType;
        }

        // / Retrieves the handler of this compiled mesh
        handler hGetHandler()
        {
            return(m_hHandler);
        }

    protected:

        handler m_hHandler;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
