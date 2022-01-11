#include <iostream>
#include <queue>
using namespace std;

int n, m, v;
bool visited[1001];
int node[1001][1001];
queue<int> q;

//dfs
void dfs(int v) {
	cout << v << ' ';
	visited[v] = true;
	for (int i = 1; i <= n; i++) {
		if (node[v][i] == 1 && !visited[i]) {
			dfs(i);
		}
	}
}

//bfs
void bfs(int v) {
	q.push(v);
	visited[v] = true;

	while (!q.empty()) {
		v = q.front();
		cout << v << ' ';
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (node[v][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		node[a][b] = 1;
		node[b][a] = 1;
	}

	dfs(v);
	cout << '\n';

	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}

	bfs(v);
	return 0;
}