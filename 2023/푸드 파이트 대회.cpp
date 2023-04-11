#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for (int i = 0; i < food.size(); i++) {
        if (food[i] % 2 != 0) food[i] -= 1;
    }
    for (int i = 1; i < food.size(); i++) {
        for (int j = 0; j < food[i] / 2; j++) {
            answer += to_string(i);
        }
    }
    string temp = answer;
    answer += '0';
    reverse(temp.begin(), temp.end());
    
    return answer + temp;
}