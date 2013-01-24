/* UVa problem 495: Fibonacci Freeze
 *  website: http://hoyusun.blogspot.tw/2012/03/uva-495-fibonacci-freeze.html
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 5001
#define MAX_LEN 120
#define BASE_BILLION 1000000000

typedef struct struct_BigNumber {
	unsigned int big[MAX_LEN];
} BigNumber;

BigNumber* table;

void display(int n) {
	int i;
	printf("The Fibonacci number for %d is ", n);
	for (i = MAX_LEN - 1; i > 0 && table[n].big[i] == 0; --i);
	printf("%u", table[n].big[i]);
	for (--i; i >= 0; --i)
		printf("%09u", table[n].big[i]);
	printf("\n");
}

int main() {
	int i, j, n;

	/* initial table */
	table = (BigNumber*)calloc(MAX_NUM, sizeof(BigNumber));

	/* calculate */
	table[1].big[0] = table[2].big[0] = 1;
	for (i = 3; i < MAX_NUM; ++i) {
		for (j = 0; j < MAX_LEN; ++j) {
			table[i].big[j] += table[i-1].big[j] + table[i-2].big[j];
			table[i].big[j+1] += table[i].big[j] / BASE_BILLION;
			table[i].big[j] %= BASE_BILLION;
		}
	}

	while ( scanf("%d", &n) != EOF ) {
		display(n);
	}

	return 0;
}

