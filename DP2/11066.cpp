#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int dp[501][501];
int sum[501];

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, tmp;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> tmp;
			sum[i] = sum[i - 1] + tmp;
		}

		for (int gap = 1; gap < n; gap++) {
			for (int i = 1; i <= n - gap; i++) {
				int j = i + gap;
				dp[i][j] = INT_MAX;
				for (int k = i; k < j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
				}
			}
		}
		cout << dp[1][n] << endl;

	}
	return 0;
}