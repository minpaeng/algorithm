#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[8] = { 2, 2, 1 ,1, -1, -1, -2, -2 }, dy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

void bfs(pair<int, int>& now, pair<int, int>& to_go, int l) {
	queue<pair<int, int>> q;
	int visit[301][301];

	memset(visit, 0, sizeof(visit));

	q.push(now);

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (x == to_go.first && y == to_go.second) {
			cout << visit[x][y] << '\n';
			return;
		}
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx > l - 1 || nx < 0 || ny > l - 1 || ny < 0) continue;
			if (!visit[nx][ny]) {
				q.push(make_pair(nx, ny));
				visit[nx][ny] = visit[x][y] + 1;
			}
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int l;
		pair<int, int> now, to_go;
		cin >> l;
		cin >> now.first >> now.second;
		cin >> to_go.first >> to_go.second;
		bfs(now, to_go, l);
	}

	return 0;
}