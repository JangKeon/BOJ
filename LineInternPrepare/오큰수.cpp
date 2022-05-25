// 18∫– Ω√¿€
#include <iostream>
#include <vector>
using namespace std;

vector <int> vec;
int dp[1000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, num, prev_num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (i != 0 && num > prev_num) {
			dp[i - 1] = num;
		}
		vec.push_back(num);
		prev_num = num;
	}

	int current_max = 0;
	int current_max_index = 0; 

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			
			if (dp[i] != 0) {
				break; 
			}
			
			if (i != 0 && current_max_index > i && current_max > vec[i] && vec[i] >= vec[i - 1]) {
				dp[i] = current_max;
			}

			if (vec[j] > vec[i]) {
				dp[i] = vec[j];
				current_max = vec[j];
				current_max_index = j;
				break;
			}
		}
		if (dp[i] == 0) {
			dp[i] = -1;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << dp[i] << ' ';
	}
}