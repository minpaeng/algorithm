#include <iostream>
#include <string>
using namespace std;

#define MAX 2000000
int q[MAX];

int front = 0;
int rear = -1;
int num = 0;
void push(int item);
int pop();
int size();
int empty();
int get_front();
int get_back();

int size() {
	return num;
}

int empty() {
	if (num) return 0;
	else return 1;
}

void push(int item) {
	if (rear > MAX - 1) return;
	q[++rear] = item;
	num++;
}

int pop() {
	if (num == 0) {
		return -1;
	}
	num--;
	return q[front++];
}

int get_front() {
	if (num == 0) {
		return -1;
	}
	return q[front];
}

int get_back() {
	if (num == 0) {
		return -1;
	}
	return q[rear];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s.compare("pop") == 0) {
			cout << pop() << '\n';
		}
		else if (s.compare("front") == 0) {
			cout << get_front() << '\n';
		}
		else if (s.compare("back") == 0) {
			cout << get_back() << '\n';
		}
		else if (s.compare("empty") == 0) {
			cout << empty() << '\n';
		}
		else if (s.compare("size") == 0) {
			cout << size() << '\n';
		}
		else if (s.compare("push") == 0) {
			int num;
			cin >> num;
			push(num);
		}
	}

	return 0;
}