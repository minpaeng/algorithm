#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> h;

long long find_max_height(int m, int n, int max_value) {
	long long start = 1, end = max_value, mid, sum, res = 0;

	while (start <= end) {
		mid = (start + end) / 2;

		sum = 0;
		for (int i = 0; i < n; i++) {
			long long temp = h[i] - mid;
			if (temp > 0) sum += temp;
		}

		if (sum >= m) {
			start = mid + 1;
			res = mid;
		}
		else end = mid - 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;
	h.assign(n, 0);

	int max_value = 0;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		max_value = max(h[i], max_value);
	}

	cout << find_max_height(m, n, max_value) << '\n';

	return 0;
}