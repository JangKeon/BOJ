#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(void) {
	int N, student, B, C;
	long long int count = 0;
	float num;
	vector <int> vec;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> student;
		vec.push_back(student);
	}
	cin >> B >> C;
	for (int i = 0; i < N; i++) {
		if (vec[i] - B >= 0) {
			vec[i] = vec[i] - B;
		}
		else vec[i] = 0;
		if (vec[i] % C == 0) { count = count + (vec[i] / C); }
		else { count = count + (vec[i] / C) + 1; }
	}
	count += N;
	cout << count;
}