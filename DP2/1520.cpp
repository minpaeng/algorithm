#include <iostream>
using namespace std;

int m, n;
int dp[501][501];
int height[501][501];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int dfs(int x, int y) {
	if (x == 0 && y == 0) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= m || nx < 0 || ny >= n || ny < 0) continue;
		if (height[nx][ny] > height[x][y]) {
			dp[x][y] += dfs(nx, ny);
		}
	}
	return dp[x][y];
}

int main() {
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> height[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(m - 1, n - 1);
	return 0;
}