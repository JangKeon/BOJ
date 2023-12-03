#include <string>
#include <vector>
#include <iostream>

using namespace std;

char map[50][50];
int x_min = 51, x_max = -1;
int y_min = 51, y_max = -1;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[0].size(); j++) {
            if (wallpaper[i][j] == '#') {
                if (i < x_min)   x_min = i;
                if (i > x_max)   x_max = i;
                if (j < y_min)   y_min = j;
                if (j > y_max)   y_max = j;
            }
        }
    }
    answer.push_back(x_min);
    answer.push_back(y_min);
    answer.push_back(x_max + 1);
    answer.push_back(y_max + 1);
    return answer;
}