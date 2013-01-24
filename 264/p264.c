/* UVa problem 264: Count on Cantor
 *  website: http://www.knightzone.org/wordpress/archives/1251
 */
#include <stdio.h>
#include <math.h>

unsigned int get_sum(unsigned int num) {
	return num * (num + 1) / 2;
}

int main() {
	unsigned int n, pre, post, layer, tmp;

	while( scanf("%u", &n) != EOF ) {
		if (n == 1) {
			pre = 1;
			post = 1;
		}
		else {
			layer = (unsigned int) sqrt((double)n) + 1;
			while ( (tmp = get_sum(layer)) < n )
				++layer;
			tmp = n - get_sum(layer - 1) - 1;
			if (layer % 2 == 0) { /* even */
				pre = 1 + tmp;
				post = layer - tmp;
			}
			else { /* odd */
				pre = layer - tmp;
				post = 1 + tmp;
			}
		}

		printf("TERM %u IS %u/%u\n", n, pre, post);
	}

	return 0;
}

