#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct member {
	int age;
	string name;
	int index;
};

bool cmp(member a, member b) {
	if (a.age == b.age) {
		return a.index < b.index;
	}
	else return a.age < b.age;
}

int main(void) {
	int N, age;
	string name;
	cin >> N;
	vector <member> vec;
	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		vec.push_back({ age, name, i });
	}
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < N; i++) {
		cout << vec[i].age << ' ' << vec[i].name << '\n';
	}
}