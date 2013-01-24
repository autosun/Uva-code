/* UVa problem 406: Prime Cuts
 */
#include <iostream>
#include <cstring>
#include <vector>

#define MAX_N 1001

using namespace std;

int main() {
	int N, C, i, j;
	bool prime[MAX_N];
	int prime_count[MAX_N];
	int counter;
	vector<int> primes;

	/* calculate prime */
	memset(prime, true, MAX_N * sizeof(bool));
	prime[0] = false;
	prime_count[0] = 0;
	prime_count[1] = 1;
	counter = 1;
	primes.push_back(1);
	for (i = 2; i < MAX_N; ++i) {
		if (prime[i]) {
			primes.push_back(i);
			++counter;
			int k = 2;
			int clearr = i * k;
			while ( clearr < MAX_N ) {
				prime[clearr] = false;
				++k;
				clearr = i * k;
			}
		}
		prime_count[i] = counter;
	}

	while ( cin >> N >> C ) {
		cout << N << " " << C << ":";
		int disp_n = (prime_count[N] % 2) ? (C << 1) - 1 : C << 1;
		if ( prime_count[N] < disp_n )
			disp_n = prime_count[N];
		for (i = (prime_count[N] - disp_n) / 2, j = 1; j <= disp_n; ++i, ++j)
			cout << " " << primes[i];
		cout << endl << endl;
	}

	return 0;
}

