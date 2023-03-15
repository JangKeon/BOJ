#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    vector <int> vec;
    for (int u = 1; u < elements.size(); u++) { // u = k
        vector<int> tempVector;
        for (int i = 0; i < u; i++) {
            tempVector.push_back(1);
        }
        for (int i = 0; i < elements.size() - u; i++) { // elements.size() = n
            tempVector.push_back(0);
        }
        sort(tempVector.begin(), tempVector.end());
        do {
            int sum = 0;
            for (int i = 0; i < tempVector.size(); i++) {
                if (tempVector[i] == 1) {
                    sum += elements[i];
                }
            }
            vec.push_back(sum);
        } while (next_permutation(tempVector.begin(), tempVector.end()));
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << '\n';
    }
    return vec.size();
}