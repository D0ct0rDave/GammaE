// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGRenderStatsH
#define CGRenderStatsH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
class CGRenderStats
{
    public:

        // / Number of objects processed for rendering this frame
        uint m_uiNumTestedObjs;

        // / Number of objects finally rendered this frame
        uint m_uiNumRenderedObjs;

        // / Number of objects that did not pass the culling test this frame
        uint m_uiNumCulledObjs;

        // / Number of triangles set to the rendering device this frame
        uint m_uiNumRenderedTris;

        // / Number of vertices set to the rendering device this frame
        uint m_uiNumRenderedVerts;

        // / Frames Per Second computed according to this frame
        float m_fFPS;

        // / Time elapsed to complete the last frame
        float m_fDelta;

        // / Current rendered frame since the first BeginRender
        uint m_uiCurrentFrame;

        // / Total time elapsed since the first BeginRender frame
        float m_fTotalTime;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
