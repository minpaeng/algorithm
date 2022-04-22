#include <iostream>
#include <string>
using namespace std;

typedef struct Node* node;

struct Node {
	node left = NULL;
	node right = NULL;
	int data;
};

class deque {
private:
	node front = NULL;
	node rear = NULL;
	int n = 0;
public:
	void push_front(int x) {
		if (n == 0) {
			front = rear = new Node;
		}
		else {
			node tmp = new Node;
			tmp->right = front;
			front->left = tmp;
			front = tmp;
		}
		front->data = x;
		n++;
	}

	void push_back(int x) {
		if (n == 0) {
			front = rear = new Node;
		}
		else {
			node tmp = new Node;
			tmp->left = rear;
			rear->right = tmp;
			rear = tmp;
		}
		rear->data = x;
		n++;
	}

	int pop_front() {
		if (front == NULL) return -1;
		int x;
		x = front->data;
		node tmp = front;
		front = front->right;
		delete tmp;
		if (front != NULL) front->left = NULL;
		else rear = NULL;
		n--;
		return x;
	}
	int pop_back() {
		if (rear == NULL) return -1;
		int x;
		x = rear->data;
		node tmp = rear;
		rear = rear->left;
		delete tmp;
		if (rear != NULL) rear->right = NULL;
		else front = NULL;
		n--;
		return x;
	}

	int size() {
		return n;
	}

	int empty() {
		if (n) return 0;
		else return 1;
	}

	int get_front() {
		if (n == 0) return -1;
		return front->data;
	}

	int get_back() {
		if (n == 0) return -1;
		return rear->data;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	deque d = deque();

	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s == "push_front") {
			int x;
			cin >> x;
			d.push_front(x);
		}
		else if (s == "push_back") {
			int x;
			cin >> x;
			d.push_back(x);
		}
		else if (s == "pop_front") {
			cout << d.pop_front() << '\n';
		}
		else if (s == "pop_back") {
			cout << d.pop_back() << '\n';
		}
		else if (s == "size") {
			cout << d.size() << '\n';
		}
		else if (s == "empty") {
			cout << d.empty() << '\n';
		}
		else if (s == "front") {
			cout << d.get_front() << '\n';
		}
		else if (s == "back") {
			cout << d.get_back() << '\n';
		}
	}

	return 0;
}