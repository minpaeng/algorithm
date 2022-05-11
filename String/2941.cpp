#include <iostream>
#include <string>
using namespace std;

string croa[] = { "c=", "c-", "dz=" , "d-" , "lj" , "nj", "s=", "z=" };
int main() {
	string s;
	cin >> s;

	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		bool flag = false;
		for (auto x : croa) {
			if (!x.compare(0, x.length(), s, i, x.length())) {
				cnt++;
				flag = true;
				i += (x.length() - 1);
				break;
			}
		}
		if (!flag) cnt++;
	}
	cout << cnt;
	return 0;
}