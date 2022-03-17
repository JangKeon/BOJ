#include <iostream>
#include <stdlib.h>
#define Max_Size 10
using namespace std;

int n_node = 0;

struct node {
	int data;
	struct node* link;
};

struct node* front;
struct node* rear;

void enqueue(int x) {
	struct node* temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->link = NULL;
	if (front == NULL && rear == NULL) {
		front = temp;
		rear = temp;
		n_node++;
		return;
	}
	rear->link = temp;
	rear = temp;
	n_node++;
}

int dequeue() {
	int value;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if (front == NULL && rear == NULL) {
		n_node = 0;
		return 0;
	}
	temp = front;
	front = front->link;
	value = temp->data;
	free(temp);
	n_node--;
	return value;
}

int queue_full() {
	if (n_node == Max_Size) {
		return 1;
	}
	else return 0;
}

int queue_empty() {
	if (n_node == 0) {
		return 1;
	}
	return 0;
}

void print_queue() {
	struct node* temp = front;
	printf("Current Queue : ");
	while (temp != NULL) {
		if (temp == rear) {
			printf("%d \n", temp->data);
		}
		else {
			printf("%d -> ", temp->data);
		}
		temp = temp->link;
	}
	printf("\n");
}

void run_enqueue(int arr[], int num) {
	for (int i = 0; i < num; i++) {
		if (queue_full()) {
			printf("Queue is full.\n");
		}
		else {
			enqueue(arr[i]);
		}
	}
	print_queue();
}

void run_dequeue(int arr[], int num) {
	for (int i = 0; i < num; i++) {
		if (queue_empty()) {
			printf("Queue is empty.\n");
		}
		else {
			dequeue();
		}
	}
	print_queue();
}

int main(void) {
	int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	run_enqueue(numbers, 5);
	run_dequeue(numbers, 2);
	run_enqueue(numbers, 3);
	run_dequeue(numbers, 4);
}