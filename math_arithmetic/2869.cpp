#include <iostream>
using namespace std;

int main() {
	int a, b, v;
	cin >> a >> b >> v;
	int res = (v - a) / (a - b);
	int r = (v - a) % (a - b);
	if (r == 0) cout << res + 1;
	else cout << res + 2;
	return 0;
}