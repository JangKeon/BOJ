#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	bool arr[21] = { false, };
	int N, num;
	string func;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> func;
		if (func == "add") {
			cin >> num;
			arr[num] = true;
		}
		else if (func == "remove") {
			cin >> num;
			arr[num] = false;
		}
		else if (func == "check") {
			cin >> num;
			if (arr[num]) {
				printf("1\n");
			}
			else printf("0\n");
		}
		else if (func == "toggle") {
			cin >> num;
			if (arr[num]) {
				arr[num] = false;
			}
			else arr[num] = true;
		}
		else if (func == "all") {
			memset(arr, true, sizeof(arr));
		}
		else if (func == "empty") {
			memset(arr, false, sizeof(arr));
		}
	}
}