#include "CGColliderDefinitionFileWH.h"
#include "CGColliderResourceWH.h"
#include "CGColliderResource.h"
// ----------------------------------------------------------------------------
CGColliderPrimitive* CGColliderDefinitionFileWH::poRetrieveCollider(const CGConfigFile& _oCfg,const CGString& _sSection)
{
	// Retrieve the type for this collidable part
	CGString sType = _oCfg.sGetString(_sSection + ".Type", "sphere" );

	// Read Collider properties
	if (sType |= "sphere")
	{
		CGVect3 oCenter;
		CGString sName  = _oCfg.sGetString(_sSection + ".Name", "none" );

		float	fRadius = _oCfg.fGetFloat(_sSection + ".Radius", 0.0f );

		oCenter.x = _oCfg.fGetFloat(_sSection + ".Center.x", 0.0f );
		oCenter.y = _oCfg.fGetFloat(_sSection + ".Center.y", 0.0f );
		oCenter.z = _oCfg.fGetFloat(_sSection + ".Center.z", 0.0f );

		return ( mNew CGCPTSphere(sName,oCenter,fRadius) );
	}

else if (sType |= "aabb")
	{
		CGVect3 oCenter,oExtents;
		CGString sName  = _oCfg.sGetString(_sSection + ".Name", "none" );

		oCenter.x = _oCfg.fGetFloat(_sSection + ".Center.x", 0.0f );
		oCenter.y = _oCfg.fGetFloat(_sSection + ".Center.y", 0.0f );
		oCenter.z = _oCfg.fGetFloat(_sSection + ".Center.z", 0.0f );

		oExtents.x = _oCfg.fGetFloat(_sSection + ".Extents.x", 0.0f );
		oExtents.y = _oCfg.fGetFloat(_sSection + ".Extents.y", 0.0f );
		oExtents.z = _oCfg.fGetFloat(_sSection + ".Extents.z", 0.0f );

		return ( mNew CGCPTAABB(sName,oCenter,oExtents) );	
	}

else if (sType |= "composite")
	{
		// Recursive code
		// retrieve the number of elements for this collider
		uint uiNumElems = _oCfg.iGetInteger(_sSection + ".NumElems",1);
		CGCPTComposite* poCTC = mNew CGCPTComposite(uiNumElems);

		// 
		CGString sSection = _sSection + ".Composition";

		// Retrieve one by one the elements of the composite object
		for (uint i=0;i<uiNumElems;i++)
		{
			CGString sVar = sSection + ".Elem" + CGString(i);

			// Retrieve the elements of this collidable object
			poCTC->AddElem( poRetrieveCollider(_oCfg,sVar) );
		}

		return(poCTC);
	}

	return(NULL);
}
// ----------------------------------------------------------------------------
void CGColliderDefinitionFileWH::ProcessColliderDefFile(const CGString& _sColliderDefFilename)
{
	CGConfigFile oCfg(_sColliderDefFilename);

	if (! oCfg.bInitialized())
		return;	

	uint uiNumDefs = oCfg.iGetInteger("General.NumDefinitions",0);
	
	for (uint j=0;j<uiNumDefs;j++)
	{
		CGString sDef  = CGString("Definition") + CGString(j);

		// Get the name of this Collider
		CGString sName =  oCfg.sGetString(sDef+".Name","");

		// Retrieve the Collider in case it's already defined
		CGColliderResource* poCR = CGColliderResourceWH::I()->poFind(sName);

		// If the Collider doesn't exist, create a new one and add to the warehouse
		if (poCR == NULL)
		{
			poCR = mNew CGColliderResource;
			CGColliderResourceWH::I()->uiAdd(poCR,sName);
		}

		CGString sSection = sDef + ".ColliderStructure";
	
		// Retrieve the collision structure
		poCR->m_poCT = poRetrieveCollider(oCfg,sSection);
	}
}
// ----------------------------------------------------------------------------
CGTextResource* CGColliderDefinitionFileWH::poLoadResource(const CGString &_sFilename)
{
	CGTextResource* poRes = mNew CGTextResource;
	// poRes->SetData( ParseUtils_ReadFile((char*)_sFilename.szString()) );
	// ProcessPSGDefFile( poRes->sGetData().szString() );

	ProcessColliderDefFile( _sFilename );

	return ( poRes );
}
// ----------------------------------------------------------------------------
