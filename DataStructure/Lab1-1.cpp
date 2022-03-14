#include <iostream>
#pragma warning(disable:4996)
#define Max_Size 10
using namespace std;

int Stack[Max_Size];
int top_num = -1;

void print_stack() {
	for (int i = 0; i <= top_num; i++) {
		printf("%d ", Stack[i]);
	}
	printf("\n");
}

int stack_full() {
	if (top_num == 9) {
		return 1;
	}
	else return 0;
}

int stack_empty() {
	if (top_num == -1) {
		return 1;
	}
	else return 0;
}

void push(int num) {
	if (!stack_full()) {
		top_num++;
		Stack[top_num] = num;
	}
}

int pop() {
	if (stack_empty()) {
		return 0;
	}
	else {
		int n = Stack[top_num];
		if (top_num < -1) {
			top_num = -1;
		}
		else {
			top_num--;
		}
		return n;
	}
}


int main(void) {
	int num;
	string func;
	while(1){		// 각 기능 별로 push, pop, empty, full, print, out 의 형태로 입력 후 사용.
		cin >> func;
		if (func == "push") {
			scanf("%d", &num);
			push(num);
		}
		else if (func == "pop") {
			printf("%d\n", pop());
		}
		else if (func == "full") {
			if (stack_full()) {
				printf("Stack is full.\n");
			}
			else printf("Stack is not full.\n");
		}
		else if (func == "empty") {
			if (stack_empty()) {
				printf("Stack is empty.\n");
			}
			else printf("Stack is not empty.\n");
		}
		else if (func == "print") {
			print_stack();
		}
		else if (func == "out") {
			break;
		}
	}
}