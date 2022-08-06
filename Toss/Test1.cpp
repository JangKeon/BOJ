#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
    string s = "12223";
    int answer = 0, same = 0;
    char cmp = s[0];
    cout << cmp << '\n';
    vector <int> nums;
    for (int i = 1; i < s.size(); i++) {
        if (cmp == s[i]) {
            same++;
            if (same == 2) {
                nums.push_back(s[i] - '0');
            }
        }
        else same = 0;
        cmp = s[i];
    }
    int max = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (max < nums[i])   max = nums[i];
        cout << nums[i] << ' ';
    }
    answer = 100 * max + 10 * max + max;
    cout << "Answer : " << answer;
}