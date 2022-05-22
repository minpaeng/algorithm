#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);

	istringstream ss(s);
	string res;
	int cnt = 0;
	while (getline(ss, res, ' ')) {
		if(res.length()) cnt++;
	}
	cout << cnt;
	return 0;
}