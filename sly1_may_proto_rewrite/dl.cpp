#include "dl.h"

void InitDl(DL *pdl, int ibDle)
{
	pdl->ibDle = ibDle;
}

void AppendDlEntry(DL *pdl, void *pv)
{
	if (pdl->pvLast == nullptr)
		pdl->pvFirst = pv;

	else
	{

	}

	pdl->pvLast = pv;
}
