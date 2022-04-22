#include <iostream>
#include <algorithm>
using namespace std;

int dp[5001];

int main() {
	int n;
	cin >> n;

	fill_n(dp, n + 1, 2000);
	dp[3] = dp[5] = 1;
	for (int i = 6; i <= n; i++) {
		dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
	}

	if (dp[n] >= 2000) cout << "-1";
	else cout << dp[n];
	return 0;
}