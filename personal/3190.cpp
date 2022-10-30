#include <iostream>
#include <vector>
#include <map>
#include <deque>
using namespace std;

map<char, char> l_dir = { {'r', 'u'}, {'u', 'l' }, {'l', 'd'}, {'d', 'r'} };
map<char, char> r_dir = { {'r', 'd'}, {'d', 'l'}, {'l', 'u'}, {'u', 'r'} };

deque<pair<int, int>> snake(1, {1, 1});
char head = 'r';
int res, n, k, l;

bool move(vector<vector<int>>& v, int second, char direction) {
	if (head == 'r') {
		while (second--) {
			res++;
			int nx = snake.front().first;
			int ny = snake.front().second + 1;
			if (ny > n) return false;
			snake.push_front({ nx, ny });
			if (v[nx][ny] == 1) return false;
			else if (v[nx][ny] == 0) {
				v[snake.back().first][snake.back().second] = 0;
				snake.pop_back();
			}
			v[nx][ny] = 1;
		}
	}
	else if (head == 'l') {
		while (second--) {
			res++;
			int nx = snake.front().first;
			int ny = snake.front().second - 1;
			if (ny <= 0) return false;
			snake.push_front({ nx, ny });
			if (v[nx][ny] == 1) return false;
			if (v[nx][ny] == 0) {
				v[snake.back().first][snake.back().second] = 0;
				snake.pop_back();
			}
			v[nx][ny] = 1;
		}
	}
	else if (head == 'u') {
		while (second--) {
			res++;
			int nx = snake.front().first - 1;
			int ny = snake.front().second;
			if (nx <= 0) return false;
			snake.push_front({ nx, ny });
			if (v[nx][ny] == 1) return false;
			if (v[nx][ny] == 0) {
				v[snake.back().first][snake.back().second] = 0;
				snake.pop_back();
			}
			v[nx][ny] = 1;
		}
	}
	else if (head == 'd') {
		while (second--) {
			res++;
			int nx = snake.front().first + 1;
			int ny = snake.front().second;
			if (nx > n) return false;
			snake.push_front({ nx, ny });
			if (v[nx][ny] == 1) return false;
			if (v[nx][ny] == 0) {
				v[snake.back().first][snake.back().second] = 0;
				snake.pop_back();
			}
			v[nx][ny] = 1;
		}
	}

	if (direction == 'L') head = l_dir[head];
	else head = r_dir[head];

	return true;
}

int main() {
	cin >> n >> k;

	vector<vector<int>> v(n + 2, vector<int>(n + 2, 0));

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		v[a][b] = 2;
	}
	v[1][1] = 1;

	cin >> l;
	vector<pair<int, char>> directions;
	int tmp;
	for (int i = 0; i < l; i++) {
		int a;
		char b;
		cin >> a >> b;
		if (i == 0) tmp = a;
		else {
			int tmp2 = a;
			a -= tmp;
			tmp = tmp2;
		}
		directions.push_back({ a, b });
	}

	bool flag = true;
	for (int i = 0; i < l; i++) {
		int second = directions[i].first;
		char direction = directions[i].second;
		if (!move(v, second, direction)) {
			flag = false;
			break;
		}
	}

	if(flag) move(v, n, directions[l - 1].second);
	cout << res;

	return 0;
}