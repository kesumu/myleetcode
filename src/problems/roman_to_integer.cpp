#include "roman_to_integer.h"

#include <iostream>


int Solution_roman_to_integer::romanToInt(string s) {
	int currTotalValue = 0;
	int len = s.length();
	int lastCharValue = 0;
	int currCharValue = 0;
	int waitConsumeValue = 0;
	char currChar;
	for (int i=0; i<len; i++) {
		currChar = s.at(i);
		switch (currChar)
		{
			case 'I': currCharValue = 1; break;
			case 'V': currCharValue = 5; break;
			case 'X': currCharValue = 10; break;
			case 'L': currCharValue = 50; break;
			case 'C': currCharValue = 100; break;
			case 'D': currCharValue = 500; break;
			case 'M': currCharValue = 1000; break;
			default:
				{
					//#find next valid index
					do {
						i++;
						if (i == len) {
							break;
						}
						currChar = s.at(i);
					} while (currChar != 'I'
						&& currChar != 'V'
						&& currChar != 'X'
						&& currChar != 'L'
						&& currChar != 'C'
						&& currChar != 'D'
						&& currChar != 'M');
					currTotalValue += waitConsumeValue;
					lastCharValue = 0;
					waitConsumeValue = 0;
					i--; //back to next valid char
					continue;
				}
				break;
		}

		if (waitConsumeValue == 0) {
			waitConsumeValue = currCharValue;
		}else if(waitConsumeValue < currCharValue) {
			//#need to consume lastCharValue
			currTotalValue += currCharValue - waitConsumeValue;
			waitConsumeValue = 0;
		}else {
			//#consume lastCharValue, but need to wait for currCharValue
			currTotalValue += waitConsumeValue;
			waitConsumeValue = currCharValue;
		}

		lastCharValue = currCharValue;


		//cout << s.substr(i+1, len) << ": " << currTotalValue << '\n';
	}

	return currTotalValue + waitConsumeValue;
}


void Solution_roman_to_integer::test(void) {
	string s = "BMVBXWAJNK";

	cout << s << '\n';
	cout << this->romanToInt(s);
}