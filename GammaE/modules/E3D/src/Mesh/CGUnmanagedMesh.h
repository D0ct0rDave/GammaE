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
#ifndef CGUnmanagedMeshH
#define CGUnmanagedMeshH
// ----------------------------------------------------------------------------
#include "Mesh\CGMesh.h"
// ----------------------------------------------------------------------------
class CGUnmanagedMesh : public CGMesh
{
public:
    ~CGUnmanagedMesh();

    // / This allows the user to setup programatically the number of vertices
    void SetNumVXs(uint _uiNumVXs);

    // / This allows the user to setup programatically the number of primitives
    void SetNumPrims(uint _uiNumPrims);

    // / This allows the user to setup programatically the mesh type
    void SetPrimitiveType(E3D_PrimitiveType _eMeshType);
    
    ///  Points the all internal unmanaged data to the given mesh data
    void Link(CGMesh* _poMesh);

protected:
    void ComputeNumberOfIndices();

protected:

    uint m_uiMaxVXs;
    uint m_uiMaxPrims;
};

// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
