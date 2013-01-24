/* UVa problem 401: Palindromes
 */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 21

char maps[128];

void initial_maps() {
	maps['A'] = 'A';
	maps['B'] = maps['C'] = maps['D'] = 0;
	maps['E'] = '3';
	maps['F'] = maps['G'] = 0;
	maps['H'] = 'H';
	maps['I'] = 'I';
	maps['J'] = 'L';
	maps['K'] = 0;
	maps['L'] = 'J';
	maps['M'] = 'M';
	maps['N'] = 0;
	maps['O'] = 'O';
	maps['P'] = maps['Q'] = maps['R'] = 0;
	maps['S'] = '2';
	maps['T'] = 'T';
	maps['U'] = 'U';
	maps['V'] = 'V';
	maps['W'] = 'W';
	maps['X'] = 'X';
	maps['Y'] = 'Y';
	maps['Z'] = '5';
	maps['1'] = '1';
	maps['2'] = 'S';
	maps['3'] = 'E';
	maps['4'] = 0;
	maps['5'] = 'Z';
	maps['6'] = 0;
	maps['7'] = 0;
	maps['8'] = '8';
	maps['9'] = 0;
}

int is_Palindromes(char str[]) {
	int i, j;
	for (i = 0, j = strlen(str) - 1; i <= j; ++i, --j)
		if ( str[i] != str[j] )
			return 0;
	return 1;
}

int is_Mirrored(char str[]) {
	int i, j;
	for (i = 0, j = strlen(str) - 1; i <= j; ++i, --j)
		if ( maps[str[i]] != str[j] )
			return 0;
	return 1;
}

int main() {
	char str[MAX_LEN];
	int is_p, is_m;

	initial_maps();

	while ( scanf("%s", str) != EOF ) {
		is_p = is_Palindromes(str);
		is_m = is_Mirrored(str);
		printf("%s", str);
		if ( is_p && is_m )
			printf(" -- is a mirrored palindrome.\n\n");
		else if ( is_p )
			printf(" -- is a regular palindrome.\n\n");
		else if ( is_m )
			printf(" -- is a mirrored string.\n\n");
		else
			printf(" -- is not a palindrome.\n\n");
	}

	return 0;
}

