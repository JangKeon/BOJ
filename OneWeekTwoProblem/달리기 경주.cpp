#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map <string, int> m1;
    map <int, string> m2;
    for (int i = 0; i < players.size(); i++) {
        m1.insert({ players[i], i });
        m2.insert({ i, players[i] });
    }
    for (int i = 0; i < callings.size(); i++) {
        int tmp = m1[callings[i]]; 
        string temp = m2[tmp - 1];

        m1[callings[i]] -= 1;
        m1[temp] += 1;

        m2[tmp] = temp;
        m2[tmp - 1] = callings[i];

    }
    for (int i = 0; i < m2.size(); i++) {
        answer.push_back(m2[i]);
    }
    return answer;
}