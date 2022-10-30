#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<vector<int>> board;
int res, n;

vector<vector<int>> up(vector<vector<int>> board) {
	for (int j = 0; j < n; j++) {
		queue<pair<int, bool>> q;
		for (int i = 0; i < n; i++)
			if (board[i][j] != 0) {
				q.push({ board[i][j], false });
				board[i][j] = 0;
			}

		stack<pair<int, bool>> res_q;
		while (!q.empty()) {
			if (res_q.empty()) {
				res_q.push(q.front());
				q.pop();
				continue;
			}
			if ((q.front().first == res_q.top().first) && !res_q.top().second) {
				res_q.pop();
				res_q.push({ q.front().first * 2 , true });
				q.pop();
			}
			else {
				res_q.push(q.front());
				q.pop();
			}
		}

		int i = res_q.size() - 1;
		while (!res_q.empty()) {
			board[i][j] = res_q.top().first;
			res_q.pop();
			i--;
		}
	}
	return board;
}

vector<vector<int>> down(vector<vector<int>> board) {
	for (int j = 0; j < n; j++) {
		queue<pair<int, bool>> q;
		for (int i = n - 1; i >= 0; i--)
			if (board[i][j] != 0) {
				q.push({ board[i][j], false });
				board[i][j] = 0;
			}

		stack<pair<int, bool>> res_q;
		while (!q.empty()) {
			if (res_q.empty()) {
				res_q.push(q.front());
				q.pop();
				continue;
			}
			if ((q.front().first == res_q.top().first) && !res_q.top().second) {
				res_q.pop();
				res_q.push({ q.front().first * 2 , true });
				q.pop();
			}
			else {
				res_q.push(q.front());
				q.pop();
			}
		}

		int i = n - 1 - (res_q.size() - 1);
		while (!res_q.empty()) {
			board[i][j] = res_q.top().first;
			res_q.pop();
			i++;
		}
	}
	return board;
}

vector<vector<int>> left(vector<vector<int>> board) {
	for (int i = 0; i < n; i++) {
		queue<pair<int, bool>> q;
		for (int j = 0; j < n; j++)
			if (board[i][j] != 0) {
				q.push({ board[i][j], false });
				board[i][j] = 0;
			}

		stack<pair<int, bool>> res_q;
		while (!q.empty()) {
			if (res_q.empty()) {
				res_q.push(q.front());
				q.pop();
				continue;
			}
			if ((q.front().first == res_q.top().first) && !res_q.top().second) {
				res_q.pop();
				res_q.push({ q.front().first * 2 , true });
				q.pop();
			}
			else {
				res_q.push(q.front());
				q.pop();
			}
		}

		int j = res_q.size() - 1;
		while (!res_q.empty()) {
			board[i][j] = res_q.top().first;
			res_q.pop();
			j--;
		}
	}
	return board;
}

vector<vector<int>> right(vector<vector<int>> board) {
	for (int i = 0; i < n; i++) {
		queue<pair<int, bool>> q;
		for (int j = n - 1; j >= 0; j--)
			if (board[i][j] != 0) {
				q.push({ board[i][j], false });
				board[i][j] = 0;
			}

		stack<pair<int, bool>> res_q;
		while (!q.empty()) {
			if (res_q.empty()) {
				res_q.push(q.front());
				q.pop();
				continue;
			}
			if ((q.front().first == res_q.top().first) && !res_q.top().second) {
				res_q.pop();
				res_q.push({ q.front().first * 2 , true });
				q.pop();
			}
			else {
				res_q.push(q.front());
				q.pop();
			}
		}

		int j = n - 1 - (res_q.size() - 1);
		while (!res_q.empty()) {
			board[i][j] = res_q.top().first;
			res_q.pop();
			j++;
		}
	}
	return board;
}

void solve(int depth, vector<vector<int>> board) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (board[i][j] != 0) {
			cnt++;
			res = max(res, board[i][j]);
		}

	if (cnt == 1) return;
	if (depth == 5) return;

	solve(depth + 1, up(board));
	solve(depth + 1, down(board));
	solve(depth + 1, left(board));
	solve(depth + 1, right(board));
}

int main() {
	int cnt = 0;
	cin >> n;

	board.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) cnt++;
		}

	solve(0, board);

	cout << res;
	return 0;
}