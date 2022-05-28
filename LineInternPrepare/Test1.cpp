#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

vector <pair<string, string>> vec;
map <string, int> Name;
map <string, int> Problem;

vector<string> solution(vector<string> logs) {
    vector<string> answer;
    
    bool enter = false;
    string name, problem;
    int user = 0;
    for (int i = 0; i < logs.size(); i++) {
        string input = logs[i];
        string name, problem;
        
        for (int j = 0; j < input.size(); j++) {
            if (input[j] == ' ') {
                enter = true;
                continue;
            }
            if (!enter) {
                name.push_back(input[j]);
            }
            if (enter) {
                problem.push_back(input[j]);
            }
        }

        Name[name]++;
        // map.size() = 전체 유저 수
        Problem[problem]++;
        // Problem.size() = 푼 문제 수

        for (auto it : Problem) {
            if (it.second >= Name.size()/2) answer.push_back(it.first);
        }

        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << ' ';
        }
    }
    return answer;
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    vector <string> input;

}





#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector <pair<string, string>> vec;
unordered_map <string, int> Name;
unordered_map <string, int> Problem;

vector<string> solution(vector<string> logs) {
    vector<string> answer;
    bool enter = false;
    string name, problem;
    int user = 0;
    for (int i = 0; i < logs.size(); i++) {
        string input = logs[i];
        string name, problem;

        for (int j = 0; j < input.size(); j++) {
            if (input[j] == ' ') {
                enter = true;
                continue;
            }
            if (!enter) {
                name.push_back(input[j]);
            }
            if (enter) {
                problem.push_back(input[j]);
            }
        }

        Name[name]++;
        // map.size() = 전체 유저 수
        Problem[problem]++;
        // Problem.size() = 푼 문제 수
        for (auto it : Problem) {
            if (it.second >= Name.size() / 2) answer.push_back(it.first);
        }
        sort(answer.begin(), answer.end());
    }
    return answer;
}
