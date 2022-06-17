#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
int cost[1001][1001];
int visited[1001][1001];
int crash = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int N, M;
bool check = false;

struct point {
	int x;
	int y;
};

queue <point> que;


int main(void) {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}
	que.push({ 1,1 });
	cost[1][1] = 1;
	visited[1][1] = 1;
	bfs();
	if (!check) {
		cout << "-1\n";
	}
}