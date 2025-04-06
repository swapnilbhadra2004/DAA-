#include <stdio.h>
#include <string.h>

// Recursive brute-force function
int lcs(char* X, char* Y, int m, int n) {
    if (m == 0 || n == 0)
        return 0;

    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return (lcs(X, Y, m - 1, n) > lcs(X, Y, m, n - 1)) ?
                lcs(X, Y, m - 1, n) : lcs(X, Y, m, n - 1);
}

int main() {
    char X[] = "ABCBDAB";
    char Y[] = "BDCABA";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS (brute-force): %d\n", lcs(X, Y, m, n));
    return 0;
}
