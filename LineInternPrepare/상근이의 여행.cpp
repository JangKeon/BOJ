#include <iostream>
#include <vector>
using namespace std;

vector <int> graph[1001];
int visited[1001];
int res = 0;

void dfs(int x) {
	visited[x] = 1;
	res++;
	for (int i = 0; i < graph[x].size(); i++) {
		if (!visited[graph[x][i]]) {
			visited[graph[x][i]] = 1;
			dfs(visited[graph[x][i]]);
		}
	}
}

int main(void) {
	int T;
	cin >> T;

	for (int u = 0; u < T; u++) {
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dfs(1);
		cout << N - 1 << '\n';
	}
}