#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Fight {
	int health;
	int people;
};

bool compare(Fight a, Fight b){
	if (a.health <= b.health) {
		if (a.people <= b.people) {
			return false;
		}
		else return true;
	}
	else return false;
}

int N, K;

int main(void) {
	vector <Fight> vec;
	vector <int> heal;
	vector <int> peop;
	cin >> N >> K;
	int h, p;
	for (int i = 0; i < N; i++) {
		cin >> h;
		heal.push_back(h);
	}
	for (int i = 0; i < N; i++) {
		cin >> p;
		peop.push_back(p);
	}
	for (int i = 0; i < N; i++) {
		vec.push_back({ heal[i], peop[i] });
	}
	sort(vec.begin(), vec.end(), compare);
	int result = 0, index = 0;
	while (K > 0) {
		K -= vec[index].health;
		if (K < 1) {
			break;
		}
		result += vec[index].people;
		index++;
	}
	if (result == 0) {
		cout << '0' << '\n';
	}
	else cout << result << '\n';
}