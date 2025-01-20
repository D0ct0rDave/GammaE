// -----------------------------------------------------------------------------
#ifndef CGMHLevelH
#define CGMHLevelH
// -----------------------------------------------------------------------------
#include "Loop/Game/Ents/CEntity.h"
#include "Loop/Game/Ents/CGoal.h"
#include "Loop/Game/Ents/CRock.h"
#include "Loop/Game/Ents/CPowerUp.h"
#include "Loop/Game/Ents/CMovBlock.h"
#include "Loop/Cinematic/CCINScene.h"
// -----------------------------------------------------------------------------
#define MAX_ROCKS	32

typedef struct {

	float		m_fHandicap;
	float		m_fMaloMult;
	float		m_fTime;
}TSkillValues;
// -----------------------------------------------------------------------------
class CGMHLevel : public CEntity
{
public:
		CGMHLevel();

		virtual void Init(int _iSkill) = 0;
		virtual void Finish() = 0;
		virtual void Reset() = 0;
		virtual void Think() = 0;

		virtual void Init(char *_szLevelName,int _iSkill);
		virtual void CreateLevelEntities();

public:

		char			m_szLevelName[32];

		CMap*			m_poMap;

		char			m_szIntroCIN[MAX_CHARS];
		char			m_szOutroCIN[MAX_CHARS];

		CDMCTex*		m_poMinimap;

		float			m_fIniPPos;		// Initial player position

		bool			m_bBossLevel;	// Is a boss level?
		float			m_fIniBPos;		// Initial boss position

		TSkillValues	m_oSV;			// Skill parameters
		
		int				m_iCamType;
		int				m_iSkill;
		
		CGoal*			m_poGoal;
		CRock*			m_poRocks;
		CPowerUp*		m_poPUps;

		unsigned int	m_uiMovs;
		CMovBlock*		m_poMBs;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------