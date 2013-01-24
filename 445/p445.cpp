/* UVa problem 445: Marvelous Mazes
 */
#include <iostream>
#include <cctype>

using namespace std;

int main() {
	string line;
	int line_len;
	int repeat;
	char ch;
	while ( getline(cin, line) ) {
		line_len = line.size();
		repeat = 0;
		for (int i = 0; i < line.size(); ++i) {
			ch = line[i];
			if ( ch == '!' )
				cout << endl;
			else if ( isdigit(ch) ) {
				repeat += ch - '0';
			}
			else if ( ch == 'b' ) {
				for (int j = 0; j < repeat; ++j)
					cout << " ";
				repeat = 0;
			}
			else {
				for (int j = 0; j < repeat; ++j)
					cout << ch;
				repeat = 0;
			}
		}
		cout << endl;
	}
	return 0;
}

