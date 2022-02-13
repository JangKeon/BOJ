#include <iostream>
#include <string.h>
using namespace std;

bool board[52][52] = { false, };
bool visited[52][52] = { false, };
int T, M, N, K;

void dfs(int x, int y) {
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];
		if (!board[ax][ay] || visited[ax][ay]) {
			continue;
		}
		dfs(ax, ay);
	}

}

int main(void) {
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> M >> N >>  K;
		int x, y, result = 0; 
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			board[x + 1][y + 1] = true;
		}

		for (int i = 1; i <= M ; i++) {
			for (int j = 1; j <= N ; j++) {
				if (board[i][j] && !visited[i][j]) {
					dfs(i, j);
					result++;
				}
			}
		}

		cout << result << '\n';
		memset(board, 0, sizeof(board));
		memset(visited, 0, sizeof(visited));
	}
}