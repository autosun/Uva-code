/* UVa problem 111: History Grading
 *  reference: Longest Common Subsequence
 */

#include <stdio.h>
#include <string.h>

#define MAX_N 20

int LCS(int N, const int * const seq1, const int * const seq2) {
	int i, j, left_up = 0;
	int table[N+1];
	int next_leftup;

	// clean table
	memset(table, 0, sizeof(int) * (N+1));

	// calculate
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if (j == 0 )
				left_up = 0;
			else
				left_up = next_leftup;
			next_leftup = table[j+1];
			if ( seq2[i] == seq1[j] ) {
				table[j+1] = left_up + 1;
			}
			else if ( table[j] > table[j+1] ) {
				table[j+1] = table[j];
			}
		}
	}

	return table[N];
}

int main() {
	int i, order, N;
	int correct_seq[MAX_N], test_seq[MAX_N];
	
	// Get N
	scanf("%d", &N);

	// Get correct sequence
	for (i = 1; i <= N; ++i) {
		scanf("%d", &order);
		correct_seq[order-1] = i;
	}

	// For each test case
	while ( scanf("%d", &order) != EOF ) {
		test_seq[order-1] = 1;
		for (i = 2; i <= N; ++i) {
			scanf("%d", &order);
			test_seq[order-1] = i;
		}
		printf("%d\n", LCS(N, correct_seq, test_seq));
	}

	return 0;
}

