#include "brx.h"

void StartupBrx()
{
	BuildEopids();
}

void* PloNew(CID cid, SW* parentSW, ALO* paloParent, OID oid, int isplice)
{
	LO LocalObject;

	LocalObject.cid = cid;
	LocalObject.psw = parentSW;
	LocalObject.paloParent = paloParent;
	LocalObject.oid = oid;

	switch (cid)
	{
		case CID::CID_SW:
		// Making and initializing new parent SW object
		SW *sw = new SW(LocalObject);
		// Storing parent SW address in object header
		sw->LocalObject.psw = sw;
		// Storing first parent SW object in objectMap
		AppendDlEntry(sw->PdlFromSwOid(sw, oid), sw);
		// Initializing SW object
		sw->InitSw();
		// Returning newly made parent SW object
		return sw;
	}
}