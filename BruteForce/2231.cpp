#include <iostream>
using namespace std;

int main() {
	int n, res = 0;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int tmp = i;
		int sum = 0;
		sum += tmp;
		while(tmp > 0) {
			sum += tmp % 10;
			tmp /= 10;
		}
		if (sum == n) {
			res = i;
			break;
		}
	}
	cout << res;
	return 0;
}