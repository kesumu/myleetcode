#include "integer_to_roman.h"
#include <iostream>

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

string Solution_integer_to_roman::intToRoman(int num) {
	string output;
	int modResult = 0;
	int tenCnt = 0;
	string symbolOne;
	string symbolFive;
	string symbolTen;

	while (num > 0) {
		modResult = num % 10;

		if (tenCnt == 0) {
			symbolOne = "I";
			symbolFive = "V";
			symbolTen = "X";
		} else if (tenCnt == 1) {
			symbolOne = "X";
			symbolFive = "L";
			symbolTen = "C";
		} else if (tenCnt == 2) {
			symbolOne = "C";
			symbolFive = "D";
			symbolTen = "M";
		} else if (tenCnt == 3) {
			symbolOne = "M";
			symbolFive = "";
			symbolTen = "";
		}

		switch (modResult)
		{
		case 0:
			/* do nothing */
			break;
		case 1:
			output.insert(0, symbolOne);
			break;
		case 2:
			output.insert(0, symbolOne);
			output.insert(0, symbolOne);
			break;
		case 3:
			output.insert(0, symbolOne);
			output.insert(0, symbolOne);
			output.insert(0, symbolOne);
			break;
		case 4:
			output.insert(0, symbolFive);
			output.insert(0, symbolOne);
			break;
		case 5:
			output.insert(0, symbolFive);
			break;
		case 6:
			output.insert(0, symbolOne);
			output.insert(0, symbolFive);
			break;
		case 7:
			output.insert(0, symbolOne);
			output.insert(0, symbolOne);
			output.insert(0, symbolFive);
			break;
		case 8:
			output.insert(0, symbolOne);
			output.insert(0, symbolOne);
			output.insert(0, symbolOne);
			output.insert(0, symbolFive);
			break;
		case 9:
			output.insert(0, symbolTen);
			output.insert(0, symbolOne);
			break;
		default:
			break;
		}

		num /= 10;
		tenCnt++;
	}

	return output;
}

void Solution_integer_to_roman::test(void) {
	string output = this->intToRoman(3999);
	cout << output.c_str();
}