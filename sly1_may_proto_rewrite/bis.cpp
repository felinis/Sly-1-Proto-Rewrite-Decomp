#include "bis.h"

CBinaryInputStream::CBinaryInputStream(std::string fileName)
{
    file.open(fileName, std::ios::binary);
}

void CBinaryInputStream::Align(int n)
{
    std::streamoff pos = file.tellg();

    if (pos % n != 0)
        pos += (uint32_t)(n - (pos % n));

    file.seekg(pos, SEEK_SET);
}

byte CBinaryInputStream::U8Read()
{
    byte temp;
    file.read(reinterpret_cast<char*> (&temp), sizeof(byte));
    return temp;
}

uint16_t CBinaryInputStream::U16Read()
{
    int16_t temp;
    file.read(reinterpret_cast<char*> (&temp), sizeof(uint16_t));
    return temp;
}

uint32_t CBinaryInputStream::U32Read()
{
    uint32_t temp;
    file.read(reinterpret_cast<char*> (&temp), sizeof(uint32_t));
    return temp;
}

int8_t CBinaryInputStream::S8Read()
{
    int8_t temp;
    file.read(reinterpret_cast<char*> (&temp), sizeof(int8_t));
    return temp;
}

int16_t  CBinaryInputStream::S16Read()
{
    int16_t temp;
    file.read(reinterpret_cast<char*> (&temp), sizeof(int16_t));
    return temp;
}

int32_t CBinaryInputStream::S32Read()
{
    int32_t temp;
    file.read(reinterpret_cast<char*> (&temp), sizeof(int32_t));
    return temp;
}

float CBinaryInputStream::F32Read()
{
    float temp;
    file.read(reinterpret_cast<char*> (&temp), sizeof(float));
    return temp;
}

void CBinaryInputStream::Close()
{
    file.clear();
    file.close();
}

CBinaryInputStream::~CBinaryInputStream()
{
    Close();
}