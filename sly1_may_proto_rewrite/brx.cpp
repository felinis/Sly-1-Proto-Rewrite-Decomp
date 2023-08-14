#include "brx.h"

void StartupBrx()
{
	BuildEopids();
}

void* PloNew(CID cid, SW* parentSW, ALO* paloParent, OID oid, int isplice)
{
	switch (cid)
	{
		case CID::CID_SW:
		SW *sw = new SW(cid, parentSW, paloParent, oid);

		return sw;
	}
}