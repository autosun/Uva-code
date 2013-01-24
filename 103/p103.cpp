/* UVa problem 103: Stacking Boxes
 *  reference: Longest Increasing Subsequence
 *  website: http://www.csie.ntnu.edu.tw/~u91029/LongestIncreasingSubsequence.html
 *  website: http://www.wretch.cc/blog/telnet001/20497845
 */
#include <iostream>
#include <algorithm>

#define MAX_D 10
#define MAX_N 30

using namespace std;

class Box {
private:
	int dim;
	int d[MAX_D];
	int index;
	int feasible_pos;
public:
	Box(int dim, int idx);
	friend istream &operator>>(istream &s, Box *b);
	bool operator>(const Box& another) const;
	void sort_d();
	int get_first_d() { return this->d[0]; }
	int get_index() { return this->index; }
	void set_pos(int pos) { this->feasible_pos = pos; }
	int get_pos() { return this->feasible_pos; }
};

class Group {
private:
	int num;
	Box* boxes[MAX_N];
public:
	Group(int num, int dim);
	~Group();
	friend istream &operator>>(istream &s, Group *g);
	void sort_boxes();
	void LIS();
	void report();
};

Box::Box(int dim, int idx) {
	this->dim = dim;
	this->index = idx;
	this->feasible_pos = 1;
}

void Box::sort_d() {
	sort(d, d+dim);
}

bool Box::operator>(const Box& another) const {
	for (int i = 0; i < dim; ++i)
		if (d[i] <= another.d[i])
			return false;
	return true;
}

int boxes_cmp(Box* a, Box* b) {
	return (a->get_first_d() < b->get_first_d());
}

Group::Group(int num, int dim) {
	this->num = num;
	for (int i = 0; i < num; ++i)
		boxes[i] = new Box(dim, i + 1);
}

Group::~Group() {
	for (int i = 0; i < num; ++i)
		delete(boxes[i]);
}

void Group::sort_boxes() {
	// sort d
	for (int i = 0; i < num; ++i)
		boxes[i]->sort_d();
	// sort boxes
	sort(boxes, boxes + num, boxes_cmp);
}

void Group::LIS() {
	sort_boxes();
	for (int i = 1; i < num; ++i) {
		for (int j = 0; j < i; ++j) {
			if ( *boxes[i] > *boxes[j] ) {
				boxes[i]->set_pos( max(boxes[i]->get_pos(), boxes[j]->get_pos() + 1) );
			}
		}
	}
}

void Group::report() {
	int pos_array[num];
	for (int i = 0; i < num; ++i)
		pos_array[i] = boxes[i]->get_pos();
	int len = *max_element(pos_array, pos_array + num);
	int out_array[len];
	int j = len;

	Box *pre = NULL;
	for (int i = num - 1; i >= 0; --i) {
		if ( boxes[i]->get_pos() == j && (pre == NULL || *pre > *boxes[i]) ) {
			out_array[j - 1] = boxes[i]->get_index();
			--j;
			pre = boxes[i];
		}
	}

	cout << len << endl;
	for (int i = 0; i < len - 1; ++i)
		cout << out_array[i] << " ";
	cout << out_array[len - 1] << endl;
}

istream &operator>>(istream &s, Group *g) {
	for (int i = 0; i < g->num; ++i)
		s >> g->boxes[i];
}

istream &operator>>(istream &s, Box *b) {
	for (int i = 0; i < b->dim; ++i)
		s >> b->d[i];
}

int main() {
	int N, D;

	// Get matrix
	while (cin >> N) {
		cin >> D;
		Group* group = new Group(N, D);
		cin >> group;
		group->LIS();
		group->report();
		delete(group);
	}
}

