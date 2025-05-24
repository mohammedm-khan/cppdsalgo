#include <stdio.h>
#include <stdlib.h>

struct Test
{
    int a;
};


int main(){

    struct Test** doubleptr = NULL;

    struct Test* singleptr = (struct Test*) malloc(sizeof(struct Test));

    singleptr->a = 10;

    doubleptr = &singleptr;

    printf("%p      \n", &*doubleptr);
    printf("%p      \n", &singleptr);


    return 0;
}