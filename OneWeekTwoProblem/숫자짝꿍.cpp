#include <string>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

int X_number[10];
int Y_number[10];
int common[10];

string solution(string X, string Y) {
    string answer = "";
    for (int i = 0; i < X.size(); i++) {
        X_number[X[i] - '0']++;
    }
    for (int i = 0; i < Y.size(); i++) {
        Y_number[Y[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (X_number[i] > Y_number[i])   common[i] = Y_number[i];
        else common[i] = X_number[i];
    }
    if (!common[1] && !common[2] && !common[3] && !common[4] && !common[5] && !common[6] && !common[7] && !common[8] && !common[9]) {
        if (common[0])   return "0";
        else    return "-1";
    }
    for (int i = 9; i >= 0; i--) {
        if (common[i]) {
            string add = to_string(i);
            for (int j = 0; j < common[i]; j++) {
                answer += add;
            }
        }
    }
    return answer;
}