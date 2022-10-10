#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		vector<int> v[2];
		vector<int> dp[2];
		cin >> n;
		dp[0].assign(n + 1, 0);
		dp[1].assign(n + 1, 0);

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				int a;
				cin >> a;
				v[i].push_back(a);
			}
		}

		dp[0][0] = v[0][0], dp[1][0] = v[1][0];
		dp[0][1] = dp[1][0] + v[0][1], dp[1][1] = dp[0][0] + v[1][1];
		for (int i = 2; i < n; i++) {
			dp[0][i] = max(dp[1][i - 1], max(dp[0][i - 2], dp[1][i - 2])) + v[0][i];
			dp[0][i] = max(dp[0][i], max(dp[0][i - 1], dp[1][i - 1]));

			dp[1][i] = max(dp[0][i - 1], max(dp[0][i - 2], dp[1][i - 2])) + v[1][i];
			dp[1][i] = max(dp[1][i], max(dp[0][i - 1], dp[1][i - 1]));

		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}

	return 0;
}