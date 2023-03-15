// https://school.programmers.co.kr/learn/courses/30/lessons/160586

#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map <char, int> m;
    for (int i = 0; i < keymap.size(); i++) {
        for (int j = 0; j < keymap[i].size(); j++) {
            if (!m[keymap[i][j]]) {
                m[keymap[i][j]] = j + 1;
            }
            else {
                if (m[keymap[i][j]] > j + 1) {
                    m[keymap[i][j]] = j + 1;
                }
            }
        }
    }
    for (int i = 0; i < targets.size(); i++) {
        int sum = 0, no = 0;
        for (int j = 0; j < targets[i].size(); j++) {
            if (!m[targets[i][j]]) {
                no = 1;
                break;
            }
            sum += m[targets[i][j]];
        }
        if (no) answer.push_back(-1);
        else answer.push_back(sum);
    }
    return answer;
}