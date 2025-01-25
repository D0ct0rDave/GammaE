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
#ifndef CGGraphBVFactoryH
#define CGGraphBVFactoryH
// -----------------------------------------------------------------------------
#include "GraphBV\CGGraphBV.h"
#include "GammaE_Math.h"
// -----------------------------------------------------------------------------
class CGGraphBVFactory
{
    public:
        static CGGraphBV* poCreate();
        static CGGraphBV* poCreate(EGBoundingVolumeType _eBVMode);

        static void SetBVMode(EGBoundingVolumeType _eBVMode);
        static EGBoundingVolumeType eGetBVMode();

    private:
        static EGBoundingVolumeType m_eBVMode;
};
// -----------------------------------------------------------------------------
inline void CGGraphBVFactory::SetBVMode (EGBoundingVolumeType _eBVMode)
{
    m_eBVMode = _eBVMode;
}
// -----------------------------------------------------------------------------
inline EGBoundingVolumeType CGGraphBVFactory::eGetBVMode ()
{
    return (m_eBVMode);
}
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------

