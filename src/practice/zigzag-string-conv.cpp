#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *convert(char *s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    int len = strlen(s);
    int cycleLen = 2 * numRows - 2;
    char *result = (char *)malloc(len + 1);
    int index = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < len; j += cycleLen) {
            result[index++] = s[j + i];
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < len) {
                result[index++] = s[j + cycleLen - i];
            }
        }
    }

    result[index] = '\0';
    return result;
}

int main() {
    char s[] = "PAYPALISHIRING";
    int numRows = 4;
    char *zigzag = convert(s, numRows);
    printf("%s\n", zigzag);
    free(zigzag);
    return 0;
}