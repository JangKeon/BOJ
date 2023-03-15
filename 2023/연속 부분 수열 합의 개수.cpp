#include <string>
#include <vector>
#include <map>
using namespace std;
map<int, bool> m;

void sol(vector<int> v, int idx, int& answer) {

    // 시작 인덱스(idx)의 위치 값을 총합으로 초기화.
    int sum = v[idx];

    // 총합이 map에 존재하지 않으면 추가
    if (m.find(sum) == m.end()) {
        m.insert({ sum,true });
        answer++;
    }

    // 시작 인덱스는 검사했으니 다음 인덱스로 현재 인덱스(i)로 초기화.
    int i = idx + 1;
    if (i >= v.size()) // 마지막 인덱스(총 크기)를 넘어선다면
        i = 0; // 0으로 초기화 (원형을 위해서)


    // 현재 인덱스 i가 시작 인덱스(idx)와 동일해지면 연속하는 모든 부분을 탐색한것임.
    // 그래서 i가 시작 인덱스가 될때까지 반복문을 돌릴것임.
    while (i != idx) {
        sum += v[i]; // 현재 인덱스를 총합에 더함.
        if (m.find(sum) == m.end()) { // 총합이 존재하지않으면 map에 추가.
            m.insert({ sum,true });
            answer++;
        }

        i++; // 다음인덱스로 이동
        if (i >= v.size()) // 마지막인덱스를 넘어간다면 0으로 초기화.
            i = 0;
    }
}

int solution(vector<int> elements) {
    int answer = 0;

    // 모든 인덱스에 대해 연속 부분 탐색
    for (int i = 0; i < elements.size(); i++) {
        sol(elements, i, answer);
    }
    return answer;
}