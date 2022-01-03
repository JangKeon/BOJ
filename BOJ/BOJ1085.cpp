#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable:4996)
# define Size 4
int main() {
    int x = 0, y = 0, w = 0, h = 0, min = 999999; 
    int distance[Size];
    scanf("%d %d %d %d", &x, &y, &w, &h);
    distance[0] = x - 0;
    distance[1] = y - 0;
    distance[2] = w - x;
    distance[3] = h - y;
    for (int i = 0; i < Size; i++) {
        if (min > distance[i]) {
            min = distance[i];
        }
    }
    printf("%d", min);
    return 0;
}