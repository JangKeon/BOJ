#include <iostream>
using namespace std;

int N, M;
long long int D[31][31];

long long int nCr(int n, int r)
{
    if (n == r || r == 0)
        return D[n][r] = 1;
    if (r == 1)
        return D[n][r] = n;
    if (D[n][r])
        return D[n][r];
    return D[n][r] = (nCr(n - 1, r - 1) + nCr(n - 1, r));
}


int main(void) {
    int T;
    cin >> T;
    for (int u = 0; u < T; u++) {
        cin >> N >> M;
        cout << nCr(M, N) << '\n';
        memset(D, 0, sizeof(D));
    }
}