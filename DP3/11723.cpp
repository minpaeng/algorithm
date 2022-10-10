#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, bit = 0;
	cin >> m;

	while (m--) {
		string oper;
		cin >> oper;
		// all일때
		if (!oper.compare("all")) {
			bit = (1 << 21) - 1;
		}
		else if (!oper.compare("empty")) {
			bit = 0;
		}
		// all이 아닐때
		else {
			int n;
			cin >> n;
			if (!oper.compare("add")) bit |= (1 << n);
			else if (!oper.compare("remove")) bit &= ~(1 << n);
			else if (!oper.compare("check")) {
				if (bit & (1 << n)) cout << "1\n";
				else cout << "0\n";
			}
			else if (!oper.compare("toggle")) bit ^= (1 << n);
		}
	}
	return 0;
}