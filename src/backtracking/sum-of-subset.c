#include <stdio.h>
#include <stdlib.h>

void sumOfSubset(int* nums, int numsSize, int current, int* sumptr, int m, int** result, int* resultSize, int j) {

    if(current >= numsSize) {
        return;
    }
    
    if(*sumptr + nums[current] < m) {
        *sumptr += nums[current];
        sumOfSubset(nums, numsSize, current + 1, sumptr, m, result, resultSize, j + 1);    
    }

    if(*sumptr + nums[current] > m) {
        sumOfSubset(nums, numsSize, current + 1, sumptr, m, result, resultSize, j + 1);
    }

    if(*sumptr + nums[current] == m) {
        *sumptr += nums[current];
        result[*resultSize][j] = current;
    }
}

int main() {

    int nums[] = {2, 4, 9, 19, 3, 7, 5, 6, 1};
    int numsSize = 9;
    int m = 20;

    int** result = (int** ) malloc(sizeof(int*) * 100);

    int resultSize = 0;

    int sum = 0;

    sumOfSubset(nums, numsSize, 0, &sum, m, result, &resultSize, 0);
}