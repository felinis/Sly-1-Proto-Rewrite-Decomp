#include "lo.h"

void LO::InitLo(LO *parentLo)
{
	SetLoDefaults(parentLo);
	AddLo(parentLo);
}

void LO::SetLoDefaults(LO *parentLo)
{

}

void LO::AddLo(LO *parentLo)
{
	// Loading object's parent
	void* objectParent = parentLo->paloParent;
	DL objectsChild;

	// If object doesnt have a parent load up the static world dlChild
	if (objectParent == nullptr)
	{
		// Loading parent SW
		SW* psw = (SW*)parentLo->psw;
		objectsChild = psw->dlChild;
	}
}

SW::SW(LO LocalObject)
{
	this->LocalObject = LocalObject;

	for (int i = 0; i < 0x200; i++)
		InitDl(&objectParents[i], 0xC);
}

void SW::InitSw()
{
	LocalObject.InitLo(&LocalObject);

	InitDl(&dlChild, 0x1C);
	InitDl(&dlMRD, 0x54);
	InitDl(&dlMRDRealClock, 0x54);
	InitDl(&dlBusy, 0x4C);
	InitDl(&dlBusySo, 0x434);
	InitDl(&dlRoot, 0x2e0);
	InitDl(&dlAsega, 0x34);
	InitDl(&dlAsegaRealClock, 0x34);
	InitDl(&dlAsegaPending, 0x34);
	InitDl(&dlSma, 0x10);
	InitDl(&dlAmb, 0x60);
	InitDl(&dlExc, 4);
	InitDl(&dlLight, 0x420);
	InitDl(&dlShadow, 0xb8);
	InitDl(&dlExplste, 100);
	InitDl(&dlProxy, 0x2ec);
	InitDl(&dlFly, 0x60c);
	InitDl(&dlDprize, 900);
	InitDl(&dlRat, 0x630);
	InitDl(&dlRathole, 0x90);
	InitDl(&dlDartFree, 0x59c);
	InitDl(&dlSpire, 0x50);
	InitDl(&dlRail, 0x50);
	InitDl(&dlLanding, 0x50);
	InitDl(&dlBusyLasen, 0xb20);
	InitDl(&dlBlipg, 0x640);
	InitDl(&dlBlipgFree, 0x640);
	InitDl(&dlFader, 0xc);
	InitDl(&dlRealClockFader, 0xc);
	InitDl(&dlCrfod, 0xb90);
	InitDl(&dlShape, 0x44);
	InitDl(&dlPathzone, 100);
}

DL* SW::PdlFromSwOid(SW* psw, OID oid)
{
	return &psw->objectParents[oid];
}

void SW::LoadSwFromBrx(SW* psw, CBinaryInputStream* pbis)
{

}

void SW::SetSwGravity(SW* sw, float z)
{

}

ALO::ALO(CID cid, SW* parentSW, ALO* paloParent, OID oid, int isplice)
{

}

void ALO::LoadAloFromBrx(ALO *parentAlo, CBinaryInputStream *pbis)
{
	
}