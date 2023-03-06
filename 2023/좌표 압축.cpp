#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	int N, num;
	vector <int> origin;
	vector <int> sorting;
	map <int, int> m;
	cin >> N; 
	for (int i = 0; i < N; i++) {
		cin >> num;
		origin.push_back(num);
		sorting.push_back(num);
	}
	sort(sorting.begin(), sorting.end());
	unique(sorting.begin(), sorting.end());
	for (int i = 0; i < sorting.size(); i++) {
		m.insert({ sorting[i], i });
	}
	for (int i = 0; i < origin.size(); i++) {
		cout << m[origin[i]] << ' ';
	}
}