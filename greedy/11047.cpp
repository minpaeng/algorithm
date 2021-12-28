#include <iostream>
using namespace std;

int main() {
	int n, k, cnt = 0, w[10], t;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> w[i];

	for (int i = n - 1; k != 0; i--) {
		t = k / w[i];
		if (t > 0) {
			cnt += t;
			k -= w[i] * t;
		}
	}

	cout << cnt;
	return 0;
}