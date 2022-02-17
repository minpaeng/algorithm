#include <iostream>
#include <vector>
using namespace std;
#define MAX 10001

typedef struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int v): data(v), left(NULL), right(NULL) {}
} Node;

Node* insert(Node* node, int v) {
	if (node == NULL) {
		node = new Node(v);
	}
	else if (node->data >= v) {
		node->left = insert(node->left, v);
	}
	else {
		node->right = insert(node->right, v);
	}
	return node;
}

void post(Node* node) {
	if (node == NULL) return;
	post(node->left);
	post(node->right);
	cout << node->data << '\n';
}

int main() {
	int n;

	Node* root = NULL;

	while (cin >> n) {
		if (n == EOF) break;
		root = insert(root, n);
	}

	post(root);
	
	return 0;
}