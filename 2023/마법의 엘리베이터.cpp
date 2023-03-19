

#include <string>
#include <vector>

using namespace std;

int mul(int n) {
    int ret = 1;
    for (int i = 0; i < n; i++) {
        ret * 10;
    }
    return ret;
}

int solution(int storey) {
    int answer = 0;
    int up = 0, down = 0;
    int temp = storey;
    while (temp % 10 == 0) {
        temp++;
        up++;
    }
    temp = storey;
    while (temp % 10 == 0) {
        temp--;
        down++;
    }
    if (up < down) {
        storey += up;
        answer += up;
    }
    else {
        storey -= down;
        answer += down;
    }
    string str = to_string(storey);
    for (int i = str.size(); i > 0; i--) {
        answer += storey / mul(i);
    }
    return answer;
}