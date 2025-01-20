//## begin module%3B8B83190029.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8B83190029.cm

//## begin module%3B8B83190029.cp preserve=no
//## end module%3B8B83190029.cp

//## Module: CLoaderMD3%3B8B83190029; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\3D_Loaders\MD3Loader\CLoaderMD3.h

#ifndef CLoaderMD3_h
#define CLoaderMD3_h 1

//## begin module%3B8B83190029.additionalIncludes preserve=no
//## end module%3B8B83190029.additionalIncludes

//## begin module%3B8B83190029.includes preserve=yes
#include "MD3Model.h"
//## end module%3B8B83190029.includes

// CObject3D_Node
#include "Scene\CObject3D_Node.h"
// C3DLoader
#include "Scene\3D_Loaders\C3DLoader.h"
// SCNUt_AnimMesh_NormalComputer
#include "Scene\SceneUtils\ScnNormalGen\SCNUt_AnimMesh_NormalComputer.h"
// CObject3D_AnimCfgMgr
#include "Scene\Animation\CObject3D_AnimCfgMgr.h"
// CObject3D_AnimTransf
#include "Scene\Animation\CObject3D_AnimTransf.h"
// CObject3D_AnimMesh
#include "Scene\Animation\CObject3D_AnimMesh.h"
// CObject3D_AnimCfg
#include "Scene\Animation\CObject3D_AnimCfg.h"
// CObject3D_AnimNode
#include "Scene\Animation\CObject3D_AnimNode.h"
//## begin module%3B8B83190029.additionalDeclarations preserve=yes
//## end module%3B8B83190029.additionalDeclarations


//## begin CLoaderMD3%3B8B83190029.preface preserve=yes
//## end CLoaderMD3%3B8B83190029.preface

//## Class: CLoaderMD3%3B8B83190029
//## Category: Scene::3D_Loaders::MD3Loader%3B8B82FF01D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B9BF6F30093;CObject3D_Node { -> }
//## Uses: <unnamed>%3B9E8E030117;CObject3D_AnimMesh { -> }
//## Uses: <unnamed>%3B9E8E190000;CObject3D_AnimCfg { -> }
//## Uses: <unnamed>%3B9E92D60203;CObject3D_AnimTransf { -> }
//## Uses: <unnamed>%3BA52267001F;CObject3D_AnimCfgMgr { -> }
//## Uses: <unnamed>%3BA53AF40170;CObject3D_AnimNode { -> }
//## Uses: <unnamed>%3BA7C9F403C2;SCNUt_AnimMesh_NormalComputer { -> }

class CLoaderMD3 : public C3DLoader  //## Inherits: <unnamed>%3B8B832C02ED
{
  //## begin CLoaderMD3%3B8B83190029.initialDeclarations preserve=yes
  //## end CLoaderMD3%3B8B83190029.initialDeclarations

  public:
    //## Constructors (generated)
      CLoaderMD3();

    //## Destructor (generated)
      ~CLoaderMD3();


    //## Other Operations (specified)
      //## Operation: iParseSkinSentence%1000073571
      int iParseSkinSentence (char* _Buffer, char *SkinName, char *MeshName);

      //## Operation: LoadSkinInfo%1000073566
      void LoadSkinInfo (char* _Filename);

      //## Operation: poGetShader%1000073569
      CE3D_Shader * poGetShader (char *_szMeshName);

      //## Operation: CreateAnimTransfNode%1000332372
      CObject3D_AnimTransf* CreateAnimTransfNode (tag_t* _pTags, int _iNumTags, int _iTagStep);

      //## Operation: pCreateAnimMesh%1000073570
      CObject3D_AnimMesh * pCreateAnimMesh (mesh_header_t& _Header, skin_t &_Skin, Q3triangle_t *_Tris, vertice_t* _VXs, tex_coord_t* _UVs);

      //## Operation: pLoadModel%1000073567
      CObject3D * pLoadModel (char *Filename);

      //## Operation: pLoad%1000073568
      CObject3D * pLoad (char *_ModelName, char* _SkinName);

      //## Operation: pLoad%998998857
      virtual CObject3D * pLoad (char* Filename);

      //## Operation: pLoadQ3Player%1000046686
      CObject3D_AnimCfgGen * pLoadQ3Player (char* _Path, char* _SkinName);

      //## Operation: pLoadAnimation%1000758288
      CObject3D_AnimCfgMgr * pLoadAnimation (char *_Filename, CObject3D_AnimNode* _pLegs, CObject3D_AnimNode* _pTorso);

      //## Operation: SetupAnim%1000758289
      void SetupAnim (int _iAnimNum, anim_t *_MD3Anim, CObject3D_AnimCfg* _pLegs, CObject3D_AnimCfg* _pTorso);

    // Additional Public Declarations
      //## begin CLoaderMD3%3B8B83190029.public preserve=yes
      //## end CLoaderMD3%3B8B83190029.public

  protected:
    // Additional Protected Declarations
      //## begin CLoaderMD3%3B8B83190029.protected preserve=yes
      //## end CLoaderMD3%3B8B83190029.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: SkinBookmark%3B9BF1D302BE
      //## begin CLoaderMD3::SkinBookmark%3B9BF1D302BE.attr preserve=no  private: skin_file_t {UA} 
      skin_file_t SkinBookmark;
      //## end CLoaderMD3::SkinBookmark%3B9BF1D302BE.attr

    // Additional Private Declarations
      //## begin CLoaderMD3%3B8B83190029.private preserve=yes
      //## end CLoaderMD3%3B8B83190029.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLoaderMD3%3B8B83190029.implementation preserve=yes
      //## end CLoaderMD3%3B8B83190029.implementation

};

//## begin CLoaderMD3%3B8B83190029.postscript preserve=yes
//## end CLoaderMD3%3B8B83190029.postscript

// Class CLoaderMD3 

//## begin module%3B8B83190029.epilog preserve=yes
//## end module%3B8B83190029.epilog


#endif
