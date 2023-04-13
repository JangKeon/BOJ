// https://school.programmers.co.kr/learn/courses/30/lessons/140108
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

int solution(string s) {
    int answer = 0;
    while (1) {
        int x = 0, notx = 0;
        char first = s[0];
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == first) {
                x++;
            }
            else notx++;
            if (x == notx) {
                s = s.substr(i + 1, s.size() - 1);
                answer++;
                break;
            }
        }
        if (s.size() == 0)   break;
        if (x != notx) {
            answer++;
            break;
        }
    }
    return answer;
}