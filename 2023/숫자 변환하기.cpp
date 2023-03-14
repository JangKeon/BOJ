// https://school.programmers.co.kr/learn/courses/30/lessons/154538

#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int result[1000001];

int solution(int x, int y, int n) {
    queue <int> que;
    que.push(x);
    result[x] = 0;
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        for (int ax : { temp + n, temp * 2, temp * 3}) {
            if (result[ax]) {
                continue;
            }
            if (ax > 1000000) {
                continue;
            }
            result[ax] = result[temp] + 1;
            que.push(ax);
        }
    }
    if (result[y] == 0 && x != y) {
        return -1;
    }
    return result[y];
}