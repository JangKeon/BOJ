#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

vector <int> graph[1000];
int visit[1001] = { 0, };
queue <int> que;

void dfs(int x) {
	visit[x] = 1;
	cout << x << ' ';
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visit[y]) {
			dfs(graph[x][i]);
		}
	}

}

void bfs() {
	while (!que.empty()) {
		int y = que.front();
		que.pop();
		visit[y] = 1;
		cout << y << ' ';
		for (int i = 0; i < graph[y].size(); i++) {
			int num = graph[y][i];
			if (!visit[num]) {
				visit[num] = 1;
				que.push(num);
			}
		}
	}
}

int main(void) {
	int N, M, V;
	cin >> N >> M >> V;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= 1000; i++) { 
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(V);
	memset(visit, 0, sizeof(visit));
	que.push(V);
	cout << '\n';
	bfs();
}