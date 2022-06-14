#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> p) {
    vector<int> answer;
    int temp = 0;
    for (int i = 0; i < p.size(); i++) {
        answer.push_back(0);
    }
    for (int i = 0; i < p.size(); i++) {
        if (p[i] != i + 1) {
            int j = find(p.begin(), p.end(), i + 1) - p.begin();
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
            answer[i] ++;
            answer[j] ++;
        }
        if (i + 1 == p.size()) {
            break;
        }
    }
    return answer;
}