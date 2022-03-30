#include <iostream>
#include <algorithm> 
using namespace std;

pair<int, int> app[101];
int n, m, sum = 0;
int dp[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> app[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> app[i].second;
		sum += app[i].second;
	}

	for (int i = 0; i < n; i++) {
		int memory = app[i].first;
		int cost = app[i].second;
		for (int j = sum; j >= cost; j--) {
			dp[j] = max(dp[j], dp[j - cost] + memory);
		}
	}

	int i = 0;
	for (i = 0; i < sum, dp[i] < m; i++);
	cout << i << endl; return 0;
}
