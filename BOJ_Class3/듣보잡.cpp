#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning(disable:4996)

struct compare {
	bool operator()(string a, string b) {
		return a > b;
	}
};

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M;
	string name;
	vector <string> Names;
	vector <string> Result;
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		cin >> name;
		Names.push_back(name);
	}
	sort(Names.begin(), Names.end());
	for (int i = 1; i < Names.size(); i++) {
		if (Names[i] == Names[i - 1]) {
			Result.push_back(Names[i]);
		}
	}

	cout << Result.size() << '\n';
	for (int i = 0; i < Result.size(); i++) {
		cout << Result[i] << '\n'; 
	}
}