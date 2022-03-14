#include <iostream>
using namespace std;
#pragma warning(disable:4996)
#define Max_Size 10

int Queue[Max_Size];
int front_num = -1;
int rear_num = -1;

void enqueue(int num) {
	if (front_num == -1) {	// 정수가 없을 때
		front_num++;
		rear_num++;
	}
	else {	// 정수가 있을 때
		rear_num++;
	}
	Queue[rear_num] = num;
}

int dequeue() {
	int temp;
	if (front_num == -1) {	// 정수가 아예 없을 때
		return 0;
	}
	else if (front_num == rear_num) {	// 정수가 하나 있을 때
		temp = Queue[front_num];
		front_num = -1;
		rear_num = -1;
		return temp;
	}
	else {	// 정수가 여러 개 있을 때
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
		cin >> func; // 각 기능 별로 enqueue, dequeue, empty, full, print, out 의 형태로 입력 후 사용
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