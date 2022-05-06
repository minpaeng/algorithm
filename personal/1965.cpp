#include <iostream>
#include <algorithm>
using namespace std;

int box[1000];
int res[1000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> box[i];
	}

	fill_n(res, n, 1);
	int max_val = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (box[i] > box[j]) res[i] = max(res[i], res[j] + 1);
		}
		max_val = max(max_val, res[i]);
	}

	cout << max_val;
	return 0;
}