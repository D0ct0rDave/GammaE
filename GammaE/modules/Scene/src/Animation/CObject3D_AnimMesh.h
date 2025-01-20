//	  %X% %Q% %Z% %W%



#ifndef CObject3D_AnimMesh_h
#define CObject3D_AnimMesh_h 1



// CObject3D_Leaf
#include "CObject3D_Leaf.h"
// CObject3D_AnimGen
#include "Animation\CObject3D_AnimGen.h"




class CObject3D_AnimMesh : public CObject3D_AnimGen
{
	public:
        CObject3D_AnimMesh();

        virtual ~CObject3D_AnimMesh();


		virtual void SetAnimState (int _iSrc, int _iDst, float _fFactor);

        virtual void CreateStates (int _iNumStates, int _iNumStateVXs);

        virtual void Render ();

        virtual CGraphBV* poGetBoundVol ();

        virtual void ComputeBoundVol ();

        void SetLeaf (CObject3D_Leaf *_pLeafMesh);

        virtual CGraphBV * poGetStateBVol (int _iState);

        int iGetNumStateVXs ();

    
        CObject3D_Leaf * GetLeaf ();

    // Data Members for Class Attributes

        CVect3 *pMeshStates;
      
        CVect3 *pNMeshStates;
      
        int iNumStateVXs;
      
        CGraphBV* *pBVolStates;
      
    // Data Members for Associations

        CObject3D_Leaf *Leaf;
};


// Class CObject3D_AnimMesh 


inline int CObject3D_AnimMesh::iGetNumStateVXs ()
{
  	return (iNumStateVXs);
}


inline CObject3D_Leaf * CObject3D_AnimMesh::GetLeaf ()
{
    return Leaf;
}



#endif
