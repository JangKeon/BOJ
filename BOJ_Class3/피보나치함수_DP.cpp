#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int main(void) {
    int T;
    scanf("%d", &T);
    int zerotable[41] = { 1, 0, };
    int onetable[41] = { 0, 1 };

    for (int i = 2; i < 41; i++) {
        zerotable[i] = zerotable[i - 1] + zerotable[i - 2];
        onetable[i] = onetable[i - 1] + onetable[i - 2];
    }
    for (int a = 0; a < T; a++) {
        int num;
        cin >> num;
        cout << zerotable[num] << ' ' << onetable[num] << '\n';
    }
}
