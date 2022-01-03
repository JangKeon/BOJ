#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable:4996)

int main() {
    int T = 0;
    int H = 0, W = 0, N = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &H, &W, &N);
        if (N % H == 0) {
            W = N / H;
            if (W < 10) {
                printf("%d%02d\n", H, W);
            }
            else {
                printf("%d%d\n", H, W);
            }
        }
        else {
            W = N / H + 1;
            H = N % H;
            if (W < 10) {
                printf("%d%02d\n", H, W);
            }
            else {
                printf("%d%d\n", H, W);
            }
        }
        
    }
    
    return 0;
}