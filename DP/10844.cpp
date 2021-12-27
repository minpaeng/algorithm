#include <iostream>
using namespace std;
# define mod 1000000000
int main() {
	int n, dp[101][11] = {}, sum = 0;
	cin >> n;

	for (int i = 1; i <= 9; i++) dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
		for (int j = 1; j <= 8; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
	}

	for (int i = 0; i <= 9; i++) {
		sum = (sum + dp[n][i]) % mod;
	}

	cout << sum << "\n";
	return 0;
}