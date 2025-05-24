#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int arr[] = {12, 8, 7, 10, 3, 4, 14, 17, 9}, n = 9, low = 0, high = n - 1;

    int k = 0;
    for(int gap=n/2;gap>=1;gap=gap/2) {
        for(int j=gap;j<n;j++) {
            for(int i=j-gap;i>=0;i=i-gap) {
                if(arr[i+gap] > arr[i]) {
                    break;
                } else {
                    swap(&arr[i+gap], &arr[i]);
                }
                k++;
            }
        }
    }
    printf("k: %d \n", k);
    return 0;
}