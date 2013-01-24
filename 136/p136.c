/* UVa problem 136: Ugly Numbers
 *  website: http://pastie.org/1236070
 *  website: http://www.knightzone.org/wordpress/archives/1131
 */
#include <stdio.h>

#define TH 1500

int main() {
	int uglys[TH];
	int p2, p3, p5;
	int idx = 0;
	uglys[idx] = 1;
	for (p2 = p3 = p5 = 0; idx < TH - 1; ) {
		while (uglys[p2] * 2 <= uglys[idx]) p2++;
		while (uglys[p3] * 3 <= uglys[idx]) p3++;
		while (uglys[p5] * 5 <= uglys[idx]) p5++;

		if ( uglys[p2] * 2 < uglys[p3] * 3 && uglys[p2] * 2 < uglys[p5] * 5 )
			uglys[++idx] = uglys[p2++] * 2;
		else if ( uglys[p3] * 3 < uglys[p5] * 5 )
			uglys[++idx] = uglys[p3++] * 3;
		else
			uglys[++idx] = uglys[p5++] * 5;
	}
	printf("The 1500'th ugly number is %d.\n", uglys[TH-1]);
	return 0;
}

