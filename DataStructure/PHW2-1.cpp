#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
	int data;
	struct node* link;
};

struct node* head = NULL;

void push(int x) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->link = head;
	head = temp;
}

void pop() {
	int val;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp = head;
	val = temp->data;
	head = head->link;
	free(temp);
}

int main(void) {
	int number;
	printf("Enter the number you want to convert.\n");
	scanf_s("%d", &number);
	while (number > 0) {
		if (number % 2 == 0) {
			push(0);
			number /= 2;
		}
		else {
			push(1);
			number /= 2;
		}
	}
	printf("Converted Binary number : ");
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->link;
	}
}