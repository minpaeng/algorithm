#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][100001], w[101], v[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			// 1. 물건을 담을 수 있는 경우
			if (j >= w[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			// 2. 물건을 담을 수 없는 경우
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k];
	return 0;
}