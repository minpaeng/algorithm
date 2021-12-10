#include <iostream>
using namespace std;
void star(int i, int j, int n)
{
	//n이 1이라면 * 출력 후 리턴
	if (n == 1) {
		cout << '*';
		return;
	}
	//n 크기의 사각형에 대하여 가운데 공백구역에 있는지 조사
	if ((i / (n / 3)) % 3 == 1 && (j / (n / 3)) % 3 == 1) {
		cout << ' ';
	}
	//아니라면 n/3 크기의 사각형에 대한 공백 영역에 속하는지 검사하기 위해 재귀
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