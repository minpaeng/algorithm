#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, a[1000], time = 0, sum = 0;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		time += a[i];
		sum += time;
	}

	cout << sum;
	return 0;
}