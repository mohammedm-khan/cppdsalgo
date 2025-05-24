#include <stdio.h>
#include <string.h>

void intToRoman(int num, char *str) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int i=0;
    while(num>0) {
        while(num >= values[i]){
            strcat(str, symbols[i]);
            num-=values[i];
        }
        i++;
    }
}

char* intToRoman(int num) {

    char str[16];
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int i=0;
    while(num>0) {
        while(num >= values[i]){
            strcat(str, symbols[i]);
            num-=values[i];
        }
        i++;
    }
    return str;
}


int main() {
    int num = 1994;
    char romanNum[16];
    romanNum[0] = '\0';

    printf("Roman numeral: %s\n", intToRoman(num));

    printf("Roman numeral: %s\n", romanNum);

    return 0;
}