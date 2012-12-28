/**
 * Combinations
 *
 * Formula:
 *   C(n, m) = C(n-1, m-1) + C(n-1, m)
 */

#include <stdio.h>

#define MAX_N 101

int main() {
    int i, j, n, m;
    unsigned long combinations[MAX_N][MAX_N];

    for (i = 1; i < MAX_N; ++i) {
        combinations[i][1] = i;
        combinations[i][i] = 1;
    }

    for (i = 1; i < MAX_N; ++i) {
        for (j = 2; j < i; ++j) {
            combinations[i][j] = combinations[i-1][j-1] + combinations[i-1][j];
        }
    }

    while (scanf("%d %d", &n, &m) != EOF && (n != 0 || m != 0)) { 
        printf("%d things taken %d at a time is %lu exactly.\n", n, m, combinations[n][m]);
    }

    return 0;
}

