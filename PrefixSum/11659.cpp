#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	arr.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		cout << arr[e] - arr[s - 1] << '\n';
	}
	return 0;
}