#include <iostream>
#include<algorithm>
using namespace std;

int arr_n[100001];

bool binarySearch(int start, int end, int item) {
	if (start > end) return false;

	int mid = (start + end) / 2;
	if (arr_n[mid] == item) return true;
	else {
		if (arr_n[mid] > item) return binarySearch(start, mid - 1, item);
		else return binarySearch(mid + 1, end, item);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr_n[i];
	}

	cin >> m;
	int item;
	bool res;
	sort(arr_n, arr_n + n);
	for (int i = 0; i < m; i++) {
		cin >> item;
		res = binarySearch(0, n, item);
		if (res) cout <<"1\n";
		else cout << "0\n";
	}
	return 0;
}