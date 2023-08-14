#pragma once
#include "lo.h"

void DeleteSw(SW* psw); // Resets SW object
void SetupBulkDataFromBrx(int fLoadBulkData, CBinaryInputStream *pbis);