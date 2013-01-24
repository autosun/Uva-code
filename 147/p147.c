/* UVa problem 147: Dollars
 *  website: http://chchwy.blogspot.tw/2010/02/acmuva-147-dollars.html
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX      30000
#define INTERNAL 5
#define COIN_NO  11

int main() {
	int coins[COIN_NO] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
	unsigned long long *table = (unsigned long long*) calloc (MAX + 1, sizeof(unsigned long long));
	int i, j, dec, maz;

	/* Calculate table (dynamic programming) */
	table[0] = 1;
	for (i = 0; i < COIN_NO; ++i) {
		for (j = coins[i]; j <= MAX; j += INTERNAL) {
			table[j] += table[j - coins[i]];
		}
	}

	/* read input */
	do {
		scanf("%d.%d", &dec, &maz);
		int idx = dec * 100 + maz;
		if (idx > 0)
			printf("%3d.%02d%17llu\n", dec, maz, table[idx]);
	} while( dec || maz );

	return 0;
}

