/*
 * 541. Error Correction
 */

#include<stdio.h>

#define MAX_N 100

int main() {
    int n, i, j, sum, tmp;
    int sum_col[MAX_N];
    int row_odd, col_odd, row_cnt, col_cnt;

    while (scanf("%d", &n) != EOF && n != 0) {
        /* initial. */
        for (i = 0; i < n; ++i) {
            sum_col[i] = 0;
        }
        row_odd = col_odd = -1;
        row_cnt = col_cnt = 0;

        /* sum up. */
        for (i = 0; i < n; ++i) {
            sum = 0;
            for (j = 0; j < n; ++j) {
                scanf("%d", &tmp);
                sum += tmp;
                sum_col[j] += tmp;
            }
            if (sum % 2) {
                row_odd = i + 1;
                ++row_cnt;
            }
        }

        /* calc column. */
        for (i = 0; i < n; ++i) {
            if (sum_col[i] % 2) {
                col_odd = i + 1;
                ++col_cnt;
            }
        }

        if (row_cnt == 0 && col_cnt == 0)
            printf("OK");
        else if (row_cnt == 1 && col_cnt == 1)
            printf("Change bit (%d,%d)", row_odd, col_odd);
        else
            printf("Corrupt");
        printf("\n");
    }

    return 0;
}

