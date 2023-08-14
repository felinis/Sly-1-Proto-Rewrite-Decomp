#include "transition.h"

void CTransition::Set(char* pchzWorld, OID oidWarp, OID oidWarpContext, GRFTRANS grftrans)
{
	if (m_fPending == 0) {
		grftrans = grftrans;
		m_fPending = 1;
		m_pchzWorld = pchzWorld;
		m_oidWarp = oidWarp;
		m_oidWarpContext = oidWarpContext;
	}
}

void CTransition::Execute()
{
	SetPhase(PHASE_Load); // Setting the global game state to load because where loading a file
	CBinaryInputStream file("jb_intro");
	DeleteSw(g_psw); // Deleting SW object
	g_psw = nullptr;
	SetupBulkDataFromBrx(1, &file);
	g_psw = (SW*)PloNew(CID::CID_SW, 0, 0, OID::OID__WORLD, -1); // Initializing SW object
	g_psw->LoadSwFromBrx(g_psw, &file); // Loads static world from binary file.
	file.Close();
	m_fPending = 0;
}