#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

map <string, int> m;

int main(void) {
    vector<string> answer;
    vector <int> steps_one;
    vector <string> names_one;
    for (int i = 0; i < steps_one.size(); i++) {
        if (m.find(names_one[i]) != m.end()) {
            auto iter = m.find(names_one[i]);
            iter->second = max(iter->second, steps_one[i]);
        }
        else {
            m.insert({ names_one[i], steps_one[i] });
        }
    }

    // Step 2 Step 3 �� �� ������ Sorting�� �ؼ� ����ϸ� �Ǵµ� �ð� ��� �� ����..

    return answer;
}