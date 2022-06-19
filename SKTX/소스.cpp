#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string solution(string& T) {
    vector <char> vec;
    char c;
    for (int i = 0; i < T.size(); i++) {
        scanf("%1d", &c);
        vec.push_back(c);
    }
    sort(vec.begin(), vec.end(), greater<>());
    string res;
    for (int i = 0; i < vec.size(); i++) {
        res.push_back(vec[i]);
    }
    return res;
}


int main(void) {
    string a = "SSMLSML";
    solution(a);
}




#include <vector>
#include <algorithm>
using namespace std;

string solution(string& T) {
    sort(T.begin(), T.end(), greater<>());
    return T;
}
