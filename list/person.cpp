#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Person
{
    int id;
    char name[22];
};

int main() {
    printf("\ndemo\n\n");

    struct Person* persons[100];

    for (int i = 0; i < 100; i++)
    {
        struct Person* p = (struct Person*) malloc(sizeof(struct Person));
        p->id = i;
        strcpy(p->name, "Mohammed Mujahed Khan");
        persons[i] = p;
    }

    for (int i = 0; i < 100; i++)
    {
        struct Person* p = persons[i];
        printf("{\n\t\"id\" : %d,\n\t\"name\" : \"%s\"\n} \n", p->id, p->name);
    }
    
    
}
