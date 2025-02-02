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
#ifndef CDefferredMeshDBH
#define CDefferredMeshDBH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "GammaE_Math.h"

// ----------------------------------------------------------------------------

class CGShader;
class CGBaseMesh;

// ----------------------------------------------------------------------------
class CGDefferredMeshEntry
{
    public:

        // / The geometry itself
        CGBaseMesh* poMesh;

        // / Precomputed matrix for this object (Camera * Model)
        CGMatrix4x4 oMatrix;

        // / Shader to render this mesh
        CGShader* poShader;

        // / Number of lights (???)
        uint uiLights;
};
// ----------------------------------------------------------------------------
class CGDefferredMeshDB
{
    public:

        CGDefferredMeshDB();
        ~CGDefferredMeshDB();

        // / Initialize the deferred object database to a maximum of elements
        void Init(uint _uiMaxEntries = 1024);

        // / Inserts an object in the database
        bool bInsertDefferredObject(CGBaseMesh* _poMesh,CGShader* _poShader,const CGMatrix4x4& _oMatrix,uint _uiLights);

        // / Clears all the elements at a given moment of the database
        void Invalidate();

        // / Retrieves the given object in the database
        const CGDefferredMeshEntry& oGetObject(uint _uiEntry);

        // / Retrieves the total amount of objects in the database
        uint uiNumObjects();

        // / Performs the sorting of the elements of the database
        void Sort();

    protected:
        // / The database structure
        CGStArray <CGDefferredMeshEntry> m_oMeshDB;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
