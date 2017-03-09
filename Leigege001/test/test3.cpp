#include <iostream>
using namespace std;

class DisjointSet{
private:
	int *father;
public:
	DisjointSet(int size) {
		father = new int[size];
		for (int i = 1; i < size; i++) {
			father[i] = i;
		}
	}
	~DisjointSet() {
		delete[] father;
	}
	int find_set(int i) {
		if (father[i] != i) {
			return find_set(i);
		}
		return i;
	}
	void merge(int i, int j) {
		int ancestor1 = find_set(i);
		int ancestor2 = find_set(j);
		if (ancestor1 != ancestor2) {
			father[ancestor1] = ancestor2;
		}
	}
};

int main() {
	DisjointSet dsu(100);
	int n;
	cin >> n;
	for (int i = 0; i < 3; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a != 0) {
			dsu.merge(i, a);
		}
		if (b != 0) {
			dsu.merge(i, b);
		}
		if (c != 0) {
			dsu.merge(i, c);
		}
	}
	int m;
	cin >> m;
	int a1 = dsu.find_set(1);
	int a2 = dsu.find_set(m);
	if (a1 == a2) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	return 0;
}
