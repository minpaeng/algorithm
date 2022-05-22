#include <iostream>
#include <vector>
using namespace std;

vector<int> primeNum(int n) {
	vector<bool> v(n + 1, true);
	v[1] = false;
	for (int i = 2; i * i <= n; i++) {
		for (int j = i + i; j <= n; j += i) {
			v[j] = false;
		}
	}

	vector<int> res;
	for (int i = 1; i <= n; i++) {
		if (v[i]) res.push_back(i);
	}

	return res;
}

int main() {
	int n;
	cin >> n;

	vector<int> v = primeNum(n);

	int s = 0, e = 0, sum = 0, cnt = 0;
	while (s <= e) {
		if (sum <= n) {
			if (sum == n) cnt++;
			if (e == v.size()) break;
			sum += v[e];
			e++;
		}
		else {
			sum -= v[s];
			s++;
		}
	}
	
	cout << cnt;
	return 0;
}