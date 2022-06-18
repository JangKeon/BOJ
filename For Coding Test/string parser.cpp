#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;
    vector<string> result;
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }
    return result;
}

void solution(vector<string> plans) {
    
    vector<int> answer;
    vector <pair<int, vector <int>>> Plan;
    vector<string> plan_split;

    for (int i = 0; i < plans.size(); i++) {
        plan_split = split(plans[i], ' ');
        vector <int> temp;
        for (int j = 1; j < plan_split.size(); j++) {
            temp.push_back(stoi(plan_split[j]));
        }
        Plan.push_back(make_pair(stoi(plan_split[0]), temp));
    }

    cout << Plan[1].first;

}

int main(void) {

    vector <string> A = { "10 20 30 40 50", "60 70 80 90" };
    solution(A);

}