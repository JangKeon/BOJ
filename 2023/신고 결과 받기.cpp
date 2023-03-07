// Programmers : https://school.programmers.co.kr/learn/courses/30/lessons/92334

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector <pair<string, string>> vec; //report 구분
    map <string, int> m; // string이 신고당한 횟수
    map <string, int> result;
    for (int i = 0; i < report.size(); i++) {
        int blank = report[i].find(' ');
        string from = report[i].substr(0, blank);
        string to = report[i].substr(blank + 1);
        vec.push_back({ from, to });
    }
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        m[vec[i].second]++;
    }
    for (int i = 0; i < vec.size(); i++) {
        if (m[vec[i].second] >= k) {
            result[vec[i].first]++;
        }
    }
    for (int i = 0; i < id_list.size(); i++) {
        answer.push_back(result[id_list[i]]);
    }
    return answer;
}