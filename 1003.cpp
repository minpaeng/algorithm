#include <iostream>
using namespace std;

int a[41] = { 0,1, };

int fibonacci(int num)
{
	if (num == 0 || num == 1) return a[num];
	//값이 없을 때만 재귀호출
	else if (a[num] == 0) a[num] = fibonacci(num - 1) + fibonacci(num - 2);
	return a[num];
	
}
int main() {
	int T, n;
	cin >> T;

	while (T--)
	{
		cin >> n;
		if (n == 0)
			cout << "1 0" << '\n';
		else {
			fibonacci(n);
			cout << a[n-1] << ' ' << a[n] << '\n';
		}
	}
}