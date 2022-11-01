#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> tree[1000001];
bool visited[1000001];
int res[1000001][2];

void dp(int v) {
	visited[v] = true;
	res[v][0] = 1;
	res[v][1] = 0;
	for (int i = 0; i < tree[v].size(); i++) {
		int child = tree[v][i];
		if (visited[child]) 
			continue;
		dp(child);
		res[v][0] += min(res[child][1], res[child][0]);
		res[v][1] += res[child][0];
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dp(1);
	cout << min(res[1][0], res[1][1]);
	return 0;
}