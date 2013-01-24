/* UVa problem 299: Train Swapping
 */
#include <stdio.h>

#define MAX_L 50

void swap_train(int train[], int a, int b) {
	int tmp = train[a];
	train[a] = train[b];
	train[b] = tmp;
}

void print_train(int train[], int n) {
	int i;
	for (i = 0; i < n; ++i)
		printf("%d ", train[i]);
	printf("\n");
}

int main() {
	int N, L, cnt;
	int train[MAX_L];
	int i, j, k, m;

	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%d", &L);
		for (j = 0; j < L; ++j)
			scanf("%d", &train[j]);

		cnt = 0;
		for (k = L; k > 1; --k) {
			for (m = 0; m < L-1; ++m) {
				if (train[m] > train[m+1]) {
					swap_train(train, m, m+1);
					++cnt;
				}
			}
		}

		printf("Optimal train swapping takes %d swaps.\n", cnt);
	}

	return 0;
}

