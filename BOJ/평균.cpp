#include <iostream>
using namespace std;

int main(void) {
	int N, num, max = - 999, sum = 0;
	double avg = 0;
	cin >> N; 
	for (int i = 0; i < N; i++) {
		cin >> num;
		avg += num;
		if (max < num) {
			max = num;
		}
	}
	avg /= N;
	printf("%.7lf", avg / max * 100);
}