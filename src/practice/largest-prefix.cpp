#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }
    
    char* prefix = strs[0];

    int j=0;
    for (int i = 1; i < strsSize; i++) {
        j = 0;
        while (prefix[j] == strs[i][j]) {
            j++;
        }
    }

    prefix = (char *) malloc(sizeof(char) * j);
    strncat(prefix, strs[0], j);

    return prefix;
}

int main() {
    char *strs[] = {"flower", "flow", "float"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);

    char *commonPrefix = longestCommonPrefix(strs, strsSize);
    printf("Longest common prefix: %s\n", commonPrefix);

    return 0;
}