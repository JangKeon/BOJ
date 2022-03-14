#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable:4996)

int front_num = -1;
int rear_num = -1;

void push(int* arr, int num) {
	if (front_num == -1) {	// 정수가 없을 때
		front_num++;
		rear_num++;
	}
	else {	// 정수가 있을 때
		rear_num++;
	}
	arr[rear_num] = num;
}

void pop(int* arr) {
	if (front_num == -1) {	// 정수가 아예 없을 때
		printf("-1\n");
	}
	else if (front_num == rear_num) {	// 정수가 하나 있을 때
		printf("%d\n", arr[front_num]);
		front_num = -1;
		rear_num = -1;
	}
	else {	// 정수가 여러 개 있을 때
		printf("%d\n", arr[front_num]);
		front_num++;
	}
}

void size() {
	if (front_num == -1) {
		printf("0\n");
	}
	else {
		printf("%d\n", rear_num - front_num + 1);
	}
}

void empty() {
	if (front_num == -1) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
}

void front(int* arr) {
	if (front_num == -1) {
		printf("-1\n");
	}
	else printf("%d\n", arr[front_num]);
}

void back(int* arr) {
	if (front_num == -1) {
		printf("-1\n");
	}
	else printf("%d\n", arr[rear_num]);
}

int main() {
	int Queue[10000] = { 0, };
	int N, num;
	string func;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> func;
		if (func == "push") {
			cin >> num;
			push(Queue, num);
		}
		else if (func == "pop") {
			pop(Queue);
		}
		else if (func == "size") {
			size();
		}
		else if (func == "empty") {
			empty();
		}
		else if (func == "front") {
			front(Queue);
		}
		else if (func == "back") {
			back(Queue);
		}
	}

	return 0;
}