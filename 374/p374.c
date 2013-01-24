/* UVa problem 374: Big Mod
 */
#include <stdio.h>

unsigned int big_mod(unsigned int B, unsigned int P, unsigned int M) {
	if ( P == 0 )
		return 1 % M;
	else if ( P == 1 )
		return B % M;
	else if ( P % 2 == 0 ) { /* even */
		unsigned ret = big_mod(B, P / 2, M);
		return (ret * ret) % M;
	}
	else {                   /* odd */
		return (big_mod(B, P - 1, M) * (B % M)) % M;
	}
}

int main() {
	unsigned int B, P, M, ans;

	while( scanf("%u %u %u", &B, &P, &M) != EOF ) {
		printf("%u\n", big_mod(B, P, M));
	}

	return 0;
}

