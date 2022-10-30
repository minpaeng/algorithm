#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<pair<int, int>> pq;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x != 0) pq.push({ abs(x) * -1 , x * -1 });
		else {
			if (!pq.empty()) {
				cout << pq.top().second * -1 << '\n';
				pq.pop();
			}
			else cout << "0\n";
		}
	}
	return 0;
}