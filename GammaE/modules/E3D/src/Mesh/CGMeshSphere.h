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
#ifndef CGMesh_SphereH
#define CGMesh_SphereH
// ----------------------------------------------------------------------------
#include "Mesh\CGMesh.h"
// ----------------------------------------------------------------------------
class CGMeshSphere : public CGMesh
{
    public:
        CGMeshSphere();

        CGMeshSphere (int _iNumSlices, float _fRadius);

        ~CGMeshSphere();

    protected:

        void Init(int _iNumSlices, float _fRadius);

    private:

    private:
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
