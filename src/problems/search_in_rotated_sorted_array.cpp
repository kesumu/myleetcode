#include "search_in_rotated_sorted_array.h"
#include <iostream>



int Solution_search_in_rotated_sorted_array::search(vector<int>& nums, int target) {
	if (nums.size() <= 2) {
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == target) {
				return i;
			}
		}
		return -1;
	}
	else {
		int left_idx = 0;
		int right_idx = nums.size() - 1;
		int max_idx = (left_idx + right_idx) / 2;

		if (nums[right_idx] > nums[left_idx]) {
			max_idx = right_idx;
		}else{
			//search max_idx
			while (true) {
				if (nums[max_idx] > nums[left_idx]) {
					left_idx = max_idx;
				}
				else if (nums[max_idx] < nums[right_idx]) {
					right_idx = max_idx;
				}else if (nums[(max_idx + 1) >= right_idx ? right_idx : (max_idx + 1)] <= nums[0] && nums[max_idx] >= nums[(max_idx - 1) <= left_idx ? left_idx : (max_idx - 1)]) {
					//found max_idx
					break;
				}
				max_idx = (left_idx + right_idx) / 2;
			}
		}


		//search target_idx
		int target_idx;
		if (target < nums[0] && target > nums[nums.size() - 1]) {
			return -1;
		}
		else if (target < nums[0] && max_idx < right_idx) {
			left_idx = max_idx + 1;
			right_idx = nums.size() - 1;
		}
		else if (target > nums[nums.size() - 1]) {
			left_idx = 0;
			right_idx = max_idx;
		}
		else if (target < nums[0] && max_idx == right_idx) {
			left_idx = 0;
			right_idx = max_idx;
		}
		

		if (target == nums[left_idx]) {
			return left_idx;
		}
		else if (target == nums[right_idx]) {
			return right_idx;
		}
		else if (target < nums[left_idx] || target > nums[right_idx]) {
			return -1;
		}
		target_idx = (left_idx + right_idx) / 2;
		while (true) {
			if (nums[target_idx] == target) {
				return target_idx;
			}
			else if (nums[(target_idx + 1)>= right_idx ?right_idx:(target_idx + 1)] > target && nums[(target_idx - 1) <= left_idx ? left_idx : (target_idx - 1)] < target) {
				return -1;
			}
			else if (nums[target_idx] < target) {
				left_idx = target_idx;
			}
			else if (nums[target_idx] > target) {
				right_idx = target_idx;
			}
			target_idx = (left_idx + right_idx) / 2;
		}
	}

	return -1;
}

void Solution_search_in_rotated_sorted_array::test(void) {
	vector<int> nums = { 7,8,1,2,3,4,5,6 };
	int target = 2;

	cout << this->search(nums, target);
}
