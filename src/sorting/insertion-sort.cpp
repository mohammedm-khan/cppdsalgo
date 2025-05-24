#include <stdio.h>
#include <stdlib.h>


int main() {
    int arr[] = {12, 8, 7, 10, 3, 4, 14, 17, 9}, n = 9, low = 0, high = n - 1;

    int k = 0;
    for(int i=1; i<n;i++) {
        int j = i - 1;
        int x = arr[i];

        while (j >=0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j--;
            k++;
        }
        arr[j + 1] = x;
        k++;
    }
    printf("k: %d \n", k);
    return 0;
}