#include <iostream>
using namespace std;
void star(int i, int j, int n)
{
	//n�� 1�̶�� * ��� �� ����
	if (n == 1) {
		cout << '*';
		return;
	}
	//n ũ���� �簢���� ���Ͽ� ��� ���鱸���� �ִ��� ����
	if ((i / (n / 3)) % 3 == 1 && (j / (n / 3)) % 3 == 1) {
		cout << ' ';
	}
	//�ƴ϶�� n/3 ũ���� �簢���� ���� ���� ������ ���ϴ��� �˻��ϱ� ���� ���
	else star(i, j, n / 3);
	
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			star(i, j, n);
		}
		cout << '\n';
	}
}