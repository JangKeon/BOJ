#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while (n / a >= 1) {
        answer += (n / a) * b;
        n = (n % a) + (n / a) * b;
    }
    return answer;
}