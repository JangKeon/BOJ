#include <string>
#include <vector>

using namespace std;

int palindrome(int num) {
    string s = to_string(num);
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return 0;
        }
    }
    return 1;
}

vector<long long> solution(vector<long long> remittance) {
    vector<long long> answer;
    for (int i = 0; i < remittance.size(); i++) {
        while (!palindrome(remittance[i])) {
            remittance[i]++;
        }
        answer.push_back(remittance[i]);
    }
    return answer;
}