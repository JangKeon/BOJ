#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N, new_score, P;
	cin >> N >> new_score >> P;
	vector <int> vec;
	vector <int> vec2;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
		vec2.push_back(num);
	}
	vec.push_back(new_score);
	sort(vec.begin(), vec.end(), greater<>());
	sort(vec2.begin(), vec2.end(), greater<>());


	int idx = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (idx + 1 > P) {
			cout << -1 << '\n';
			break;
		}
		if (new_score == vec[i]) {
			if (vec.size() > P && new_score == vec2[P - 1]) {
				cout << -1 << '\n';
			}
			else  cout << idx + 1 << '\n';
			break;
		}
		idx++;
	}
}