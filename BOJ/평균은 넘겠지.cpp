#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int C;
	cin >> C;
	for (int a = 0; a < C; a++) {
		vector <int> vec;
		int N, score, res = 0;
		double avg = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> score;
			vec.push_back(score);
		}
		for (int i = 0; i < vec.size(); i++) {
			avg += vec[i];
		}
		avg /= vec.size();
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] > avg) {
				res++;
			}
		}
		printf("%.3lf%\n", (double)res * 100 / vec.size());
	}
}