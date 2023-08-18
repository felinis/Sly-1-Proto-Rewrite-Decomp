#pragma once

// Stores the first parent of a object and last child of first parent
struct DL
{
	// Stores the first parent of a object
	void* pvFirst;
	// Stores the last child of of parent
	void* pvLast;
	// Base offset to DL element
	int ibDle;
};

struct DLE
{
	// Stores next element
	void* pvNext;
	// Stores previous element
	void* pvPrev;
};

// Initializing DL
void InitDl(DL *pdl, int ibDle);
// Appending a parent object to end of list
void AppendDlEntry(DL *pdl, void *pv);