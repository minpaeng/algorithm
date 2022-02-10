#include <iostream>
#include <queue>
using namespace std;

int n, k, seconds;
bool visited[100001];
queue<int> q;

void bfs(int v) {
	visited[v] = true;
	q.push(v);

	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int x = q.front();
			if (x == k) return;
			q.pop();
			if (x - 1 >= 0 && x - 1 <= 100000 && !visited[x - 1]) {
				q.push(x - 1);
				visited[x - 1] = true;
			}
			if (x + 1 <= 100000 && !visited[x + 1]) {
				q.push(x + 1);
				visited[x + 1] = true;
			}
			if (2 * x <= 100000 && !visited[2 * x]) {
				q.push(2 * x);
				visited[2 * x] = true;
			}
		}
		seconds++;
	}
}

int main() {
	cin >> n >> k;

	bfs(n);

	cout << seconds;
	return 0;
}