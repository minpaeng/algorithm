#include <cstdio>
using namespace std;

long long r[101];

long long p(int n) {
	if (n <= 3) return 1;
	if (n <= 5) return 2;
	if (!r[n]) r[n] = p(n - 1) + p(n - 5);
	return r[n];
}

int main() {
	int T, n;
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);
		printf("%lld\n", p(n));
	}
	return 0;
}