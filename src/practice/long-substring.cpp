#include <stdio.h>
#include <string.h>
#include <math.h>


int longestSubstring(char* s) {

    int lenMax=0, left=0, right=0;
    int charIndex[128] = {0};

    while(right < strlen(s)) {
        
        char r = s[right];
        right++;

        if(charIndex[r] > left){
            left = charIndex[r];
        }

        lenMax = fmax(lenMax, right - left);

        charIndex[r] = right;

    }

    return lenMax;
}

int main() {
    char s[] = "helloworld";
    int lenMax = longestSubstring(s);
    printf("\nLongest substring length: %d\n", lenMax);
}