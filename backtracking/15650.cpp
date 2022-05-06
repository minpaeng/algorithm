#include <iostream>
using namespace std;

int n, m;
int res[8];
bool visited[10];

void dfs(int cnt, int pre) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}
	else {
		for (int i = pre + 1; i <= n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				res[cnt] = i;
				dfs(cnt + 1, i);
				visited[i] = false;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(0, 0);
	return 0;
}