#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;

int main() {
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		arr.push_back(t);
	}

	cin >> x;

	sort(arr.begin(), arr.end());

	int cnt = 0;
	int s = 0;
	int e = n - 1;

	while (s < e) {
		if (arr[s] + arr[e] == x) {
			s++;
			e--;
			cnt += 1;
		}
		else if (arr[s] + arr[e] < x) s++;
		else e--;
	}

	cout << cnt;
	return 0;
}