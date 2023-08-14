#pragma once
#include "lo.h"

// Initializes Options
void StartupBrx();

// Returns a new static world object based off that g_mpcidpvt global map
void* PloNew(CID cid, SW *psw, ALO* paloParent, OID oid, int isplice);