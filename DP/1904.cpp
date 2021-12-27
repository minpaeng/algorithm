#include <cstdio>

long long r[1000001];

long long f(int n) {
	if (n == 1) return 1L;
	if (n == 2) return 2L;
	if (r[n] == 0) r[n] = (f(n - 1) + f(n - 2)) % 15746L;
	return r[n];
}

int main() {
	int n; //1 ¡Â N ¡Â 1,000,000
	scanf("%d", &n);
	printf("%lld", f(n));
	return 0;
}