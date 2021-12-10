#include <iostream>
using namespace std;
void hanoi(int start, int by, int end, int num)
{
	//n�� 1�̶��, start ���뿡�� end ����� �̵�
	if (num == 1) {
		cout << start << ' ' << end << '\n';
	}
	else {
		//n-1���� ������ start ���뿡�� end ���븦 ���� by����� �̵�
		hanoi(start, end, by, num - 1);
		//�� ���� 1���� ������ start ���뿡�� end ����� �̵�
		cout << start << ' ' << end << '\n';
		//n-1���� ������ by ���뿡�� start ���븦 ���� end ����� �̵�
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