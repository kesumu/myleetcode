#include "implement_strstr.h"
#include <iostream>

int Solution_implement_strstr::strStr(string haystack, string needle) {
	if (needle.empty()) {
		return 0;
	}
	else if (needle.size() > haystack.size()) {
		return -1;
	}

	for (int i = 0; i <= haystack.size() - needle.size(); i++) {
		if (haystack[i] == needle[0]) {
			//#continue
			bool contained = true;
			for (int j = 1; j < needle.size(); j++) {
				if (needle[j] != haystack[i + j]) {
					contained = false;
					break;
				}
			}
			if (contained) {
				return i;
			}
		}
	}
	return -1;
}

void Solution_implement_strstr::test(void) {
	string haystack = "ab";
	string needle = "baa";

	cout << this->strStr(haystack, needle);
}
