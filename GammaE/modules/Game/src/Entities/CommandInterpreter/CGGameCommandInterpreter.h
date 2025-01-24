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
// -----------------------------------------------------------------------------
#ifndef CGGameCommandInterpreter_h
#define CGGameCommandInterpreter_h 1
// -----------------------------------------------------------------------------
#include "CGGameConsoleApp.h"
#include "CGGCIState.h"
// -----------------------------------------------------------------------------
class CGGCICommand;
class CGGameCommandInterpreter : public CGGameConsoleApp
{
    public:
        PUBLISH_GAMEENTITY_CLASSNAME;

        CGGameCommandInterpreter();
        ~CGGameCommandInterpreter();

        virtual void Think(float fDelta);
        virtual void ReceiveChar(int _iKey);
        virtual void Exec(const CGString& _sCommand);

    protected:

        // -----------------------------------------------------------------------------
        void ProcessInstruction(char* _szCmdLine);

        // -----------------------------------------------------------------------------
        // -----------------------------------------------------------------------------
        ECIState m_eCIState;

        // -----------------------------------------------------------------------------
        // -----------------------------------------------------------------------------
        // -----------------------------------------------------------------------------
    public:
        virtual void ShowCursor();
        virtual void ShowPrompt();
        CGString& sPrompt()
        {
            return(m_sPrompt);
        }
        void SetPrompt(const CGString& _sPrompt)
        {
            m_sPrompt = _sPrompt;
        }

    protected:
        int m_iLastCurX;
        int m_iLastCurY;
        CGString m_sPrompt;

        // -----------------------------------------------------------------------------
        // -----------------------------------------------------------------------------
        // -----------------------------------------------------------------------------
    public:
        void SetDelayTime(float _fTime);

    protected:
        float m_fDelayTime;
        float m_fTime;

        // -----------------------------------------------------------------------------
        // -----------------------------------------------------------------------------
        // -----------------------------------------------------------------------------
    public:

        void AddInstruction(const CGString& _oString);

    protected:

        // -----------------------------------------------------------------------------
        CGDynArray <CGString> m_oInstLst;

        // -----------------------------------------------------------------------------
        // -----------------------------------------------------------------------------
        // -----------------------------------------------------------------------------
    public:
        void RegisterCommand(CGGCICommand* _poCmd);

    protected:
        friend class CGGCICommandHelp;

        // -----------------------------------------------------------------------------
        CGDynArray <CGGCICommand*> m_poCmds;
        // -----------------------------------------------------------------------------
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
