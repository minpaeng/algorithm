#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 30

int n, m;
int w[MAX + 1], q[7];
bool dp[MAX + 1][MAX * 500 + 1];

void make_weight(int num, int weight) {
	if (num > n) return;
	if (dp[num][weight]) return;

	dp[num][weight] = true;

	make_weight(num + 1, weight + w[num]);
	make_weight(num + 1, weight);
	make_weight(num + 1, abs(weight - w[num]));
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}

	make_weight(0, 0);

	cin >> m;
	int tmp;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		if (tmp > MAX * 500) cout << "N ";
		else if (dp[n][tmp]) cout << "Y ";
		else cout << "N ";
	}
	return 0;
}
