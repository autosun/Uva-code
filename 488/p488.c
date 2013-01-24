/* UVa problem 488: Triangle Wave
 */
#include <stdio.h>

int main() {
	int N, A, F;
	int i, j, k, m;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%d%d", &A, &F);
		for (j = 0; j < F; ++j) {
			for (k = 1; k <= A; ++k) {
				for (m = 0; m < k; ++m)
					printf("%d", k);
				printf("\n");
			}
			for (k = A-1; k > 0; --k) {
				for (m = 0; m < k; ++m)
					printf("%d", k);
				printf("\n");
			}
			if (j != F-1)
				printf("\n");
		}
		if (i != N-1)
			printf("\n");
	}
	return 0;
}

