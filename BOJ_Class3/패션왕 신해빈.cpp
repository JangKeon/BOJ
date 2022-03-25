#include <iostream>
#include <unordered_map>
using namespace std;

int main(void) {
	int T, number;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> number;
		unordered_map <string, int> map;
		string name, type;
		for (int j = 0; j < number; j++) {
			cin >> name >> type;
			map[type] ++;
		}
		int res = 1;
		for (auto p = map.begin(); p != map.end(); p++) {
			res *= (p->second + 1);
		}
		cout << res - 1 << '\n';
	}
}