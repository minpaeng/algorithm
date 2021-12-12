#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[1001][1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	for (size_t i = 0; i < a.length(); i++) {
		for (size_t j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
			else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}

	cout << dp[a.length()][b.length()] << endl;
	return 0;
}