#include "string_to_integer_atoi.h"
#include <iostream>

int Solution_string_to_integer_atoi::myAtoi(string str) {
	const int BOUND = 2147483647;
	const int BOUND_DIV_10 = 214748364;
	int value = 0;
	int sign = 0;
	bool outOfRange = false;
	bool numberSignFound = false;

	for (string::iterator it = str.begin(); it != str.end(); ++it) {
		if (*it == ' ') {
			if (!numberSignFound) {
				continue;
			}
			else {
				break;
			}
		}
		else if (*it == '-') {
			numberSignFound = true;
			if (sign == 0) {
				sign = -1;
			}else {
				break;
			}
		}
		else if (*it == '+') {
			numberSignFound = true;
			if (sign == 0) {
				sign = 1;
			}
			else {
				break;
			}
		}
		else if (*it >= '0' && *it <= '9') {
			numberSignFound = true;
			if (sign == 0) {
				sign = 1;
			}
			
			if (sign == 1) {
				if (value > BOUND_DIV_10 || value * 10 >= BOUND - (*it - '0')) {
					return BOUND;
				}
				else {
					value = value * 10 + (*it - '0');
				}
			}else if (sign == -1) {
				if (value > BOUND_DIV_10 || value * 10 - 1>= BOUND - (*it - '0')) {
					return -(BOUND + 1);
				}
				else {
					value = value * 10 + (*it - '0');
				}
			}
		}
		else {
			break;
		}
	}

	return sign * value;
}



void Solution_string_to_integer_atoi::test(void) {
	string str = "0 23";
	
	cout<< this->myAtoi(str);

	return;
}