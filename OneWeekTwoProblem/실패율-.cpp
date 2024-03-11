#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool compare(pair<int, double> v, pair<int, double> v2) {
    return v.second > v2.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector <int> num(501, 0);
    vector <double> failure(501, 0);
    vector <pair<int, double>> vec;

    for (int i = 0; i < stages.size(); i++) {
        num[stages[i]]++;
    }

    int all = stages.size();
    for (int i = 1; i <= N + 1; i++) {
        if (!num[i]) failure[i] = 0;
        else failure[i] = num[i] / all;
        all -= num[i];
        cout << all << '\n';
    }


    // for (int i = 1; i <= N; i++){
    //     vec.push_back({i, failure[i]});
    //     cout << "Failure : " << failure[i] << '\n';
    // }
    // for (int i = 1; i <= N; i++){
    //     cout << "First : " << vec[i].first << " Second : " << vec[i].second << '\n';
    // }
    // sort(vec.begin(), vec.end(), compare);
    // for (int i = 0; i < N; i++){
    //     answer.push_back(vec[i].first);
    // }
    return answer;
}