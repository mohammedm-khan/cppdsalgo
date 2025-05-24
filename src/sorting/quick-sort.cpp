#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {

    int pivot = low;
    int i = low;
    int j = high;

    while(i < j) {

        while(arr[i] <= arr[pivot]) {
            i++;
        }

        while(arr[j] > arr[pivot]){
            j--;
        }

        if(i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[pivot], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int j = partition(arr, low, high);
        quickSort(arr, low, j);
        quickSort(arr, j + 1, high);
    }
}

int main() {

    int arr[] = {12, 8, 7, 10, 3, 4, 14, 17, 9}, n = 9, low = 0, high = n - 1;
    quickSort(arr, low, high);
    return 0;
}