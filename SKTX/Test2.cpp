#include <string>
#include <vector>
#include <iostream>

using namespace std;

int isVIP[1001];
int changedVIP[1001];

vector<int> solution(vector<int> periods, vector<vector<int>> payments, vector<int> estimates) {
    vector<int> answer;
    int GoVip = 0, NotVip = 0;
    for (int i = 0; i < periods.size(); i++) {
        int currentTotal = 0;
        for (int j = 0; j < 12; j++) {
            currentTotal += payments[i][j];
        }
        if (periods[i] >= 24 && periods[i] < 60 && currentTotal >= 900000) {
            isVIP[i] = 1;
        }
        if (periods[i] >= 60 && currentTotal >= 600000) {
            isVIP[i] = 1;
        }
    }

    for (int i = 0; i < periods.size(); i++) {
        int changedTotal = 0;
        for (int j = 1; j < 12; j++) {
            changedTotal += payments[i][j];
        }
        changedTotal += estimates[i];
        if (periods[i] + 1 >= 24 && periods[i] + 1 < 60 && changedTotal >= 900000) {
            changedVIP[i] = 1;
        }
        if (periods[i] + 1 >= 60 && changedTotal >= 600000) {
            changedVIP[i] = 1;
        }
    }

    for (int i = 0; i < periods.size(); i++) {
        if (isVIP[i] == 0 && changedVIP[i] == 1) {
            GoVip++;
        }
        if (isVIP[i] == 1 && changedVIP[i] == 0) {
            NotVip++;
        }
    }

    answer.push_back(GoVip);
    answer.push_back(NotVip);
    return answer;
}