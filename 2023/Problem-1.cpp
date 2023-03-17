#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int solution(int K, vector<string> user_scores) {
    int answer = 0;
    map <string, int> m; //name, <index, score>
    vector <pair<string, int>> score;
    for (int i = 0; i < user_scores.size(); i++) {
        stringstream ss(user_scores[i]);
        string name; string s;
        ss >> name >> s;
        score.push_back({ name, stoi(s) });
    }

    for (int i = 0; i < score.size(); i++) {
        string u = score[i].first;
        int s = score[i].second;
        if (m[u]) {
            if (s > m[u]) {
                m[u] = s;
            }
        }
        else {
            if (m.size() < K) {
                answer++;
                m.insert({ u, s });
            }
            else {
                bool change = false;
                for (auto iter = m.begin(); iter != m.end(); iter++) {
                    if (iter->second < s) {
                        change = true;
                        break;
                    }
                }
                if (change) {
                    int min = 99999;
                    string key;
                    for (auto iter = m.begin(); iter != m.end(); iter++) {
                        if (min > iter->second) {
                            min = iter->second;
                            key = iter->first;
                        }
                    }
                    cout << key << '\n';
                    m.erase(key);
                    m.insert({ u, s });
                    answer++;
                }
            }
        }
    }

    return answer;
}
// 너무 안일했다