#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b, res = 0, dp[101];
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.emplace_back(a, b);
	}
	sort(v.begin(), v.end());

	fill_n(dp, n, 1);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++)
			if (v[i].second > v[j].second && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
		res = max(res, dp[i]);
	}

	cout << n - res;
	return 0;
}