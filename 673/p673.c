/* UVa problem 673: Parentheses Balance
 */
#include <stdio.h>

#define MAX 129

int main() {
	int n, i, top, valid;
	char stack[MAX];
	char line[MAX];
	char c;
	scanf("%d", &n);
	getchar();

	while (n--) {
		gets(line);
		valid = 1;
		top = -1;
		for (i = 0; ((i < MAX) && (line[i] != '\0')) && (valid == 1); i++) {
			if (line[i] == '(' || line[i] == '[') {
				stack[++top] = line[i];
			} else if (line[i] == ')') {
				if (stack[top] != '(') {
					valid = 0;
				} else {
					--top;
				}
			} else if (line[i] == ']') {
				if (stack[top] != '[') {
					valid = 0;
				} else {
					--top;
				}
			}
		}

		if (valid && top == -1) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}

	return 0;
}

