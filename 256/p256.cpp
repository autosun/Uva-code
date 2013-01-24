/* UVa problem 256: Quirksome Squares
 *  website: http://hoyusun.blogspot.tw/2012/03/uva-256-quirksome-squares.html
 */
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
	unsigned int digits[] = {2, 4, 6, 8};
	vector<unsigned int> solutions[4];
	char buf[20];
	int n;

	/* Calculate */
	for (unsigned int i = 0; i <= 9; ++i)
		for (unsigned int j = 0; j <= 9; ++j)
			if ( (i + j) * (i + j) == i * 10 + j)
				solutions[0].push_back(i * 10 + j);
	for (unsigned int i = 0; i <= 99; ++i)
		for (unsigned int j = 0; j <= 99; ++j)
			if ( (i + j) * (i + j) == i * 100 + j)
				solutions[1].push_back(i * 100 + j);
	for (unsigned int i = 0; i <= 999; ++i)
		for (unsigned int j = 0; j <= 999; ++j)
			if ( (i + j) * (i + j) == i * 1000 + j)
				solutions[2].push_back(i * 1000 + j);
	for (unsigned int i = 0; i <= 9999; ++i)
		for (unsigned int j = 0; j <= 9999; ++j)
			if ( (i + j) * (i + j) == i * 10000 + j)
				solutions[3].push_back(i * 10000 + j);

	/* display */
	while (scanf("%d", &n) != EOF) {
		sprintf(buf, "%%0%du\n", n);
		int idx = n / 2 - 1;
		for(vector<unsigned int>::iterator it = solutions[idx].begin();
				it != solutions[idx].end(); ++it) {
			printf(buf, *it);
		}
	}
}

