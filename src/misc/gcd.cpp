#include <stdio.h>
#include <stdlib.h>


int gcd(int x, int y);

int main() {

    int x = 6;
    int y = 9;

    printf("\n\nGCD(%d, %d) = %d\n\n", x, y, gcd(x, y));
}

int gcd(int x, int y) {
    
    int rem = x%y;
    if(rem == 0) {
        return y;
    }
    return gcd(y, rem);
}