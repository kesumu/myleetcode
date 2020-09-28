#include "3sum_closest.h"
#include <iostream>

static int twoSumClosest(vector<int>& nums, int target, int exceptIdx) {
	int twoSum = nums[exceptIdx + 1] + nums[exceptIdx + 2];
	int nextSum;

	for (int i = exceptIdx + 1; i < nums.size(); i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			if (twoSum == target) {
				return twoSum;
			}

			nextSum = nums[i] + nums[j];
			if ((nextSum > target ? nextSum - target : target - nextSum) < (twoSum > target ? twoSum - target : target - twoSum)) {
				twoSum = nextSum;
			}
		}
	}

	return twoSum;
}

int Solution_3sum_closest::threeSumClosest(vector<int>& nums, int target) {
	/* nums size must be bigger than or equal to 3 */
	int sum = nums[0] + nums[1] + nums[2];
	int nextSum;

	for (int i = 0; i < nums.size() - 2; i++) {
		if (sum == target) {
			return sum;
		}
		nextSum = nums[i] + twoSumClosest(nums, target - nums[i], i);
		if ((nextSum > target ? nextSum - target : target - nextSum) < (sum > target ? sum - target : target - sum)) {
			sum = nextSum;
		}
	}

	return sum;
}

void Solution_3sum_closest::test(void) {
	vector<int> nums = {0,1,2};
	int target = 0;
	int output = this->threeSumClosest(nums, target);
	cout << output;
}