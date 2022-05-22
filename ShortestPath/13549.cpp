#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001

bool visited[MAX];

/*int dist[MAX];

void dijkstra(int n, int k) {
	fill_n(dist, MAX, MAX);
	dist[n] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ dist[n], n });

	while (!pq.empty()) {
		int front = pq.top().second;
		int time = pq.top().first;
		pq.pop();
		//cout << "front: " << front << ", time: " << time << endl;
		if (time > dist[front]) continue;

		if (front * 2 < MAX && (dist[front * 2] > time)) {
			pq.push({ time, front * 2 });
			dist[front * 2] = time;
		}
		if (front + 1 < MAX && (dist[front + 1] > time + 1)) {
			pq.push({ time + 1, front + 1 });
			dist[front + 1] = time + 1;
		}
		if (front - 1 >= 0 && (dist[front - 1] > time + 1)) {
			pq.push({ time + 1, front - 1 });
			dist[front - 1] = time + 1;
		}
	}
}

void dijkstra(int n, int k) {
	fill_n(dist, MAX, MAX);
	dist[n] = 0;

	queue<int> pq;
	pq.push(n);

	while (!pq.empty()) {
		int front = pq.front();
		pq.pop();

		if (front * 2 < MAX && (dist[front * 2] > dist[front])) {
			pq.push({ front * 2 });
			dist[front * 2] = dist[front];
		}
		if (front + 1 < MAX && (dist[front + 1] > dist[front] + 1)) {
			pq.push(front + 1);
			dist[front + 1] = dist[front] + 1;
		}
		if (front - 1 >= 0 && (dist[front - 1] > dist[front] + 1)) {
			pq.push(front - 1);
			dist[front - 1] = dist[front] + 1;
		}
	}
}*/

int dfs(int n, int k) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, n });

	while (!pq.empty()) {
		int front = pq.top().second;
		int time = pq.top().first;
		pq.pop();

		if (visited[front]) continue;
		if (front == k) return time;
		visited[front] = true;

		if (front * 2 < MAX) pq.push({ time, front * 2 });
		if (front + 1 < MAX) pq.push({ time + 1, front + 1 });
		if (front - 1 >= 0) pq.push({ time + 1, front - 1 });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;

	cout << dfs(n, k);
	/*dijkstra(n, k);
	cout << dist[k];*/
	return 0;
}