#include <iostream>
#include <vector>
using namespace std;

bool visit[1001];
vector <int> graph[1001];

void dfs(int x) {
	visit[x] = true;
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visit[y]) {
			dfs(y);
		}
	}
}

int main(void) {
	int N, M, a, b, result = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		if (visit[i]) {
			continue;
		}
		else {
			dfs(i);
			result++;
		}
	}
	cout << result;
}