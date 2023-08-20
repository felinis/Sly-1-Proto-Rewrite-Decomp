#pragma once
#include <vector>
#include "bis.h"
#include "dl.h"
#include "spaprops.h"

// This is where all the local objects are stored 
// ALL OBECTS THAT ARE STORED IN THE g_mpcidpvt GLOBAL VARIABLE ARE TO BE STORED IN HERE
// Initialize all objects into there constructor

// Local Object
// This is like a header for the objects
class LO
{
	public:
		// Class ID
		CID cid;
		// Object ID
		OID oid;
		DLE dleOid;
		// Parent Static World Object
		void *psw;
		// Objects Parent
		void *paloParent;
		DLE dleChild;
		LO* ploCidNext;
		char* pchzName;
		uint64_t dtickPerf;

		// Initializes LO
		void InitLo(LO *parentLo);
		void SetLoDefaults(LO *parentLo);
		// Adds LO to parent LO if LO doesnt have a parent it makes LO a parent
		void AddLo(LO *plo);
};

// Static World
class SW
{
	public:
		// Object Header
		LO LocalObject;
		int cpsoAll;
		int cpsoRoot;
		DL dlRoot;
		DL dlChild;
		DL dlMRD;
		DL dlBusy;
		DL dlBusySo;
		DL dlMRDRealClock;
		// Used to store the first parent of a local object.
		DL objectParents[512];
		LO* aploCidHead[162];
		DL dlAsega;
		DL dlAsegaRealClock;
		DL dlAsegaPending;
		DL dlSma;
		DL dlAmb;
		DL dlExc;
		DL dlExplste;
		DL dlLight;
		DL dlShadow;
		DL dlFader;
		DL dlRealClockFader;
		DL dlShape;
		DL dlPathzone;
		DL dlProxy;
		DL dlFly;
		DL dlDprize;
		DL dlRat;
		DL dlRathole;
		DL dlDartFree;
		DL dlSpire;
		DL dlRail;
		DL dlLanding;
		DL dlBusyLasen;
		DL dlBlipg;
		DL dlBlipgFree;
		DL dlCrfod;

		// Initializing object header
		SW (LO plo);

		// Initializing SW object
		void InitSw();
		// Returns a object parent list from SW parent list
		DL* PdlFromSwOid(SW* psw, OID oid);
		// Loads all global world data from binary file
		void LoadSwFromBrx(SW *psw, CBinaryInputStream *pbis);
		// Sets gravity for level
		void SetSwGravity(SW *sw, float z);
};

// Global pointer to parent static world object
static SW *g_psw;

// A Local Object
class ALO
{
	public:
		// Object header
		LO localObject;
		DL dlChild;
		// Initializing ALO object
		ALO (CID cid, SW* parentSW, ALO* paloParent, OID oid, int isplice);

		// Loads ALO object from binary file
		void LoadAloFromBrx(ALO *parentAlo, CBinaryInputStream *pbis);
};