#include <iostream>
using namespace std;

int main(void) {
    int n1 = 9999, n2 = 9999;
    while (1) {
        cin >> n1 >> n2;
        if (n1 == 0 && n2 == 0) {
            break;
        }
        if (n1 > n2) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
}