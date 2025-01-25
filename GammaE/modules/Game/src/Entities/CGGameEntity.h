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
/*! \class CGGameEntity
 *  \brief The minimum information for a logic entity in the system.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
#ifndef CGGameEntityH
#define CGGameEntityH
// -----------------------------------------------------------------------------
#include "GammaE_E3D.h"
#include "GammaE_Misc.h"
#include "GammaE_Math.h"
// -----------------------------------------------------------------------------
typedef enum TEntityState
{
    ENTSTATE_NONE = 0x00000000,
    ENTSTATE_IDLE = 0x00000001,
    ENTSTATE_INIT = 0x00000002,
    ENTSTATE_DEAD = 0x00000003,
    ENTSTATE_ALIVE = 0x00000004,
    ENTSTATE_UNUSED = 0x00000005,

    ENTSTATE_LASTSTATE = 0xffffffff
};
// -----------------------------------------------------------------------------
class CGGraphicInstance;
class CCOL_Collider;
class CGScriptInstance;
class CGInputHandler;
// -----------------------------------------------------------------------------
class CGGameEntity
{
    public:
        CGGameEntity();
        ~CGGameEntity();

        // / The Name of the class of this entity
        virtual CGString sClass();

        // / A unique identifier for this entity in the system
        CGString sUID()
        {
            return( sClass() + CGString('.') + CGString( (int)m_uiID ) );
        }

        // / A numeric class identifier
        uint uiClass();

        // / The numeric identifier for this entity
        uint uiID()
        {
            return(m_uiID);
        }

        // / Perform some preprocessing before the actual entity game logic step
        virtual void PreThink(float _fDeltaT);

        // / Perform a game logic step for this entity
        virtual void Think(float _fDeltaT);

        // / Spawns the entity and set the entity as alive
        virtual void Spawn();

        // / Resets the entity to its initial state
        virtual void Reset();

        // / Switchs the entity state to a new state
        void SwitchToState(TEntityState _eNewState);

        // / Retrieves the current entity state
        TEntityState eGetState()
        {
            return(m_eState);
        }

    protected:
        // / Function to call when exiting from a given state. It`s called right before switching to a New State
        virtual void OnExitState(TEntityState _eState);

        // / Function to call after switching to a New State
        virtual void OnEnterState(TEntityState _eState);

    public:
        // / Enables the entity game logic
        virtual void Enable()
        {
            m_bEnabled = true;
        }

        // / Disables the entity game logic
        virtual void Disable()
        {
            m_bEnabled = false;
        }

        // / Tells whether this entity is enabled or not
        bool bIsEnabled()
        {
            return(m_bEnabled);
        }

        // / Return the life time multiplier for this entity
        float fTimeMult()
        {
            return(m_fTimeMult);
        }

        // / Changes the life time multiplier for this entity
        void TimeMult(float _fTimeMult)
        {
            m_fTimeMult = _fTimeMult;
        }

        // / Returns the entity time
        float fTime()
        {
            return(m_fTime);
        }

        // / Sets the entity time
        void Time(float _fTime)
        {
            m_fTime = _fTime;
        }

        // / Retrieves the time delta for this entity
        float fDeltaT()
        {
            return(m_fDeltaT);
        }

// Compound of ... (vs inheritance approach)

        // / Sets the graphic instance for the entity
        void GraphicInstance(CGGraphicInstance* _poVis)
        {
            m_poGraph = _poVis;
        }

        // / Gets the graphic instance of the entity
        CGGraphicInstance* poGraphicInstance()
        {
            return(m_poGraph);
        }

        // / Sets the collision information for the entity
        void Collider(CCOL_Collider* _poCol)
        {
            m_poCol = _poCol;
        }

        // / Gets the collision information of the entity
        CCOL_Collider* poCollider()
        {
            return(m_poCol);
        }

        // / Sets the resource that handles the logic of this entity
        void Logic(CGScriptInstance* _poLogic)
        {
            m_poLogic = _poLogic;
        }

        // / Gets the resource that handles the logic of this entity
        CGScriptInstance* poLogic()
        {
            return(m_poLogic);
        }

        // / Sets the input handler for the entity
        void Input(CGInputHandler* _poInput)
        {
            m_poInput = _poInput;
        }

        // / Retrieves the input handler of the entity
        CGInputHandler* poInput()
        {
            return (m_poInput);
        }

        // / Sets the logger message channel for the entity
        void Logger(CGLogger* _poLogger)
        {
            m_poLogger = _poLogger;
        }

        // / Retrieves the logger message channel for the entity
        CGLogger* poLogger()
        {
            return (m_poLogger);
        }

        // / Adds a user data object to the entity
        uint uiAddUserData(uobject _uoData)
        {
            return( m_uoUserData.uiAdd(_uoData) );
        }

        // / Retrieves the user data linked to the given index
        uobject hGetUserData(uint _uiUserDataIdx)
        {
            if ( m_uoUserData.uiNumElems() )
                return(m_uoUserData[_uiUserDataIdx]);
            else
                return(NULL);
        }

        // / Clears all the user data
        void ClearUserData()
        {
            m_uoUserData.Clear();
        }

        // / Sets the constant color for this entity
        void SetColor(const CGColor& _oColor)
        {
            m_oColor = _oColor;
        }

        // / Retrieves the constant color for this entity
        const CGColor& SetColor(const CGColor& _oColor) const
        {
            return(m_oColor);
        }

        // / Updates the position of the entity updating the graphic instance and collision data if available
        virtual void UpdatePos(const CGVect3& _oNewPos);

    protected:

        TEntityState m_eState;

        float m_fTime;
        float m_fOTime;
        float m_fDeltaT;
        float m_fTimeMult;

        bool m_bEnabled;
        uint m_uiID;

        CGGraphicInstance* m_poGraph;
        CCOL_Collider* m_poCol;
        CGScriptInstance* m_poLogic;
        CGInputHandler* m_poInput;
        CGDynArray <uobject> m_uoUserData;
        CGLogger* m_poLogger;
        CGColor m_oColor;
};

// -----------------------------------------------------------------------------
#define PUBLISH_GAMEENTITY_CLASSNAME \
    virtual CGString sClass() \
    { \
        static CGString sClassName = ExtractShortFileName( CGString(__FILE__) ); \
        return (sClassName); \
    }; \

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
