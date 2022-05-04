#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(void) {
	vector <pair<int, int>> quiz;
	vector <int> index;
	int num;
	for (int i = 1; i <= 8; i++) {
		cin >> num;
		quiz.push_back(make_pair(num, i));
	}
	sort(quiz.begin(), quiz.end(), greater<>());
	int max = 0;
	for (int i = 0; i < 5; i++) {
		max += quiz[i].first;
		index.push_back(quiz[i].second);
	}
	cout << max << '\n';
	sort(index.begin(), index.end());
	for (int i = 0; i < 5; i++) {
		cout << index[i] << ' ';
	}
}