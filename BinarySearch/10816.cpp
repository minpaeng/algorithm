#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.emplace_back(temp);
	}

	cin >> m;
	int item;
	int res;
	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) {
		cin >> item;
		res = upper_bound(v.begin(), v.end(), item) - lower_bound(v.begin(), v.end(), item);
		cout << res << ' ';
	}

	return 0;
}