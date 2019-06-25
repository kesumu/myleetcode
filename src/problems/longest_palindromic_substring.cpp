#include "longest_palindromic_substring.h"
#include <iostream>
#include <vector>

#define _CRT_SECURE_NO_WARNINGS
string Solution_longest_palindromic_substring::longestPalindrome(string s) {
	int len = s.length();
	if (len < 1) {
		return "";
	}
	else if (len < 2) {
		return s;
	}
	char *s_char = (char *)s.c_str();
	int max_found_len = 0;
	int max_found_left = 0;
	int max_found_right = 0;

	vector<int> posibleLeftBounds;
	vector<int> posibleRightBounds;
	//find seeds
	for (int i = 1; i < len; i++) {
		if (s_char[i - 1] == s_char[i]) {
			posibleLeftBounds.push_back(i - 1);
			posibleRightBounds.push_back(i);
		}
		if (i + 1 < len && s_char[i - 1] == s_char[i + 1]) {
			posibleLeftBounds.push_back(i - 1);
			posibleRightBounds.push_back(i + 1);
		}
	}
	int seeds_size = posibleLeftBounds.size();
	if (seeds_size < 1) {
		//no seeds
		//then aa, or only a
		for (int i = 0; i < len-1; i++) {
			if (s_char[i] == s_char[i + 1]) {
				//aa found, return aa
				return s.substr(i, 2);
			}
		}
		//no aa is found, return a
		return s.substr(0, 1);
	}

	//expand seeds
	int left = 0;
	int right = 0;
	while (seeds_size > 0) {
		for (int i = 0; i < seeds_size; i++) {
			left = posibleLeftBounds[i];
			right = posibleRightBounds[i];
			if (left != 0 && right != len - 1 && s_char[left - 1] == s_char[right + 1]) {
				//expand more
				posibleLeftBounds[i] = left - 1;
				posibleRightBounds[i] = right + 1;
			}else {
				//reach wall
				//or cant expand any more
				if (max_found_len < right - left + 1) {
					max_found_len = right - left + 1;
					max_found_right = right;
					max_found_left = left;
					cout << "Found: " << s.substr(max_found_left, max_found_right + 1 - max_found_left) << '\n';
				}

				//throw this seed
				posibleLeftBounds.erase(posibleLeftBounds.begin() + i);
				posibleRightBounds.erase(posibleRightBounds.begin() + i);
				seeds_size--;
			}
		}
	}

	return s.substr(max_found_left, max_found_right + 1 - max_found_left);
}

void Solution_longest_palindromic_substring::test(void) {
	string a = "babaddtattarrattatddetartrateedredividerb";
	std::cout << this->longestPalindrome(a);
	return;
}