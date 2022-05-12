#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    long long a, b, num = 0;
    vector <int> vec;
    cin >> a >> b;
    if (a < b) {
        for (long long i = a + 1; i < b; i++) {
            num++;
        }
        cout << num << '\n';
        for (long long i = a + 1; i < b; i++) {
            cout << i << ' ';
        }
    }

    else if (a > b) {
        for (long long i = b + 1; i < a; i++) {
            num++;
        }
        cout << num << '\n';
        for (long long i = b + 1; i < a; i++) {
            cout << i << ' ';
        }
    }

    else {
        cout << '0';
    }
}