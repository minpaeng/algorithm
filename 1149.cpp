#include <cstdio>
#include <algorithm>
using namespace std;

int rgb[1001][3];


int main() {
	int cost[3], n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &cost[0], &cost[1], &cost[2]);
		rgb[i][0] = min(rgb[i - 1][1], rgb[i - 1][2]) + cost[0];
		rgb[i][1] = min(rgb[i - 1][0], rgb[i - 1][2]) + cost[1];
		rgb[i][2] = min(rgb[i - 1][0], rgb[i - 1][1]) + cost[2];

	}
	int res = min(rgb[n - 1][2], min(rgb[n - 1][0], rgb[n - 1][1]));
	printf("%d\n", res);
	return 0;
}