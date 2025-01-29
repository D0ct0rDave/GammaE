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
// Name:        CApplication.h
// Author:      PepeMagnifico
// Created:     27/04/2009 19:49:10
// Description:
//
// ---------------------------------------------------------------------------
#ifndef CApplicationH
#define CApplicationH
// ---------------------------------------------------------------------------
class CApplication
{
    public:
        static void OnCreate(void* _pParam,char* pszCmdLine);
        static void OnDestroy(void* _pParam);
        static bool bFinishApp();
        static void OnIdle();
        static void OnResize(unsigned int _uiNewWidth,unsigned int _uiNewHeight);

    protected:
};
// ---------------------------------------------------------------------------
#endif
// ---------------------------------------------------------------------------
