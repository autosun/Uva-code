/* UVa problem 120: Stacks of Flapjacks
 */
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void reverse_array(vector<int> &array, int begin) {
	int tmp = 0;
	int i = begin;
	int j = array.size() - 1;
	for (; i < j; ++i, --j) {
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

int find_max_val(vector<int> &array, int begin) {
	int local_max = 0;
	int local_max_idx = begin;
	for (int i = begin; i < array.size(); ++i) {
		if (array[i] > local_max) {
			local_max = array[i];
			local_max_idx = i;
		}
	}
	return local_max_idx;
}

int main() {
	string line;
	vector<int> varray;
	vector<int> flip;
	while ( getline(cin, line) ) {
		stringstream steam;
		steam.str(line);
		int num;
		while ( steam >> num )
			varray.insert(varray.begin(), num);

		/* calculate */
		for (int i = 0; i < varray.size() - 1; ++i) {
			int pos = find_max_val(varray, i);
			if ( pos != i && pos != varray.size() - 1) {
				reverse_array(varray, pos);
				flip.push_back(pos + 1);
			}
			pos = find_max_val(varray, i);
			if ( pos == varray.size() - 1 ) {
				reverse_array(varray, i);
				flip.push_back(i + 1);
			}
		}
		flip.push_back(0);

		/* output */
		cout << line << endl;
		for (int i = 0; i < flip.size() - 1; ++i)
			cout << flip[i] << " ";
		cout << flip[flip.size() - 1] << endl;

		/* clear */
		varray.clear();
		flip.clear();
	}
}

