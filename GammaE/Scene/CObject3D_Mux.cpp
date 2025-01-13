//## begin module%3BD972AC0089.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BD972AC0089.cm

//## begin module%3BD972AC0089.cp preserve=no
//## end module%3BD972AC0089.cp

//## Module: CObject3D_Mux%3BD972AC0089; Pseudo Package body
//## Source file: i:\Projects\GammaE\Scene\CObject3D_Mux.cpp

//## begin module%3BD972AC0089.additionalIncludes preserve=no
//## end module%3BD972AC0089.additionalIncludes

//## begin module%3BD972AC0089.includes preserve=yes
#include <string.h>
#include "memory/gammae_mem.h"
//## end module%3BD972AC0089.includes

// CObject3D_Mux
#include "Scene\CObject3D_Mux.h"
//## begin module%3BD972AC0089.additionalDeclarations preserve=yes
//## end module%3BD972AC0089.additionalDeclarations


// Class CObject3D_Mux 


CObject3D_Mux::CObject3D_Mux()
  //## begin CObject3D_Mux::CObject3D_Mux%.hasinit preserve=no
      : Selected(NULL)
  //## end CObject3D_Mux::CObject3D_Mux%.hasinit
  //## begin CObject3D_Mux::CObject3D_Mux%.initialization preserve=yes
  //## end CObject3D_Mux::CObject3D_Mux%.initialization
{
  //## begin CObject3D_Mux::CObject3D_Mux%.body preserve=yes
	TypeID = e3DObj_Mux;
  //## end CObject3D_Mux::CObject3D_Mux%.body
}


CObject3D_Mux::~CObject3D_Mux()
{
  //## begin CObject3D_Mux::~CObject3D_Mux%.body preserve=yes
	if (Selected) mDel []Selected;
  //## end CObject3D_Mux::~CObject3D_Mux%.body
}



//## Other Operations (implementation)
void CObject3D_Mux::Init (int _MaxSubObjects)
{
  //## begin CObject3D_Mux::Init%1004106494.body preserve=yes
	CObject3D_Node::Init(_MaxSubObjects);

	Selected = mNew char[_MaxSubObjects];
	memset(Selected,1,_MaxSubObjects);
  //## end CObject3D_Mux::Init%1004106494.body
}

void CObject3D_Mux::Render ()
{
  //## begin CObject3D_Mux::Render%1004106495.body preserve=yes
	int cObj;

	for (cObj=0;cObj<poSubObj.iNumElems();cObj++)
		if ((poSubObj[cObj]) && (Selected[cObj]))
		{
			poSubObj[cObj]->Render();
		}
  //## end CObject3D_Mux::Render%1004106495.body
}

void CObject3D_Mux::SelectAll ()
{
  //## begin CObject3D_Mux::SelectAll%1004106496.body preserve=yes
	assert (Selected && "NULL mux selection array");
	memset(Selected,1,iNumSubObjs());
  //## end CObject3D_Mux::SelectAll%1004106496.body
}

void CObject3D_Mux::SelectNone ()
{
  //## begin CObject3D_Mux::SelectNone%1004106497.body preserve=yes
	assert (Selected && "NULL mux selection array");
	memset(Selected,0,iNumSubObjs());
  //## end CObject3D_Mux::SelectNone%1004106497.body
}

void CObject3D_Mux::Select (int _iIdx)
{
  //## begin CObject3D_Mux::Select%1004106498.body preserve=yes
	assert (Selected && "NULL mux selection array");
	assert ((_iIdx<iNumSubObjs()) && "Mux index out of bounds");
	Selected[_iIdx] = 1;
  //## end CObject3D_Mux::Select%1004106498.body
}

void CObject3D_Mux::Unselect (int _iIdx)
{
  //## begin CObject3D_Mux::Unselect%1004106499.body preserve=yes
	assert (Selected && "NULL mux selection array");
	assert ((_iIdx<iNumSubObjs()) && "Mux index out of bounds");
	Selected[_iIdx] = 0;
  //## end CObject3D_Mux::Unselect%1004106499.body
}

bool CObject3D_Mux::bIsSelected (int _iIdx)
{
  //## begin CObject3D_Mux::bIsSelected%1004106500.body preserve=yes
	assert (Selected && "NULL mux selection array");
	assert ((_iIdx<iNumSubObjs()) && "Mux index out of bounds");
	return (Selected[_iIdx]);	
  //## end CObject3D_Mux::bIsSelected%1004106500.body
}

// Additional Declarations
  //## begin CObject3D_Mux%3BD972AC0089.declarations preserve=yes
  //## end CObject3D_Mux%3BD972AC0089.declarations

//## begin module%3BD972AC0089.epilog preserve=yes
//## end module%3BD972AC0089.epilog
