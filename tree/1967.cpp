#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define MAX 10001

vector<pair<int, int>> tree[MAX];
bool visited[MAX];
int len, max_v;

void dfs(int v, int l) {
	visited[v] = true;
	if (len < l) {
		len = l;
		max_v = v;
	}

	for (size_t i = 0; i < tree[v].size(); i++) {
		int next = tree[v][i].first;
		int dist = tree[v][i].second;
		if (!visited[next]) {
			dfs(next, l + dist);
		}
	}
}

int main() {
	int v;
	cin >> v;
	for (int i = 0; i < v - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].emplace_back(make_pair(b, c));
		tree[b].emplace_back(make_pair(a, c));
	}

	dfs(1, 0);
	memset(visited, 0, sizeof(visited));
	dfs(max_v, 0);

	cout << len;
	return 0;
}