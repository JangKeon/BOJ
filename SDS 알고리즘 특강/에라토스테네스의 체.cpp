#include <iostream>
#include <vector>
using namespace std;

int arr[1001];
vector <int> vec;

int main(void) {
	int N, K;
	cin >> N >> K;
	for (int i = 2; i <= N; i++) {
		arr[i] = i;
	}
	for (int i = 2; i <= N; i++) {
		if (arr[i] == 0) {
			continue;
		}
		for (int j = i; j <= N; j+=i) {
			if (arr[j]) {
				arr[j] = 0;
				K--;
				if (K == 0) {
					cout << j << '\n';
					break;
				}
			}
		}
		
	}

}