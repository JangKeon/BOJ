#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable:4996)

int front_num = -1;
int rear_num = -1;

int size() {
	int n;
	if ((front_num == -1 && rear_num == -1) || front_num > rear_num) {
		n = 0;
	}
	else {
		n = rear_num - front_num + 1;
	}
	return n;
}

void print_size() {
	if (front_num == -1 || rear_num == -1 || front_num > rear_num) {
		printf("0\n");
	}
	else {
		printf("%d\n", rear_num - front_num + 1);
	}
}

void push(int *arr, int num) {
	if (size() == 0) {
		front_num = 0;
		rear_num = 0;
		arr[rear_num] = num;
	}
	else {
		rear_num++;
		arr[rear_num] = num;
	}
}

void pop(int* arr) {
	if (size() == 0) {
		front_num = -1;
		rear_num = -1;
		printf("-1\n");
	}
	else {
		printf("%d\n", arr[front_num]);
		front_num++;
	}
}

void empty() {
	if (size() == 0) {
		printf("1\n");
	}
	else printf("0\n");
}

void front(int *arr) {
	if (size() == 0) {
		printf("-1\n");
	}
	else printf("%d\n", arr[front_num]);
}

void back(int *arr) {
	if (size() == 0) {
		printf("1\n");
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
			print_size();
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