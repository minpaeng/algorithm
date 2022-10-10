#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	vector<int> res;
	res.push_back(v[0]);
	for (int i = 1; i < n; i++) {
		if (*(res.end() - 1) >= v[i]) {
			auto iter = lower_bound(res.begin(), res.end(), v[i]);
			*iter = v[i];
		}
		else res.push_back(v[i]);
	}
	cout << res.size();
	return 0;
}