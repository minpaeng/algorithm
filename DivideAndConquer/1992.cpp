#include <iostream>
#include <string>
using namespace std;

int arr[64][64];

bool can_zip(int n, int x, int y) {
	int item = arr[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (item != arr[i][j]) return false;
		}
	}
	return true;
}

void zip_video(int n, int x, int y) {
	if (can_zip(n, x, y)) {
		cout << arr[x][y];
		return;
	}
	cout << '(';
	zip_video(n / 2, x, y);
	zip_video(n / 2, x, y + (n / 2));
	zip_video(n / 2, x + (n / 2), y);
	zip_video(n / 2, x + (n / 2), y + (n / 2));
	cout << ')';
}

int main() {
	int n;
	cin >> n;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	zip_video(n, 0, 0);
	return 0;
}