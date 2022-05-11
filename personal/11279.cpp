#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int> pq;
	int n;
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		if (m == 0) {
			if (pq.size() == 0) {
				cout << '0' << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else pq.push(m);
	}
	return 0;
}