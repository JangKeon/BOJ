// https://school.programmers.co.kr/learn/courses/30/lessons/159994

#include <string>
#include <vector>
#include <queue>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue <string> q1{ {begin(cards1), end(cards1)} };
    queue <string> q2{ {begin(cards2), end(cards2)} };
    queue <string> goals{ {begin(goal), end(goal)} };
    while (1) {
        if (goals.empty()) {
            answer = "Yes";
            break;
        }
        string g = goals.front();
        if (q1.front() == g) {
            q1.pop();
            goals.pop();
        }
        else if (q2.front() == g) {
            q2.pop();
            goals.pop();
        }
        else {
            answer = "No";
            break;
        }
    }
    return answer;
}