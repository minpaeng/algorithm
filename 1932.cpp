#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, val, sum[501][501] = {}, m = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &val);
			sum[i][j] = max(sum[i - 1][j - 1], sum[i - 1][j]) + val;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (sum[n][i] > m) m = sum[n][i];
	}

	printf("%d", m);
	return 0;
}