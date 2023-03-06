#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	map <string, int> m;
	vector <string> vec;
	int N, M;
	string name;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> name;
		m.insert({ name, 1 });
	}
	for (int i = 0; i < M; i++) {
		cin >> name;
		if (m[name] == 1) {
			vec.push_back(name);
		}
	}
	sort(vec.begin(), vec.end());
	cout << vec.size() << '\n';
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << '\n';
	}
}