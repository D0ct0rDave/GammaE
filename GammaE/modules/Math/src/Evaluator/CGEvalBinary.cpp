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
#include "CGEvalBinary.h"
// ----------------------------------------------------------------------------
#include "GammaE_Mem.h"
// ----------------------------------------------------------------------------
CGEvalBinary::CGEvalBinary()
    : m_poAOp(NULL), m_poBOp(NULL)
{
}
// ----------------------------------------------------------------------------
CGEvalBinary::~CGEvalBinary()
{
    if ( m_poAOp ) mDel m_poAOp;
    if ( m_poBOp ) mDel m_poBOp;
}
// ----------------------------------------------------------------------------
