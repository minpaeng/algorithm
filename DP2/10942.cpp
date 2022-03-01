#include <iostream>
#include <vector>
using namespace std;

vector<int> num;
bool dp[2001][2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		dp[i][i] = true;
		if (i != n - 1 && num[i] == num[i + 1]) dp[i][i + 1] = true;
	}

	for (int gap = 2; gap < n; gap++) {
		for (int i = 0; i < n - gap; i++) {
			int j = i + gap;
			if (num[i] == num[j] && dp[i + 1][j - 1]) dp[i][j] = dp[i + 1][j - 1];
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		cout << dp[start - 1][end - 1] << '\n';
	}

	return 0;
}