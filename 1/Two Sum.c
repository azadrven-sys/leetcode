#include <stdlib.h>
int* result;
int* keys;
int* values;
int* used;
int* num;
int TABLE_SIZE;
int complement;
int slot;
int i;
int si = sizeof(int);
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    result = (int*)malloc(2 * si);
    TABLE_SIZE = numsSize * 2;
    keys   = (int*)malloc(TABLE_SIZE * si);
    values = (int*)malloc(TABLE_SIZE * si);
    used   = (int*)calloc(TABLE_SIZE, si);
    num = nums;
    num--;
    for (i = 0; i < numsSize; i++) {
        num++;
        complement = target - *num;
        slot = ((complement % TABLE_SIZE) + TABLE_SIZE) % TABLE_SIZE;
        while (used[slot]) {
            if (keys[slot] == complement) {
                result[0] = values[slot];
                result[1] = i;
                *returnSize = 2;
                free(keys); free(values); free(used);
                return result;
            }
            ++slot;
            if (slot == TABLE_SIZE)
                slot = 0;
            }
        slot = ((*num % TABLE_SIZE) + TABLE_SIZE) % TABLE_SIZE;
        while (used[slot] && keys[slot] != *num) {
            ++slot;
            if (slot == TABLE_SIZE)
                slot = 0;
            }
        keys[slot] = *num;
        values[slot] = i;
        used[slot] = 1;
        }
    free(keys); free(values); free(used);
    *returnSize = 0;
    return NULL;
    }
