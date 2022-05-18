#include <iostream>
#include <vector>
using namespace std;

vector <pair <int, int>> vec; 

int main(void) {
	int T;
	cin >> T;
	for (int a = 0; a < T; a++) {
		int N;
		cin >> N;
		for (int i = 1; i <= N / 2; i++) {
			if (i != N - i) {
				vec.push_back({ i, N - i });
			}
		}
		cout << "Pairs for " << N << ": ";
		for (int i = 0; i < vec.size(); i++) {
			if (i == vec.size() - 1) {
				cout << vec[i].first << ' ' << vec[i].second;
			}
			else {
				cout << vec[i].first << ' ' << vec[i].second << ", ";
			}		}
		cout << '\n';
		vec.clear();
	}
}