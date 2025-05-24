#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printCombinations(char *digits, char *current, int index) {
    int len = strlen(digits);

    if (index == len) {
        printf("%s\n", current);
        return;
    }

    char *letters = "";
    switch (digits[index]) {
        case '2': letters = "abc"; break;
        case '3': letters = "def"; break;
        case '4': letters = "ghi"; break;
        case '5': letters = "jkl"; break;
        case '6': letters = "mno"; break;
        case '7': letters = "pqrs"; break;
        case '8': letters = "tuv"; break;
        case '9': letters = "wxyz"; break;
        default: break;
    }

    for (int i = 0; letters[i]; i++) {
        current[index] = letters[i];
        printCombinations(digits, current, index + 1);
    }
}

int main() {
    char digits[10];
    printf("Enter digits (2-9): ");
    scanf("%s", digits);

    int len = strlen(digits);
    char *current = (char *)malloc(len + 1);
    current[len] = '\0';

    printCombinations(digits, current, 0);

    free(current);
    return 0;
}