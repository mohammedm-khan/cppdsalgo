#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    
    int n = strlen(haystack);
    int m= strlen(needle);

    
    int index = -1;
    for(int i=0; i<n; i++) {
        if(haystack[i] == needle[0]) {
            int k=0;
            while(k < m && haystack[i + k] == needle[k]) {
                k++;
            }
            if(k == m) {
                index = i;
                break;
            }
        }
    }
    return index;
}

int main() {

    strStr("sadbutsad", "sad");
}