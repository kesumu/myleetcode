#include "remove_duplicates_from_sorted_array.h"
#include <iostream>

int Solution_remove_duplicates_from_sorted_array::removeDuplicates(vector<int>& nums) {
	if (nums.size() < 2) {
		return nums.size();
	}
	int last_i = 0;
	for (int i = 1; i < nums.size(); i++) {
		if(nums[i] != nums[last_i]){
			if (last_i + 1 != i) {
				nums[last_i + 1] = nums[i];
			}
			last_i++;
		}
	}
	return last_i+1;
}

void Solution_remove_duplicates_from_sorted_array::test(void) {
	vector<int> nums = {1,2};

	cout << this->removeDuplicates(nums);
	return;
}
