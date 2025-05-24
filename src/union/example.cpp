#include <stdio.h>
#include <stdlib.h>

int main() {
    

    union Point
    {
        int x, y;
    };


    Point p;
    p.x = 10;
    p.y =30;

    printf("p(x,y) = p(%d, %d)", p.x, p.y);
    

}