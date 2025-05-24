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
    for(int i=1; i<n;i++) {
        bool flag = true;
        for(int j=0; j < n - i; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                flag = false;
            }
            k++;
        }
        if(flag) break;
    }
    printf("k: %d \n", k);
    return 0;
}