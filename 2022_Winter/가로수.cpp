#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

int road[100001];

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main(void) {
	int N, num, dist, answer = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> road[i];
	}
	dist = abs(road[1] - road[2]);
	for (int i = 2; i < N; i++) {
		dist = gcd(dist, abs(road[i] - road[i + 1]));
	}
	sort(road + 1, road + N);
	for (int i = 1; i <= N - 1; i++) {
		answer += ( abs(road[i + 1] - road[i]) / dist) - 1;
	}
	cout << answer << '\n';
}