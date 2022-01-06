#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable:4996)

int fac(int n) {
    int result = 1;
    for (int i = n; i > 0; i--) {
        result *= i;
    }
    return result;
}
 
int main() {
    int N = 0, K = 0;
    int result = 0;
    scanf("%d %d", &N, &K);
    if (K < 0 || K > N) {
        result = 0;
    }
    else {
        result = fac(N) / (fac(K) * fac(N - K));
    }
    printf("%d", result);
    return 0;
}