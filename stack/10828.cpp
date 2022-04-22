#include <iostream>
#include <string>
using namespace std;

class stack {
private:
	int st[10001];
	int top = -1;
public:
	void push(int item);
	int pop();
	int size();
	int empty();
	int get_top();
};

int stack::size() {
	return top + 1;
}

int stack::empty() {
	if (top == -1) return 1;
	else return 0;
}

void stack::push(int item) {
	st[++top] = item;
}

int stack::pop() {
	if (top == -1) {
		return -1;
	}
	return st[top--];
}

int stack::get_top() {
	if (top == -1) {
		return -1;
	}
	return st[top];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack st = stack();

	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s.compare("pop") == 0) {
			cout << st.pop() << '\n';
		}
		else if (s.compare("top") == 0) {
			cout << st.get_top() << '\n';
		}
		else if (s.compare("empty") == 0) {
			cout << st.empty() << '\n';
		}
		else if (s.compare("size") == 0) {
			cout << st.size() << '\n';
		}
		else if (s.compare("push") == 0) {
			int num;
			cin >> num;
			st.push(num);
		}
	}

	return 0;
}