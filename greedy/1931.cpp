#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, cnt = 1;
	vector<pair<int, int>> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.emplace_back(make_pair(a, b));
	}

	sort(v.begin(), v.end(), compare);

	int end = v[0].second;
	for (int i = 1; i < n; i++) {
		cout << v[i].first << ' ' << v[i].second << endl;
	}

	cout << cnt;
	return 0;
}