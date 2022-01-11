#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int node[26][26], n;
bool visited[26][26];
vector<int> cnt;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int house_numbering(int v1, int v2, int num) {
	visited[v1][v2] = true;
	num++;
	for (int i = 0; i < 4; i++) {
		int x = v1 + dx[i], y = v2 + dy[i];
		if (x >= n || y >= n || x < 0 || y < 0) continue;
		if (node[x][y] == 1 && !visited[x][y]) {
			num = house_numbering(x, y, num);
		}
	}
	return num;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			node[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && node[i][j] == 1) {
				cnt.emplace_back(house_numbering(i, j, 0));
			}
		}
	}

	int size = cnt.size();
	cout << size << '\n';
	sort(cnt.begin(), cnt.end());
	for (int i = 0; i < size; i++) {
		cout << cnt[i] << '\n';
	}
	return 0;
}