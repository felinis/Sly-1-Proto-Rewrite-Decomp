#pragma once
#include "lo.h"

// Resets SW object
void DeleteSw(SW* psw);
void SetupBulkDataFromBrx(int fLoadBulkData, CBinaryInputStream *pbis);