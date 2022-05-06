#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int n, cnt;

bool is_group_word(string s) {
	set<char> arr;
	for (size_t i = 0; i < s.length(); i++) {
		if (arr.find(s[i]) != arr.end()) {
			if (s[i] != s[i - 1]) return false;
		}
		else arr.insert(s[i]);
	}
	return true;
}

int main() {
	cin >> n;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (is_group_word(s)) cnt++;
	}
	cout << cnt;
	return 0;
}