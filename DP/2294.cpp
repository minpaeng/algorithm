#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 987654321
int coin[100], dp[101][10001];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> coin[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 1001; j++) dp[i][j] = MAX;
	}

	for (int i = 0; i < n; i++) {
		dp[i][0] = 0;
		for (int j = 0; j <= k; j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			int cost = j + coin[i];
			if (cost <= k) dp[i][cost] = min(dp[i][cost], dp[i][j] + 1);
		}
	}

	if (dp[n-1][k] == MAX) cout << -1;
	else cout << dp[n - 1][k];
	return 0;
}