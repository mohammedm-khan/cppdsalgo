#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int expandAroundCenter(char *str, int left, int right) {
    while (left >= 0 && right < strlen(str) && str[left] == str[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char* longestPalindrome(char *s) {
    int start = 0, end = 0, len = 0, maxLen = 0;
    for (int i = 0; i < strlen(s); i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        len = fmax(len1, len2);
        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    char *longestPalindrome = (char *)malloc((maxLen + 1) * sizeof(char));
    strncpy(longestPalindrome, s + start, maxLen);
    longestPalindrome[maxLen] = '\0';
    return longestPalindrome;
}

int main() {
    char str[] = "babad";
    char* sub = longestPalindrome(str);
    printf("Longest palindrome substring: %s\n", sub);
    free(sub);
    return 0;
}