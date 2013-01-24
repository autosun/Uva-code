/* UVa problem 119: Greedy Gift Givers
 *  reference: 
 *  website: 
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	int n, amount, given_num;
	string tmp_name1, tmp_name2;
	vector<string> names;
	map<string, int> money;
	bool first = true;

	while (cin >> n) {
		if (!first) {
			names.clear();
			money.clear();
			cout << endl;
		}
		first = false;

		/* initial */
		for (int i = 0; i < n; ++i) {
			cin >> tmp_name1;
			names.push_back(tmp_name1);
			money[tmp_name1] = 0;
		}

		/* calculate */
		for (int i = 0; i < n; ++i) {
			cin >> tmp_name1 >> amount >> given_num;
			if (given_num) {
				int per_given_amount = (int)(amount / given_num);

				for (int j = 0; j < given_num; ++j) {
					cin >> tmp_name2;
					money[tmp_name1] -= per_given_amount;
					money[tmp_name2] += per_given_amount;
				}
			}
		}

		/* output */
		for (int i = 0; i < n; ++i) {
			cout << names[i] << " " << money[names[i]] << endl;
		}
	}
}

