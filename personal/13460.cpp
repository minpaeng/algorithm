#include <iostream>
#include <string>
#include <queue>
using namespace std;

char board[10][10];
bool visited[10][10][10][10];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

struct Node {
	int rx, ry;
	int bx, by;
	int cnt;
};

void move(int& x, int& y, int& dist, int i) {
	while (board[x + dx[i]][y + dy[i]] != '#' && board[x][y] != 'O') {
		x += dx[i];
		y += dy[i];
		dist++;
	}
}

void bfs(pair<int, int> red, pair<int, int> blue) {
	queue<Node> q;
	q.push({ red.first, red.second, blue.first, blue.second, 0 });
	visited[red.first][red.second][blue.first][blue.second] = true;

	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int cnt = q.front().cnt;
		q.pop();

		if (cnt >= 10) break;

		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rdist = 0, bdist = 0, ncnt = cnt + 1;
			move(nrx, nry, rdist, i);
			move(nbx, nby, bdist, i);

			if (board[nbx][nby] == 'O') continue;
			if (board[nrx][nry] == 'O') {
				cout << ncnt;
				return;
			}

			if (nrx == nbx && nry == nby) {
				if (rdist > bdist) {
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}

			if (visited[nrx][nry][nbx][nby]) continue;
			visited[nrx][nry][nbx][nby] = true;
			q.push({ nrx, nry, nbx, nby, ncnt });
		}
	}

	cout << -1;
}

int main() {
	int n, m;
	priority_queue<pair<int, int>> pq;
	pair<int, int> red, blue;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j];
			if (board[i][j] == 'R') red = { i, j };
			else if (board[i][j] == 'B') blue = { i, j };
		}
	}

	bfs(red, blue);
	return 0;
}