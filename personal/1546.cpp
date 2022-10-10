#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	float max_score = 0;
	cin >> n;
	vector<float> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] > max_score) max_score = v[i];
	}

	float sum = 0;
	for (int i = 0; i < n; i++) {
		v[i] = v[i] / max_score * 100;
		sum += v[i];
	}
	cout << sum / n;
	return 0;
}