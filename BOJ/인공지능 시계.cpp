#include <iostream>
using namespace std;

int main(void) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int H, M, S;
    H = D / 3600;
    M = (D % 3600) / 60;
    S = (D % 3600) % 60;
    A += H;
    B += M;
    C += S;
    B += (C / 60);
    A += (B / 60);
    cout << A % 24 << ' ' << B % 60  << ' ' << C % 60;
}