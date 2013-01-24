/* UVa problem 424: Integer Inquiry
 *  website: 
 */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 105

void display(char num[]) {
	int i;
	for (i = MAX_LEN - 1; i > 0 && num[i] == 0; --i);
	for (; i >= 0; --i)
		printf("%d", num[i]);
	printf("\n");
}

int main() {
	char tmp[MAX_LEN], operand[MAX_LEN], sum[MAX_LEN];
	char ans, carry;
	int i, j;

	/* initial sum */
	for (i = 0; i < MAX_LEN; ++i)
		sum[i] = 0;

	do {
		/* read data */
		scanf("%s", &tmp);
		for (i = strlen(tmp) - 1, j = 0; i >= 0; --i, ++j)
			operand[j] = tmp[i] - '0';
		for (; j < MAX_LEN; ++j)
			operand[j] = 0;

		/* calculate */
		carry = 0;
		for (i = 0; i < MAX_LEN; ++i) {
			ans = sum[i] + operand[i] + carry;
			carry = ans / 10;
			sum[i] = ans % 10;
		}

	} while (strlen(tmp) != 1 || tmp[0] != '0');

	display(sum);
	
	return 0;
}

