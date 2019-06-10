#include<stdio.h>
#include<stdlib.h>

#include "lru_cache.h"


typedef struct {
	int *keys;
	int *values;
	int *ages;
	int capacity;
	int used;
} LRUCache;

LRUCache globalCache;

LRUCache* lRUCacheCreate(int capacity) {
	globalCache.keys = (int *)malloc(capacity * sizeof(int));
	globalCache.values = (int *)malloc(capacity * sizeof(int));
	globalCache.ages = (int *)malloc(capacity * sizeof(int));
	globalCache.capacity = capacity;
	globalCache.used = 0;
	return &globalCache;
}

int lRUCacheGet(LRUCache* obj, int key) {
	int value = -1;
	for (int i = 0; i < (*obj).used; i++) {
		if ((*obj).keys[i] == key) {
			value = (*obj).values[i];
			(*obj).ages[i] = 0;
		}else {
			(*obj).ages[i]++;
		}
	}
	return value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
	if ((*obj).used < (*obj).capacity) {
		for (int i = 0; i < (*obj).used; i++) {
			(*obj).ages[i]++;
		}
		(*obj).used++;
		(*obj).keys[(*obj).used - 1] = key;
		(*obj).values[(*obj).used - 1] = value;
		(*obj).ages[(*obj).used - 1] = 0;
	}else {
		int maxAge = -1;
		int maxAgeI = -1;
		int equalKeyI = -1;
		for (int i = 0; i < (*obj).used; i++) {
			(*obj).ages[i]++;
			if ((*obj).keys[i] == key) {
				equalKeyI = i;
			}

			if (maxAge < (*obj).ages[i]) {
				maxAge = (*obj).ages[i];
				maxAgeI = i;
			}
		}

		if (equalKeyI == -1) {
			(*obj).keys[maxAgeI] = key;
			(*obj).values[maxAgeI] = value;
			(*obj).ages[maxAgeI] = 0;
		}
		else {
			(*obj).keys[equalKeyI] = key;
			(*obj).values[equalKeyI] = value;
			(*obj).ages[equalKeyI] = 0;
		}
	}
}

void lRUCacheFree(LRUCache* obj) {

}

/**
* Your LRUCache struct will be instantiated and called as such:
* LRUCache* obj = lRUCacheCreate(capacity);
* int param_1 = lRUCacheGet(obj, key);

* lRUCachePut(obj, key, value);

* lRUCacheFree(obj);
*/

void test_lru_cache(void) {
	LRUCache *cache = lRUCacheCreate(10 /* capacity */);

	int readValue = -1;

	static char testString[1000] = "[10,13],[3,17],[6,11],[10,5],[9,10],[13],[2,19],[2],[3],[5,25],[8],[9,22],[5,5],[1,30],[11],[9,12],[7],[5],[8],[9],[4,30],[9,3],[9],[10],[10],[6,14],[3,1],[3],[10,11],[8],[2,14],[1],[5],[4],[11,4],[12,24],[5,18],[13],[7,23],[8],[12],[3,27],[2,12],[5],[2,9],[13,4],[8,18],[1,7],[6],[9,29],[8,21],[5],[6,30],[1,12],[10],[4,15],[7,22],[11,26],[8,17],[9,29],[5],[3,4],[11,30],[12],[4,29],[3],[9],[6],[3,4],[1],[10],[3,29],[10,28],[1,20],[11,13],[3],[3,12],[3,8],[10,9],[3,26],[8],[7],[5],[13,17],[2,27],[11,15],[12],[9,19],[2,15],[3,16],[1],[12,17],[9,1],[6,19],[4],[5],[5],[8,1],[11,7],[5,2],[9,28],[1],[2,2],[7,4],[4,22],[7,24],[9,26],[13,28],[11,26]";
	char *p = testString;

	int i = 0;
	int nextCmdSta = 0;
	int nextCmdEnd = 0;
	while (p[i] != '\0') {
		if (p[i] == '['){
			nextCmdSta = i;
		}
		else if (p[i] == ']') {
			nextCmdEnd = i;

			char str1[10] = "";
			char str2[10] = "";
			int idx1 = 0;
			int idx2 = 0;
			int dotFound = 0;
			//Perform this cmd
			for (int k = nextCmdSta+1; k < nextCmdEnd; k++) {
				if (p[k] == ',') {
					dotFound = 1;
					continue;
				}

				if (dotFound == 0) {
					str1[idx1] = p[k];
					idx1++;
				}
				else if (dotFound == 1) {
					str2[idx2] = p[k];
					idx2++;
				}
			}

			if (dotFound == 0) {
				//do get operation
				int key = atoi(str1);
				int value = lRUCacheGet(cache, key);
				printf("%d, ", value);
				if (value == 17) {
					key = 0;
				}
			}
			else {
				//do put operation
				int key = atoi(str1);
				int value = atoi(str2);
				lRUCachePut(cache, key, value);
				printf("null, ");
			}
		}

		i++;
	}

	printf("hello, lru");
	return;
}