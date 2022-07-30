#include <iostream>
using namespace std;

int main(void) {
    int dice[3], same = 0, max = 0, idx;
    for (int i = 0; i < 3; i++) {
        cin >> dice[i];
    }
    for (int i = 1; i < 3; i++) {
        if (dice[i - 1] == dice[i]) {
            idx = dice[i];
        }
    }
    if (dice[0] == dice[2])  idx = dice[0];
    if (dice[0] == dice[1] && dice[1] == dice[2]) {
        cout << 10000 + (dice[0] * 1000);
    }
    else if (dice[0] == dice[1] || dice[1] == dice[2] || dice[0] == dice[2]) {
        cout << 1000 + (idx * 100);
    }
    else {
        for (int i = 0; i < 3; i++) {
            if (dice[i] > max) {
                max = dice[i];
            }
        }
        cout << max * 100;
    }
}