#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

struct rectangle {
    int x1;
    int y1;
    int x2;
    int y2;
};

int Connected(rectangle a, rectangle b) {
    if (a.x2 == b.x1 && !(a.y2 <= b.y1 || b.y2 <= a.y1))    return 1;
    if (a.x1 == b.x2 && !(a.y2 <= b.y1 || b.y2 <= a.y1))    return 1;
    if (a.y1 == b.y2 && !(a.x2 <= b.x1 || b.x2 <= a.x1))    return 1;
    if (a.y2 == b.y1 && !(a.x2 <= b.x1 || b.x2 <= a.x1))    return 1;
    return 0;
}

int visit[10001];
vector <int> graph[10001];
int res;

void dfs(int x) {
    visit[x] = 1;
    res++;
    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if (!visit[y]) {
            dfs(y);
        }
    }
}

vector<int> solution(int n, vector<int> x1, vector<int> y1, vector<int> x2, vector<int> y2) {
    vector<int> answer;
    vector <rectangle> vec;
    for (int i = 0; i < n; i++) {
        rectangle a;
        a.x1 = x1[i]; a.x2 = x2[i]; a.y1 = y1[i]; a.y2 = y2[i];
        int res = 0;
        for (int j = 0; j < n; j++) {
            if (i == j)    continue;
            rectangle b;
            b.x1 = x1[j]; b.x2 = x2[j]; b.y1 = y1[j]; b.y2 = y2[j];
            if (Connected(a, b)) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        res = 0;
        dfs(i);
        answer.push_back(res);
        memset(visit, 0, sizeof(visit));
    }

    return answer;
}