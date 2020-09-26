#include "palindrome_number.h"
#include <iostream>



bool Solution_palindrome_number::isPalindrome(int x){
	if (x < 0) {
		return false;
	} else if (x == 0) {
		return true;
	}

	int remaining = x;
	int reversedX = 0;

	while (remaining > 0) {
		if (reversedX > INT_MAX / 10) {
			return false;
		} else {
			reversedX = reversedX * 10 + (remaining % 10);
		}
		remaining /= 10;
	}

	return x == reversedX;
}

void Solution_palindrome_number::test(void) {
	bool output = this->isPalindrome(2147483621);
	cout << output;
}