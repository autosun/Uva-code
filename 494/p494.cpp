/* UVa problem 494: Kindergarten Counting Game
 */
#include <iostream>

using namespace std;

bool isLetter(char a) {
	if ( (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') )
		return true;
	else
		return false;
}

int main() {
	string line;
	int line_len, cnt;
	bool pre;
	while ( getline(cin, line) ) {
		line_len = line.size();
		cnt = 0;
		pre = false;
		for (int i = 0; i < line_len; ++i) {
			bool is_let = isLetter(line[i]);
			if (is_let == true && pre == false)
				++cnt;
			pre = is_let;
		}
		cout << cnt << endl;
	}
	return 0;
}

