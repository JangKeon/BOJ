#include <iostream>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

struct node {
	int left, right;
}Node[26];

void preorder(int cur) {
	cout << (char)(cur + 'A');
	if (Node[cur].left != -1) {
		preorder(Node[cur].left);
	}
	if (Node[cur].right != -1) {
		preorder(Node[cur].right);
	}
}

void inorder(int cur) {
	if (Node[cur].left != -1) {
		inorder(Node[cur].left);
	}
	cout << (char)(cur + 'A');
	if (Node[cur].right != -1) {
		inorder(Node[cur].right);
	}
}

void postorder(int cur) {
	if (Node[cur].left != -1) {
		postorder(Node[cur].left);
	}
	if (Node[cur].right != -1) {
		postorder(Node[cur].right);
	}
	cout << (char)(cur + 'A');
}

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		Node[i].left = -1;
		Node[i].right = -1;
	}

	for (int i = 0; i < N; i++) {
		char cur, l, r;
		cin >> cur >> l >> r;
		if (l != '.') {
			Node[cur - 'A'].left = l - 'A';
		}
		if (r != '.') {
			Node[cur - 'A'].right = r - 'A';
		}
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
}