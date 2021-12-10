#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, a[1000], dp[1000] = {}, maxlen, res = 1;
	scanf("%d", &n);

	fill_n(dp, n, 1);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		maxlen = 0;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) dp[i] = max(dp[j]+1, dp[i]);
		}
		res = max(dp[i], res);
	}

	printf("%d", res);
	return 0;
}