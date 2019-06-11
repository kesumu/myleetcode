#include "stdio.h"

int lengthOfLongestSubstring(char * s) {
	char *s_cpy = s;
	int s_len = 0;
	while (*s_cpy != '\0') {
		s_len++;
		s_cpy++;
	}

	//char *lgstSub = malloc(s_len * sizeof(char));
	char *currSub;
	int rptFlag = 0;
	int ls_len = 0;
	int cs_len = 0;
	s_cpy = s;
	currSub = s;
	int i = 0;
	while (*s_cpy != '\0') {
		rptFlag = 0;
		for (i = 0; i < cs_len; i++) {
			if (currSub[i] == *s_cpy) {
				rptFlag = 1;
				break;
			}
		}

		//check rpt
		if (rptFlag == 0) {
			cs_len++;
		}else {
			//cut the sub string before last rpt char
			currSub = currSub + i + 1;
			cs_len = cs_len - i;
		}

		if (ls_len < cs_len) {
			ls_len = cs_len;
		}
		s_cpy++;
	}
	return ls_len;
}


void test_longest_substring_without_repeating_characters(void) {
	char s[10] = "pwwkew";

	printf("%d", lengthOfLongestSubstring(s));
}