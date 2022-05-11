#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());
	pair<int, int> near_zero = { 0, n - 1 };
	int s = 0, e = n - 1;
	while (s < e) {
		if (abs(v[s] + v[e]) < abs(v[near_zero.first] + v[near_zero.second])) {
			near_zero.first = s, near_zero.second = e;
		}
		else {
			if (abs(v[s]) > abs(v[e])) s++;
			else e--;
		}
	}
	cout << v[near_zero.first] << ' ' << v[near_zero.second];

	return 0;
}