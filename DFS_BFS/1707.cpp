#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int V, E;

void bfs(vector<int> graph[20001], int visit[], int start) {
	queue<int> q;
	q.push(start);
	visit[start] = 1;

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (size_t i = 0; i < graph[front].size(); i++) {
			int next = graph[front][i];
			if (visit[next] == 0) {
				q.push(next);
				if (visit[front] == 1)
					visit[next] = visit[front] + 1;
				else
					visit[next] = visit[front] - 1;
			}
		}
	}
}

void answer(vector<int> graph[20001], int visit[]) {
	for (int i = 1; i <= V; i++) {
		for (size_t j = 0; j < graph[i].size(); j++) {
			if (visit[i] == visit[graph[i][j]]) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		vector<int> graph[20001];
		int visit[20001];
		graph->clear();
		memset(visit, 0, sizeof(visit));

		cin >> V >> E;
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int i = 1; i <= V; i++) {
			if (visit[i] == 0) {
				bfs(graph, visit, i);
			}
		}

		answer(graph, visit);
	}

	return 0;
}