#include <iostream>
using namespace std;

int paper[128][128];
int white, blue;

bool canFinish(int n, int x, int y) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if(paper[i][j] != paper[x][y]) return false;
		}
	}
	return true;
}

void divide(int n, int x, int y) {
	if (canFinish(n, x, y)) {
		if (!paper[x][y]) white += 1;
		else blue += 1;
		return;
	}
	divide(n / 2, x, y);
	divide(n / 2, x + (n / 2), y);
	divide(n / 2, x, y + (n / 2));
	divide(n / 2, x + (n / 2), y + (n / 2));
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	divide(n, 0, 0);
	cout << white << '\n';
	cout << blue << '\n';
	return 0;
}