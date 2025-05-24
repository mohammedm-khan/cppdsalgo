#include <stdio.h>
#include <stdlib.h>


struct Matrix {
    int n;
    int* arr;
    Matrix(int size){
        n = size;
        arr = new int[size];
    }
};

void set(Matrix* matrix, int i, int j, int elm) {
    if(i == j)
        matrix->arr[i] = elm;
}

int get(Matrix* matrix, int i, int j) {
    if(i == j)
        return matrix->arr[i];
    else 
        return 0;

}

int main() {

    Matrix* matrix = new Matrix(10);

    for(int i=0; i<matrix->n; i++) {
        for(int j=0; j<matrix->n; j++) {
            set(matrix, i, j, i * j + 3 + j * 5 + - 2);
        }
        printf("\n");
    }

    for(int i=0; i<matrix->n; i++) {
        for(int j=0; j<matrix->n; j++) {
            printf("%d\t", get(matrix, i, j));
        }
        printf("\n");
    }
}