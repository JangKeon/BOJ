#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable:4996)

int top_num = -1;

void push(int* arr, int num) {
	top_num++;
	arr[top_num] = num;
}

void pop(int* arr) {
	if (top_num == -1) {
		printf("-1\n");
	}
	else {
		printf("%d\n", arr[top_num]);
		if (top_num < -1) {
			top_num = -1;
		}
		else {
			top_num--;
		}
	}
}

void size() {
	printf("%d\n", top_num + 1);
}

void empty() {
	if (top_num == -1) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
}

void top(int* arr) {
	if (top_num == -1) {
		printf("-1\n");
	}
	else {
		printf("%d\n", arr[top_num]);
	}
}

int main() {
	int Stack[10000] = {0, };
	int N, num;
	string func;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> func;
		if (func == "push") {
			cin >> num;
			push(Stack, num);
		}
		else if (func == "pop") {
			pop(Stack);
		}
		else if (func == "top") {
			top(Stack);
		}
		else if (func == "size") {
			size();
		}
		else if (func == "empty") {
			empty();
		}
	}

	return 0;
}