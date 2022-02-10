#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

typedef struct {
	int x;
	int y;
	short wall; //벽을 뚫은 상태이면 1, 뚫지 않은 상태이면 0
}type;

int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
int node[1001][1001];
int dist[1001][1001][2];
bool visit[1001][1001];

queue<type> q;


int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			node[i][j] = tmp[j] - '0';
		}
	}
	
	q.push({ 0, 0, 0 });
	dist[0][0][0] = 1;
	visit[0][0] = true;

	int x, y;
	short wall;

	while (!q.empty()) {
		x = q.front().x;
		y = q.front().y;
		wall = q.front().wall;
		if (x == n && y == m) break;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx > n - 1 || nx < 0 || ny > m - 1 || ny < 0) continue;
			//벽이 없고 방문하지 않은 경우
			if (node[nx][ny] == 0 && !visit[nx][ny]) {
				q.push({ nx, ny, wall });
				dist[nx][ny][wall] = dist[x][y][wall] + 1;
				visit[x][y] = true;
			}
			//벽이 있고 벽을 부순 적이 없으며 방문하지 않은 경우
			else if (node[nx][ny] == 1 && wall == 0 && !visit[nx][ny]) {
				q.push({ nx, ny, 1 });
				dist[nx][ny][1] = dist[x][y][wall] + 1;
				visit[x][y] = true;
			}
		}
	}

	int res = dist[n - 1][m - 1][wall];
	if (res == 0) cout << -1;
	else cout << res;
	return 0;
}