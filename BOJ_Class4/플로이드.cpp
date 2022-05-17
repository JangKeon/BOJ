#include <iostream>
#include <vector>
using namespace std;

vector < pair <pair<int, int>, int>> vec;
int map[101][101];
int visit[101][101];

void Floyd(int n) {

}

void dfs(int x, int y) {
	visit[x][y] = 1;

}

int main(void) {
	int N, M;
	cin >> N >> M;
	int	a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		vec.push_back({ {a, b},c });
		map[a][b] = c;
	}

	for (int i = 1; i <= N; i++) {
		Floyd(i);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}


}