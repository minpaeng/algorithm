#include <iostream>
#include <algorithm>
using namespace std;

int ar[100000];
int dp[100000];

int main() {
	int n, res;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> ar[i];

	dp[0] = ar[0];
	res = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + ar[i], ar[i]);
		res = max(res, dp[i]);
	}
	cout << res;
	return 0;
}