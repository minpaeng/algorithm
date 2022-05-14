#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 987654321

vector<pair<int, int>> graph[20001];
vector<int> dist;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int v, e, start;
	cin >> v >> e;
	cin >> start;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	dist.assign(v + 1, MAX);

	dist[start] = 0;
	pq.push({ dist[start], start });

	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();

		int idx = cur.second;
		int idx_dist = cur.first;

		if (dist[idx] < idx_dist) continue;

		for (size_t i = 0; i < graph[idx].size(); i++) {
			int n_idx = graph[idx][i].first;
			int cost = graph[idx][i].second;
			if (idx_dist + cost < dist[n_idx]) {
				dist[n_idx] = idx_dist + cost;
				pq.push({ dist[n_idx], n_idx });
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] != MAX) cout << dist[i] << '\n';
		else cout << "INF\n";
	}

	return 0;
}