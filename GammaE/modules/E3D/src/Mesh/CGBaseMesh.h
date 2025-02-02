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
#ifndef CGBaseMeshH
#define CGBaseMeshH
// ----------------------------------------------------------------------------
#include "GammaE_Math.h"
#include "GammaE_Misc.h"
#include "E3D_Enums.h"
#include "GraphBV/CGGraphBV.h"
// ----------------------------------------------------------------------------
class CGBaseMesh
{
    public:

        // / Default constructor for the base mesh
        CGBaseMesh();

        // / Sets the bounding volume for to this mesh
        void SetBV(CGGraphBV* _poBV)
        {
            m_poBV = _poBV;
        }

        // / Retrieves the bounding volume associated to this mesh
        CGGraphBV* poGetBV() const
        {
            return(m_poBV);
        }

        // / Retrieves the type of this mesh object
        E3D_MeshType eGetType() const
        {
            return(m_eMeshType);
        }

        // / Retrieves the primitive type used by the mesh
        E3D_PrimitiveType eGetPrimitiveType() const
        {
            return (m_ePrimitiveType);
        }

        // / Retrieves the number of primitives in the mesh
        uint uiGetNumPrims() const
        {
            return (m_uiNumPrims);
        }

        // / Retrieves the number of vertices in the mesh
        uint uiGetNumVXs() const
        {
            return (m_uiNumVXs);
        }
             
        // / Retrieves the number of indices in the mesh
        uint uiGetNumIndices() const
        {
            return (m_uiNumIdxs);
        }
        
    protected:

        E3D_MeshType m_eMeshType;
        CGGraphBV* m_poBV;
        uint m_uiNumVXs;
        uint m_uiNumPrims;
        uint m_uiNumIdxs;
        E3D_PrimitiveType m_ePrimitiveType;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
