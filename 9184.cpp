#include <cstdio>

int res[21][21][21];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	int& r = res[a][b][c];
	if (!r) {
		if (a < b && b < c) r = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		else r = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
	return r;
}

int main() {
	int a, b, c;
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
	return 0;
}