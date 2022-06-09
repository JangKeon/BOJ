#include <iostream>
using namespace std;

int main(void) {
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cout << '=';
		}
		cout << '\n';
	}
}