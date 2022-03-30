#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> v;

long long find_max_length(int n, int k, int max_value) {
	long long start = 1, end = max_value, mid, num, res = 0;

	while (start <= end) {
		mid = (start + end) / 2;

		num = 0;
		for (int i = 0; i < k; i++) num += (v[i] / mid);

		if (num >= n) {
			start = mid + 1;
			res = max(res, mid);
		}
		else end = mid - 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k, n;

	cin >> k >> n;
	v.assign(k, 0);

	int max_value = 0;
	for (int i = 0; i < k; i++) {
		cin >> v[i];
		max_value = max(max_value, v[i]);
	}

	cout << find_max_length(n, k, max_value) << '\n';

	return 0;
}