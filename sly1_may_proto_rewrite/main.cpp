#include "main.h"

int main(int cphzArgs, char* aphzArgs[])
{
	Startup();

	while (true)
	{
		if (g_transition.m_fPending != 0)
		{
		    g_transition.Execute();
		}
	}
	return 0;
}

void Startup()
{
	std::cout << "Sly Cooper 2002 Sony Computer Entertainment America & Sucker Punch Productions\n";
	SetPhase(PHASE_Startup);
	StartupBrx();
	//InitGL();

	g_transition.m_fPending = 1; // GOTTA CHANGE THIS
}