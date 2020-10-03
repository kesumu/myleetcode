#include "four_sum.h"
#include <algorithm>    // std::sort
#include <iostream>

vector<vector<int>> Solution_4sum::fourSum(vector<int>& nums, int target) {
	int len = nums.size();
	vector<vector<int>> vs = {};
	int newTarget = 0;
	int idx = 0;
	int next_idx = 0;

	if (nums.size() < 4) {
		return vs;
	}

	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 3; i++) {
		newTarget = target - nums[i];
		if (newTarget < 0 && nums[i + 1] >= 0) {
			/* no more possible answers */
			continue;
		}
		for (int j = i + 1; j < nums.size() - 2; j++) {
			newTarget = target - nums[i] - nums[j];
			if (newTarget < 0 && nums[j + 1] >= 0) {
				/* no more possible answers */
				continue;
			}
			for (int k = j + 1; k < nums.size() - 1; k++) {
				newTarget = target - nums[i] - nums[j] - nums[k];
				if (newTarget < 0 && nums[k + 1] >= 0) {
					/* no more possible answers */
					continue;
				}
				for (int m = k + 1; m < nums.size(); m++) {
					if (newTarget == nums[m]) {
						/* find one answer */
						vs.push_back(vector<int>({ nums[i], nums[j], nums[k], nums[m]}));
					}
					if (m < nums.size() - 1 && newTarget < 0 && nums[m + 1] >= 0) {
						continue;
					}
				}
			}
		}
	}

	/* delete the same answer from vs */
	
	while (idx + 1 < vs.size()) {
		next_idx = idx + 1;
		while (next_idx < vs.size()) {
			if (vs[idx][0] == vs[next_idx][0]
				&& vs[idx][1] == vs[next_idx][1]
				&& vs[idx][2] == vs[next_idx][2]
				&& vs[idx][3] == vs[next_idx][3]) {
				/* remove next_idx */
				vs.erase(vs.begin() + next_idx);
				/* after erase, no need to increase next_idx */
			}
			else {
				next_idx++;
			}
		}
		idx++;
	}

	return vs;
}

void Solution_4sum::test(void) {
	vector<int> nums = { 0,0,0,0 };
	int target = 1;
	vector<vector<int>> vs = this->fourSum(nums, target);
	cout << "[\n";
	for (int i = 0; i < vs.size(); i++) {
		vector<int> v = vs[i];
		cout << " [" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << "]\n";
	}
	cout << "]";
}

