#include <stdio.h>
#include <stdlib.h>


int cmpfunc(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **result = (int **)malloc(10000 * sizeof(int *));
    *returnSize = 0;

    // Sort the array
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    // Iterate through the array
    for (int i = 0; i < numsSize - 2; i++) {
        // Skip duplicates
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1, right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result[*returnSize] = (int *)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnSize)++;

                // Skip duplicates
                while (left < right && nums[left] == result[*returnSize - 1][1]) {
                    left++;
                }
                while (left < right && nums[right] == result[*returnSize - 1][2]) {
                    right--;
                }
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int **result;

    result = threeSum(nums, numsSize, &returnSize, NULL);

    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d]\n", result[i][0], result[i][1], result[i][2]);
        free(result[i]);
    }

    free(result);

    return 0;
}