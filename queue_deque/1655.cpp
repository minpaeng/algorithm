#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	priority_queue<int> pq_min, pq_max;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (pq_min.size() < pq_max.size()) pq_min.push(-t);
		else pq_max.push(t);

		if (!pq_max.empty() && !pq_min.empty()) {
			if (pq_max.top() > -pq_min.top()) {
				int val_max = pq_max.top();
				int val_min = -pq_min.top();
				pq_max.pop();
				pq_min.pop();

				pq_min.push(-val_max);
				pq_max.push(val_min);
			}
		}
		cout << pq_max.top() << endl;
	}

	return 0;
}