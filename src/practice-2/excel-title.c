#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convertToTitle(int columnNumber) {
    if (columnNumber <= 0) {
        return NULL; // Handle invalid input
    }

    int len = 0;
    int temp = columnNumber;
    while(temp > 0){
        len++;
        temp = (temp - 1) / 26;
    }

    char* title = (char*)malloc(sizeof(char) * (len + 1)); // +1 for null terminator
    if (title == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    title[len] = '\0'; // Null-terminate the string

    while (columnNumber > 0) {
        int remainder = (columnNumber - 1) % 26;
        title[--len] = 'A' + remainder;
        columnNumber = (columnNumber - 1) / 26;
    }

    return title;
}

int main() {
    // Test cases
    int columnNumber1 = 1;
    char* title1 = convertToTitle(columnNumber1);
    printf("Column %d: %s\n", columnNumber1, title1); // Output: A
    free(title1);

    int columnNumber2 = 28;
    char* title2 = convertToTitle(columnNumber2);
    printf("Column %d: %s\n", columnNumber2, title2); // Output: AB
    free(title2);

    int columnNumber3 = 701;
    char* title3 = convertToTitle(columnNumber3);
    printf("Column %d: %s\n", columnNumber3, title3); // Output: ZY
    free(title3);

    int columnNumber4 = 2147483647;
    char* title4 = convertToTitle(columnNumber4);
    printf("Column %d: %s\n", columnNumber4, title4); // Output: FXSHRXW
    free(title4);

    int columnNumber5 = 0;
    char* title5 = convertToTitle(columnNumber5);
    if(title5 == NULL)
        printf("Column %d: NULL\n", columnNumber5);
    
    return 0;
}