#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> dots, vector<int> lines) {
    int answer = 0, index = 0;
    sort(lines.begin(), lines.end(), greater<int>());
    for (int i = 0; i < lines.size(); i++) {
        int temp = dots[index];
        cout << index << '\n';
        while (index < dots.size() && dots[index] <= temp + lines[i]) {
            index++;
        }
        answer++;
        if (index >= dots.size()) {
            break;
        }
    }
    if (index < dots.size())  return -1;
    return answer;
}