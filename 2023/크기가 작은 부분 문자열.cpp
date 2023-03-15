// https://school.programmers.co.kr/learn/courses/30/lessons/147355

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long comp = stol(p);
    for (int i = 0; i < t.size() - p.size() + 1; i++) {
        string str;
        for (int j = i; j < i + p.size(); j++) {
            str.push_back(t[j]);
        }
        long long num = stol(str);
        if (num <= comp) {
            answer++;
        }
    }
    return answer;
}