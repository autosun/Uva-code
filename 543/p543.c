/*
 * 543 : Goldbach's Conjecture
 * Reference: http://maplewing.blogspot.tw/2011/02/uva543goldbachs-conjecture.html
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int main() {
    int num;
    int i, j;
    int *prime_table = (int*) calloc(MAX, sizeof(int));

    /* calculate prime. */
    for (i = 2; i < MAX / 2; ++i) {
        if (prime_table[i] == 0) {
            for (j = i + i; j < MAX; j += i) {
                prime_table[j] = 1;
            }
        }
    }

    while (scanf("%d", &num) != EOF && num != 0) {
        int exist = 0;
        for (i = 2; i < MAX / 2; ++i ) {
            if (!prime_table[i] && !prime_table[num - i]) {
                exist = 1;
                printf("%d = %d + %d\n", num, i, num - i);
                break;
            }
        }
        if (!exist)
            printf("Goldbach's conjecture is wrong.");
    }

    return 0;
}

