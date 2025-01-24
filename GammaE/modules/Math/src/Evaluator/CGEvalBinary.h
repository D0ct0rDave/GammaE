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
#ifndef CGEvalBinaryH
#define CGEvalBinaryH
// ----------------------------------------------------------------------------
#include "CGEvaluator.h"
// ----------------------------------------------------------------------------
class CGEvalBinary : public CGEvaluator
{
    public:

        CGEvalBinary();
        virtual ~CGEvalBinary();

        CGEvaluator* poGetAOp();
        void SetAOp(CGEvaluator* _poOp);

        CGEvaluator* poGetBOp();
        void SetBOp(CGEvaluator* _poOp);

    protected:

        CGEvaluator* m_poAOp;
        CGEvaluator* m_poBOp;
};
// ----------------------------------------------------------------------------
inline CGEvaluator* CGEvalBinary::poGetAOp ()
{
    return(m_poAOp);
}
// ----------------------------------------------------------------------------
inline void CGEvalBinary::SetAOp (CGEvaluator* _poOp)
{
    m_poAOp = _poOp;
}
// ----------------------------------------------------------------------------
inline CGEvaluator* CGEvalBinary::poGetBOp ()
{
    return(m_poBOp);
}
// ----------------------------------------------------------------------------
inline void CGEvalBinary::SetBOp (CGEvaluator* _poOp)
{
    m_poBOp = _poOp;
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
