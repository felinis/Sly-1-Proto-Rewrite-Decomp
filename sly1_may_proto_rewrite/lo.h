#pragma once
#include <vector>
#include "bis.h"
#include "find.h"
#include "spaprops.h"

// This is where all the local objects are stored 
// ALL OBECTS THAT ARE STORED IN THE g_mpcidpvt GLOBAL VARIABLE ARE TO BE STORED IN HERE


// Local Object
class LO
{
	public:
		CID cid; // Current Class
		OID oid; // Object ID
		//DLE dleOid;
		void *psw; // Parent Static World Object
		void *paloParent; // Objects Parent
		//DLE dleChild;
		LO *ploCidNext;
		//MQ* pmqFirst;
		//std::string objectname; // Object Name
		//CFrame* pframe;
		//PXR* ppxr;
		uint64_t dtickPerf;

		LO   SetLo(LO parentLo, CID cid, void* parentSW, void* paloParent, OID oid);
		void InitLo(LO *parentLo);
		void SetLoDefaults(LO *parentLo);
		void AddLo(LO *parentLo);
};

// Static World
class SW : public LO
{
	public:
		// Object Header
		LO localObject;

		// Used to store the first parent of a local object.
		std::vector <void*> objectmap[512];

		// Initializing SW object
		SW(CID cid, SW* parentSW, void* paloParent, OID oid);

		// Loads all global world data from binary file
		void LoadSwFromBrx(SW *parentSW, CBinaryInputStream *pbis);
};

static SW *g_psw; // Global pointer to parent static world object

// A Local Object
class ALO : public LO
{
	public:
		// Initializing ALO object
		ALO (CID cid, SW* parentSW, ALO* paloParent, OID oid, int isplice);

		// Loads ALO object from binary file
		void LoadAloFromBrx(ALO *parentAlo, CBinaryInputStream *pbis);
};