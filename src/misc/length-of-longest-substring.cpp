#include <stdio.h>
#include <string.h>
#include <math.h>

int lengthOfLongestSubstring(char *s) {
    int charIndex[128] = {0}; // Array to store the last index of each character
    int left = 0, right = 0, maxLen = 0;

    while (right < strlen(s)) {
        char r = s[right];
        right++;

        // If the character is repeated, move the left pointer to the character's last index + 1
        if (charIndex[r] > left) {
            left = charIndex[r];
        }

        // Update the maximum length
        maxLen = fmax(maxLen, right - left);

        // Update the last index of the current character
        charIndex[r] = right;
    }

    return maxLen;
}

int main() {
    char s[] = "abcabcbb";
    int len = lengthOfLongestSubstring(s);
    printf("Length of the longest substring without repeating characters: %d\n", len);
    return 0;
}