#include <iostream>
using namespace std;

int arr[201];

int main(void) {
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[num + 100]++;
	}
	cin >> num;
	cout << arr[num + 100];
}