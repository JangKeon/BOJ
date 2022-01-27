#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

vector <int> vec;

void add(int num) {
	auto it = find(vec.begin(), vec.end(), num);
	if (it == vec.end()) {
		vec.push_back(num);
	}
}

void remove(int num) {
	auto it = find(vec.begin(), vec.end(), num);
	int index = distance(vec.begin(), it);
	if (it != vec.end()) {
		vec.erase(vec.begin() + index);
	}
}

void check(int num)
{
	auto it = find(vec.begin(), vec.end(), num);
	if (it != vec.end()) {
		printf("1\n");
	}
	else printf("0\n");
}

void toggle(int num) {
	auto it = find(vec.begin(), vec.end(), num);
	int index = distance(vec.begin(), it);
	if (it != vec.end()) {
		vec.erase(vec.begin() + index);
	}
	else {
		vec.push_back(num);
	}
}

void all() {
	vec.clear();
	for (int i = 1; i <= 20; i++) {
		vec.push_back(i);
	}
}

void empty() {
	vec.clear();
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, num;
	string func;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> func;
		if (func == "add") {
			cin >> num;
			add(num);
		}
		else if (func == "remove") {
			cin >> num;
			remove(num);
		}
		else if (func == "check") {
			cin >> num;
			check(num);
		}
		else if (func == "toggle") {
			cin >> num;
			toggle(num);
		}
		else if (func == "all") {
			all();
		}
		else if (func == "empty") {
			empty(); 
		}
	}
	
}

