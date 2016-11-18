//---------------------------------------------------------------------------

#ifndef ConvertNumbersH
#define ConvertNumbersH

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
#include <limits.h>
//---------------------------------------------------------------------------

class TConvertNumbers
{
private:
	int max_len;
	std::string Result;

	enum Numerical_Signs {
		DEC='D',
		HEX='H',
		BIN='B',
		OCT='O'
	} Signs;

	bool CheckConversion(long int nr);
	bool Parse(std::string sToParse);

	bool dec2bin(std::string sNumber);
	bool dec2hex(std::string sNumber);
	bool dec2oct(std::string sNumber);
	bool hex2dec(std::string sNumber);
	bool hex2bin(std::string sNumber);
	bool hex2oct(std::string sNumber);
	bool bin2dec(std::string sNumber);
	bool bin2hex(std::string sNumber);
	bool bin2oct(std::string sNumber);
	bool oct2dec(std::string sNumber);
	bool oct2hex(std::string sNumber);
	bool oct2bin(std::string sNumber);
public:
	TConvertNumbers(void);
	virtual ~TConvertNumbers(void);

	bool Convert(std::string sToParse, std::string& sResult);
};
#endif
