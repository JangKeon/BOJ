#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> vec1, pair<int, int> vec2) {
	if (vec1.second == vec2.second) {
		return vec1.first > vec2.first;
	}
	else return vec1.second < vec2.second;
}

int dp[100][100000];

int main(void) {
	int N, K, W, V;
	vector <pair<int, int>> vec;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> W >> V;
		vec.push_back(make_pair(W, V));
	}
	sort(vec.begin(), vec.end(), compare);

	cout << vec[1].first << " " << vec[1].second << '\n';
}