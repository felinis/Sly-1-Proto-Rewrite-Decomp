#include "lo.h"

LO LO::SetLo(LO parentLo, CID cid, void* parentSW, void* paloParent, OID oid)
{
	parentLo.cid = cid;
	parentLo.psw = psw;
	parentLo.paloParent = paloParent;
	parentLo.oid = oid;

	return parentLo;
}

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

}

SW::SW(CID cid, SW* parentSW, void* paloParent, OID oid)
{
	localObject = SetLo(localObject, cid, parentSW, paloParent, oid);

	InitLo(&localObject);
}

void SW::LoadSwFromBrx(SW* parentSW, CBinaryInputStream* pbis)
{

}

ALO::ALO(CID cid, SW* parentSW, ALO* paloParent, OID oid, int isplice)
{

}

void ALO::LoadAloFromBrx(ALO *parentAlo, CBinaryInputStream *pbis)
{
	
}