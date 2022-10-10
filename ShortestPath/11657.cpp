#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, m;
long long dist[501];

struct node {
	int s;
	int e;
	int c;
};

vector<node> v;

bool bf(int start) {
	fill(dist + 1, dist + 1 + n, INF);
	dist[start] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cur = v[j].s;
			int next = v[j].e;
			int cost = v[j].c;
			if (dist[cur] == INF) continue;
			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				if (i == n - 1) return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a, b, c });
	}

	bool res = bf(1);
	if (res) cout << "-1";
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF) cout << "-1\n";
			else cout << dist[i] << '\n';
		}
	}
	return 0;
}