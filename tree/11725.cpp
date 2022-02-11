#include <iostream>
#include <vector>
using namespace std;

bool visited[100001];
int parent[100001];
vector<vector<int>> tree;

void dfs(int node) {
	visited[node] = true;

	for (size_t i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];
		if (!visited[next]) {
			parent[next] = node;
			dfs(next);
		}
	}
}

int main(void) {
	int n;
	cin >> n;

	tree.assign(n + 1, vector<int>(0));

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}

	return 0;
}