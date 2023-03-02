#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;


bool cmp(const pair<string, int> a, const pair<string, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main(void) {
	map <string, int> m;
	int N;
	string a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		m.insert({ a, a.length() });
	}

	vector <pair<string, int>> vec(m.begin(), m.end());
	sort(vec.begin(), vec.end(), cmp);
	for (auto iter = vec.begin(); iter != vec.end(); iter++) {
		cout << iter->first << '\n';
	}
}