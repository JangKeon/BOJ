#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0, flag = -1;
    answer = health;
    int last_time = attacks[attacks.size() - 1].at(0);
    int j = 0;
    for (int i = 0; i <= last_time; i++) {
        if (i == attacks[j].at(0)) {
            flag = 0;
            answer -= attacks[j].at(1);
            j++;
        }
        else {
            flag++;
            answer += bandage[1];
            if (flag == bandage[0]) {
                answer += bandage[2];
                flag = -1;
            }
            if (answer > health) answer = health;
        }
        if (answer <= 0)  return -1;
    }

    return answer;
}