#pragma once

// Stores the first parent of a object and last child of first parent
struct DL
{
	// Stores the first parent of a object
	void* pvFirst;
	// Stores the last child of of parent
	void* pvLast;
	// Base offset to DL entry
	int ibDle;
};

struct DLE
{
	// Stores next entry
	void* pvNext;
	// Stores previous entry
	void* pvPrev;
};

// Initializing DL
void InitDl(DL *pdl, int ibDle);
// Returns entry from list
DLE* PdleFromDlEntry(DL *pdl, void *pv);
// Appending a parent object to end of list
void AppendDlEntry(DL *pdl, void *pv);
// Returns whether entry was found in list or not
int FFindDlEntry(DL *pdl, void *pv);