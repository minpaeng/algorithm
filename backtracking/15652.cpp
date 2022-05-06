#include <iostream>
using namespace std;

int n, m;
int res[8];

void dfs(int cnt, int pre) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}
	else {
		for (int i = pre; i <= n; i++) {
			res[cnt] = i;
			dfs(cnt + 1, i);
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(0, 1);
	return 0;
}