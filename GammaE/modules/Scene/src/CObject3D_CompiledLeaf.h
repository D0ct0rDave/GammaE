//	  %X% %Q% %Z% %W%

#ifndef CObject3D_CompiledLeaf_h
#define CObject3D_CompiledLeaf_h 1

// CObject3D
#include "CObject3D.h"

class CObject3D_CompiledLeaf : public CObject3D
{
public: CObject3D_CompiledLeaf();

    virtual ~CObject3D_CompiledLeaf();

    virtual void Render ();

    void SetCMesh (CCompiledMesh *_poCMesh);

    virtual CGraphBV *poCreateBoundVol ()
    {
        return( CGraphBV_Manager::poCreate() );
    };

    CCompiledMesh *poGetCMesh ();

    virtual CGraphBV *poGetBoundVol ();

    virtual void ComputeBoundVol ();

    void SetShader (CE3D_Shader *_poShader);

    CE3D_Shader *poGetShader ();

     // Additional Public Declarations
protected:
     // Additional Protected Declarations
private:
    // Data Members for Class Attributes

    CCompiledMesh *poCMesh;

    CE3D_Shader *poShader;

     // Additional Private Declarations
private:
    // Additional Implementation Declarations
};

// Class CObject3D_CompiledLeaf

#endif // ifndef CObject3D_CompiledLeaf_h
