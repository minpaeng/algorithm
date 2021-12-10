#include <iostream>
#include <algorithm>
using namespace std;
int n, stair[301];
int res[301] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) cin >> stair[i];

	res[1] = stair[1]; res[2] = stair[1] + stair[2];

	for (int i = 3; i <= n; i++) {
		res[i] = max(stair[i - 1] + res[i - 3], res[i - 2]) + stair[i];
	}

	cout << res[n];
	return 0;
}