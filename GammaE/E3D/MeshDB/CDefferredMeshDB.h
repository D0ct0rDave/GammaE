//## begin module%3C509C6E0260.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C509C6E0260.cm

//## begin module%3C509C6E0260.cp preserve=no
//## end module%3C509C6E0260.cp

//## Module: CDefferredMeshDB%3C509C6E0260; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\MeshDB\CDefferredMeshDB.h

#ifndef CDefferredMeshDB_h
#define CDefferredMeshDB_h 1

//## begin module%3C509C6E0260.additionalIncludes preserve=no
//## end module%3C509C6E0260.additionalIncludes

//## begin module%3C509C6E0260.includes preserve=yes
//## end module%3C509C6E0260.includes

// TDefferredMeshEntry
#include "E3D\MeshDB\TDefferredMeshEntry.h"
//## begin module%3C509C6E0260.additionalDeclarations preserve=yes
//## end module%3C509C6E0260.additionalDeclarations


//## begin CDefferredMeshDB%3C509C6E0260.preface preserve=yes
//## end CDefferredMeshDB%3C509C6E0260.preface

//## Class: CDefferredMeshDB%3C509C6E0260
//## Category: E3D::MeshDB%3C509C55008D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CDefferredMeshDB 
{
  //## begin CDefferredMeshDB%3C509C6E0260.initialDeclarations preserve=yes
  //## end CDefferredMeshDB%3C509C6E0260.initialDeclarations

  public:
    //## Constructors (generated)
      CDefferredMeshDB();

    //## Destructor (generated)
      ~CDefferredMeshDB();


    //## Other Operations (specified)
      //## Operation: Init%1011911195
      void Init (int _iNumEntries);

      //## Operation: InsertDefferredObject%1011911196
      void InsertDefferredObject (void* _poMesh, eE3D_MeshType _eMT, CE3D_Shader* _poShader, CMatrix4x4& _roMatrix, unsigned int _uiLights);

      //## Operation: Invalidate%1011911197
      void Invalidate ();

      //## Operation: eGetObject%1011911198
      eE3D_MeshType eGetObject (int _iEntry, void *&_rpMesh, CE3D_Shader* &_rpoShader, CMatrix4x4* &_rpoMatrix, unsigned int& _ruiLights);

      //## Operation: iNumDefferredObjects%1011911199
      int iNumDefferredObjects ();

      //## Operation: Sort%1020152547
      void Sort ();

    // Data Members for Associations

      //## Association: E3D::MeshDB::<unnamed>%3C509CDE008A
      //## Role: CDefferredMeshDB::MeshDB%3C509CDE01E0
      //## begin CDefferredMeshDB::MeshDB%3C509CDE01E0.role preserve=no  public: TDefferredMeshEntry { -> RHAN}
      TDefferredMeshEntry *MeshDB;
      //## end CDefferredMeshDB::MeshDB%3C509CDE01E0.role

    // Additional Public Declarations
      //## begin CDefferredMeshDB%3C509C6E0260.public preserve=yes
      //## end CDefferredMeshDB%3C509C6E0260.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: iNumEntries%3C509D1301E5
      //## begin CDefferredMeshDB::iNumEntries%3C509D1301E5.attr preserve=no  protected: int {UA} 
      int iNumEntries;
      //## end CDefferredMeshDB::iNumEntries%3C509D1301E5.attr

      //## Attribute: iMaxEntries%3C509D1F026E
      //## begin CDefferredMeshDB::iMaxEntries%3C509D1F026E.attr preserve=no  protected: int {UA} 
      int iMaxEntries;
      //## end CDefferredMeshDB::iMaxEntries%3C509D1F026E.attr

    // Additional Protected Declarations
      //## begin CDefferredMeshDB%3C509C6E0260.protected preserve=yes
      //## end CDefferredMeshDB%3C509C6E0260.protected

  private:
    // Additional Private Declarations
      //## begin CDefferredMeshDB%3C509C6E0260.private preserve=yes
      //## end CDefferredMeshDB%3C509C6E0260.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CDefferredMeshDB%3C509C6E0260.implementation preserve=yes
      //## end CDefferredMeshDB%3C509C6E0260.implementation

};

//## begin CDefferredMeshDB%3C509C6E0260.postscript preserve=yes
//## end CDefferredMeshDB%3C509C6E0260.postscript

// Class CDefferredMeshDB 


//## Other Operations (inline)
inline int CDefferredMeshDB::iNumDefferredObjects ()
{
  //## begin CDefferredMeshDB::iNumDefferredObjects%1011911199.body preserve=yes
  return (iNumEntries);
  //## end CDefferredMeshDB::iNumDefferredObjects%1011911199.body
}

//## begin module%3C509C6E0260.epilog preserve=yes
//## end module%3C509C6E0260.epilog


#endif
