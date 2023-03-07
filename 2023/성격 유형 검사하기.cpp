// https://school.programmers.co.kr/learn/courses/30/lessons/118666 
#include <string>
#include <vector>
#include <map>
using namespace std;

map <char, int> m;

void score(string s, int select) {
    if (select == 1) m[s[0]] += 3;
    else if (select == 2) m[s[0]] += 2;
    else if (select == 3) m[s[0]] += 1;
    else if (select == 5) m[s[1]] += 1;
    else if (select == 6) m[s[1]] += 2;
    else if (select == 7) m[s[1]] += 3;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    string MBTI[4] = { "RT", "CF", "JM", "AN" };
    for (int i = 0; i < survey.size(); i++) {
        score(survey[i], choices[i]);
    }
    for (int i = 0; i < 4; i++) {
        if (m[MBTI[i][0]] >= m[MBTI[i][1]]) {
            answer.push_back(MBTI[i][0]);
        }
        else answer.push_back(MBTI[i][1]);
    }
    return answer;
}