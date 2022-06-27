#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(void) {
	int num, result = 0;
	
	for (int i = 0; i < 5; i++) {
		scanf_s("%1d", &num);
		result += pow(num, 5);
	}
	cout << result;
}