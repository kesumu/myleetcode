#include "stdio.h"
#include "stdlib.h"
#include <string.h>

int decompose(int *nums, int numsSize, int *used_nums, int target_left, int* returnSize){
	for (int i = 0; i < numsSize; i++) {
		//try to use i to decompose
		if (used_nums[i] != 0) {
			continue;
		}else {
			if (nums[i] == target_left) {
				//solution found
				used_nums[i] = 1;

				printf("Solution found!!! -- [");
				for (int udn = 0; udn<numsSize - 1; udn++) {
					printf("%d ,", used_nums[udn]);
				}
				printf("%d]", used_nums[numsSize - 1]);
				return 1;
			}else {
				int maxLevelOfUsedNum = 0;
				for (int un = 0; un < numsSize; un++) {
					if (maxLevelOfUsedNum < used_nums[un]) {
						maxLevelOfUsedNum = used_nums[un];
					}
				}
				used_nums[i] = maxLevelOfUsedNum+1;
				target_left = target_left - nums[i];

				printf("[");
				for (int udn = 0; udn<numsSize - 1; udn++) {
					printf("%d ,", used_nums[udn]);
				}
				printf("%d]  --used num[%d]: %d, target left: %d\n", used_nums[numsSize - 1], i, nums[i], target_left);

				//use this num to decompose
				int ret = decompose(nums, numsSize, used_nums, target_left, returnSize);
				if (ret == 1) {
					//found solution return idx
					return 1;
				}else if (ret == 0) {
					//cancel this num try next
					used_nums[i] = 0;
					target_left = target_left + nums[i];

					printf("[");
					for (int udn = 0; udn<numsSize - 1; udn++) {
						printf("%d ,", used_nums[udn]);
					}
					printf("%d]  --cancel num[%d]: %d, target left: %d\n", used_nums[numsSize - 1], i, nums[i], target_left);
				}
			}
		}
	}

	//no solution is found for all nums
    return 0;
}

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum_all(int* nums, int numsSize, int target, int* returnSize) {
	int *idx = malloc(numsSize * sizeof(int));
	int *used_nums = malloc(numsSize * sizeof(int));

	memset(used_nums, 0, numsSize * sizeof(int));

	decompose(nums, numsSize, used_nums, target, returnSize);

	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == 0) {
			used_nums[i] = 1;
		}
	}

	int size = 0;
	for (int i = 0; i < numsSize; i++) {
		if (used_nums[i] != 0) {
			size++;
			idx[size - 1] = i;
		}
	}

	free(used_nums);
	*returnSize = size;
	return idx;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int *idx = (int *)malloc(2 * sizeof(int));
	int *sorted_nums = (int *)malloc(numsSize * sizeof(int));
	int *tried_nums = (int *)malloc(numsSize * sizeof(int));
	int *true_idx = (int *)malloc(numsSize * sizeof(int));

	memset(tried_nums, 0, numsSize * sizeof(int));

	//sorted nums
	for (int i = 0; i < numsSize; i++) {
		sorted_nums[i] = nums[i];
		true_idx[i] = i;
		for (int j = 0; j < i; j++) {
			if (sorted_nums[i] < sorted_nums[j]) {
				//put i in front of j
				int tmp_i = sorted_nums[i];
				for (int k = i; k > j; k--) {
					sorted_nums[k] = sorted_nums[k - 1];
					true_idx[k] = true_idx[k-1];
				}
				sorted_nums[j] = tmp_i;
				true_idx[j] = i;
			}
		}
	}

	//printf("nums [%d", nums[0]);
	//for (int i = 1; i < numsSize; i++) {
	//	printf(", %d", nums[i]);
	//}
	//printf("]\n");

	//printf("sorted_nums [%d", sorted_nums[0]);
	//for (int i = 1; i < numsSize; i++) {
	//	printf(", %d", sorted_nums[i]);
	//}
	//printf("]\n");

	//printf("true_idx [%d", true_idx[0]);
	//for (int i = 1; i < numsSize; i++) {
	//	printf(", %d", true_idx[i]);
	//}
	//printf("]\n");


	for (int i = 0; i < numsSize; i++) {
		//try i
		int target_left = target - sorted_nums[i];
		tried_nums[i] = 1;
		int ret = -1;
		int j = numsSize / 2;
		if (j == i) {
			j = i+1;
			if (j >= numsSize) {
				j = i - 1;
			}
		}
		
		while (ret == -1 && j>=0 && j<numsSize && tried_nums[j] == 0) {
			tried_nums[j] = 1;
			if (target_left == sorted_nums[j]) {
				//found
				*returnSize = 2;
					
				idx[0] = true_idx[i] < true_idx[j] ? true_idx[i] : true_idx[j];
				idx[1] = true_idx[i] > true_idx[j] ? true_idx[i] : true_idx[j];
				return idx;
			}else if (target_left > sorted_nums[j]) {
				j++;
				if(j==i){
					j++;
				}
			}else {
				j--;
				if (j == i) {
					j--;
				}
			}
		}

		memset(tried_nums, 0, numsSize * sizeof(int));
	}

    return 0;
}

void test_two_sum(void){
	int nums[] = { 0,3,-3,4,-1 };
    int target = -1;
    int numsSize = 5;
    int returnSize = 0;
    int *idxs;

    idxs = twoSum(nums, numsSize, target, &returnSize);
    printf("\n%d [", returnSize);

    for(int i=0; i<returnSize-1;i++){
        printf("%d ,", idxs[i]);
    }
	if (returnSize > 0) {
		printf("%d]", idxs[returnSize - 1]);
	}

    return;
}