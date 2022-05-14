#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	for (int i = min(a, b);; i--) {
		if (a % i == 0 && b % i == 0) {
			cout << i << '\n';
			break;
		}
	}

	for (int i = max(a, b);; i++) {
		if (i % a == 0 && i % b == 0) {
			cout << i;
			break;
		}
	}

	return 0;
}