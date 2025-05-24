#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

int my_tolower(int c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A'); // Add the difference between 'a' and 'A'
    } else {
        return c;
    }
}

bool isPalindrome(char* s) {

    int len = 0;

    for(int i=0; s[i] != '\0'; i++) {
        printf("s[%d]: %c\n", i, s[i]);
        if((s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90) || s[i] >= 97 && s[i] <= 122 ) {
            len++;
        }

    }

    char* str = (char*) malloc(sizeof(char) * (len));

    int j=0;
    for(int i=0; s[i] != '\0'; i++) {

        if((s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90) || s[i] >= 97 && s[i] <= 122 ) {
            //printf("s[%d]: %c\n", i, s[i]);
            str[j] = my_tolower(s[i]);
            printf("str[%d]: %c\n", j, str[j]);
            j++;
        }

    }

    int left=0,right=len - 1;

    bool isPalidrome = true;
    while(left<=right) {
        if(str[left] != str[right]) {
            isPalidrome = false;
            break;
        }
        left++;
        right--;
    }

    return isPalidrome;
}

int main() {

    char* s = "race a car";
    bool isPalindromes = isPalindrome(s);
    return 0;
}