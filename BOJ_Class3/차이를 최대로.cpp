#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N, num;
	cin >> N;
	vector <int> vec;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end(), greater<>());
	cout << "Vec 1 : \n";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << ' ';
	}
	cout << '\n'; 
	vector <int> vec2;
	if (N % 2 == 0) {
		for (int i = 0; i < vec.size() / 2; i++) {
			vec2.push_back(vec[N - 1 - i]);
			vec2.push_back(vec[i]);
		}
	}
	else {
		for (int i = 0; i < vec.size() / 2; i++) {
			vec2.push_back(vec[N - 1 - i]);
			vec2.push_back(vec[i]);
		}
		vec2.push_back(vec[N / 2]);
	}
	cout << "Vec 2 : \n";
	for (int i = 0; i < vec2.size(); i++) {
		cout << vec2[i] << ' ';
	}
	int result = 0;
	for (int i = 0; i < N - 1; i++) {
		result += abs(vec2[i] - vec2[i + 1]);
	}
	cout << result;
}