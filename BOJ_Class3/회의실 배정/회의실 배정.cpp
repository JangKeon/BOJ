#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> vec1, pair<int, int> vec2) {
	if (vec1.second == vec2.second) {
		return vec1.first < vec2.first;
	}
	else return vec1.second < vec2.second;
}

int main(void) {
	vector <pair<int, int>> vec;
	int N, start, finish;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> finish;
		vec.push_back(make_pair(start, finish));
	}
	sort(vec.begin(), vec.end(), compare);
	int F_time = vec[0].second , result = 1;
	for (int i = 1; i < N; i++) {
		if (vec[i].first < F_time) {
			continue; 
		}
		F_time = vec[i].second;
		result++;
	}
	cout << result;
}