#include <iostream>
#include <cstring>
using namespace std;

int inOrder[100001];
int postOrder[100001];
int idx[100001];
int n;

void pre(int postStart, int postEnd, int inStart) {
	if (postStart > postEnd) return;
	cout << postOrder[postEnd] << ' ';
	
	int frontLen = idx[postOrder[postEnd]] - inStart;
	pre(postStart, postStart + frontLen - 1, inStart);
	pre(postStart + frontLen, postEnd - 1, idx[postOrder[postEnd]] + 1);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inOrder[i];
		idx[inOrder[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> postOrder[i];
	}

	pre(1, n, 1);
	return 0;
}