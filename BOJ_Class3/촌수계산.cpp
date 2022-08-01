#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int visited[101];
vector <int> graph[101];
queue <int> que;

void bfs() {
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			if (!visited[graph[x][i]]) {
				que.push(graph[x][i]);
				visited[graph[x][i]] = visited[x] + 1;
			}
		}
	}
}

int main(void) {
	int N, M, start, end;
	cin >> N >> start >> end >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	que.push(start);
	visited[start] = 1;
	bfs();
	cout << visited[end] - visited[start];
}