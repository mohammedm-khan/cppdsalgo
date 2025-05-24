#include <stdio.h>
#include <stdlib.h>


int fact(int n);

int main() {

    int n = 31;

    printf("\n\nFactorial(%d) = %d\n\n", n, fact(n));
}

int fact(int n) {
    if(n == 1) {
        return n;
    }
    return n * fact(n - 1);
}