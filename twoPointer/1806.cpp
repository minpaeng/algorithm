#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S;
	cin >> N >> S;
	v.push_back(0);
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		v.push_back(v[i] + t);
	}

	int s = 1, e = N;
	int len = N + 1;

	while (s <= e) {
		if (v[e] - v[s - 1] >= S) {
			len = min(e - (s - 1), len);
			e--;
		}
		else {
			s++;
			if (s + len - 1 <= N) e = s + len - 1;
			else e = N;
		}
	}

	if (len != (N + 1))cout << len;
	else cout << '0';
	return 0;
}