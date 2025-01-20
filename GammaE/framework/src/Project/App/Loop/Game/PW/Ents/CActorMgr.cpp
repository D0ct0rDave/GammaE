// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include "CActorMgr.h"

TActorInfo		CActorMgr::m_oALst[MAX_ACTORS];
int 			CActorMgr::m_iNumActors = 0;
		
// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------
void CActorMgr::Reset()
{
	memset(m_oALst,0,sizeof(m_oALst));
	m_iNumActors = 0;
}
// -----------------------------------------------------------------------------
int  CActorMgr::iRegister(char* _szActorName,CActor* _poActor)
{
	m_oALst[m_iNumActors].m_poActor = _poActor;
	strcpy(m_oALst[m_iNumActors].m_szName,_szActorName);
	m_iNumActors++;

	return(m_iNumActors-1);
}
// -----------------------------------------------------------------------------
CActor *CActorMgr::poGetActor(char* _szActorName)
{
	for (int i=0;i<m_iNumActors;i++)
	{
		if (! strcmp(m_oALst[i].m_szName,_szActorName))
			return (m_oALst[i].m_poActor);
	}

	return(NULL);
}
// -----------------------------------------------------------------------------