#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	int difficult, min = 99999;
	string problem, result;

	for (int i = 0; i < N; i++) {
		cin >> problem >> difficult;
		if (min > difficult) {
			min = difficult;
			result = problem;
		}
	}
	cout << result;
}