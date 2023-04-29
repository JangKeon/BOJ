#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<vector<int>> problems) {
    vector<int> result;
    int min_size = 987654321;

    for (int bit = 1; bit < (1 << problems.size()); ++bit) {
        vector<int> types(n, 0);
        vector<int> temp;

        for (int i = 0; i < problems.size(); ++i) {
            if (bit & (1 << i)) {
                temp.push_back(i);

                for (int j = 0; j < n; ++j) {
                    types[j] += problems[i][j];
                }
            }
        }

        bool all_types = true;
        for (int type : types) {
            if (type == 0) {
                all_types = false;
                break;
            }
        }

        if (all_types && temp.size() < min_size) {
            min_size = temp.size();
            result = temp;
        }
    }

    for (int i = 0; i < result.size(); ++i) {
        result[i]++;
    }

    return result;
}

int main() {
    int n = 4;
    vector<vector<int>> problems = { {0, 0, 0, 1}, {0, 1, 0, 1}, {1, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 0} };
    vector<int> result = solution(n, problems);

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
