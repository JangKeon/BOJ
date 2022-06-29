#include <iostream>
using namespace std;

int N, M;
int ch[8];
bool visited[8];


void Print() {
    for (int i = 0; i < 8; i++) {
        if (visited[i] == true) {
            cout << ch[i] << ' ';
        }
    }
    cout << '\n';
}

void DFS(int Idx, int Cnt)
{
    if (Cnt == M){
        Print();
        return;
    }

    for (int i = Idx; i < N; i++)
    {
        if (visited[i] == true) continue;
        visited[i] = true;
        DFS(i, Cnt + 1);
        visited[i] = false;
    }
}

int main(void) {
    for (int i = 0; i < 8; i++) {
        ch[i] = i + 1;
    }
    cin >> N >> M;
    DFS(0, 0);
}