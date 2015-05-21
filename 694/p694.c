/* UVa problem 694: The Collatz Sequence
 */
#include <stdio.h>

#define MAX 129

int main() {
	long long initA, limitA, A, count, n;
	n = 0;

	scanf("%lld %lld", &initA, &limitA);
	while (initA != -1 || limitA != -1) {
		n++;
		count = 0;
		A = initA;
		while (1) {
			count++;
			if (A == 1) {
				break;
			}

			if (A % 2 == 0) {
				A = A / 2;
			} else {
				A = A * 3 + 1;
			}

			if (A > limitA) {
				break;
			}
		}
		printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n", n, initA, limitA, count);
		scanf("%lld %lld", &initA, &limitA);
	}

	return 0;
}

