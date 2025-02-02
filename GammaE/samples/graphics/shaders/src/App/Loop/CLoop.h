// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ---------------------------------------------------------------------------
//
// Name:        CLoop.h
// Author:      PepeMagnifico
// Created:     27/04/2009 17:56:10
// Description:
//
// ---------------------------------------------------------------------------
#ifndef CLoopH
#define CLoopH
// ---------------------------------------------------------------------------
class CLoop
{
    public:
        static void Init();
        static void Finish();

        static bool bLoop(float _fDeltaT);
        static bool bUpdate(float _fDeltaT);
        static void Render();
};
// ---------------------------------------------------------------------------
#endif
// ---------------------------------------------------------------------------
