#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0, idx = 0;
    vector <int> v(1000001, 0);
    for (int i = 0; i < ingredient.size(); i++) {
        v[idx] = ingredient[i];
        if (v[idx] == 1 && v[idx - 1] == 3 && v[idx - 2] == 2 && v[idx - 3] == 1) {
            answer++;
            idx -= 3;
        }
        else idx++;
    }
    return answer;
}