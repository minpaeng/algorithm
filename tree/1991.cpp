#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

char tree[27];
int A = 64;

void pre(char v, int n) {
	int i = v - A;
	if (i > n) return;
	cout << v;
	if (tree[i * 2] != '.') {
		pre(tree[i * 2], n);
	}
	if (tree[i * 2 + 1] != '.') {
		pre(tree[i * 2 + 1], n);
	}
}

void mid(char v, int n) {
	int i = v - A;
	if (i > n) return;
	if (tree[i * 2] != '.') {
		mid(tree[i * 2], n);
	}
	cout << v;
	if (tree[i * 2 + 1] != '.') {
		mid(tree[i * 2 + 1], n);
	}
}

void post(char v, int n) {
	int i = v - A;
	if (i > n) return;
	if (tree[i * 2] != '.') {
		post(tree[i * 2], n);
	}
	if (tree[i * 2 + 1] != '.') {
		post(tree[i * 2 + 1], n);
	}
	cout << v;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		tree[2 * (a - A)] = b;
		tree[2 * (a - A) + 1] = c;
	}

	pre('A', n);
	cout << '\n';
	mid('A', n);
	cout << '\n';
	post('A', n);
	return 0;
}