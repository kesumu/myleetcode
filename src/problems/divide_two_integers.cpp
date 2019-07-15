#include "divide_two_integers.h"
#include <iostream>

using namespace std;

int Solution_divide_two_integers::divide(int dividend, int divisor) {
	if (dividend == 0) {
		return 0;
	}
	const int MIN = 0-2147483648;
	const int MAX = 2147483647;
	int quotient = 0;
	bool negative = false;
	if (dividend > 0 && divisor < 0) {
		dividend = -dividend;
		negative = true;
	}
	else if (dividend < 0 && divisor > 0) {
		divisor = -divisor;
		negative = true;
	}
	else if (dividend > 0 && divisor > 0) {
		dividend = -dividend;
		divisor = -divisor;
	}

	while (dividend <= divisor) {
		int power_divisior = divisor;
		for (int sub_quotient = -1; sub_quotient >= dividend; sub_quotient += sub_quotient) {
			if (dividend - power_divisior > power_divisior) {
				quotient += sub_quotient;
				dividend = dividend - power_divisior;
				break;
			}
			else {
				power_divisior += power_divisior;
			}
		}
	}

	if (negative) {
		return quotient;
	}
	else if(quotient == MIN){
		return MAX;
	}
	else {
		return -quotient;
	}
}
void Solution_divide_two_integers::test(void) {
	int dividend = 2147483647;
	int divisor = 1;
	cout << this->divide(dividend, divisor);
}
