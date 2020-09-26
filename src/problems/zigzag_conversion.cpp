#include "zigzag_conversion.h"
#include <iostream>

string Solution_zigzag_conversion::convert(string s, int numRows) {
	string output = s;
	if (numRows <= 1 || numRows >= s.size()) {
		return output;
	}

	int packetNum = 2 * numRows - 2;
	int totalA = s.size() / packetNum;
	int totalB = s.size() % packetNum;

	for (int i = 1; i < s.size() + 1; i++) {
		int outputIdx = 0;
		int rowIdx = 0;
		int a = 0;
		int b = 0;
		int modResult = 0;

		//calculate output index based on i and numRows
		a = i / packetNum;
		b = i % packetNum;

		if (b != 0 && b <= numRows) {
			rowIdx = b;
		} else if (b == 0) {
			rowIdx = 2;
		} else {
			rowIdx = 2 * numRows - b;
		}

		/* scan previous rows */
		for (int k = 1; k < rowIdx; k++) {
			if (k == 1) {
				outputIdx += totalA;
				if (totalB > 0) {
					outputIdx += 1;
				}
			} else {
				outputIdx += 2 * totalA;
				if (totalB == 0) {
					/* do nothing */
				} else if (totalB <= numRows) {
					if (totalB >= k) {
						outputIdx++;
					}
				} else {
					/* check  "go back line" overlap with k or not */
					if (k + totalB - 2 * numRows >= 0) {
						outputIdx += 2;
					} else {
						outputIdx++;
					}
				}
			}
		}

		/* check last row */
		if (rowIdx == 1 || rowIdx == numRows) {
			outputIdx += a;
			if (b > 0) {
				outputIdx++;
			}
		} else {
			outputIdx += 2 * a;
			if (b == 0) {
				/* do nothing */
			} else if (b <= numRows) {
				if (b >= rowIdx) {
					outputIdx++;
				}
			} else {
				/* check  "go back line" overlap with k or not */
				if (rowIdx + b - 2 * numRows >= 0) {
					outputIdx += 2;
				} else {
					outputIdx++;
				}
			}
		}

		output[outputIdx - 1] = s[i - 1];
	}

	return output;
}

void Solution_zigzag_conversion::test(void) {
	string output = this->convert("PAYPALISHIRING", 5);
	cout << output.c_str();
}