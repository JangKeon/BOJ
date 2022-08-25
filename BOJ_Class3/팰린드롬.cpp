#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	while (1) {
		string meter, temp;
		cin >> meter;
		int original_size = meter.size();
		if (stoi(meter) == 0)	break;
		for (int i = 0; i < 999999999; i++) {
			bool pel = true;
			for (int j = 0; j < meter.size() / 2; j++) {
				if (meter[j] != meter[meter.size() - j - 1]) {
					pel = false;
					break;
				}
			}
			if (pel) {
				cout << i << '\n';
				break;
			}
			temp = to_string(stoi(meter) + 1);
			meter = "";
			for (int j = 0; j < original_size - temp.size(); j++) {
				meter += '0';
			}
			meter += temp;
		}
	}
}