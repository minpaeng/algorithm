#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a[1000], dp_plus[1000] = {}, dp_minus[1000] = {}, res1 = 1, res2 = 0, res = 0;;

	cin >> n;

	fill_n(dp_plus, n, 1);
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
		for (int k = 0; k <= i - 1; k++) if (a[i] > a[k]) dp_plus[i] = max(dp_plus[i], dp_plus[k] + 1);
		for (int k = j + 1; k < n; k++) if (a[j] > a[k]) dp_minus[j] = max(dp_minus[j], dp_minus[k] + 1);
	}

	for (int i = 0; i < n; i++) {
		dp_plus[i] += dp_minus[i];
		if (dp_plus[i] > res) res = dp_plus[i];
	}

	cout << res;
	return 0;
}