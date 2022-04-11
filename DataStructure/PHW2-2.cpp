#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
	int level;
	int key;
	int child_num;
	struct Node* next;
	struct Node* child;
};

Node* newNode(int lev, int data, int num) {
	Node* newNode = new Node;
	newNode->next = newNode->child = NULL;
	newNode->key = data;
	newNode->level = lev;
	newNode->child_num = num;
	return newNode;
}

Node* addSibling(Node* n,int lev, int data, int num) {
	if (n == NULL) {
		return NULL;
	}

	while (n->next) {
		n = n->next;
	}

	return (n->next = newNode(lev, data, num));
}

Node* addChild(Node* n, int lev, int data, int num)
{
	if (n == NULL) {
		return NULL;
	}

	if (n->child) {
		return addSibling(n->child, lev, data, num);
	}
	else
		return (n->child = newNode(lev, data, num));
}

void preOrder(Node* root)
{
	if (root == NULL) {
		return;
	}

	while (root)
	{
		printf("(%d, %d, %d)\n", root->level, root->key, root->child_num);
		if (root->child) {
			preOrder(root->child);
		}
		root = root->next;
	}
}

int main(void) {
	
	Node* root = newNode(1, 100, 200);
	Node* n1 = addChild(root, 2, 200, 0);
	Node* n2 = addSibling(n1, 2, 75, 25);
	Node* n3 = addChild(n2, 3, 25, 0);
	Node* n4 = addSibling(n2, 2, 300, 0);
	Node* n5 = addSibling(n4, 2, 95, 150);
	Node* n6 = addChild(n5, 3, 150, 0);
	Node* n7 = addSibling(n3, 3, 50, 0);
	Node* n8 = addSibling(n7, 3, 30, 120);
	Node* n9 = addChild(n8, 4, 120, 0);
	printf("Preorder for Tree 2.\n");
	preOrder(root);
}