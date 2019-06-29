#include "longest_common_prefix.h"

#include <iostream>

string Solution_longest_common_prefix::longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 0) {
		return "";
	}
	int prefix_cnt = strs[0].length();
	for (int i = 0; i < strs.size()-1; i++) {
		if (prefix_cnt == 0) {
			return "";
		}
		string *s1 = &strs[i];
		string *s2 = &strs[i + 1];
		int len = s1->length() < s2->length() ? s1->length() : s2->length();
		if (len < prefix_cnt) {
			prefix_cnt = len;
		}
		for (int j = 0; j < prefix_cnt; j++) {
			if (s1->at(j) != s2->at(j)) {
				prefix_cnt = j;
				break;
			}
		}
	}
	return strs[0].substr(0,prefix_cnt);
}

void Solution_longest_common_prefix::test(void) {
	vector<string> strs = {};

	cout << this->longestCommonPrefix(strs);
}