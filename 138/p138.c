/* UVa problem 138: Street Numbers
 *  reference: Pell's equation and Continued fractions
 *  website: http://www.cnblogs.com/devymex/archive/2010/09/07/1818983.html
 *           http://blog.csdn.net/alfredtofu/article/details/6294069
 *           http://zh.wikipedia.org/wiki/佩尔方程
 *           http://episte.math.ntu.edu.tw/articles/mm/mm_02_3_08/index.html
 */

#include <stdio.h>

#define LIMIT 10

int pell_reverse_a(int num) {
	return (num - 1) >> 1;
}

int pell_reverse_b(int num) {
	return num >> 1;
}

int main() {
	int k = 2;
	int base_a = 3;
	int base_b = 2;
	int pre_a = 7;
	int pre_b = 5;
	int a, b, i;

	for (i = 0; i < LIMIT;) {
		a = k * pre_a + base_a;
		b = k * pre_b + base_b;
		if ( b % 2 == 0 ) {
			printf("%10d%10d\n", pell_reverse_b(b), pell_reverse_a(a));
			++i;
		}
		base_a = pre_a;
		base_b = pre_b;
		pre_a = a;
		pre_b = b;
	}

	return 0;
}

