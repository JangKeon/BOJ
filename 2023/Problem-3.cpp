#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(int N, vector<int> coffee_times) {
    vector<int> answer;
    priority_queue <pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> pq;
    int index = 0;
    for (int i = 0; i < N && index < coffee_times.size(); i++) {
        pq.push({ coffee_times[index], index + 1 });
        index++;
    }
    while (!pq.empty()) {
        int time = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        answer.push_back(now);
        if (index < coffee_times.size()) {
            pq.push({ time + coffee_times[index], index + 1 });
            index++;
        }
    }

    return answer;
}