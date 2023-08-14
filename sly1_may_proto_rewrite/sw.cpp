#include "sw.h"

void DeleteSw(SW* psw)
{

}

void SetupBulkDataFromBrx(int fLoadBulkData, CBinaryInputStream* pbis)
{
	uint32_t BulkDataSize = pbis->S32Read();
	uint32_t BulkDataSignal = pbis->S32Read();
}