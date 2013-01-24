/* UVa problem 492: Pig-Latin
 */
#include <iostream>
#include <cctype>

using namespace std;

string vowels = "aeiouAEIOU";

bool is_vowel(char c) {
	for (int i = 0; i < vowels.size(); ++i)
		if ( vowels[i] == c )
			return true;
	return false;
}

int main() {
	string line;
	int line_len;
	bool is_begin, is_contain_vowel;
	char keep;

	while ( getline(cin, line) ) {
		line_len = line.size();
		is_begin = is_contain_vowel = false;
		keep = ' ';
		for (int i = 0; i < line_len; ++i) {
			if ( !isalpha(line[i]) ) {
				if (is_begin) {
					if (keep != ' ')
						cout << keep;
					if (is_contain_vowel)
						cout << "ay";
					is_begin = false;
					keep = ' ';
				}
				cout << line[i];
			}
			else {
				bool ret = is_vowel(line[i]);
				if (!is_begin && !ret)
					keep = line[i];
				else
					cout << line[i];
				is_begin = true;
				is_contain_vowel |= ret;
			}
		}
		cout << endl;
	}
	return 0;
}

