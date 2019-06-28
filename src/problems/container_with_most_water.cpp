#include "container_with_most_water.h"

#include <iostream>

int Solution_container_with_most_water::maxArea(vector<int>& height) {
	int len = height.size();
	if (len <= 1) {
		return 0;
	}
	int currMaxArea = height[0]<height[len-1]?height[0] * (len-1): height[len-1] * (len - 1);
	int currArea = 0;
	
	for (int i = 0; i < len; i++) {
		int oneWallIndex = 0;
		if (i % 2 == 0) {
			oneWallIndex = i;
		}else {
			oneWallIndex = len - ((i+1)/2);
		}

		if (height[oneWallIndex] == 0) {
			continue;
		}
		int leastDistance = currMaxArea / height[oneWallIndex];
		int leftBound = oneWallIndex - leastDistance;
		int rightBound = oneWallIndex + leastDistance;

		if (leftBound >= 0 && rightBound <= len - 1) {
			//both left wall and right wall are possible
			//#search farest one firstly
			if (oneWallIndex < len - 1 - rightBound) {
				//#search len - 1 side first
				for (int j = len - 1; j >= rightBound; j--) {
					if (j - oneWallIndex < leastDistance) {
						//when currMaxArea changes, if current distance is too short, don't need to keep searching
						break;
					}
					else {
						currArea = height[oneWallIndex]<height[j] ? height[oneWallIndex] * (j - oneWallIndex) : height[j] * (j - oneWallIndex);
						if (currArea > currMaxArea) {
							currMaxArea = currArea;
							leastDistance = currMaxArea / height[oneWallIndex];
						}
					}
				}

				for (int j = 0; j <= leftBound; j++) {
					if (oneWallIndex - j< leastDistance) {
						//when currMaxArea changes, if current distance is too short, don't need to keep searching
						break;
					}
					else {
						currArea = height[oneWallIndex]<height[j] ? height[oneWallIndex] * (oneWallIndex - j) : height[j] * (oneWallIndex-j);
						if (currArea > currMaxArea) {
							currMaxArea = currArea;
							leastDistance = currMaxArea / height[oneWallIndex];
						}
					}
				}
			}
			else {
				//#search 0 side first
				for (int j = 0; j <= leftBound; j++) {
					if (oneWallIndex - j< leastDistance) {
						//when currMaxArea changes, if current distance is too short, don't need to keep searching
						break;
					}
					else {
						currArea = height[oneWallIndex]<height[j] ? height[oneWallIndex] * (oneWallIndex - j) : height[j] * (oneWallIndex - j);
						if (currArea > currMaxArea) {
							currMaxArea = currArea;
							leastDistance = currMaxArea / height[oneWallIndex];
						}
					}
				}

				for (int j = len - 1; j >= rightBound; j--) {
					if (j - oneWallIndex < leastDistance) {
						//when currMaxArea changes, if current distance is too short, don't need to keep searching
						break;
					}
					else {
						currArea = height[oneWallIndex]<height[j] ? height[oneWallIndex] * (j - oneWallIndex) : height[j] * (j - oneWallIndex);
						if (currArea > currMaxArea) {
							currMaxArea = currArea;
							leastDistance = currMaxArea / height[oneWallIndex];
						}
					}
				}
			}
		}else if (leftBound < 0) {
			//no left wall is possible
			//#search right wall only
			for (int j = len - 1; j >= rightBound; j--) {
				if (j - oneWallIndex < leastDistance) {
					//when currMaxArea changes, if current distance is too short, don't need to keep searching
					break;
				}
				else {
					currArea = height[oneWallIndex]<height[j] ? height[oneWallIndex] * (j - oneWallIndex) : height[j] * (j - oneWallIndex);
					if (currArea > currMaxArea) {
						currMaxArea = currArea;
						leastDistance = currMaxArea / height[oneWallIndex];
					}
				}
			}
		}else if(rightBound > len - 1) {
			//no right wall is possible
			//#search left wall only
			for (int j = 0; j <= leftBound; j++) {
				if (oneWallIndex - j< leastDistance) {
					//when currMaxArea changes, if current distance is too short, don't need to keep searching
					break;
				}
				else {
					currArea = height[oneWallIndex]<height[j] ? height[oneWallIndex] * (oneWallIndex - j) : height[j] * (oneWallIndex - j);
					if (currArea > currMaxArea) {
						currMaxArea = currArea;
						leastDistance = currMaxArea / height[oneWallIndex];
					}
				}
			}
		}else {
			//no left/right wall possible
			continue;
		}
	}
	return currMaxArea;
}


void Solution_container_with_most_water::test(void) {
	vector<int> height = {0,3};

	cout << this->maxArea(height);
}