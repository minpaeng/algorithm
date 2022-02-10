#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct {
	int x, y, z;
} index;

int m, n, h;
int tomato[101][101][101];
bool visited[101][101][101];
int day, cnt;
queue<index> q;
int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

void bfs() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (tomato[i][j][k] == 1) {
					q.push({j, k, i});
					visited[i][j][k] = true;
				}
			}
		}
	}

	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int x = q.front().x, y = q.front().y, z = q.front().z;
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
				if (tomato[nz][nx][ny] == 0 && !visited[nz][nx][ny]) {
					q.push({ nx, ny, nz});
					visited[nz][nx][ny] = true;
					cnt--;
				}
			}
		}
		day++;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 0) cnt++;
			}
		}
	}

	bfs();
	if (cnt > 0) {
		cout << -1;
		return 0;
	}

	cout << day - 1;
	return 0;
}