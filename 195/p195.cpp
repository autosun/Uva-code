/* UVa problem 195: Anagram
 * website: http://1.congzhao.sinaapp.com/?p=670
 * note: A < a < B < b < ...
 */
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

bool compare_function(char a, char b) {
	if ( a == (b - 32) || b == (a - 32) )
		return a < b;
	else {
		char la = tolower(a);
		char lb = tolower(b);
		return la < lb;
	}
}

int main() {
	int n;
	string str;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		sort(str.begin(), str.end(), compare_function);
		do {
			cout << str << endl;
		} while( next_permutation(str.begin(), str.end(), compare_function) );
	}
}

