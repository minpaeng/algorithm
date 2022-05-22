#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	priority_queue<int, vector<int>, greater<int>> pq;
	while (n--) {
		int t;
		cin >> t;
		pq.push(t);
	}

	while(!pq.empty()) {
		cout << pq.top() << '\n';
		pq.pop();
	}
	return 0;
}