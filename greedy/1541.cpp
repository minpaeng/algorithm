#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b = "";
	int n1 = 0, n2 = 0, res = 0;
	bool flag = false;
	cin >> a;

	for (size_t i = 0; i <= a.length(); i++) {
		if (a[i] == '+' || a[i] == '-' || a[i] == '\0') {
			if (flag) res -= stoi(b);
			else res += stoi(b);
			if (a[i] == '-') flag = true;
			b = "";
			continue;
		}
		b += a[i];
	}

	cout << res;
	return 0;
}