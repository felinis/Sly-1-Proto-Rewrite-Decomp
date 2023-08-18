#pragma once
#include "lo.h"

// Initializes Options
void StartupBrx();

// Returns a new static world object based off g_mpcidpvt global map variable
void* PloNew(CID cid, SW *psw, ALO* paloParent, OID oid, int isplice);