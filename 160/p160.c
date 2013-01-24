/* UVa problem 160: Factors and Factorials
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 100
#define PRIME_SZ 25
#define LINE_LIMIT 15

int main() {
	/* Primes in 1 to 100 */
	int prime_table[PRIME_SZ] = {
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
		43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
	};

	/* record for the counts of each primes */
	int i, p, tmp;
	int prime_count[MAX_N + 3][PRIME_SZ];

	memset(prime_count, 0, sizeof(int) * (MAX_N + 2) * PRIME_SZ);

	/* Count the primes */
	for (i = 2; i <= MAX_N; ++i) {
		tmp = i;
		for (p = 0; p < PRIME_SZ; ++p) {
			while (tmp % prime_table[p] == 0) {
				++prime_count[i][p];
				tmp /= prime_table[p];
			}
			prime_count[i+1][p] = prime_count[i][p];
		}
	}

	int N, flag;
	int total_count[PRIME_SZ];

	/* For each test case */
	while ( scanf("%d", &N) != EOF && N != 0 ) {
		flag = 0;
		printf("%3d! =", N);
		for (p = 0; p < PRIME_SZ && prime_table[p] <= N; ++p) {
			if (p == LINE_LIMIT)
				printf("\n      ");
			printf("%3d", prime_count[N][p]);
		}
		printf("\n");
	}

	return 0;
}

