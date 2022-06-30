#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[8];
vector <int> v;
bool visited[8];


void Print() {
    for (int i = 0; i < v.size(); i++) {
         cout << v[i] << ' ';
    }
    cout << '\n';
}

void DFS(int Cnt)
{
    if (Cnt == M) {
        Print();
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (visited[i] == true) continue;
        visited[i] = true;
        v.push_back(arr[i]);
        DFS(Cnt + 1);
        v.pop_back();
        visited[i] = false;
    }
}

int main() {
    cin >> N >> M;
    int num; 
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    DFS(0);
    return 0;
}