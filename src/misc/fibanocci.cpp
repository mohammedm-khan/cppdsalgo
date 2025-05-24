#include <stdio.h>
#include <stdlib.h>


int fibonacii(int n);

int main() {

    int n = 5;

    printf("Fibonacci series:\n");

    for(int i = 0; i < n; i++ ) {
        int res = fibonacii(i);
        printf("%d, ",res);
    }
    printf("\n\n");
}

int fibonacii(int n) {
    if ( n == 0 )
        return 0;
    else if ( n == 1 )
		return 1;
    else
       return ( fibonacii(n-1) + fibonacii(n-2) );
}