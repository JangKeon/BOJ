#include <string>
#include <vector>
#include <map>
using namespace std;
map<int, bool> m;

void sol(vector<int> v, int idx, int& answer) {

    // ���� �ε���(idx)�� ��ġ ���� �������� �ʱ�ȭ.
    int sum = v[idx];

    // ������ map�� �������� ������ �߰�
    if (m.find(sum) == m.end()) {
        m.insert({ sum,true });
        answer++;
    }

    // ���� �ε����� �˻������� ���� �ε����� ���� �ε���(i)�� �ʱ�ȭ.
    int i = idx + 1;
    if (i >= v.size()) // ������ �ε���(�� ũ��)�� �Ѿ�ٸ�
        i = 0; // 0���� �ʱ�ȭ (������ ���ؼ�)


    // ���� �ε��� i�� ���� �ε���(idx)�� ���������� �����ϴ� ��� �κ��� Ž���Ѱ���.
    // �׷��� i�� ���� �ε����� �ɶ����� �ݺ����� ��������.
    while (i != idx) {
        sum += v[i]; // ���� �ε����� ���տ� ����.
        if (m.find(sum) == m.end()) { // ������ �������������� map�� �߰�.
            m.insert({ sum,true });
            answer++;
        }

        i++; // �����ε����� �̵�
        if (i >= v.size()) // �������ε����� �Ѿ�ٸ� 0���� �ʱ�ȭ.
            i = 0;
    }
}

int solution(vector<int> elements) {
    int answer = 0;

    // ��� �ε����� ���� ���� �κ� Ž��
    for (int i = 0; i < elements.size(); i++) {
        sol(elements, i, answer);
    }
    return answer;
}