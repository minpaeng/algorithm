#include <iostream>
#include <queue>
using namespace std;

int node[101][101], cnt = 0, n, m;
bool visited[101];
queue<int> q;

void virus(int v) {
	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (node[x][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;
				cnt++;
			}
		}
	}
}

//dfs
//void virus(int v) {
//	visited[v] = true;
//	for (int i = 1; i <= n; i++) {
//		if (node[v][i] == 1 && !visited[i]) {
//			virus(i);
//			cnt++;
//		}
//	}
//}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		node[a][b] = 1;
		node[b][a] = 1;
	}

	virus(1);
	cout << cnt;

	return 0;
}