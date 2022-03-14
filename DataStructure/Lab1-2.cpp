#include <iostream>
using namespace std;
#pragma warning(disable:4996)
#define Max_Size 10

int Queue[Max_Size];
int front_num = -1;
int rear_num = -1;

void enqueue(int num) {
	if (front_num == -1) {	// ������ ���� ��
		front_num++;
		rear_num++;
	}
	else {	// ������ ���� ��
		rear_num++;
	}
	Queue[rear_num] = num;
}

int dequeue() {
	int temp;
	if (front_num == -1) {	// ������ �ƿ� ���� ��
		return 0;
	}
	else if (front_num == rear_num) {	// ������ �ϳ� ���� ��
		temp = Queue[front_num];
		front_num = -1;
		rear_num = -1;
		return temp;
	}
	else {	// ������ ���� �� ���� ��
		temp = Queue[front_num];
		front_num++;
		return temp;
	}
}

int queue_empty() {
	if (front_num == -1) {
		return 1;
	}
	else return 0;
}

int queue_full() {
	if (rear_num == 9) {
		return 1;
	}
	else return 0;
}

void print_queue() {
	for (int i = front_num; i <= rear_num; i++) {
		printf("%d ", Queue[i]);
	}
	printf("\n");
}

int main() {
	string func;
	int num;
	while (1) {
		cin >> func; // �� ��� ���� enqueue, dequeue, empty, full, print, out �� ���·� �Է� �� ���
		if (func == "enqueue") {
			scanf("%d", &num);
			enqueue(num);
		}
		else if (func == "dequeue") {
			printf("%d\n", dequeue());
		}
		else if (func == "empty") {
			if (queue_empty()) {
				printf("Queue is empty.\n");
			}
			else printf("Queue is not empty.\n");
		}
		else if (func == "full") {
			if (queue_full()) {
				printf("Queue is full.\n");
			}
			else printf("Queue is not full.\n");
		}
		else if (func == "print") {
			print_queue();
		}
		else if (func == "out") {
			break;
		}
	}

	return 0;
}