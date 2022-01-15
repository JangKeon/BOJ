#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#pragma warning(disable:4996)

struct Member {
    int mNumber;
    string Name;
    int index;
    Member() {};
    Member(int mNumber, string Name, int index) : mNumber(mNumber), Name(Name), index(index) {};
    bool operator<(const Member m) const {
        if (mNumber == m.mNumber) {
            return index > m.index;
        }
        else {
            return mNumber > m.mNumber;
        }
    }
};

int main() {
    priority_queue <Member> pq;
    int N, age, index;
    string names;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        index = i;
        cin >> age >> names;
        pq.push(Member(age, names, index));
        
    }
    while (!pq.empty()) {
        Member m = pq.top();
        cout << m.mNumber << ' ' << m.Name << '\n';
        pq.pop();
    }
}