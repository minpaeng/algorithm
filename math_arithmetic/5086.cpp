#include <iostream>
using namespace std;

int main() {

	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		if ((n % m) != 0 && (m % n) != 0) cout << "neither\n";
		else if ((n / m) != 0) cout << "multiple\n";
		else cout << "factor\n";
	}
	return 0;
}