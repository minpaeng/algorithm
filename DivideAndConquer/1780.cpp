#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<int, int> m;
vector<int> v[2188];

bool can_finish(int n, int x, int y) {
	int item = v[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (item != v[i][j]) return false;
		}
	}
	return true;
}

void color_paper(int n, int x, int y) {
	if (can_finish(n, x, y)) {
		m[v[x][y]] += 1;
		return;
	}
	int k = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			color_paper(k, x + k * i, y + k * j);
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			v[i].push_back(t);
		}
	}

	m[-1] = 0;
	m[0] = 0;
	m[1] = 0;
	color_paper(n, 0, 0);
	for (auto x : m) cout << x.second << '\n';
	return 0;
}