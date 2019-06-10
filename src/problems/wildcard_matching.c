#include "stdio.h"

#include "wildcard_matching.h"

bool isMatchNoStar(char *s1, int startOfS1, char *p1, int startOfP1, int p1_len, int *offsetOfMatched) {
	int idx_s1 = startOfS1;
	int idx_p1 = startOfP1;



	while (s1[idx_s1] != '\0') {
		if (idx_p1 == p1_len + startOfP1) {
			return true;
		}
		else if (p1[idx_p1] == '?') {
			idx_p1++;
		}
		else if (p1[idx_p1] == s1[idx_s1]) {
			idx_p1++;
		}
		else {
			//current match failed, restart match
			*offsetOfMatched = idx_s1 + 1;
			idx_p1 = startOfP1;
		}
		idx_s1++;
	}

	if (idx_p1 == p1_len + startOfP1) {
		return true;
	}
	return false;
}

bool isMatch(char* s, char* p) {
	int idx_s = 0;
	int s_len = 0;
	int idx_p = 0;
	int p_len = 0;
	int p_part_len = 0;
	int offsetOfMatched = 0;
	int startOfS1 = 0;
	int startOfP1 = 0;
	int idx_s1 = 0;
	int idx_p1 = 0;
	int p1_len = 0;
	bool partIsMatched;
	int p_not_star_size = 0;

	if (s[0] != '\0' && p[0] == '\0') {
		return false;
	}

	//if p is all '*', then true
	while (p[idx_p] == '*') {
		idx_p++;
	}
	if (p[idx_p] == '\0') {
		return true;
	}

	idx_s = 0;
	while (s[idx_s] != '\0') {
		idx_s++;
	}
	s_len = idx_s;
	idx_p = 0;
	while (p[idx_p] != '\0') {
		idx_p++;
	}
	p_len = idx_p;

	//if p not '*' size bigger than s, then false
	for (idx_p = 0; idx_p < p_len; idx_p++) {
		if (p[idx_p] != '*') {
			p_not_star_size++;
		}
	}
	if (p_not_star_size > s_len) {
		return false;
	}

	idx_p = 0;
	if (s[0] == '\0') {
		while (p[idx_p] != '\0') {
			if (p[idx_p] != '?' || p[idx_p] != '*') {
				return false;
			}
			idx_p++;
		}
		return true;
	}

	idx_s = 0;
	idx_p = 0;
	while (idx_p <= p_len) {
		//skip current '*'
		for (; idx_p <= p_len; idx_p++) {
			if (p[idx_p] == '\0') {
				return true;
			}
			else if (p[idx_p] != '*') {
				break;
			}
		}

		//try match next part of p, before '*'
		//p_part_len = 0;
		//while (idx_p != p_len && p[idx_p] != '*') {
		//	p_part_len++;
		//	idx_p++;
		//}
		p_part_len = 0;
		for (; idx_p <= p_len; idx_p++) {
			if (idx_p != p_len && p[idx_p] != '*') {
				p_part_len++;
			}
			else {
				break;
			}
		}

		startOfS1 = idx_s;
		startOfP1 = idx_p - p_part_len;

		if (startOfP1 == 0) {
			partIsMatched = true;
			idx_s1 = 0;
			idx_p1 = 0;
			p1_len = p_part_len;
			offsetOfMatched = idx_s1;
			//first part, without '*' before
			for (; idx_p1 < idx_p; idx_p1++, idx_s1++) {
				if (p[idx_p1] == s[idx_s1] || p[idx_p1] == '?') {
					continue;
				}
				else {
					partIsMatched = false;
				}
			}
		}
		else if (startOfP1 + p_part_len == p_len) {
			//last part, without '*' after, but with '*' before
			partIsMatched = true;
			if (idx_s > s_len - p_part_len) {
				return false;
			}
			idx_s = s_len - p_part_len;
			idx_s1 = idx_s;
			idx_p1 = startOfP1;
			p1_len = p_part_len;
			offsetOfMatched = idx_s1;
			//first part, without '*' before
			for (; idx_p1 < idx_p; idx_p1++, idx_s1++) {
				if (p[idx_p1] == s[idx_s1] || p[idx_p1] == '?') {
					continue;
				}
				else {
					partIsMatched = false;
				}
			}
		}
		else {
			//--------------------------------------------------------
			partIsMatched = false;
			idx_s1 = startOfS1;
			idx_p1 = startOfP1;
			p1_len = p_part_len;
			offsetOfMatched = idx_s1;
			//while (idx_s1 <= s_len) {
			for (; idx_s1 < s_len; idx_s1++) {
				if (idx_p1 == p_len || idx_p1 == p1_len + startOfP1) {
					partIsMatched = true;
					break;
				}
				else if (p[idx_p1] == '?') {
					idx_p1++;
				}
				else if (p[idx_p1] == s[idx_s1]) {
					idx_p1++;
				}
				else {
					//current match failed, restart match
					offsetOfMatched++;
					idx_s1 = offsetOfMatched - 1;
					idx_p1 = startOfP1;
				}
				//idx_s1++;
			}
			//}
			if (idx_p1 == p_len || idx_p1 == p1_len + startOfP1) {
				partIsMatched = true;
			}
			else {
				partIsMatched = false;
			}
			///------------------------------------------------------------
		}

		//this part of p must be matched, otherwise failed directly
		if (partIsMatched) {
			//move pointer of s to skip the used match string
			idx_s = offsetOfMatched + p_part_len;
		}
		else {
			return false;
		}

		//check next '*' matched or not
		if (idx_p < p_len && p[idx_p] == '*') {
			continue;//keep searching next part
		}
		else {
			if (idx_p >= p_len && idx_s >= s_len) {
				return true;
			}
			else if (idx_p >= p_len && p[p_len - 1] == '*') {
				return true;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

void test_wildcard_matching(void) {
	char a[64] = "abcd";
	char b[64] = "*?*?*?*?";

	bool ret = false;

	ret = isMatch(a, b);

	printf("ret: %d", ret);

	printf("\nclick to close...\n");
	getchar();
	return;
}