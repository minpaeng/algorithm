#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int t;
	
	cin >> t;
	while (t--) {
		stack<char> s;
		string str;

		cin >> str;
		bool flag = true;
		for (unsigned i = 0; i < str.length(); i++) {
			if (str[i] == '(') {
				s.push(str[i]);
			}
			else if (str[i] == ')') {
				if (s.empty()) {
					flag = false;
					break;
				}
				else s.pop();
			}
		}
		if (!flag || !s.empty()) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}