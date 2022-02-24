#include <iostream>
#include <vector>
using namespace std;

int cnt;
vector<int> graph[501];
bool visited[501];

void init() {
	for (int i = 1; i < 501; i++) {
		graph[i].clear();
		visited[i] = false;
	}
	cnt = 0;
}

bool dfs(int v, int pre_v) {
	visited[v] = true;

	for (size_t i = 0; i < graph[v].size(); i++) {
		int next_v = graph[v][i];
		if (next_v == pre_v) continue;
		if (visited[next_v]) return false;
		if (dfs(next_v, v) == false) return false;
	}
	return true;
}

int main() {
	int t = 0;

	while (true) {
		int n, m, u, v;
		cin >> n >> m;
		if (n == 0) break;

		t++;
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			graph[u].emplace_back(v);
			graph[v].emplace_back(u);
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				if (dfs(i, 0)) cnt++;
			}
		}

		cout << "Case " << t << ": ";
		if (cnt == 0) cout << "No trees.\n";
		else if (cnt == 1) cout << "There is one tree.\n";
		else cout << "A forest of " << cnt << " trees.\n";

		init();
	};
	return 0;
}