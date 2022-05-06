#include <iostream>
using namespace std;

int n, m;
int res[7];
//bool visited[10];

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			res[cnt] = i;
			dfs(cnt + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(0);
	return 0;
}