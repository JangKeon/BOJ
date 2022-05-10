#include <iostream>
#include <vector>
using namespace std;

struct street {
	int start;
	int end;
	int time;
};

vector <int> map[501];
vector <street> way;
int visit[501];

void dfs(int x) {
	visit[x] = 1;
	for (int i = 0; i < map[x].size(); i++) {
		if (!visit[map[x][i]]) {
			dfs(map[x][i]);
		}
	}
}

int main(void) {
	int T;
	cin >> T;

	for (int a = 0; a < T; a++) {
		int total = 0;
		int N, M, W;
		cin >> N >> M >> W;
		for (int i = 0; i < M; i++) {
			int S, E, T;
			cin >> S >> E >> T;
			map[S].push_back(E);
			way.push_back({ S, E, T });
		}

		for (int i = 0; i < 5; i++) {

		}
	}
}