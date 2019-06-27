#include "regular_expression_matching.h"
#include <iostream>

bool isMatchHelper(char *s, int s_len, char* p, int p_len) {
	cout << "s["<<s_len << "]: "<< s << ", p["<<p_len<<"]: " << p<<"\n";
	if (p_len < 2) {
		if (p_len == s_len) {
			while (*p != '\0') {
				if (*p != *s && *p != '.') {
					return false;
				}
				s++;
				p++;
			}
			return true;
		}else {
			return false;
		}
	}else {
		if ((p[0] != s[0]) && (p[0] != '.') && (p[1] != '*')) {
			return false;
		}else {
			if (p[1] == '*') {
				//several cases
				bool ret = false;
				char *s_cpy = s;
				int s_cpy_len = s_len;
				while ((*p == *s_cpy || *p == '.') && *s_cpy != '\0') {
					//eat first char of s
					ret = isMatchHelper(s_cpy + 1, s_cpy_len - 1, p+2, p_len-2);
					if (ret) {
						return true;
					}else {
						//skip first char of s
						s_cpy++;
						s_cpy_len--;
					}
				}
				//use up first two char of p
				return isMatchHelper(s, s_len, p+2, p_len-2);
			}else if(s_len > 0){
				return isMatchHelper(s+1, s_len-1, p+1, p_len-1);
			}
			else {
				return false;
			}
		}
	}
	return false;
}

bool Solution_regular_expression_matching::isMatch(string s, string p) {
	char *s_char = (char*)s.c_str();
	char *p_char = (char*)p.c_str();
	int s_len = s.length();
	int p_len = p.length();

	return isMatchHelper(s_char, s_len, p_char, p_len);
}
void Solution_regular_expression_matching::test(void) {
	string s = "aacaaacbacccbcbaaaaaaaaaaaaaaaaaaaaaaaaa";
	string p = ".*aaaaaaaaaaaaaaaaaaaaaaa";

	cout << isMatch(s, p);
}