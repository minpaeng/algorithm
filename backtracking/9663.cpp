#include <iostream>
#include <vector>
using namespace std;

int n, cnt;
vector<int> v;
void dfs(int row) {
	//n - 1번 행까지 탐색했다면 리턴
	if (row == n) {
		cnt++;
		return;
	}
	// row번 행의 i번째 위치에 퀸을 놓아 봄
	for (int i = 0; i < n; i++) {
		// row번 이전 행들을 탐색
		// 현재 위치의 퀸이 이전 위치의 퀸들과 
		// 세로, 대각선 방향에 위치한다면 퀸을 다음 위치로 옮겨서 놓아 봄
		//그렇지 않다면 해당 위치에 퀸을 놓을 수 있다는 것이므로 다음 행 탐색
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
		//0번 행의 i번째 위치에 퀸을 놓고 시작할 때
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