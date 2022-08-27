#include <iostream>
using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	int r = a * b;
	int result = r - c;
	if (result >= 0) {
		cout << result;
	}
	else
	{
		cout << 0;
	}
}