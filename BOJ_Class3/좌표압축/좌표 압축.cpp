#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	unordered_map <int, int> points;
	vector <int> vec, vec2;
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
		vec2.push_back(num);
	}
	sort(vec2.begin(), vec2.end());
	unique(vec2.begin(), vec2.end());
	for (int i = 0; i < N; i++) {
		points.insert(make_pair(vec2[i], i));
	}

	for (int i = 0; i < N; i++) {
		cout << points.find(vec[i])->second << ' ';
	}
}