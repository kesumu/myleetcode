#include "valid_parentheses.h"
#include <vector>

bool Solution_valid_parentheses::isValid(string s) {
	vector<char> stack;

	int i = 0;
	while (s[i] != '\0') {
		switch (s[i])
		{
		case '(':
		case '{':
		case '[':
			stack.push_back(s[i]);
			break;
		case ')':
			if (stack.size()<1 || stack[stack.size() - 1] != '(') {
				return false;
			}
			else {
				stack.erase(stack.begin() + stack.size() - 1);
			}
			break;
		case '}':
			if (stack.size()<1 || stack[stack.size() - 1] != '{') {
				return false;
			}
			else {
				stack.erase(stack.begin() + stack.size() - 1);
			}
			break;
		case ']':
			if (stack.size()<1 || stack[stack.size() - 1] != '[') {
				return false;
			}
			else {
				stack.erase(stack.begin() + stack.size() - 1);
			}
			break;
		default:
			break;
		}
		i++;
	}

	if (stack.size() > 0) {
		return false;
	}
	return true;
}
void Solution_valid_parentheses::test(void) {
	string s = "{[]}";

	cout << this->isValid(s);
}

