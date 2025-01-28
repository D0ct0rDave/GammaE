#include "CColliderRenderer.h"
#include "Collision/CGColliderResource.h"
#include "Collision/CGColliderInstance.h"
// #include "Collision/CGGEntityCollisionMgr.h"
// -----------------------------------------------------------------------------		
CGMeshSphere*		poSph;
CGSceneLeaf*		poLeaf;
CGSceneTransf*	poTransf;
// -----------------------------------------------------------------------------
CColliderRenderer::CColliderRenderer()
{
	poSph		= mNew CGMeshSphere;
	poTransf	= mNew CGSceneTransf;
	poLeaf		= mNew CGSceneLeaf;
	
	poLeaf->SetShader( CGShaderWH::I()->poCreateShader("wireframe") );
	poLeaf->SetMesh( poSph );
	
	poTransf->SetObject( poLeaf );
	SetObject(poTransf);
	Disable();
}
// -----------------------------------------------------------------------------
void CColliderRenderer::RenderCollider(CGColliderPrimitive* _poCT,const CGVect3& _oOffset,float _fScale)
{
	switch (_poCT->eType())
	{
		case CPT_Sphere:
		{
			CGCPTSphere* poSph = (CGCPTSphere*)_poCT;

			CGVect3 oPos = poSph->m_oCenter;
			oPos.Scale(_fScale);
			oPos.Add(_oOffset);		

			float fScale = _fScale * poSph->m_fRadius;

			CGMatrix4x4 oMat;
			oMat.LoadIdentity();
			oMat.Translate( oPos.x, oPos.y, oPos.z );
			oMat.Scale(fScale,fScale,fScale);

			poTransf->SetTransf( oMat );
			
			CGSCNVRenderer::I()->Render(poTransf);
		}
		break;
		
		case CPT_AABB:
		break;
		
		case CPT_Composite:
		{
			CGCPTComposite* poCompo = (CGCPTComposite*)_poCT;
			for (uint i=0;i<poCompo->uiNumElems();i++)
			{
				RenderCollider(poCompo->poElem(i),_oOffset,_fScale);
			}
		}
		break;
	}
}
// -----------------------------------------------------------------------------
void CColliderRenderer::Render()
{
	if (! bEnabled()) return;

	for (uint i=0;i<CGGameEntityMgr::I()->uiNumEntities();i++)
	{
		CGGameEntity*	poEnt		= CGGameEntityMgr::I()->poGetEntity(i);
		CGColliderInstance* poCol   = (CGColliderInstance*)poEnt->poCollider();

		if (poEnt->bIsEnabled() && poCol && poCol->m_poResource && poCol->m_poResource->m_poCT)
		{
			RenderCollider(poCol->m_poResource->m_poCT,poCol->m_oPos,poCol->m_fScale);
		}
	}
}
// -----------------------------------------------------------------------------