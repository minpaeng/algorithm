#include <iostream>
using namespace std;

#define MIN 1000000000
#define MAX -1000000000

int arr[101];
int oper[4]; // 0: +, 1: -, 2: *, 3: /
int min_val = MIN, max_val = MAX, n;

void cal(int pre_val, int cnt) {
	if (cnt == n - 1) {
		if (pre_val > max_val) max_val = pre_val;
		if (pre_val < min_val) min_val = pre_val;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i]) {
			oper[i] -= 1;
			if (i == 0) cal(pre_val + arr[cnt + 1], cnt + 1);
			if (i == 1) cal(pre_val - arr[cnt + 1], cnt + 1);
			if (i == 2) cal(pre_val * arr[cnt + 1], cnt + 1);
			if (i == 3) cal(pre_val / arr[cnt + 1], cnt + 1);
			oper[i] += 1;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < 4; i++) cin >> oper[i];

	cal(arr[0], 0);
	cout << max_val << '\n';
	cout << min_val << '\n';
	return 0;
}