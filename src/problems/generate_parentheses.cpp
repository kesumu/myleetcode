#include "generate_parentheses.h"
#include <iostream>

vector<string> Solution_generate_parentheses::generateParenthesis(int n) {
	vector<string> vs;
	if (n<0) {
		return vs;
	}
	else if (n == 0) {
		vs.push_back("");
	}
	else if (n == 1) {
		vs.push_back("()");
	}
	else {
		//#1 leave 0
		//#2 leave 1
		//#.. leave n-1
		for (int i = 0; i < n; i++) {
			vector<string> prex_vs = (this->generateParenthesis(n - i-1));
			vector<string> suff_vs = (this->generateParenthesis(i));
			for (int j = 0; j < prex_vs.size();j++) {
				for (int k = 0; k < suff_vs.size(); k++) {
					string s;
					s.append("(");
					s.append(prex_vs[j]);
					s.append(")");
					s.append(suff_vs[k]);
					vs.push_back(s);
				}
			}
		}
	}

	return vs;
}


void Solution_generate_parentheses::test(void) {
	int n = 2;
	vector<string> vs = this->generateParenthesis(n);

	for (int i = 0; i < vs.size(); i++) {
		cout << vs.at(i)<<"\n";
	}
}