#include <stdio.h>
#include <stdlib.h>



int cmpfunc(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void fourSum(int* nums, int numsSize, int target, int*** result, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    int quadCount = 0;
    *result = (int**)malloc(10000 * sizeof(int*)); // Adjust capacity as needed
    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }

            int left = j + 1, right = numsSize - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    (*result)[quadCount] = (int*)malloc(4 * sizeof(int));
                    (*result)[quadCount][0] = nums[i];
                    (*result)[quadCount][1] = nums[j];
                    (*result)[quadCount][2] = nums[left];
                    (*result)[quadCount][3] = nums[right];
                    quadCount++;

                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    *returnSize = quadCount;
}

int main() {
    int nums[] = {1, 0, -1, 0, -2, 2};
    int target = 0;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int **result;
    int returnSize;

    fourSum(nums, numsSize, target, &result, &returnSize);

    printf("Number of quadruplets: %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d, %d]\n", result[i][0], result[i][1], result[i][2], result[i][3]);
        free(result[i]);
    }
    free(result);

    return 0;
}