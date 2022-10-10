#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int arr[101];
int cnt[101];

int solve(int now) {
	fill_n(cnt + 1, 100, -1);
	cnt[now] = 0;

	queue<int> q;
	q.push(now);

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int next = front + i;
			if (next > 100) break;
			if (arr[next] != 0) next = arr[next];
			if (cnt[next] == -1) {
				q.push(next);
				cnt[next] = cnt[front] + 1;
			}
		}
	}

	return cnt[100];
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n + m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		arr[t1] = t2;
	}

	cout << solve(1);
	return 0;
}