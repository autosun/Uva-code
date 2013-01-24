/* UVa problem 458: The Decoder
 */
#include <iostream>

using namespace std;

int main() {
	string line;
	int line_len;
	while ( getline(cin, line) ) {
		line_len = line.size();
		for (int i = 0; i < line_len; ++i)
			line[i] -= 7;
		cout << line << endl;
	}
	return 0;
}

