#include <iostream>
using namespace std;
void hanoi(int start, int by, int end, int num)
{
	//n이 1이라면, start 막대에서 end 막대로 이동
	if (num == 1) {
		cout << start << ' ' << end << '\n';
	}
	else {
		//n-1개의 원판을 start 막대에서 end 막대를 거쳐 by막대로 이동
		hanoi(start, end, by, num - 1);
		//맨 밑의 1개의 원판을 start 막대에서 end 막대로 이동
		cout << start << ' ' << end << '\n';
		//n-1개의 원판을 by 막대에서 start 막대를 거쳐 end 막대로 이동
		hanoi(by, start, end, num - 1);
	}
}
int main() {
	int n;
	cin >> n;
	cout << (1 << n) - 1 << "\n";
	hanoi(1, 2, 3, n);
	return 0;
}