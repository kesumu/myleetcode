#include "letter_combinations_of_a_phone_number.h"
#include <iostream>

vector<string> Solution_letter_combinations_of_a_phone_number::letterCombinations(string digits) {
	vector<string> v;
	if (digits.size() < 1) {
		return v;
	}
	vector<int> v_idx;
	vector<int> bound;
	const string num_2_char[8] = { "abc" , "def" ,"ghi" ,"jkl" ,"mno" ,"pqrs" ,"tuv","wxyz" };

	for (int i = 0; i < digits.size(); i++) {
		switch (digits[i])
		{
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			v_idx.push_back(digits[i] - '2');
			break;
		default:
			return v;
			break;
		}
	}

	int len = 1;
	for (int i = v_idx.size() - 1; i >= 0; i--) {
		if (v_idx[i] == 5 || v_idx[i] == 7) {
			len = len * 4;
		}
		else {
			len = len * 3;
		}
		bound.insert(bound.begin(), len);
	}

	string base = "";
	int str_len = v_idx.size();
	for (int i = 0; i < v_idx.size(); i++) {
		base += num_2_char[v_idx[i]][0];
	}

	for (int i = 0; i < len; i++) {
		v.push_back(base);

		//check need to update base or not
		for (int j = str_len - 1; j >= 0; j--) {
			if ((i+1) % bound[j] == 0) {
				//new char in the center
				base[j] = num_2_char[v_idx[j]][0];
			}
			else {
				int new_char_idx = ((i + 1) % bound[j]);
				if (j != str_len - 1) {
					new_char_idx = new_char_idx / bound[j + 1];
				}
				base[j] = num_2_char[v_idx[j]][new_char_idx];
				break;
			}
		}
	}
	return v;
}


void Solution_letter_combinations_of_a_phone_number::test(void) {
	string digits = "221";//2387465458

	vector<string> v = this->letterCombinations(digits);

	cout << "[";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].c_str() << ", ";
	}
	cout << "]";
}

