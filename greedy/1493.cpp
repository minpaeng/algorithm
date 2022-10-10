#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int cnt;

bool solve(int l, int w, int h, vector<pair<int, int>> &cube) {
	if (l == 0 || w == 0 || h == 0) return true;

	int cube_length = -1;
	for (auto &x : cube) {
		if (x.second > 0 && x.first <= l && x.first <= w && x.first <= h) {
			cube_length = x.first;
			x.second--;
			cnt++;
			break;
		}
	}
	if (cube_length == -1) return false;

	bool res = solve(l, w - cube_length, h, cube)
		&& solve(l - cube_length, cube_length, h, cube)
		&& solve(cube_length, cube_length, h - cube_length, cube);

	if (res) return true;
	else return false;
}


bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int main() {
	vector<pair<int, int>> cube;
	int l, w, h, n;
	cin >> l >> w >> h >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a = pow(2, a);
		cube.push_back({ a, b });
	}

	sort(cube.begin(), cube.end(), compare);

	if (!solve(l, w, h, cube)) cout << -1;
	else cout << cnt;
	return 0;
}