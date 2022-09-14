#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	int newN = 99999999, cycle = 0, first, second, plus;
	while (newN != N) {
		if (cycle == 0) {
			first = N / 10;
			second = N % 10;
			plus = first + second;
			newN = N % 10 * 10 + plus % 10;
		}
		else {
			first = newN / 10;
			second = newN % 10;
			plus = first + second;
			newN = newN % 10 * 10 + plus % 10;
		}
		cycle++;
	}
	cout << cycle;
}