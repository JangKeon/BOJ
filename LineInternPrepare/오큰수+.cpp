#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int result[1000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N, num;
	cin >> N;
	vector <int> vec;

	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}
	stack <int> st;
	for (int i = N - 1; i >= 0; i--) {
		while (!st.empty() && st.top() <= vec[i]) {
			st.pop();
		}

		if (st.empty()) {
			result[i] = -1;
		}
		else {
			result[i] = st.top();
		}
		st.push(vec[i]);
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << ' ';
	}
}