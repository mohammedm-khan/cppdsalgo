#include <stdio.h>
#include <stdlib.h>

int main() {

    int size = 10;
    int* arr = (int*) malloc(sizeof(int) * size);

    //int arr[size];
    
    for(int i=0;i<=size+i;i++) {
        arr[i] = i;
        printf("arr val: %d \n", arr[i]);
    }
}