// https://school.programmers.co.kr/learn/courses/30/lessons/154539

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 이중 for문. 당여니 시간초과,, TC 19/23 정답
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i; j < numbers.size(); j++) {
            if (numbers[i] < numbers[j]) {
                answer.push_back(numbers[j]);
                break;
            }
            if (j == numbers.size() - 1) {
                answer.push_back(-1);
            }
        }
    }
    return answer;
}

// Stack 사용

