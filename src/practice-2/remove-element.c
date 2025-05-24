#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int slow = 0;

    for (int fast = 0; fast < numsSize; fast++) {
        if (nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++;
        }
    }

    return slow;
}

int main() {
    int nums[] = {3, 2, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 3;

    int k = removeElement(nums, numsSize, val);

    printf("The array after removing elements equal to %d: ", val);
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}