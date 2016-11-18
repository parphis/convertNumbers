//---------------------------------------------------------------------------
/**
 * Purpose: provide a useful command line tool to convert numbers
 * between numericals.
 *
 * Format of the command:
 *
 * <NUMBER><FROM><TO>, where
 * FROM: the numerical must be converted;
 * NUMBER: the number must be converted;
 * TO: the target numerical;
 *
 * Examples:
 *
 * Convert the decimal number 1002 to hexadecimal: 1002DH
 * Convert the binary number 11001111 to decimal: 11001111BD
 */


#include <tchar.h>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>

#include "ConvertNumbers.h"
using namespace std;
//---------------------------------------------------------------------------

int no_of_errors;
istream* input;
const int max_read_in = 1024;

int _tmain(int argc, _TCHAR* argv[])
{
	switch (argc)
	{
		case 1 :				// read from standard input
			input = &cin;
			break;
		case 2 :
			input = new istringstream(argv[1], istringstream::in);		// read argument string
			break;
		default :
			cout << "\tUsage 1" << endl << "\t\tCN <NUMBER><FROM><TO>" << endl;
			cout << "\t\tNUMBER: the number must be converted"  << endl;
			cout << "\t\tFROM: the numerical must be converted"  << endl;
			cout << "\t\tTO: the target numerical."  << endl << endl;
			cout << "\tUsage 2" << endl << "\t\tCN without argument and then ";
			cout << "use the same format as desribed above." << endl;
			return 1;
	}

	char *str = new char[max_read_in];
	std::string sIn = "";
	std::string sResult = "";

	while (*input)
	{
		(*input).getline(str, max_read_in);

		sIn = str;

		if (sIn!="")
		{
			TConvertNumbers *cn = new TConvertNumbers();

			if (cn->Convert(sIn, sResult))
				cout << sResult << endl;
			else
				// convert error
				cout << "An error has occured: " << sResult << endl;

			delete cn;
			sIn = "";
		}
	}

	if (input != &cin) delete input;

	return no_of_errors;
}
//---------------------------------------------------------------------------

