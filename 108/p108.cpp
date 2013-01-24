/* UVa problem 108: Maximum Sum
 *  reference: Kadane's Algorithm
 *  website: http://alexeigor.wikidot.com/kadane
 */
#include <iostream>

#define MAX_N 100

using namespace std;

int main() {
	int matrix[MAX_N][MAX_N];
	int sum_array[MAX_N];

	int N, i, j;
	int maximum, local, left, right, upper, lower;

	// Get matrix
	cin >> N;
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			cin >> matrix[i][j];

	// Initial value
	maximum = 1 << (8 * sizeof(int) - 1); // negative infinity

	// Calculate
	for (left = 0; left < N; ++left) {
		for (int k = 0; k < N; ++k)
			sum_array[k] = 0;
		for (right = left; right < N; ++right) {
			local = 0;
			upper = 0;
			for (lower = 0; lower < N; ++lower) {
				sum_array[lower] += matrix[lower][right];
				local += sum_array[lower];
				if (local > maximum) {
					maximum = local;
				}
				if (local < 0) {
					upper = lower + 1;
					local = 0;
				}
			}
		}
	}

	// Output results
	cout << maximum << endl;
}

