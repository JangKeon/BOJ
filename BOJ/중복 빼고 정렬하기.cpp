#include <iostream>
using namespace std;

int Arr[2002];

int main(void) {
	int N, num;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		Arr[num+1000] = 1;
	}
	for (int i = 0; i <= 2000; i++) {
		if (Arr[i] == 1) {
			cout << i - 1000 << ' ';
		}
	}
}