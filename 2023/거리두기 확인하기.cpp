#include <string>
#include <vector>
#include <iostream>

using namespace std;

char map[5][5];
int res;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dx2[4] = { 2, 0, -2, 0 };
int dy2[4] = { 0, 2, 0, -2 };

int dx3[4] = { 1, -1, 1, -1 };
int dy3[4] = { 1, -1, -1, 1 };

void search(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int ax = x + dx[i];
        int ay = y + dy[i];
        if (ax < 0 || ax > 4 || ay < 0 || ay > 4) {
            continue;
        }
        if (map[ax][ay] == 'P') {
            res = 0;
            break;
        }
    }
    for (int i = 0; i < 4; i++) {
        int ax = x + dx2[i];
        int ay = y + dy2[i];
        if (ax < 0 || ax > 4 || ay < 0 || ay > 4) {
            continue;
        }
        if (map[ax][ay] == 'P') {
            res = 0;
            if (i == 0) {
                if (map[ax - 1][ay] == 'X')  res = 1;
            }
            else if (i == 1) {
                if (map[ax][ay - 1] == 'X')  res = 1;
            }
            else if (i == 2) {
                if (map[ax + 1][ay] == 'X')  res = 1;
            }
            else if (i == 3) {
                if (map[ax][ay + 1] == 'X')  res = 1;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        int ax = x + dx3[i];
        int ay = y + dy3[i];
        if (ax < 0 || ax > 4 || ay < 0 || ay > 4) {
            continue;
        }
        if (map[ax][ay] == 'P') {
            res = 0;
            if (i == 0) {
                if (map[ax - 1][ay] == 'X' && map[ax][ay - 1] == 'X')  res = 1;
            }
            else if (i == 1) {
                if (map[ax + 1][ay] == 'X' && map[ax][ay + 1] == 'X')  res = 1;
            }
            else if (i == 2) {
                if (map[ax - 1][ay] == 'X' && map[ax][ay + 1] == 'X')  res = 1;
            }
            else if (i == 3) {
                if (map[ax + 1][ay] == 'X' && map[ax][ay - 1] == 'X')  res = 1;
            }
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int u = 0; u < places.size(); u++) {
        res = 1;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                map[i][j] = places[u][i][j];
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (map[i][j] == 'P') {
                    search(i, j);
                }
            }
        }
        answer.push_back(res);
    }
    return answer;
}