#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	long long S;
	cin >> S;
	long long add = 1, count = 0;
	while (S > 0) {
		S -= add;
		add++;
		count++;
	}
	if (S == 0) {
		cout << count;
	}
	else cout << count - 1;
}