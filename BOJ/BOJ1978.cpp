#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int main() {
	int N, num;
	vector <int> vec;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		vec.push_back(num);
	}
	int count = 0, result = 0;
	for (int i = 0; i < vec.size(); i++) {
		count = 0;
		for (int j = 1; j <= vec[i]; j++) {
			if (vec[i] % j == 0) {
				count++;
			}
			if (count > 2) {
				break;
			}
		}
		if (count == 2) {
			result++;
		}
	}
	printf("%d", result);
}