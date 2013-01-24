/* UVa problem 113: Power of Cryptography
 *  website: http://acm-solution.blogspot.com/2011/09/acm-uva-113-power-of-cryptography.html
 */
#include <stdio.h>
#include <math.h>

int main() {
	double n, p;
	while (scanf("%lf%lf", &n, &p) != EOF) {
		printf("%.0lf\n", pow(p, 1.0/n));
	}
	return 0;
}

