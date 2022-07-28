#include <iostream>
#include <math.h>
using namespace std;

int arr[1000001];

int main(void) {
    int N, M;
    cin >> N >> M;
    arr[1] = true;
    for (int i = 2; i <= sqrt(M); i++) {
        if (arr[i]) continue;
        for (int j = i + i; j <= M; j += i)
            arr[j] = true;
    }

    for (int i = N; i <= M; i++) {
        if (!arr[i]) {
            cout << i << '\n';
        }
    }
}