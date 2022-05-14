#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 87654321

int n, e, v1, v2;
int graph[801][801];
int dist[801];

void dijkstra(int s) {
	for (int i = 1; i <= n; i++) dist[i] = MAX;
	dist[s] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ dist[s], s });

	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();
		int idx = cur.second;
		int idx_dist = cur.first;
		if (idx_dist > dist[idx]) continue;

		for (int i = 1; i <= n; i++) {
			if (!graph[idx][i]) continue;
			if (idx_dist + graph[idx][i] < dist[i]) {
				dist[i] = idx_dist + graph[idx][i];
				pq.push({ dist[i], i });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = graph[b][a] = c;
	}

	cin >> v1 >> v2;

	dijkstra(1);
	int startToV1 = dist[v1], startToV2 = dist[v2];

	dijkstra(v1);
	int v1ToV2 = dist[v2], v1ToEnd = dist[n];

	dijkstra(v2);
	int v2ToV1 = dist[v1], v2ToEnd = dist[n];

	int total1 = startToV1 + v1ToV2 + v2ToEnd;
	int total2 = startToV2 + v2ToV1 + v1ToEnd;

	int res = (total1 < total2 ? total1 : total2);
	if (res >= MAX) cout << -1;
	else cout << res;

	return 0;
}