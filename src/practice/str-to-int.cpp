#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int stringToInt(const char *str) {
    int sign = 1;
    int result = 0;

    // Handle leading whitespace
    while (*str == ' ') {
        str++;
    }

    // Handle sign
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // Convert digits to integer
    while (*str != '\0') {
        if (*str < '0' || *str > '9') {
            return 0; // Invalid character
        }

        int digit = *str - '0';
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
            return INT_MAX; // Overflow
        }
        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) {
            return INT_MIN; // Underflow
        }

        result = result * 10 + digit;
        str++;
    }

    return result * sign;
}

int main() {
    char str[] = "-91283472332";
    int num = stringToInt(str);
    printf("Integer value: %d\n", num);

    int k = -123 / 10;
    printf("k = %d", k);
    return 0;
}