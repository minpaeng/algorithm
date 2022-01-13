#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int m, n, max_days = 0;
int tomato[1001][1001];
int days[1001][1001];
queue<pair<int, int>> q;
bool visited[1001][1001];
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

void bfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 1) {
				q.push(make_pair(i, j));
				visited[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (tomato[nx][ny] == 0 && !visited[nx][ny]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				days[nx][ny] = days[x][y] + 1;
				max_days = max(days[nx][ny], max_days);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
		}
	}

	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0 && !visited[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << max_days;
	return 0;
}