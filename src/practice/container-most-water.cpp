#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int maxArea = 0;

    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int width = right - left;
        int area = h * width;
        maxArea = area > maxArea ? area : maxArea;

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(height[0]);

    int maxAreaResult  = maxArea(height, heightSize);
    printf("Max area: %d\n", maxAreaResult);

    return 0;
}