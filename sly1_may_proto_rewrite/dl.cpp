#include "dl.h"

void InitDl(DL *pdl, int ibDle)
{
	pdl->ibDle = ibDle;
}

DLE* PdleFromDlEntry(DL* pdl, void* pv)
{
	return (DLE*)pv + pdl->ibDle;
}

void AppendDlEntry(DL *pdl, void *pv)
{
	DLE *entry0 = PdleFromDlEntry(pdl, pv);

	// checking to see if list is empty
	if (pdl->pvLast == nullptr)
		// if list is empty than it makes data the head node
		pdl->pvFirst = pv;

	else
	{
		DLE* entry1 = PdleFromDlEntry(pdl, pdl->pvLast);
		entry0 = (DLE*)pdl;
		entry1->pvNext = pv;
	}

	// storing data at the end of list
	pdl->pvLast = pv;
}

int FFindDlEntry(DL* pdl, void* pv)
{
	DLE* element = PdleFromDlEntry(pdl, pv);

	bool isFound = 0;

	if (element->pvNext != 0 || pdl->pvLast == pv)
		isFound = 1;

	return isFound;
}
