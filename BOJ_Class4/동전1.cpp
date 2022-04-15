#include <iostream>
#include <vector>
using namespace std;

int cost[10001];

int main(void) {
	int n, k, num;
	cin >> n >> k;
	vector <int> value;
	cost[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> num;
		value.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		for (int j = value[i]; j <= k; j++) {
			cost[j] = cost[j] + cost[j - value[i]];
		}
	}
	cout << cost[k];
}