#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int main() {
	vector <int> vec;
	int N, num, M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		if (binary_search(vec.begin(), vec.end(), num)) {
			
		}
	}
}