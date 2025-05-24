#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateParenthesisHelper(char** result, int* returnSize, char* current, int open, int close, int n) {
    if (close == n) {
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        current[strlen(current)] = '(';
        generateParenthesisHelper(result, returnSize, current, open + 1, close, n);
        current[strlen(current) - 1] = '\0';
    }

    if (close < open) {
        current[strlen(current)] = ')';
        generateParenthesisHelper(result, returnSize, current, open, close + 1, n);
        current[strlen(current) - 1] = '\0';
    }
}

char** generateParenthesis(int n, int* returnSize) {
    char** result = (char**)malloc(sizeof(char*) * 1000); // Adjust capacity as needed
    *returnSize = 0;
    char current[2 * n + 1];
    current[0] = '\0';
    generateParenthesisHelper(result, returnSize, current, 0, 0, n);
    return result;
}

int main() {
    int n = 3;
    int returnSize;
    char** result = generateParenthesis(n, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);

    return 0;
}