#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector <int> answer;
    priority_queue <int, vector <int>, greater<int>> q;
    for (int m = 0; m < score.size(); m++) {
        if (m >= k) {
            q.push(score[m]);
            q.pop();
        }
        else    q.push(score[m]);
        answer.push_back(q.top());
    }
    return answer;
}