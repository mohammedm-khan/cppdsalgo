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
    for(int i=0; i<n-1;i++) {
        int minIdx = i;
        for(int j=i + 1; j<n;j++) {
            if(arr[j]<arr[minIdx]) {
                minIdx=j;
            }
            k++;
        }
        if(i != minIdx) {
            swap(&arr[i], &arr[minIdx]);
        }
        k++;
    }
    printf("k: %d \n", k);
    return 0;
}