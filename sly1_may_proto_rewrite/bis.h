#pragma once
#include <fstream>

typedef unsigned char byte;

class CBinaryInputStream
{
	public:

		std::ifstream file;

		CBinaryInputStream(std::string fileName);

		void Align(int n);
		byte U8Read();
		uint16_t U16Read();
		uint32_t U32Read();
		int8_t S8Read();
		int16_t S16Read();
		int32_t S32Read();
		float F32Read();
		void Close();

		~CBinaryInputStream();
};