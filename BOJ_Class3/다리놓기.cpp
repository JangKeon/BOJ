#include <iostream>
using namespace std;

int N, M;
bool visited[30];
int result = 0;

void DFS(int Idx, int Cnt)
{
    if (Cnt == N)
    {
        result++;
        return;
    }

    for (int i = Idx; i < M; i++)
    {
        if (visited[i] == true) continue;
        visited[i] = true;
        DFS(i, Cnt + 1);
        visited[i] = false;
    }
}

int main(void) {
    int T;
    cin >> T;
    for (int u = 0; u < T; u++) {
        cin >> N >> M;
        result = 0;
        DFS(0, 0);
        cout << result << '\n';
    }
}