// ----------------------------------------------------------------------------
#ifndef CGRenderStateH
#define CGRenderStateH
// ----------------------------------------------------------------------------
class CGRenderState
{
    public:
        CGRenderState();

        bool m_bDefferredMode;

        bool m_bFrustumCulling;

        bool m_bBVRender;

        bool m_bNormalRender;

        bool m_bFlatRender;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
