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

#ifndef CGSceneAnimCfgMgrH
#define CGSceneAnimCfgMgrH

// CGSceneAnimCfgGen
#include "Animation\CGSceneAnimCfgGen.h"
// CGSceneAnimCfg
#include "Animation\CGSceneAnimCfg.h"

class CGSceneAnimCfgMgr : public CGSceneAnimCfgGen
{
    public:
        CGSceneAnimCfgMgr();

        virtual ~CGSceneAnimCfgMgr();

        void Init(int _iMaxAnimObjs);

        virtual void SetFrameAnim(int _iFrameAnim);

        virtual CGBoundingVolume* poGetBoundVol();

        virtual void ComputeBoundVol();

        virtual void Render();

        int AddAnimObj(CGSceneAnimCfg* _pAnimObj);

        int iNumAnimObjs;

        int iMaxAnimObjs;

        CGSceneAnimCfg* * pAnimObjs;

        int iCurrentFrame;

    protected:

    private:

    private:
};

#endif
