#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int res;
int n, m;

void maxSum(int cnt, int sum, int pos) {
	if (cnt == 3) {
		if (sum <= m && res < sum) res = sum;
		return;
	}
	for (int i = pos + 1; i < n; i++) {
		maxSum(cnt + 1, sum + v[i], i);
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	maxSum(0, 0, 0);
	cout << res;
	return 0;
}