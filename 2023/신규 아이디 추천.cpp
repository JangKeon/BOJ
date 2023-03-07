#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";
    //1단계
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    //2단계
    for (int i = 0; i < new_id.length(); i++) {
        if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
            answer.push_back(new_id[i]);
        }
        if (new_id[i] >= 'a' && new_id[i] <= 'z') {
            answer.push_back(new_id[i]);
        }
        if (new_id[i] - '0' >= 0 && new_id[i] - '0' <= 9) {
            answer.push_back(new_id[i]);
        }
    }
    //3단계
    int dot = 0;
    string temp;
    for (int i = 0; i < answer.length(); i++) {
        if (answer[i] == '.') {
            if (dot > 0) continue;
            temp.push_back(answer[i]);
            dot++;
        }
        else {
            dot = 0;
            temp.push_back(answer[i]);
        }
    }
    //4단계
    answer = "";
    for (int i = 0; i < temp.length(); i++) {
        if (i == 0 || i == temp.length() - 1) {
            if (temp[i] != '.') {
                answer.push_back(temp[i]);
            }
        }
        else answer.push_back(temp[i]);
    }
    //5단계
    if (answer.length() == 0) {
        answer.push_back('a');
    }
    //6단계
    temp = "";
    string temp2 = answer;
    if (answer.length() >= 16) {
        for (int i = 0; i < 15; i++) {
            temp.push_back(answer[i]);
        }
        if (temp[14] == '.') temp.pop_back();
        answer = temp;
    }
    else answer = temp2;
    //7단계
    if (answer.length() <= 2) {
        while (answer.length() != 3) {
            answer.push_back(answer[answer.length() - 1]);
        }
    }
    return answer;
}