/* UVa problem 490: Rotating Sentences
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<string> sentences;
	string line;
	int max_len = 0, max_pos;
	int str_len;
	while ( getline(cin, line) ) {
		str_len = line.size();
		sentences.push_back(line);
		if (str_len > max_len) {
			max_len = str_len;
			max_pos = sentences.size() - 1;
		}
	}

	for (int i = sentences.size() - 1; i > max_pos; --i)
		sentences[i].append(max_len - sentences[i].size(), ' ');

	for (int i = 0; i < max_len; ++i) {
		for (int j = sentences.size() - 1; j >= 0; --j)
			cout << sentences[j][i];
		cout << endl;
	}
	return 0;
}

