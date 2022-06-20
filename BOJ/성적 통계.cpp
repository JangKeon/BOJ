#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	for (int u = 0; u < T; u++) {
		int num, score;
		vector <int> student;
		cin >> num;
		for (int i = 0; i < num; i++) {
			cin >> score;
			student.push_back(score);
		}
		sort(student.begin(), student.end(), greater<>());
		int gap = 0;
		for (int i = 1; i < student.size(); i++) {
			if (student[i - 1] - student[i] > gap) {
				gap = student[i - 1] - student[i];
			}
		}
		cout << "Class " << u + 1 << '\n';
		cout << "Max " << student[0] << ", Min " << student[num - 1] << ", Largest gap " << gap << '\n';
	}
}