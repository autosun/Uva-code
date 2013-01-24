/* UVa problem 483: Word Scramble
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string line;
	int line_len;
	string::iterator bit, eit;
	while ( getline(cin, line) ) {
		line_len = line.size();
		bit = line.begin();
		do {
			while ( bit != line.end() && *bit == ' ' )
				bit++;
			eit = bit;
			while ( eit != line.end() && *eit != ' ' )
				eit++;
			if ( bit != line.end() )
				reverse(bit, eit);
			bit = eit;
		} while (bit != line.end());
		cout << line << endl;
	}
	return 0;
}

