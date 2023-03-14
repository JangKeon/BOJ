// https://school.programmers.co.kr/learn/courses/30/lessons/161989

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int temp = 0;
    for (int i = 0; i < section.size(); i++) {
        int start = section[i];
        if (temp > start) {
            continue;
        }
        answer++;
        temp = start + m;
    }

    return answer;
}