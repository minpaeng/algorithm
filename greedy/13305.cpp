#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	long long res = 0, min = 1000000000;
	vector<int> len(n - 1), price(n);

	for (int i = 0; i < n - 1; i++) cin >> len[i];
	for (int i = 0; i < n; i++) cin >> price[i];

	for (int i = 0; i < n - 1; i++) {
		if (min > price[i]) min = price[i];
		res += len[i] * min;
	}

	cout << res;
	return 0;
}