#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmpfunc(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {


    int closestSum = INT_MAX;
    int diff = INT_MAX;

    // Sort the array
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1, right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int currentDiff = abs(sum - target);

            if (currentDiff < diff) {
                diff = currentDiff;
                closestSum = sum;
            }

            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return closestSum;

}

int main() {
    int nums[] = {1,1,1,0}, target = -100;

    printf("Closest target: %d \n", threeSumClosest(nums, 4, 1));
}