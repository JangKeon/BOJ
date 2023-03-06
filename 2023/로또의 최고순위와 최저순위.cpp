// Programmers : https://school.programmers.co.kr/learn/courses/30/lessons/77484

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int award(int n) {
    switch (n) {
    case 6: return 1; break;
    case 5: return 2; break;
    case 4: return 3; break;
    case 3: return 4; break;
    case 2: return 5; break;
    default: return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int correct = 0, zeros = 0;
    int wins[46];
    fill(wins, wins + 45, 99999);
    for (int i = 0; i < win_nums.size(); i++) {
        wins[win_nums[i]] = 1;
    }
    for (int i = 0; i < lottos.size(); i++) {
        if (wins[lottos[i]] == 1) {
            correct++;
        }
        if (lottos[i] == 0) {
            zeros++;
        }
    }
    int best = award(correct + zeros);
    int worst = award(correct);
    answer.push_back(best);
    answer.push_back(worst);
    return answer;
}