#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> arr;

int main() {
	cin >> n >> k;
	arr.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	int max = -10000001;
	for (int i = 1; i <= n - (k - 1); i++) {
		int sum = arr[i + k - 1] - arr[i - 1];
		if (sum > max) max = sum;
	}

	cout << max;
	return 0;
}