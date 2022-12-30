#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N, num;
	vector <int> vec;
	int answer = 99999999;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
 // 정렬되어 있으니까 두 번째 부터 i 개로 나누었을 때와 최댓값을 비교한 거를 저장해놓는다.
 // 이후부터는 저장된 전 값이랑만 비교하면 되니까? DP 형식으로 풀어보자.
}