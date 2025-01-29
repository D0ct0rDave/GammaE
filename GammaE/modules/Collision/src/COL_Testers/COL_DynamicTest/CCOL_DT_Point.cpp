// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// %X% %Q% %Z% %W%

// CCOL_DT_Point
#include "COL_Testers\COL_DynamicTest\CCOL_DT_Point.h"
// CCOL_DT_Box
#include "COL_Testers\COL_DynamicTest\CCOL_DT_Box.h"
// CCOL_DT_Sphere
#include "COL_Testers\COL_DynamicTest\CCOL_DT_Sphere.h"

#include "CollisionSystem\CCOL_ColState.h"
// -----------------------------------------------------------------------------
static CGVect3 SrcIP,SrcFP,SrcSp;
static CGVect3 DstIP,DstFP,DstSp;
static CGVect3 DSSpeed;
// -----------------------------------------------------------------------------
inline void SaveStateVars()
{
    // Backup variables
// SrcIP  .Assign(CCOL_ColState::SrcIPos);
// SrcFP  .Assign(CCOL_ColState::SrcFPos);
    SrcSp.Assign(CCOL_ColState::SrcSp  );

// DstIP  .Assign(CCOL_ColState::DstIPos);
// DstFP  .Assign(CCOL_ColState::DstFPos);
    DstSp.Assign(CCOL_ColState::DstSp  );

    DSSpeed.Assign(CCOL_ColState::DSSp   );
}
// -----------------------------------------------------------------------------
inline void RestoreStateVars()
{
    // Backup variables
// CCOL_ColState::SrcIPos.Assign(SrcIP);
// CCOL_ColState::SrcFPos.Assign(SrcFP);
    CCOL_ColState::SrcSp.Assign(SrcSp);

// CCOL_ColState::DstIPos.Assign(DstIP);
// CCOL_ColState::DstFPos.Assign(DstFP);
    CCOL_ColState::DstSp.Assign(DstSp);

    CCOL_ColState::DSSp.Assign(DSSpeed);
}
// -----------------------------------------------------------------------------
inline void SwapStateVars()
{
    // Backup variables
// CCOL_ColState::SrcIPos.Assign(DstIP);
// CCOL_ColState::SrcFPos.Assign(DstFP);
    CCOL_ColState::SrcSp.Assign(DstSp);

// CCOL_ColState::DstIPos.Assign(SrcIP);
// CCOL_ColState::DstFPos.Assign(SrcFP);
    CCOL_ColState::DstSp.Assign(SrcSp);

    CCOL_ColState::DSSp.Scale(-1.0f);
}
// -----------------------------------------------------------------------------
float CCOL_DT_Point::fTestSphere (const CGVect3& _oSPoint, const CGVect3& _oDCenter, float _fDRadius)
{
    float fRes;
    SaveStateVars();
    SwapStateVars();

    // Setup vars
    fRes = CCOL_DT_Sphere::fTestPoint(_oDCenter,_fDRadius,_oSPoint);

    RestoreStateVars();

    return(fRes);
}
// -----------------------------------------------------------------------------
float CCOL_DT_Point::fTestBox (const CGVect3& _oSPoint, const CGVect3& _oDMaxs, const CGVect3& _oDMins)
{
    float fRes;
    SaveStateVars();
    SwapStateVars();

    // Setup vars
    fRes = CCOL_DT_Box::fTestPoint( (CGVect3 &)_oDMaxs,(CGVect3 &)_oDMins,(CGVect3 &)_oSPoint );

    RestoreStateVars();

    return(fRes);
}
// -----------------------------------------------------------------------------
float CCOL_DT_Point::fTestPoint (const CGVect3& _oSPoint, float _fDRadius, const CGVect3& _oDCenter)
{
    return(-1.0f);
}
// -----------------------------------------------------------------------------
// Additional Declarations
