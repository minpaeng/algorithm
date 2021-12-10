#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ar[10001], dp[10001] = {};

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> ar[i];

	dp[1] = ar[1]; dp[2] = ar[1] + ar[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + ar[i - 1] + ar[i], max(dp[i - 1], dp[i - 2] + ar[i]));
	}

	cout << dp[n];
	return 0;
}