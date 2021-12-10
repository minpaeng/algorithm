#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b, res = 0;
	cin >> n;

	vector<pair<int, int>> v;
	v.emplace_back(0, 0);
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.emplace_back(a, b);
	}
	sort(v.begin(), v.end());


	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) {
				if (dp[j] >= dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
		}
		res = max(res, dp[i]);
	}

	cout << n - res << endl;
	return 0;
}