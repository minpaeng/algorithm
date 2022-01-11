#include <iostream>
using namespace std;

int node[50][50];
bool visited[50][50];
int m, n, k, cnt;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= n || ny >= m || nx < 0 || ny < 0) continue;
		if (node[nx][ny] == 1 && !visited[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				node[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		cnt = 0;

		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			node[b][a] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && node[i][j] == 1) {
					cnt++;
					dfs(i, j);
				}
			}
		}

		cout << cnt << '\n';
	}
	return 0;
}