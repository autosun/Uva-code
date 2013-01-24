/* UVa problem 499: What's The Frequency, Kenneth
 */
#include <iostream>
#include <cctype>

using namespace std;

int main() {
	string line;
	unsigned int freq[128];
	while ( getline(cin, line) ) {
		for (int i = 0; i < 128; ++i)
			freq[i] = 0;
		unsigned int max = 0;
		for (int i = 0; i < line.size(); ++i) {
			if ( isalpha(line[i]) ) {
				++freq[line[i]];
				if ( freq[line[i]] > max )
					max = freq[line[i]];
			}
		}
		for (char i = 'A'; i <= 'Z'; ++i)
			if ( freq[i] == max )
				cout << i;
		for (char i = 'a'; i <= 'z'; ++i)
			if ( freq[i] == max )
				cout << i;
		cout << " " << max << endl;
	}
	return 0;
}

