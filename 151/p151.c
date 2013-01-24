/* UVa problem 151: Power Crisis
 *  reference: Josephus Problem
 *  website: http://acm.nudt.edu.cn/~twcourse/JosephusProblem.html
 *           http://www.knightzone.org/wordpress/archives/1227
 */

#include <stdio.h>

#define MAX_N 100
#define Wellington 13

int Josephus(int n, int m) {
	int i, answer = 0;
	for (i = 2; i <= n; ++i)
		answer = (answer + m) % i;
	return answer + 2;
}

int main() {
	int m, N;

	/* For each test case */
	while ( scanf("%d", &N) && N != 0 ) {
		N--; /* power off Auckland first */
		for (m = 1; m < N; ++m) {
			if ( Josephus(N, m) == Wellington )
				break;
		}
		printf("%d\n", m);
	}

	return 0;
}

