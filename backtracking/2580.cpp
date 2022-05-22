#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int v[9][9];
bool flag = false;

bool can_fill(int x, int y, int item) {
	for (int i = 0; i < 9; i++) {
		if (v[x][i] == item) return false;
		if (v[i][y] == item) return false;
	}
	int tmp_x = (x / 3) * 3;
	int tmp_y = (y / 3) * 3;
	for (int i = tmp_x; i < tmp_x + 3; i++) {
		for (int j = tmp_y; j < tmp_y + 3; j++) {
			if (v[i][j] == item) return false;
		}
	}
	return true;
}

void solve(int x, int y) {
	if (flag) return;
	if (pq.size() == 0) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << v[i][j] << ' ';
			}
			cout << endl;
		}
		flag = true;
		return;
	}

	pq.pop();
	for (int i = 1; i <= 9; i++) {
		if (can_fill(x, y, i)) {
			v[x][y] = i;
			int nx = 0, ny = 0;
			if (pq.size() > 0) {
				nx = pq.top().first;
				ny = pq.top().second;
			}
			solve(nx, ny);
		}
	}
	v[x][y] = 0;
	pq.push({ x, y });
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> v[i][j];
			if (v[i][j] == 0) pq.push({ i, j });
		}
	}

	int nx = 0, ny = 0;
	if (pq.size() > 0) {
		nx = pq.top().first;
		ny = pq.top().second;
	}
	solve(nx, ny);
	return 0;
}