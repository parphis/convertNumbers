/**
 * Class TConvertNumbers.
 *
 * Purpose: convert a given number into other number system.
 *
 * The public function "Convert" look for a STRING which must be in the
 * following format:
 *
 *    <NUMBER><FROM><TO>, where
 *       NUMBER: the number must be converted;
 *       FROM: the numerical must be converted;
 *       TO: the target numerical;
 *
 * Examples:
 *
 * Convert the decimal number 1002 to hexadecimal: 1002DH
 * Convert the binary number 11001111 to decimal: 11001111BD
 *
 * Version history
 *
 * 1.0.0.0 /08.03.2012/
 * This is the first usable version.
 *
 */
//---------------------------------------------------------------------------


#include "ConvertNumbers.h"
//---------------------------------------------------------------------------

TConvertNumbers::TConvertNumbers(void) : max_len(256),Result(""), Signs(DEC)
{
	;
}
TConvertNumbers::~TConvertNumbers(void)
{
    ;
}

/**
 * Receives a string which will be parsed and returns the converted number as
 * a string.
 *
 * @param sToParse | string
 * @param sResult | string
 * @return bool
 */
bool TConvertNumbers::Convert(std::string sToParse, std::string& sResult)
{
	bool res = this->Parse(sToParse);

	sResult = Result;

	return res;
}

/**
 * Handle conversion errors.
 *
 * @param nr | long int
 * @return bool
 */
bool TConvertNumbers::CheckConversion(long int nr)
{
	// error: invalid conversion
	if (nr==0)
	{
		Result = "Invalid conversion.";
		return false;
	}
	// error: out of range
	if (nr==LONG_MAX || nr==LONG_MIN)
	{
		Result = "Out of range.";
		return false;
	}

	return true;
}

/**
 * Given a string it parses it and decides the number types from and to convert
 * the number.
 * This is the requested string:
 * <NUMBER><FROM><TO>
 *
 * FROM and TO can be one of the followings: 'D'ecimal, 'B'inary, 'H'exadecimal,
 * 'O'ctal.
 * NUMBER is coming as a string.
 *
 * @param sToParse | string
 * @return bool
 */
bool TConvertNumbers::Parse(std::string sToParse)
{
	char cFrom = sToParse[sToParse.length()-2];
	char cTo = sToParse[sToParse.length()-1];

	if ((cFrom==DEC) & (cTo==BIN))
		//	call dec2bin
		return this->dec2bin(sToParse.substr(0, sToParse.length()-2));
	else if ((cFrom==DEC) & (cTo==HEX))
		// call dec2hex
		return this->dec2hex(sToParse.substr(0, sToParse.length()-2));
	else if ((cFrom==DEC) & (cTo==OCT))
		// call dec2oct
		return this->dec2oct(sToParse.substr(0, sToParse.length()-2));
	else if ((cFrom==BIN) & (cTo==DEC))
		// call bin2dec
		return this->bin2dec(sToParse.substr(0, sToParse.length()-2));
	else if ((cFrom==BIN) & (cTo==HEX))
		// call bin2hex
		return this->bin2hex(sToParse.substr(0, sToParse.length()-2));
	else if ((cFrom==BIN) & (cTo==OCT))
		// call bin2oct
		return this->bin2oct(sToParse.substr(0, sToParse.length()-2));
	else if ((cFrom==HEX) & (cTo==DEC))
		// call hex2dec
		return this->hex2dec(sToParse.substr(0, sToParse.length()-2));
	else if ((cFrom==HEX) & (cTo==BIN))
		// call hex2bin
		return this->hex2bin(sToParse.substr(0, sToParse.length()-2));
	else if ((cFrom==HEX) & (cTo==OCT))
		// call hex2oct
		return this->hex2oct(sToParse.substr(0, sToParse.length()-2));
	else if ((cFrom==OCT) & (cTo==DEC))
		// call oct2dec
		return this->oct2dec(sToParse.substr(0, sToParse.length()-2));
	else if ((cFrom==OCT) & (cTo==BIN))
		// call oct2bin
		return this->oct2bin(sToParse.substr(0, sToParse.length()-2));
	else if ((cFrom==OCT) & (cTo==HEX))
		// call oct2hex
		return this->oct2hex(sToParse.substr(0, sToParse.length()-2));
	else
	{
		// error: unknown from or to character
		Result = "Unkown FROM or TO character";
		return false;
	}

    return false;
}

