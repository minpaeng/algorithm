#include <iostream>
#include <map>
#include <vector>
using namespace std;

map <char, pair<char, char>> adj;

void pre(char c) {
	cout << c;
	if (adj[c].first != '.') pre(adj[c].first);
	if (adj[c].second != '.') pre(adj[c].second);
}

void mid(char c) {
	if (adj[c].first != '.') mid(adj[c].first);
	cout << c;
	if (adj[c].second != '.') mid(adj[c].second);
}

void suf(char c) {
	if (adj[c].first != '.') suf(adj[c].first);
	if (adj[c].second != '.') suf(adj[c].second);
	cout << c;
}
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char tmp1, tmp2, tmp3;
		cin >> tmp1 >> tmp2 >> tmp3;
		adj[tmp1] = { tmp2, tmp3 };

	}
	pre('A');
	cout << endl;

	mid('A');
	cout << endl;
	suf('A');

	return 0;
}