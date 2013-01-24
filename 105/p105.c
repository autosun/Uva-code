/* UVa problem 105: The Skyline Problem
 *  website: http://maplewing.blogspot.com/2011/03/uva105the-skyline-problem.html
 */
#include <stdio.h>

#define MAX 10001

int main() {
	int skyline[MAX];
	int i, left, top, right, rightmost = 0;
	int pp = 0;

	skyline[0] = -1;
	for (i = 1; i < MAX; ++i)
		skyline[i] = 0;

	while (scanf("%d%d%d", &left, &top, &right) != EOF) {
		for (i = left; i < right; ++i) {
			if (top > skyline[i])
				skyline[i] = top;
		}
		if (rightmost < right)
			rightmost = right;
	}

	for (i = 1; i <= rightmost; ++i) {
		if (skyline[i] != skyline[i-1]) {
			if (pp)
				printf(" ");
			pp = 1;
			printf("%d %d", i, skyline[i]);
		}
	}
	printf("\n");
	
	return 0;
}

