// 

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map <int, int> m;
    vector <pair<int, int>> vec;
    for (int i = 0; i < tangerine.size(); i++) {
        m[tangerine[i]]++;
    }
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        vec.push_back({ iter->second, iter->first });
    }
    sort(vec.begin(), vec.end(), greater<>());
    int sum = 0;
    for (int i = 0; k > sum; i++) {
        sum += vec[i].first;
        answer++;
    }
    return answer;
}