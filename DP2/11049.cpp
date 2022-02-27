#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int dp[501][501];

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	for (int gap = 1; gap < n; gap++) {
		for (int i = 0; i  + gap < n; i++) {
			int j = i + gap;
			dp[i][j] = INT_MAX;
			for (int k = i; k < j; k++) {
				int res = v[i].first * v[k].second * v[j].second;
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + res);
			}
		}
	}

	cout << dp[0][n - 1];
	return 0;
}