#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct point {
    int x;
    int y;
};

queue <point> que;
vector <string> map;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int cost[101][101];

void bfs() {
    while (!que.empty()) {
        int x = que.front().x;
        int y = que.front().y;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int ax = x + dx[i];
            int ay = y + dy[i];
            if (ax < 0 || ax >= map.size() || ay < 0 || ay >= map[0].size()) {
                continue;
            }
            if (map[ax][ay] == 'X' || cost[ax][ay]) {
                continue;
            }
            cost[ax][ay] = cost[x][y] + 1;
            que.push({ ax, ay });
        }
    }
}

int solution(vector<string> maps) {
    int answer = 0, np = 0;
    point lever;
    point exit;
    map = maps;
    memset(cost, 0, sizeof(cost));
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i][j] == 'S') {
                que.push({ i,j });
            }
            if (maps[i][j] == 'L') {
                lever.x = i; lever.y = j;
            }
            if (maps[i][j] == 'E') {
                exit.x = i; exit.y = j;
            }
        }
    }
    bfs();
    if (!cost[lever.x][lever.y]) np = 1;
    answer += cost[lever.x][lever.y];

    memset(cost, 0, sizeof(cost));
    que.push({ lever.x, lever.y });
    bfs();
    if (!cost[exit.x][exit.y]) np = 1;
    answer += cost[exit.x][exit.y];

    if (np)  return -1;
    else    return answer;
}