#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    map <char, int> m;
    for (int i = 0; i < skip.size(); i++) {
        m[skip[i]] = 1;
    }
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < index; j++) {
            if (m[s[i]]) {
                j--;
            }
            s[i]++;
            if (s[i] > 'z') {
                s[i] = 'a';
            }
        }
    }
    return s;
}

int main(void) {
    string s = "abcdef";
    string skip = "gh";
    int index = 3;
    cout << solution(s, skip, index);
}