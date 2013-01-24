/* UVa problem 382: Perfection
 *  website: http://caterpillar.onlyfun.net/Gossip/AlgorithmGossip/PerfectNumber.htm
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>

#define MAX       60001
#define PERFECT   0
#define ABUNDANT  1
#define DEFICIENT 2

using namespace std;

vector<int> primes;
string result_str[] = {"PERFECT", "ABUNDANT", "DEFICIENT"};
int result_idx;

/* calculate primes */
void calc_primes() {
	bool *tmp = (bool*)calloc(MAX, sizeof(bool));
	memset(tmp, true, MAX * sizeof(bool));
	tmp[0] = tmp[1] = false;
	for (int i = 2; i < MAX; ++i) {
		if (tmp[i]) {
			primes.push_back(i);
			int k = 2;
			int clearr = i * k;
			while ( clearr < MAX ) {
				tmp[clearr] = false;
				++k;
				clearr = i * k;
			}
		}
	}
}

int get_factor_sum(int n) {
	map<int, int> prime_count;
	int tmp = n;
	int sum = 1;

	/* factor divide */
	for (int i = 0; i < primes.size(); ++i) {
		int cnt = 0;
		while ( tmp % primes[i] == 0 ) {
			cnt++;
			tmp /= primes[i];
		}
		prime_count[i] = cnt;
	}

	/* calc sum */
	for (int i = 0; i < prime_count.size(); ++i) {
		int subsum = 0;
		for (int j = 0; j <= prime_count[i]; ++j)
			subsum += (int)pow(primes[i], j);
		sum *= subsum;
	}

	return sum;
}

int main() {
	int n;
	result_idx = 0;

	calc_primes();

	printf("PERFECTION OUTPUT\n");
	while ( scanf("%d", &n) != EOF && n != 0 ) {
		int ret = get_factor_sum(n);
		if ( ret == (n * 2) )
			result_idx = PERFECT;
		else if ( ret > (n * 2) )
			result_idx = ABUNDANT;
		else
			result_idx = DEFICIENT;
		printf("%5d  %s\n", n, result_str[result_idx].c_str());
	}
	printf("END OF OUTPUT\n");

	return 0;
}

