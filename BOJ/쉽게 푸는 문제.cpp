#include <iostream>
using namespace std;

int arr[1500];

int main(void) {
	int index = 1;
	for (int i = 1; i < 46; i++) {
		for (int j = 0; j < i; j++) {
			arr[index] = i;
			index++;
		}
	}

	int A, B, result = 0;
	cin >> A >> B;
	for (int i = A; i <= B; i++) {
		result += arr[i];
	}
	cout << result;
}