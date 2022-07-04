#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

stack <int> stk;
queue <string> que;

void POP() {
	stk.pop();
}

void INV() {
	int num = stk.top();
	stk.pop();
	stk.push(-(num));
}

void DUP() {
	int num = stk.top();
	stk.push(num);
}

void SWP() {
	int first = stk.top();
	stk.pop();
	int second = stk.top();
	stk.pop();
	stk.push(second);
	stk.push(first);
}

void ADD() {
	int first = stk.top();
	stk.pop();
	int second = stk.top();
	stk.pop();
	stk.push(first + second);
}

void SUB() {
	int first = stk.top();
	stk.pop();
	int second = stk.top();
	stk.pop();
	stk.push(second - first);
}

void MUL() {
	int first = stk.top();
	stk.pop();
	int second = stk.top();
	stk.pop();
	stk.push(first * second);
}

void DIV() {
	int first = stk.top();
	stk.pop();
	int second = stk.top();
	stk.pop();
	stk.push(second / first);
}

void MOD() {
	int first = stk.top();
	stk.pop();
	int second = stk.top();
	stk.pop();
	stk.push(second % first);
}

int main(void) {
	int N, num;
	string func;
	while (1) {
		cin >> func;
		if (func == "QUIT") {
			break;
		}
		else if (func == "NUM") {
			cin >> num;
			que.push("NUM");
		}
		else if (func == "POP") {
			que.push("NUM");
		}
		else if (func == "INV") {
			que.push("NUM");
		}
		else if (func == "DUP") {
			que.push("NUM");
		}
		else if (func == "SWP") {
			que.push("NUM");
		}
		else if (func == "ADD") {
			que.push("NUM");
		}
		else if (func == "SUB") {
			que.push("NUM");
		}
		else if (func == "MUL") {
			que.push("NUM");
		}
		else if (func == "DIV") {
			que.push("NUM");
		}
		else if (func == "MOD") {
			que.push("NUM");
		}
		else {
			N = stoi(func);
			for (int i = 0; i < N; i++) {
				while (!que.empty()) {

				}
			}
		}
	}
	
}