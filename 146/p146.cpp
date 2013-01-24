/* UVa problem 146: ID Codes
 */
#include <iostream>
#include <algorithm>

using namespace std;

/* Soultion 1 */

inline void swap_ch(char* const a, char* const b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	string line;
	bool found = false;
	while ( cin >> line && line.compare("#") != 0 ) {
		found = false;
		for (int i = line.size() - 1; i > 0 && found == false; --i) {
			for (int j = i - 1; j >= 0; --j) {
				if (line.at(i) > line.at(j)) {
					swap_ch(&line[i], &line[j]);
					partial_sort(line.begin() + j + 1, line.end(), line.end());
					found = true;
					break;
				}
			}
		}
		if ( found )
			cout << line << endl;
		else
			cout << "No Successor" << endl;
	}
	return 0;
}

/* Solution 2 */
/*
int main() {
	string line;
	while ( cin >> line && line.compare("#") != 0 ) {
		if ( next_permutation(line.begin(), line.end()) )
			cout << line << endl;
		else
			cout << "No Successor" << endl;
	}
	return 0;
}
*/
