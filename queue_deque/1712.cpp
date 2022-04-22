#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	if (b >= c) {
		cout << "-1";
		return 0;
	}

	long long cost = 0, income = 0;
	cout << a / (c - b) + 1;

	return 0;
}