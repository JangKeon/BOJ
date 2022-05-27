#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student {
	string name;
	int dd;
	int mm;
	int yy;
};


bool compare(student a, student b) {
	
	if (a.yy == b.yy && a.mm == b.mm && a.dd < b.dd) {
		return true;
	}
	else if (a.yy == b.yy && a.mm < b.mm) {
		return true;
	}
	else if (a.yy < b.yy) {
		return true;
	}
	else return false;
	
};

int main(void) {
	int n;
	vector <student> vec;
	string na;
	int d, m, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> na >> d >> m >> y;
		vec.push_back({ na, d, m, y });
	}
	sort(vec.begin(), vec.end(), compare);

	cout << vec[n - 1].name << '\n' << vec[0].name << '\n';
}