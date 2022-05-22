#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int res = 0;
	for (auto x : s) {
		if (x >= 'A' && x <= 'C') res += 3;
		else if (x >= 'D' && x <= 'F') res += 4;
		else if (x >= 'G' && x <= 'I') res += 5;
		else if (x >= 'J' && x <= 'L') res += 6;
		else if (x >= 'M' && x <= 'O') res += 7;
		else if (x >= 'P' && x <= 'S') res += 8;
		else if (x >= 'T' && x <= 'V') res += 9;
		else if (x >= 'W' && x <= 'Z') res += 10;
	}
	cout << res;
	return 0;
}