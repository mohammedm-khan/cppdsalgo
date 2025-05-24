#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(const char *s, const char *p) {
    int m = strlen(s);
    int n = strlen(p);

    bool dp[m + 1][n + 1];

    // Initialize the DP table
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        if (p[i - 1] == '*') {
            dp[0][i] = dp[0][i - 2];
        }
    }

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            } else {
                dp[i][j] = false;
            }
        }
    }

    return dp[m][n];
}

int main() {
    const char *s = "aa"; // aa
    const char *p = "a"; // a*

    if (isMatch(s, p)) {
        printf("The string matches the pattern.\n");
    } else {
        printf("The string does not match the pattern.\n");
    }

    return 0;
}