/**
 * The following functions convert a given number (stored in string) into
 * another numerical format.
 *
 * @param sNumber | string
 * @return bool
 */
bool TConvertNumbers::dec2bin(std::string sNumber)
{
	long int nr = atol(sNumber.c_str());

	if (!this->CheckConversion(nr)) return false;

	char *buffer = new char[max_len];

	itoa(nr, buffer, 2);

	Result = buffer;

	delete [] buffer;

	return true;
}
bool TConvertNumbers::dec2hex(std::string sNumber)
{
	long int nr = atol(sNumber.c_str());

	if (!this->CheckConversion(nr)) return false;

	char *buffer = new char[max_len];

	itoa(nr, buffer, 16);

	Result = buffer;

	delete [] buffer;

	return true;
}
bool TConvertNumbers::dec2oct(std::string sNumber)
{
	long int nr = atol(sNumber.c_str());

	if (!this->CheckConversion(nr)) return false;

	char *buffer = new char[max_len];

	itoa(nr, buffer, 8);

	Result = buffer;

	delete [] buffer;

	return true;
}
bool TConvertNumbers::hex2dec(std::string sNumber)
{
    unsigned int x;
	std::stringstream ss;
	ss << std::hex << sNumber;
	ss >> x;

	char *buffer = new char[max_len];

	itoa(x, buffer, 10);

	Result = buffer;

	delete [] buffer;

	return true;
}
bool TConvertNumbers::hex2bin(std::string sNumber)
{
	unsigned int x;
	std::stringstream ss;
	ss << std::hex << sNumber;
	ss >> x;

	char *buffer = new char[max_len];

	itoa(x, buffer, 10);

	this->dec2bin(buffer);

	delete [] buffer;

	return true;
}
bool TConvertNumbers::hex2oct(std::string sNumber)
{
	unsigned int x;
	std::stringstream ss;
	ss << std::hex << sNumber;
	ss >> x;

	char *buffer = new char[max_len];

	itoa(x, buffer, 10);

	this->dec2oct(buffer);

	delete [] buffer;

	return true;
}
bool TConvertNumbers::bin2dec(std::string sNumber)
{
	int i = sNumber.length()-1;
	int mul = 0;
	int res = 0;

	while (i>=0)
	{
		res += ((char)sNumber[i]-48)*pow((float)2,mul);
		i--;
		mul++;
	}

	char *buffer = new char[max_len];

	itoa(res, buffer, 10);

	Result = buffer;

	delete [] buffer;

	return true;
}
bool TConvertNumbers::bin2hex(std::string sNumber)
{
	int i = sNumber.length()-1;
	int mul = 0;
	int res = 0;

	while (i>=0)
	{
		res += ((char)sNumber[i]-48)*pow((float)2,mul);
		i--;
		mul++;
	}

	char *buffer = new char[max_len];

	itoa(res, buffer, 10);

	this->dec2hex(buffer);

	delete [] buffer;

	return true;
}
bool TConvertNumbers::bin2oct(std::string sNumber)
{
	int i = sNumber.length()-1;
	int mul = 0;
	int res = 0;

	while (i>=0)
	{
		res += ((char)sNumber[i]-48)*pow((float)2,mul);
		i--;
		mul++;
	}

	char *buffer = new char[max_len];

	itoa(res, buffer, 10);

	this->dec2oct(buffer);

	delete [] buffer;

	return true;
}
bool TConvertNumbers::oct2dec(std::string sNumber)
{
	unsigned int x;
	std::stringstream ss;
	ss << std::oct << sNumber;
	ss >> x;

	char *buffer = new char[max_len];

	itoa(x, buffer, 10);

	Result = buffer;

	delete [] buffer;

	return true;
}
bool TConvertNumbers::oct2hex(std::string sNumber)
{
	unsigned int x;
	std::stringstream ss;
	ss << std::oct << sNumber;
	ss >> x;

	char *buffer = new char[max_len];

	itoa(x, buffer, 10);

	this->dec2hex(buffer);

	delete [] buffer;

	return true;
}
bool TConvertNumbers::oct2bin(std::string sNumber)
{
	unsigned int x;
	std::stringstream ss;
	ss << std::oct << sNumber;
	ss >> x;

	char *buffer = new char[max_len];

	itoa(x, buffer, 10);

	this->dec2bin(buffer);

	delete [] buffer;

	return true;
}
