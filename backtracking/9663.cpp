#include <iostream>
#include <vector>
using namespace std;

int n, cnt;
vector<int> v;
void dfs(int row) {
	//n - 1�� ����� Ž���ߴٸ� ����
	if (row == n) {
		cnt++;
		return;
	}
	// row�� ���� i��° ��ġ�� ���� ���� ��
	for (int i = 0; i < n; i++) {
		// row�� ���� ����� Ž��
		// ���� ��ġ�� ���� ���� ��ġ�� ����� 
		// ����, �밢�� ���⿡ ��ġ�Ѵٸ� ���� ���� ��ġ�� �Űܼ� ���� ��
		//�׷��� �ʴٸ� �ش� ��ġ�� ���� ���� �� �ִٴ� ���̹Ƿ� ���� �� Ž��
		bool flag = true;
		for (int j = 0; j < row; j++) {
			if (i == v[j] || row - j == abs(i - v[j])) {
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		v[row] = i;
		dfs(row + 1);
		v[row] = -1;
	}
}

void n_queen(int num) {
	for (int i = 0; i < num; i++) {
		//0�� ���� i��° ��ġ�� ���� ���� ������ ��
		v[0] = i;
		dfs(1);
	}
	cout << cnt;
}

int main() {
	cin >> n;
	v.assign(n, -1);

	n_queen(n);
	return 0;
}